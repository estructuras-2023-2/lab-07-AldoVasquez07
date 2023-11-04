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

    return resultado;
}

int main() {
    vector<int> habilidades1 = {1, 2, 3};
    vector<int> habilidades2 = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
    vector<int> habilidades3 = {30, 12};

    vector<int> resultado1 = simularTorneo(habilidades1, 2, 2);
    
    vector<int> resultado2 = simularTorneo(habilidades2, 10, 399);
    
    vector<int> resultado3 = simularTorneo(habilidades1, 2, 4);
    
    vector<int> resultado4 = simularTorneo(habilidades3, 34, 80);

    cout << "Caso 1: " << resultado1[0] << " " << resultado1[1] << endl;
    cout << "Caso 2: " << resultado2[0] << " " << resultado2[1] << endl;
    cout << "Caso 3: " << resultado3[0] << " " << resultado3[1] << endl;
    cout << "Caso 4: " << resultado4[0] << " " << resultado4[1] << endl;
    return 0;
}

