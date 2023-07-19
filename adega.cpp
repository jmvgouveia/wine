#include "adega.h"

Adega::Adega() {
    this->nome = "";
    this->localidade = "";
    this->pais = "";
    this->paginaweb = "";
}

 Adega::~Adega(){}

string Adega::getNome() const {
    return nome;
}

string Adega::getLocalidade() const {
    return localidade;
}

string Adega::getPais() const {
    return pais;
}

string Adega::getPaginaWeb() const {
    return paginaweb;
}

void Adega::setNome(string nome) {
    this->nome = nome;
}

void Adega::setLocalidade(string localidade) {
    this->localidade = localidade;
}

void Adega::setPais(string pais) {
    this->pais = pais;
}

void Adega::setPaginaWeb(string paginaweb) {
    this->paginaweb = paginaweb;
}

void Adega::adicionarVinho(vector<Vinho> vinhos) {
    for (size_t i = 0; i < vinhos.size(); i++) {
        this->vinhos.push_back(vinhos[i]);
    }
}

void Adega::removerVinho(Vinho vinho) {
    for (size_t i = 0; i < vinhos.size(); i++) {
        if (vinhos[i].getNome() == vinho.getNome()) {
            vinhos.erase(vinhos.begin() + i);
        }
    }
}

void Adega::imprimirVinhos() {
    for (size_t i = 0; i < vinhos.size(); i++) {
        cout << vinhos[i].getNome() << endl;
    }
}

void Adega::imprimirAdega() {
    
    cout << "\n*** "<< nome << " **** "<< endl;
    cout << "Localidade: " << localidade << endl;
    cout << "Pais: " << pais << endl;
    cout << "Pagina Web: " << paginaweb << endl;
    cout << "Lista de Vinhos: " << endl;
    for (size_t i = 0; i < vinhos.size(); i++) {
        cout <<"Nome: "<< vinhos[i].getNome();
        cout <<" | Tipo: "<< vinhos[i].getTipo();
        cout << " | Castas: ";
        for (size_t j = 0; j < vinhos[i].getCastas().size(); j++) {
            cout << vinhos[i].getCastas()[j] << ", ";
        }
        cout << " | Tipos de Refeição: ";
        for (size_t j = 0; j < vinhos[i].getTipoRefeicao().size(); j++) {
            cout << vinhos[i].getTipoRefeicao()[j] << ", ";
        }
    cout  << " | Volume: "<< vinhos[i].getVolume() << endl;

    }
}

void Adega::mediaVolume() {

    vector<pair<string, float>> volumes;

    float media = 0;
    for (size_t i = 0; i < vinhos.size(); i++) 
    {   
        media += vinhos[i].getVolume();
    }
    media = media / vinhos.size();
    cout << "Media de Volume: " << media << endl;

    // Preencher o vetor volumes com os vinhos com volume inferior à média

    for (size_t i = 0; i < vinhos.size(); i++) 
    {   
       if (vinhos[i].getVolume() < media) {
           volumes.push_back(make_pair(vinhos[i].getNome(), vinhos[i].getVolume()));
       }
    }
    // Criar nome do ficheiro comsoante o nome da adega
    string nomeficheiro = "suaves" + nome + ".txt";

    // Criar Ficheiro.txt com os vinhos com volume inferior à média
    ofstream fw(nomeficheiro, std::ofstream::out);

    if (fw.is_open())
    {
   // Guardar os vinhos com volume inferior à média no ficheiro
    for (size_t i = 0; i < volumes.size(); i++) {
            fw << volumes[i].first << " " << volumes[i].second << endl;
    }
    fw.close();
    cout<< "Ficheiro criado com sucesso!!\n";
    }
    else cout << "Erro no ficheiro!!\n";

    // fecha o ficheiro
    fw.close();

}

void Adega::mediaVolumeTipo(string tipo) {
   vector<pair<string, float>> volumes;
    float media = 0;
    int numvinhos = 0;

    for (size_t i = 0; i < vinhos.size(); i++) {
        if (vinhos[i].getTipo() == tipo) {
            media += vinhos[i].getVolume();
            numvinhos++;
        }
    }
    media = media / numvinhos;
    cout << "Media de Volume de Vinhos do Tipo " << tipo << ": " << media << endl;

    for (size_t i = 0; i < vinhos.size(); i++) {
        if (vinhos[i].getTipo() == tipo) {
            if (vinhos[i].getVolume() < media) {
                volumes.push_back(make_pair(vinhos[i].getNome(), vinhos[i].getVolume()));
            }else{
                volumes.push_back(make_pair("Nao existem vinhos " + tipo +" com volume inferior a media!!", 0));
            }
        }
    }
 string nomeficheiro = "suavescomtipo.txt";

    // Criar Ficheiro.txt com os vinhos com volume inferior à média
    ofstream fw(nomeficheiro, std::ofstream::out);

    if (fw.is_open())
    {
   // Guardar os vinhos com volume inferior à média no ficheiro
    for (size_t i = 0; i < volumes.size(); i++) {
            fw << volumes[i].first << " " << volumes[i].second << endl;
    }
    fw.close();
    cout<< "Ficheiro criado com sucesso!!\n";
    }
    else cout << "Erro no ficheiro!!\n";

    // fecha o ficheiro
    fw.close();


}


void Adega::mediaVolumeTodasAdegas(vector<Adega> adegas) {

     vector<pair<string, float>> volumes;

    float media = 0;
    int numvinhos = 0;

    for (size_t i = 0; i < adegas.size(); i++) {
        for (size_t j = 0; j < adegas[i].vinhos.size(); j++) {
            media += adegas[i].vinhos[j].getVolume();
           
            numvinhos++;
        }
    }
    media = media / numvinhos;
    cout << "Media de Volume de Todos os Vinhos: " << media << endl;

      for (size_t i = 0; i < adegas.size(); i++) {
        for (size_t j = 0; j < adegas[i].vinhos.size(); j++) {

            if (adegas[i].vinhos[j].getVolume() < media) {
                volumes.push_back(make_pair(adegas[i].vinhos[j].getNome(), adegas[i].vinhos[j].getVolume()));
            }
         }
    }

    // Criar nome do ficheiro comsoante o nome da adega
    string nomeficheiro = "suaves.txt";

    // Criar Ficheiro.txt com os vinhos com volume inferior à média
    ofstream fw(nomeficheiro, std::ofstream::out);

    if (fw.is_open())
    {
   // Guardar os vinhos com volume inferior à média no ficheiro
    for (size_t i = 0; i < volumes.size(); i++) {
            fw << volumes[i].first << " " << volumes[i].second << endl;
    }
    fw.close();
    cout<< "Ficheiro criado com sucesso!!\n";
    }
    else cout << "Erro no ficheiro!!\n";

    // fecha o ficheiro
    fw.close();


}

void Adega::vinhosCom(vector<Adega>adegas, string tiporefeicao){
    bool flag = false;

    cout << "*** Vinhos para acompanhar com: " << tiporefeicao << " ***" << endl;
    for (size_t i = 0; i < adegas.size(); i++) {
        for (size_t j = 0; j < adegas[i].vinhos.size(); j++) {
            flag = false; // flag para verificar se o URL já foi impresso
            if(adegas[i].vinhos[j].getTipoRefeicao().size() > 0){
                for (size_t k = 0; k < adegas[i].vinhos[j].getTipoRefeicao().size(); k++) {
                    if(adegas[i].vinhos[j].getTipoRefeicao()[k] == tiporefeicao){
                        cout << adegas[i].getPaginaWeb() << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        
    }




}