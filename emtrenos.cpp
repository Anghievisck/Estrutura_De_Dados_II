#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <iomanip>
#include <limits>

using namespace std;

const int MAX = 110;
const double INF = numeric_limits<double>::max();

typedef pair<int, double> Edge;             // (destino, peso)
typedef vector<vector<Edge>> Graph;
typedef pair<double, int> State;            // (custo acumulado, vértice)

// Dijkstra genérico
vector<double> dijkstra(int origem, const Graph &G, int V) {
    vector<double> dist(V, INF);
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[origem] = 0.0;
    pq.push({0.0, origem});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, peso] : G[u]) {
            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int M, E, N, C;
    cin >> M >> E >> N >> C;

    Graph G_Crewmate(M);     // Grafo com corredores
    Graph G_Impostor(M);     // Grafo com tubos + corredores

    // Leitura dos corredores
    for (int i = 0; i < E; i++) {
        int u, v;
        double d;
        cin >> u >> v >> d;
        G_Crewmate[u].push_back({v, d});
        G_Crewmate[v].push_back({u, d});
        G_Impostor[u].push_back({v, d});
        G_Impostor[v].push_back({u, d});
    }

    // Leitura das tubulações (peso 1)
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        G_Impostor[u].push_back({v, 1.0});
        G_Impostor[v].push_back({u, 1.0});
    }

    // Distância da sua personagem (a partir do botão 0)
    vector<double> dist_crewmate = dijkstra(0, G_Crewmate, M);
    vector<double> dist_impostor = dijkstra(0, G_Impostor, M);

    // Consultas
    for (int i = 0; i < C; i++) {
        int impostor_pos;
        cin >> impostor_pos;

        double tempo_crewmate = dist_crewmate[impostor_pos];
        double tempo_impostor = dist_impostor[impostor_pos];

        if (tempo_impostor < tempo_crewmate - 1e-6)
            cout << "defeat\n";
        else
            cout << "victory\n";
    }

    return 0;
}