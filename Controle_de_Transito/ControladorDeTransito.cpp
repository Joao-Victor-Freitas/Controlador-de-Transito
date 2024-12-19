#include "ControladorDeTransito.h"
#include <iostream>

// Método para cadastrar uma cidade
void ControladorDeTransito::cadastrarCidade(const std::string& nome) {
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade \"" << nome << "\" cadastrada com sucesso.\n";
}

// Método para cadastrar um trajeto
void ControladorDeTransito::cadastrarTrajeto(const std::string& nomeOrigem, const std::string& nomeDestino, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    // Localiza as cidades pelo nome
    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == nomeOrigem) origem = cidade;
        if (cidade->getNome() == nomeDestino) destino = cidade;
    }

    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
        std::cout << "Trajeto de \"" << nomeOrigem << "\" para \"" << nomeDestino << "\" cadastrado com sucesso.\n";
    } else {
        std::cout << "Erro: Cidade de origem ou destino não encontrada.\n";
    }
}

// Método para cadastrar um transporte
void ControladorDeTransito::cadastrarTransporte(const std::string& nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescansos, int tempoDeDescanso, const std::string& localAtual) {
    Cidade* local = nullptr;

    // Localiza a cidade pelo nome
    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
            break;
        }
    }

    if (local) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso, local));
        std::cout << "Transporte \"" << nome << "\" cadastrado com sucesso.\n";
    } else {
        std::cout << "Erro: Cidade \"" << localAtual << "\" não encontrada.\n";
    }
}

// Método para cadastrar um passageiro
void ControladorDeTransito::cadastrarPassageiro(const std::string& nome, const std::string& localAtual) {
    Cidade* local = nullptr;

    // Localiza a cidade pelo nome
    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
            break;
        }
    }

    if (local) {
        passageiros.push_back(new Passageiro(nome, local));
        std::cout << "Passageiro \"" << nome << "\" cadastrado com sucesso.\n";
    } else {
        std::cout << "Erro: Cidade \"" << localAtual << "\" não encontrada.\n";
    }
}

// Método para listar todas as cidades
void ControladorDeTransito::listarCidades() const {
    std::cout << "\nCidades cadastradas:\n";
    for (const Cidade* cidade : cidades) {
        std::cout << "- " << cidade->getNome() << "\n";
    }
}

// Método para listar todos os trajetos
void ControladorDeTransito::listarTrajetos() const {
    std::cout << "\nTrajetos cadastrados:\n";
    for (const Trajeto* trajeto : trajetos) {
        std::cout << "- Origem: " << trajeto->getOrigem()->getNome()
                  << ", Destino: " << trajeto->getDestino()->getNome()
                  << ", Tipo: " << (trajeto->getTipo() == 'T' ? "Terrestre" : "Aquático")
                  << ", Distância: " << trajeto->getDistancia() << " km\n";
    }
}

// Método para listar todos os transportes
void ControladorDeTransito::listarTransportes() const {
    std::cout << "\nTransportes cadastrados:\n";
    for (const Transporte* transporte : transportes) {
        std::cout << "- Nome: " << transporte->getNome()
                  << ", Tipo: " << (transporte->getTipo() == 'T' ? "Terrestre" : "Aquático")
                  << ", Capacidade: " << transporte->getCapacidade()
                  << ", Velocidade: " << transporte->getVelocidade() << " km/h\n";
    }
}

// Método para listar todos os passageiros
void ControladorDeTransito::listarPassageiros() const {
    std::cout << "\nPassageiros cadastrados:\n";
    for (const Passageiro* passageiro : passageiros) {
        std::cout << "- Nome: " << passageiro->getNome()
                  << ", Local Atual: " << passageiro->getLocalAtual()->getNome() << "\n";
    }
}
