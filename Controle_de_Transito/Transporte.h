#ifndef TRANSPORTE_H
#define TRANSPORTE_H
#include "Cidade.h"

class Transporte {
    private:
        std::string nome;
        char tipo;
        int capacidade;
        int velocidade;
        int distancia_entre_descansos;
        int tempo_de_descanso;
        int tempo_de_descanso_atual;
        Cidade* localAtual;
        bool emTransito;
        Cidade* destinoAtual;
    
    public:
        Transporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual);
        std::string getNome() const;
        char getTipo() const;
        int getCapacidade() const;
        int getVelocidade() const;
        int getDistanciaEntreDescansos() const;
        int getTempoDescanso() const;
        int getTempoDescansoAtual() const;
        Cidade* getLocalAtual() const;
        void setLocalAtual(Cidade* local);
        bool estaEmTransito() const;
        void iniciarViagem(Cidade* destino);
        void finalizarViagem();
        Cidade* getDestinoAtual() const;
};

#endif
