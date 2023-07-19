#ifndef VINHO_H
#define VINHO_H


#include "main.h"



class Vinho {
private:
    string nome;
    string tipo;
    vector<string> castas;
    vector<string> tipo_refeicao;
    float volume;
    

public: 

    Vinho();
    ~Vinho(){}; 
    
    string getNome() const;
    string getTipo() const;
    vector<string> getCastas() const;
    vector<string> getTipoRefeicao() const;
    float getVolume() const;

    void setNome(string nome);
    void setTipo(string tipo);
    void setCastas(vector<string> castas);
    void setTipoRefeicao(vector<string> tipo_refeicao);
    void setVolume(float volume);

    void imprimirVinho();

};

#endif