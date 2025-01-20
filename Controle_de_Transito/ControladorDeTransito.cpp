#include "ControladorDeTransito.h"

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade " << nome << " cadastrada com sucesso!\n";
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);
    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
        std::cout << "Trajeto de " << nomeOrigem << " para " << nomeDestino << " cadastrado!\n";
    } else {
        std::cout << "Erro: Uma ou mais cidades não foram encontradas.\n";
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (cidade) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, cidade));
        std::cout << "Transporte " << nome << " cadastrado com sucesso em " << localAtual << "!\n";
    } else {
        std::cout << "Erro: Cidade " << localAtual << " não encontrada.\n";
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (cidade) {
        passageiros.push_back(new Passageiro(nome, cidade));
        std::cout << "Passageiro " << nome << " cadastrado em " << localAtual << "!\n";
    } else {
        std::cout << "Erro: Cidade " << localAtual << " não encontrada.\n";
    }
}

void ControladorDeTransito::relatarEstadoPessoas() const {
    for (const auto& passageiro : passageiros) {
        if (passageiro->getTransporteAtual()) {
            std::cout << "Passageiro " << passageiro->getNome() << " está em trânsito de "
                      << passageiro->getTransporteAtual()->getLocalAtual()->getNome() << " para "
                      << passageiro->getTransporteAtual()->getDestinoAtual()->getNome() << ", no transporte "
                      << passageiro->getTransporteAtual()->getNome() << ".\n";
        } else {
            std::cout << "Passageiro " << passageiro->getNome() << " está na cidade "
                      << passageiro->getLocalAtual()->getNome() << ".\n";
        }
    }
}

void ControladorDeTransito::relatarEstadoTransportes() const {
    for (const auto& transporte : transportes) {
        if (transporte->estaEmTransito()) {
            std::cout << "Transporte " << transporte->getNome() << " está em trânsito de "
                      << transporte->getLocalAtual()->getNome() << " para "
                      << transporte->getDestinoAtual()->getNome() << ".\n";
        } else {
            std::cout << "Transporte " << transporte->getNome() << " está na cidade "
                      << transporte->getLocalAtual()->getNome() << ".\n";
        }
    }
}

void ControladorDeTransito::relatarViagensEmAndamento() const {
    for (const auto& transporte : transportes) {
        if (transporte->estaEmTransito()) {
            std::cout << "Viagem em andamento: Transporte " << transporte->getNome() << " de "
                      << transporte->getLocalAtual()->getNome() << " para "
                      << transporte->getDestinoAtual()->getNome() << ".\n";
        }
    }
}

void ControladorDeTransito::relatarCidadesMaisVisitadas() const {
    std::cout << "Relatório das cidades mais visitadas:\n";
    for (const auto& cidade : cidades) {
        std::cout << "Cidade: " << cidade->getNome() << ", Visitas: " << cidade->getVisitas() << "\n";
    }
}

Cidade* ControladorDeTransito::buscarCidade(std::string nome) {
    for (auto cidade : cidades) {
        if (cidade->getNome() == nome) {
            return cidade;
        }
    }
    return nullptr;
}
