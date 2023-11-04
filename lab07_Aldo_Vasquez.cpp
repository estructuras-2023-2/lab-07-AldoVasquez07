#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> Torneo(vector<int> habilidades, int N, int K) {
    int tam = habilidades.size();

    queue<int> torneoQueue;
    
    for (int i = 2; i < tam; i++) {
        torneoQueue.push(habilidades[i]);
    }

    int rondasGanadas = 0;
    int jugador1 = habilidades[0];
    int jugador2 = habilidades[1];

    vector<int> resultado(2);

    return habilidades;
}

int main() {
    vector<int> habilidades = {1,2,3}
    vector<int> caso1 = Torneo(habilidades, 2, 2);
}