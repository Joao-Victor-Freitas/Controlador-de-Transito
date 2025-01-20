#ifndef CONTROLADOR_DE_TRANSITO_H
#define CONTROLADOR_DE_TRANSITO_H
#include <iostream>
#include <vector>
#include <string>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"

class ControladorDeTransito {
    private:
        std::vector<Cidade*> cidades;
        std::vector<Trajeto*> trajetos;
        std::vector<Transporte*> transportes;
        std::vector<Passageiro*> passageiros;
    
    public:
        void cadastrarCidade(std::string nome);
        void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);
        void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual);
        void cadastrarPassageiro(std::string nome, std::string localAtual);
    
        void relatarEstadoPessoas() const;
        void relatarEstadoTransportes() const;
        void relatarViagensEmAndamento() const;
        void relatarCidadesMaisVisitadas() const;
    
        Cidade* buscarCidade(std::string nome);
};

#endif