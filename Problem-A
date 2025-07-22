#include <iostream>
using namespace std;

bool imprimir(string linha, bool teclaBloq[26]) {
    for (size_t i = 0; i < linha.size(); i++) {
        char c = linha[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z') {
            if (teclaBloq[c - 'a']) {
                return false;
            }
        }
    }
    return true;
}
void marcarLetras(string linha, bool usadas[26]) {
    for (size_t i = 0; i < linha.size(); i++) {
        char c = linha[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z') {
            usadas[c - 'a'] = true;
        }
    }
}

int main() {
    string linha;
    cout << "+----------+----------------+-----------------------------+" << endl;
    cout << "| Keyboard | # of printable | Additionally, the following |" << endl;
    cout << "|          |      lines     |  letter keys can be broken  |" << endl;
    cout << "+----------+----------------+-----------------------------+" << endl;
    int teclado_id = 1;
    while (getline(cin, linha)) {
        if (linha == "finish") break;

        bool teclaBloq[26] = {false};
        for (size_t i = 0; i < linha.size(); i++) {
            char c = linha[i];
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            if (c >= 'a' && c <= 'z') {
                teclaBloq[c - 'a'] = true;
            }
        }
        int qtdLinha = 0;
        bool usadas[26] = {false};
        while (getline(cin, linha)) {
            if (linha == "END") {
                if (imprimir(linha, teclaBloq)) {
                    marcarLetras(linha, usadas);
                    qtdLinha++;
                }
                break;
            }

            if (imprimir(linha, teclaBloq)) {
                marcarLetras(linha, usadas);
                qtdLinha++;
            }
        }
        char adicionais[27];
        int tam_ad = 0;
        for (int i = 0; i < 26; i++) {
            if (!teclaBloq[i] && !usadas[i]) {
                adicionais[tam_ad++] = 'a' + i;
            }
        }
        adicionais[tam_ad] = '\0';
        printf("|%6d    |%9d       | %-27s |\n", teclado_id, qtdLinha, adicionais);
        cout << "+----------+----------------+-----------------------------+" << endl;
        teclado_id++;
    }
    return 0;
}
