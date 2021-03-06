#ifndef ESAME_H
#define ESAME_H

#include <string>
#include "data.h"

using std::string;
using std::to_string;

class Esame{
private:
    unsigned int CFU;
    unsigned int voto;//rappresenta il voto relativo all'esame
    string nomeMateria;
    string nomeCorso;
    string nomeProfessore;
    Data data;

public:
    Esame(string nomeM="Nome materia",string nomeC="Nome corso",string nomeP="Nome professore",unsigned int c=1,unsigned int v=18);
    Esame(string nomeM,string nomeC,string nomeP, const Data&,unsigned int c=1,unsigned int v=18);
    string getNomeCorso() const;
    string getNomeMateria() const;
    string getNomeProfessore() const;
    unsigned int getVoto() const;
    unsigned int getCFU() const;
    Data getData() const;
    void setNomeCorso(string);
    void setNomeMateria(string);
    void setNomeProfessore(string);
    void setVoto(int);
    void setData(const Data&);
    bool operator ==(const Esame&) const;
    bool operator !=(const Esame&) const;
    string getRappresentazioneStringa() const;
};

#endif // ESAME_H
