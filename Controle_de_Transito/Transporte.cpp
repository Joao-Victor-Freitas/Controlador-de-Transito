#include "Transporte.h"

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade,
                       int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual)
    : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade),
      distancia_entre_descansos(distancia_entre_descansos), tempo_de_descanso(tempo_de_descanso),
      tempo_de_descanso_atual(0), localAtual(localAtual) {}

std::string Transporte::getNome() const {
    return nome;
}

char Transporte::getTipo() const {
    return tipo;
}

int Transporte::getCapacidade() const {
    return capacidade;
}

int Transporte::getVelocidade() const {
    return velocidade;
}

Cidade* Transporte::getLocalAtual() const {
    return localAtual;
}

void Transporte::setLocalAtual(Cidade* local) {
    localAtual = local;
}
