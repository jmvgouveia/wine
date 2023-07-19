
#ifndef ADEGA_H
#define ADEGA_H

#include "main.h"
#include "vinho.h"



class Adega {
private:
    string nome;
    string localidade;
    string pais;
    string paginaweb;
    vector<Vinho> vinhos;

public: 

    Adega();
    ~Adega(); 
   

    string getNome() const;
    string getLocalidade() const;
    string getPais() const;
    string getPaginaWeb() const;

    void setNome(string nome);
    void setLocalidade(string localidade);
    void setPais(string pais);
    void setPaginaWeb(string paginaweb);

    void adicionarVinho(vector<Vinho> vinhos);
    void removerVinho(Vinho vinho);

    void imprimirAdega();
    void imprimirVinhos();
    
    void mediaVolume();

    void mediaVolumeTipo(string tipo);

    void mediaVolumeTodasAdegas(vector<Adega> adegas);
    
    void vinhosCom(vector<Adega> adegas, string tipo_refeicao);

};

#endif