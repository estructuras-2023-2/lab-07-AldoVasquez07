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
    
    while (K > 0) {
    if (jugador1 > jugador2) {
        rondasGanadas++;
        resultado = {jugador2, jugador1};
        torneoQueue.push(jugador2);
    } else {
        rondasGanadas = 1;
        resultado = {jugador1, jugador2};
        torneoQueue.push(jugador1);
        jugador1 = jugador2;
    }
    
    if (rondasGanadas == N) {
        torneoQueue.push(jugador1);
        jugador1 = torneoQueue.front();
        torneoQueue.pop();
        rondasGanadas = 0;
    }
    jugador2 = torneoQueue.front();
    torneoQueue.pop();
    
    K--;
}

    return habilidades;
}

int main() {
    vector<int> habilidades = {1,2,3}
    vector<int> caso1 = Torneo(habilidades, 2, 2);
}