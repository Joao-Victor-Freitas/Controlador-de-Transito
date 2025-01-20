#include "Cidade.h"

Cidade::Cidade(std::string nome) : nome(nome), visitas(0) {}

std::string Cidade::getNome() const { return nome; }

void Cidade::registrarVisita() { visitas++; }

int Cidade::getVisitas() const { return visitas; }