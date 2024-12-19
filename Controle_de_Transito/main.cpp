#include <iostream> 
#include <string>   
#include "ControladorDeTransito.h" 

using namespace std; 

int main() {
    ControladorDeTransito controlador;

    int opcao;
    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Cadastrar Cidade\n";
        cout << "2. Cadastrar Trajeto\n";
        cout << "3. Cadastrar Transporte\n";
        cout << "4. Cadastrar Passageiro\n";
        cout << "5. Listar Cidades\n";
        cout << "6. Listar Trajetos\n";
        cout << "7. Listar Transportes\n";
        cout << "8. Listar Passageiros\n";
        cout << "9. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        string nome, origem, destino, localAtual;
        char tipo;
        int capacidade, velocidade, distancia, descanso, distanciaEntreDescansos;

        switch (opcao) {
            case 1:
                cout << "Digite o nome da cidade: ";
                cin >> nome;
                controlador.cadastrarCidade(nome);
                break;

            case 2:
                cout << "Digite a cidade de origem: ";
                cin >> origem;
                cout << "Digite a cidade de destino: ";
                cin >> destino;
                cout << "Digite o tipo de trajeto (T para terrestre, A para aquático): ";
                cin >> tipo;
                cout << "Digite a distância do trajeto (km): ";
                cin >> distancia;
                controlador.cadastrarTrajeto(origem, destino, tipo, distancia);
                break;

            case 3:
                cout << "Digite o nome do transporte: ";
                cin >> nome;
                cout << "Digite o tipo de transporte (T para terrestre, A para aquático): ";
                cin >> tipo;
                cout << "Digite a capacidade de passageiros: ";
                cin >> capacidade;
                cout << "Digite a velocidade (km/h): ";
                cin >> velocidade;
                cout << "Digite a distância entre descansos (km): ";
                cin >> distanciaEntreDescansos;
                cout << "Digite o tempo de descanso (horas): ";
                cin >> descanso;
                cout << "Digite a cidade onde o transporte está atualmente: ";
                cin >> localAtual;
                controlador.cadastrarTransporte(nome, tipo, capacidade, velocidade, distanciaEntreDescansos, descanso, localAtual);
                break;

            case 4:
                cout << "Digite o nome do passageiro: ";
                cin >> nome;
                cout << "Digite a cidade atual do passageiro: ";
                cin >> localAtual;
                controlador.cadastrarPassageiro(nome, localAtual);
                break;

            case 5:
                controlador.listarCidades();
                break;

            case 6:
                controlador.listarTrajetos();
                break;

            case 7:
                controlador.listarTransportes();
                break;

            case 8:
                controlador.listarPassageiros();
                break;

            case 9:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 9);

    return 0;
}
