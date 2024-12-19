#ifndef CONTROLADOR_DE_TRANSITO_H
#define CONTROLADOR_DE_TRANSITO_H

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
    // Métodos de cadastro
    void cadastrarCidade(const std::string& nome);
    void cadastrarTrajeto(const std::string& nomeOrigem, const std::string& nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(const std::string& nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescansos, int tempoDeDescanso, const std::string& localAtual);
    void cadastrarPassageiro(const std::string& nome, const std::string& localAtual);

    // Métodos de listagem
    void listarCidades() const;
    void listarTrajetos() const;
    void listarTransportes() const;
    void listarPassageiros() const;
};

#endif // CONTROLADOR_DE_TRANSITO_H
