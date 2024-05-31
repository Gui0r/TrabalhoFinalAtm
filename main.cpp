#include <iostream>
#include <string>
using namespace std;

const int NUM_NOTAS = 4;

// Função de separação das notas por valor
void contaNotas(int qtdNotas[NUM_NOTAS], const int valNotas[NUM_NOTAS], int saque) {
    for (int i = 0; i < NUM_NOTAS; i++) {
        qtdNotas[i] = saque / valNotas[i];
        saque %= valNotas[i];
    }
}

// Função para registrar os valores das notas
void cadastraNotas(int valNotas[NUM_NOTAS]) {
    cout << "=================================\n";
    cout << "Registro dos valores das notas\n";
    cout << "=================================\n";
    for (int i = 0; i < NUM_NOTAS; i++) {
        cout << "Digite o valor da nota: ";
        cin >> valNotas[i];
    }
    cout << "=================================\n";
}

// Função para simular a saída das notas
void simulaSaida(const int qtdNotas[NUM_NOTAS], const int valNotas[NUM_NOTAS]) {
    cout << "=================================\n";
    for (int i = 0; i < NUM_NOTAS; i++) {
        cout << "Qtd. Notas de " << valNotas[i] << ": " << qtdNotas[i] << "\n";
    }
    cout << "=================================\n";
}

// Fluxo principal do código
int main() {
    int saque = 0;
    int exitSystem = 0;

    int qtdNotas[NUM_NOTAS] = {0};
    int valNotas[NUM_NOTAS] = {0};

    // Inicializa notas
    cadastraNotas(valNotas); // Cadastra valores das notas

    // Laço principal do simulador
    while (exitSystem != 1) {
        // Lê valor a ser sacado do Caixa Eletrônico
        cout << "\n=================================\n";
        cout << "Digite o valor a ser sacado: ";
        cin >> saque;

        if (saque == 9999) {
            exitSystem = 1;
            cout << "=================================\n";
            cout << "SISTEMA INTERROMPIDO - COD.9999\n";
            cout << "=================================\n";
            break;
        }

        // Executa funções para separar quantidade de notas por seu valor
        contaNotas(qtdNotas, valNotas, saque); // Conta notas por valor
        simulaSaida(qtdNotas, valNotas); // Simula saída de notas
    }

    // Final do main
    return 0;
}
