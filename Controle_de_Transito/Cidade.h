#ifndef CIDADE_H
#define CIDADE_H

#include <string>

class Cidade {
private:
    std::string nome;

public:
    Cidade(std::string nome); // Construtor
    std::string getNome() const; // Retorna o nome da cidade
};

#endif
