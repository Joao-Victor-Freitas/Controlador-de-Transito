#ifndef CIDADE_H
#define CIDADE_H
#include <string>

class Cidade {
    private:
        std::string nome;
        int visitas; // Contador de visitas a cidade
    
    public:
        Cidade(std::string nome);
        std::string getNome() const;
        void registrarVisita();
        int getVisitas() const;
};
#endif