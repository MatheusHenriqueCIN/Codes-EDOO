#include <iostream>
#include <string>
using namespace std;

bool balanceamento(string entrada) {
    char pilha[100]; // pilha 
    int topo = -1;
    for (int i = 0; i < entrada.size(); i++) {
        char caractere = entrada[i];
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            topo = topo + 1;
            pilha[topo] = caractere;
        }
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (topo == -1) {
                return false;
            }
            char ultimo = pilha[topo];
            if (caractere == ')' && ultimo != '(') {
                return false;
            }
            if (caractere == ']' && ultimo != '[') {
                return false;
            }
            if (caractere == '}' && ultimo != '{') {
                return false;
            }
            topo = topo - 1;
        }
    }
    if (topo == -1) {
        return true;
    }
    return false;
}
int main() {
    int quantidade;
    cin >> quantidade;
    for (int i = 0; i < quantidade; i++) {
        string texto;
        cin >> texto;
        bool resultado = balanceamento(texto);
        if (resultado == true) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
