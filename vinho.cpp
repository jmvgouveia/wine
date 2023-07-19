#include "vinho.h"

Vinho::Vinho() {
    this->nome = "";
    this->tipo = "";
    this->volume = 0;
}

string Vinho::getNome() const {
    return nome;
}

string Vinho::getTipo() const {
    return tipo;
}

float Vinho::getVolume() const {
    return volume;
}

vector<string> Vinho::getCastas() const {
    return castas;
}

vector<string> Vinho::getTipoRefeicao() const {
    return tipo_refeicao;
}


void Vinho::setNome(string nome) {
    this->nome = nome;
}

void Vinho::setTipo(string tipo) {
    this->tipo = tipo;
}

void Vinho::setVolume(float volume) {
    this->volume = volume;
}

void Vinho::setCastas(vector<string> castas) {
    this->castas = castas;
}


void Vinho::setTipoRefeicao(vector<string> tipo_refeicao) {
    this->tipo_refeicao = tipo_refeicao;
}

void Vinho::imprimirVinho() {
    cout << "Nome: " << nome << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Volume: " << volume << endl;
    cout << "Castas: ";
    for (size_t i = 0; i < castas.size(); i++) {
        cout << castas[i] << " ";
    }
    cout << endl;
    cout << "Tipo de Refeição: ";
    for (size_t i = 0; i < tipo_refeicao.size(); i++) {
        cout << tipo_refeicao[i] << " ";
    }
    cout << endl;
}

