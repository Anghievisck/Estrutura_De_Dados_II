#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int x, int y){ return x > y; }

int main(void){
    int n, aux;

    cin >> n;

    vector<int> itens;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        itens.push_back(aux);
    }

    sort(itens.begin(), itens.end(), desc);

    int max_discount = 0;
    for(int i = 2; i < n; i += 3){
        max_discount += itens[i];
    }

    cout << max_discount << endl;

    return 0;
}