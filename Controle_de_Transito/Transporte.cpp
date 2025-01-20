#include "Transporte.h"

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual)
    : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade), distancia_entre_descansos(distancia_entre_descansos), tempo_de_descanso(tempo_de_descanso), tempo_de_descanso_atual(0), localAtual(localAtual), emTransito(false), destinoAtual(nullptr) {}

std::string Transporte::getNome() const { return nome; }

char Transporte::getTipo() const { return tipo; }

int Transporte::getCapacidade() const { return capacidade; }

int Transporte::getVelocidade() const { return velocidade; }

int Transporte::getDistanciaEntreDescansos() const { return distancia_entre_descansos; }

int Transporte::getTempoDescanso() const { return tempo_de_descanso; }

int Transporte::getTempoDescansoAtual() const { return tempo_de_descanso_atual; }

Cidade* Transporte::getLocalAtual() const { return localAtual; }

void Transporte::setLocalAtual(Cidade* local) { localAtual = local; }

bool Transporte::estaEmTransito() const { return emTransito; }

void Transporte::iniciarViagem(Cidade* destino) {
    emTransito = true;
    destinoAtual = destino;
}

void Transporte::finalizarViagem() {
    emTransito = false;
    localAtual = destinoAtual;
    destinoAtual = nullptr;
}

Cidade* Transporte::getDestinoAtual() const { return destinoAtual; }
