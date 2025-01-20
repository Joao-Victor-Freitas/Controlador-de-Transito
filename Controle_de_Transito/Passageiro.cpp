#include "Passageiro.h"

Passageiro::Passageiro(std::string nome, Cidade* localAtual) : nome(nome), localAtual(localAtual), transporteAtual(nullptr) {}

std::string Passageiro::getNome() const { return nome; }

Cidade* Passageiro::getLocalAtual() const { return localAtual; }

void Passageiro::setLocalAtual(Cidade* local) { localAtual = local; }

Transporte* Passageiro::getTransporteAtual() const { return transporteAtual; }

void Passageiro::embarcar(Transporte* transporte) {
    transporteAtual = transporte;
    localAtual = nullptr;
}

void Passageiro::desembarcar() {
    localAtual = transporteAtual->getLocalAtual();
    transporteAtual = nullptr;
}
