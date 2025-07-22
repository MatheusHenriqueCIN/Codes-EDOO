
#include <iostream>
using namespace std;

int main() {
    int testes;
    cin >> testes;

    while (testes > 0) {
        testes--;
        int l, m;
        cin >> l >> m;
        l = l * 100;
        int esquerda[10000], direita[10000];
        int tam_esq = 0, tam_dir = 0;

        for (int i = 0; i < m; i++) {
            int tamanho;
            char lado[10];
            cin >> tamanho >> lado;

            if (lado[0] == 'l') {
                esquerda[tam_esq++] = tamanho;
            } 
            else {
                direita[tam_dir++] = tamanho;
            }
        }
        int indice_esq = 0;
        int indice_dir = 0;
        int travessias = 0;
        string lado = "left";

        while (indice_esq < tam_esq || indice_dir < tam_dir) {
            int espaco = 0;

            if (lado == "left") {
                while (indice_esq < tam_esq && espaco + esquerda[indice_esq] <= l) {
                    espaco += esquerda[indice_esq];
                    indice_esq++;
                }
            } 
            
            else {
                while (indice_dir < tam_dir && espaco + direita[indice_dir] <= l) {
                    espaco += direita[indice_dir];
                    indice_dir++;
                }
            }

            travessias++;
            if (lado == "left") {
                lado = "right";
            } 
            else {
                lado = "left";
            }
        }
        cout << travessias << endl;
    }
    return 0;
}
