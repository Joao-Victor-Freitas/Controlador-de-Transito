#include "ControladorDeTransito.h"
#include <iostream>

void exibirMenu() {
    std::cout << "\n===== Sistema de Controle de Viagens =====\n";
    std::cout << "1. Cadastrar Cidade\n";
    std::cout << "2. Cadastrar Trajeto\n";
    std::cout << "3. Cadastrar Transporte\n";
    std::cout << "4. Cadastrar Passageiro\n";
    std::cout << "5. Relatar Estado das Pessoas\n";
    std::cout << "6. Relatar Estado dos Transportes\n";
    std::cout << "7. Relatar Viagens em Andamento\n";
    std::cout << "8. Relatar Cidades Mais Visitadas\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    ControladorDeTransito controlador;
    int opcao;

    do {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1: {
                std::string nomeCidade;
                std::cout << "Digite o nome da cidade: ";
                std::getline(std::cin, nomeCidade);
                controlador.cadastrarCidade(nomeCidade);
                break;
            }
            case 2: {
                std::string origem, destino;
                char tipo;
                int distancia;

                std::cout << "Digite o nome da cidade de origem: ";
                std::getline(std::cin, origem);
                std::cout << "Digite o nome da cidade de destino: ";
                std::getline(std::cin, destino);
                std::cout << "Digite o tipo de trajeto (A - Aquático, T - Terrestre): ";
                std::cin >> tipo;
                std::cout << "Digite a distância (em km): ";
                std::cin >> distancia;
                std::cin.ignore();

                controlador.cadastrarTrajeto(origem, destino, tipo, distancia);
                break;
            }
            case 3: {
                std::string nomeTransporte, localAtual;
                char tipo;
                int capacidade, velocidade, distanciaDescanso, tempoDescanso;

                std::cout << "Digite o nome do transporte: ";
                std::getline(std::cin, nomeTransporte);
                std::cout << "Digite o tipo do transporte (A - Aquático, T - Terrestre): ";
                std::cin >> tipo;
                std::cout << "Digite a capacidade de passageiros: ";
                std::cin >> capacidade;
                std::cout << "Digite a velocidade (em km/h): ";
                std::cin >> velocidade;
                std::cout << "Digite a distância entre descansos (em km): ";
                std::cin >> distanciaDescanso;
                std::cout << "Digite o tempo de descanso (em horas): ";
                std::cin >> tempoDescanso;
                std::cin.ignore();
                std::cout << "Digite o local atual do transporte: ";
                std::getline(std::cin, localAtual);

                controlador.cadastrarTransporte(nomeTransporte, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual);
                break;
            }
            case 4: {
                std::string nomePassageiro, localAtual;

                std::cout << "Digite o nome do passageiro: ";
                std::getline(std::cin, nomePassageiro);
                std::cout << "Digite o local atual do passageiro: ";
                std::getline(std::cin, localAtual);

                controlador.cadastrarPassageiro(nomePassageiro, localAtual);
                break;
            }
            case 5: {
                controlador.relatarEstadoPessoas();
                break;
            }
            case 6: {
                controlador.relatarEstadoTransportes();
                break;
            }
            case 7: {
                controlador.relatarViagensEmAndamento();
                break;
            }
            case 8: {
                controlador.relatarCidadesMaisVisitadas();
                break;
            }
            case 0: {
                std::cout << "Encerrando o sistema...\n";
                break;
            }
            default: {
                std::cout << "Opção inválida! Tente novamente.\n";
            }
        }

    } while (opcao != 0);

    return 0;
}
