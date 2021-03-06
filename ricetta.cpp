#include "ricetta.h"

Ricetta::Ricetta(const vector<Ingrediente> & v,string nome):VettoreGenerico(v),nomeRicetta(nome){}

void Ricetta::setNomeRicetta(string nome){
    nomeRicetta = nome;
}
string Ricetta::getNomeRicetta()const{
    return nomeRicetta;
}

Ricetta::Ricetta():nomeRicetta("Non definito"){}

string Ricetta::getRicetta()const{
    string s="Ricetta: "+nomeRicetta;
    for(unsigned int i = 0 ; i < getSize(); i++){
        s= s+"\n"+operator [](i).getDescrizione();
    }
    return s;
}

//guarda se gli ingredienti della seconda ricetta sono presenti nella prima. se si allora somma le quantita altrimenti la mette in append
Ricetta* Ricetta::operator+(const VettoreGenerico<Ingrediente>& vgr) const{

    Ricetta* aux= new Ricetta(*this);
    aux->setNomeRicetta("Somma");
    const Ricetta* r = dynamic_cast<const Ricetta*>(&vgr);
    if(r){
        bool presente = false;

        for(unsigned int i = 0 ; i < r->getSize(); i++){
            for(unsigned int  j = 0; j < aux->getSize();j++){
                if(aux->operator [](j)==r->operator [](i)){
                    presente = true;
                    aux->operator [](j) = aux->operator [](j)+r->operator [](i);
                }
            }
            if(!presente){
                aux->aggiungiElemento(r->operator [](i));

            }
            presente = false;
        }

    }


    return aux;

}

//confronta ingrediente per ingrediente le 2 ricette e diminuisce dal primo le quantita dei ingredienti del secondo
Ricetta* Ricetta::operator-(const VettoreGenerico<Ingrediente>& vgr) const{

    Ricetta* aux= new Ricetta(*this);
    aux->setNomeRicetta("Differenza");

    const Ricetta* r = dynamic_cast<const Ricetta*>(&vgr);
    if(r){


        for(unsigned int i = 0 ; i < r->getSize(); i++){
            for(unsigned int  j = 0; j < aux->getSize();j++){
                if(aux->operator [](j)==r->operator [](i)){
                    if(aux->operator [](j).getQuantita()- r->operator [](i).getQuantita() >0.0){

                        aux->operator [](j) = aux->operator [](j)-r->operator [](i);
                    }
                    else{

                        aux->rimuoviPoz(j);

                    }
                }
            }
        }

    }


    return aux;

}

bool Ricetta::operator ==(const VettoreGenerico<Ingrediente>& vgr)const{
    const Ricetta* r = dynamic_cast<const Ricetta*>(&vgr);
    if(r){
        bool uguali = true;
        for(unsigned int i = 0 ; i < getSize()&&uguali; i++){


            uguali = false;
            for(unsigned int j  =  0  ; j < r->getSize()&&!uguali; j++){
                if(operator [](i)==r->operator [](j))
                    uguali=true;

            }
        }
        return uguali;
    }
    return r!=0;
}
bool Ricetta::operator !=(const VettoreGenerico<Ingrediente>& vgr)const{

    return !(*this == vgr);
}


double Ricetta::calorieRicetta()const{
    double cal=0;

    for(unsigned int i = 0 ; i < getSize();i++){
        cal+= operator [](i).calorieTorali();
    }

    return cal;
}

double Ricetta::costoRicetta()const{
    double euro=0.0;

    for(unsigned int i = 0 ; i < getSize();i++){
        euro+= operator [](i).getCosto()*operator [](i).getQuantita() ;
    }

    return euro;
}
Ricetta Ricetta::operator*(int persone)const{
    Ricetta r;
    r.setNomeRicetta(nomeRicetta+" per "+std::to_string(persone)+" persone");
    for(unsigned int i = 0 ; i < getSize();i++){
        r.aggiungiElemento(Ingrediente(operator [](i).getNome(),operator [](i).getQuantita()* persone,operator [](i).getCalorie(),operator [](i).getCosto()));

    }
return r;
}
