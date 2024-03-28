#include <iostream>
#include <vector>

using namespace std;

class Teatro {
private:
    int fileiras;
    int poltronas_por_fileira;
    vector<vector<char>> mapa_ocupacao;
    int lugares_ocupados;
    float faturamento;

public:
    Teatro() {
        fileiras = 15;
        poltronas_por_fileira = 40;
        mapa_ocupacao.resize(fileiras, vector<char>(poltronas_por_fileira, '.'));
        lugares_ocupados = 0;
        faturamento = 0;
    }

    void reservarPoltrona(int fileira, int poltrona) {
        if (fileira < 1 || fileira > fileiras || poltrona < 1 || poltrona > poltronas_por_fileira) {
            cout << "Fileira ou poltrona inválida." << endl;
            return;
        }

        if (mapa_ocupacao[fileira - 1][poltrona - 1] == '#') {
            cout << "Este lugar já está ocupado." << endl;
        } else {
            int preco;
            if (fileira <= 5) {
                preco = 50;
            } else if (fileira <= 10) {
                preco = 30;
            } else {
                preco = 15;
            }

            mapa_ocupacao[fileira - 1][poltrona - 1] = '#';
            lugares_ocupados++;
            faturamento += preco;
            cout << "Reserva realizada com sucesso." << endl;
        }
    }

    void mostrarMapaOcupacao() {
        for (const auto& fileira : mapa_ocupacao) {
            for (char lugar : fileira) {
                cout << lugar;
            }
            cout << endl;
        }
    }

    void mostrarFaturamento() {
        cout << "Qtde de lugares ocupados: " << lugares_ocupados << endl;
        cout << "Valor da bilheteria: R$ " << fixed << faturamento << endl;
    }
};

int main() {
    Teatro teatro;

    while (true) {
        cout << "\nSelecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        } else if (opcao == 1) {
            int fileira, poltrona;
            cout << "Informe a fileira: ";
            cin >> fileira;
            cout << "Informe a poltrona: ";
            cin >> poltrona;
            teatro.reservarPoltrona(fileira, poltrona);
        } else if (opcao == 2) {
            teatro.mostrarMapaOcupacao();
        } else if (opcao == 3) {
            teatro.mostrarFaturamento();
        } else {
            cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
