#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include "Cidade.h"
#include "Transporte.h"

class Passageiro {
    private:
        std::string nome;
        Cidade* localAtual;
        Transporte* transporteAtual;
    
    public:
        Passageiro(std::string nome, Cidade* localAtual);
        std::string getNome() const;
        Cidade* getLocalAtual() const;
        void setLocalAtual(Cidade* local);
        Transporte* getTransporteAtual() const;
        void embarcar(Transporte* transporte);
        void desembarcar();
};

#endif