#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> agenda;
    char op;
    string nome, telefone;

    while (cin >> op) {
        if (op == '0') break;

        cin >> nome;

        if (op == 'I') {
            cin >> telefone;
            if (agenda.find(nome) != agenda.end()) {
                cout << "Contatinho ja inserido\n";
            } else {
                agenda[nome] = telefone;
            }
        } else if (op == 'P') {
            if (agenda.find(nome) != agenda.end()) {
                cout << "Contatinho encontrado: telefone " << agenda[nome] << "\n";
            } else {
                cout << "Contatinho nao encontrado\n";
            }
        } else if (op == 'R') {
            if (agenda.find(nome) != agenda.end()) {
                agenda.erase(nome);
            } else {
                cout << "Operacao invalida: contatinho nao encontrado\n";
            }
        } else if (op == 'A') {
            cin >> telefone;
            if (agenda.find(nome) != agenda.end()) {
                agenda[nome] = telefone;
            } else {
                cout << "Operacao invalida: contatinho nao encontrado\n";
            }
        }
    }

    return 0;
}