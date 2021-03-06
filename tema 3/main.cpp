#include <iostream>
#include <vector>
#include "persoana.h"
#include "film.h"
#include "regizor.h"
#include "actor.h"
#include "actor_principal.h"
#include "tehnic.h"
#include "contracte.h"
#include "firma_distributie.h"
#include "firma_distributie_spec.h"
#include <fstream>


template <class t>
int firma_distributie<t> :: nr_persoane = 0;

template <class t>
int firma_distributie<t> :: nr_actori = 0;

int firma_distributie<actor_principal> :: nr_persoane = 0;

int firma_distributie<actor_principal> :: nr_actori = 0;

int firma_distributie<actor_principal> :: nr_actori_princ = 0;


std :: ifstream fin("fisier.in");
std :: ofstream fout ("fisier.out");

int main() {

    std :: vector <persoana*> persoane;

//    std :: cout << sizeof(film*);
    int n = 0, tip = 0;
    fin >> n;
    persoana *a = nullptr;
    for (int j = 0; j < n; ++j) {
        fin >> tip;
        if (tip == 0) {
            a = new persoana();
            fin >> *a;
            persoane.push_back(a);
        } else if (tip == 1) {
            a = new regizor();
            fin >> *a;
            persoane.push_back(a);
        } else if (tip == 2) {
            a = new actor();
            fin >> *a;
            persoane.push_back(a);
        } else if (tip == 3) {
            a = new actor_principal();
            fin >> *a;
            persoane.push_back(a);
//            std :: cout << *a;
        } else if (tip == 4) {
            a = new tehnic();
            fin >> *a;
            persoane.push_back(a);
        }
    }

//    persoana *p = new actor_principal("0045", "nu", "este", 10, 120000);
//    std :: cout << dynamic_cast<actor_principal*>(p)->getSumaPlusBonus() << "\n";

//    fout << "Afisare persoane din primul vector de persoane :D\n";
//    int i = 1;
//    for ( auto &persoana: persoane) {
////        std :: cout << typeid(*persoana).name() << " ";
//        fout << i << ") " << *persoana << '\n';
////        std :: cout << persoana->getNumeFilm() << " ";
//        i++;
//    }
//    fout << "Sfarsit persoane. ;) am vrut doar sa verific fuctiile virtuale de afisare.\n\n\n";


    std :: vector <film*> filme;
    // am vrut sa fac fara pointer dar mi se oprea .exe si am incercat asa si a mers si am lasat asa :((

    int m = 0; std :: string numefilm;
    int timp = 0; std :: string gen;
    fin >> m;
    film *f = nullptr;
    for (int i = 0; i < m; ++i) {
        fin >> numefilm >> timp >> gen;
        f = new film(persoane, numefilm, timp, gen);
        filme.push_back(f);
    }

    for (auto &film :filme) {
        fout << *film;
    }
    fout << '\n';
    // deci ce-am facut, practic in vectorul de persoane am pus toate persoanele existente si in
    // fiecare film au ramas doar cele care lucreaza la filmul respectiv :D


    contracte h;
    for (auto &i : persoane) {
        h.insert(i, 2500); // suma standard pentru toate tipurile de persoane
    }
    fout << h;

    // ! un film poate apartine unei singure firme
    firma_distributie<> F0;
    F0.insert(filme[0]);
    F0.insert(filme[2]);
    std :: cout << "Echipa firmei de distributie F0 are in componenta " << firma_distributie<>::getNrPersoane() << " persoane.\n";
    std :: cout << "Echipa firmei de distributie F0 are " << firma_distributie<> :: getNrActori() << " actori.\n";

    firma_distributie<actor_principal> F;
    F.insert(filme[1]);
    std :: cout << "Echipa firmei de distributie F are in componenta " << firma_distributie<actor_principal>::getNrPersoane()  << " persoane.\n";
    std :: cout << "Echipa firmei de distributie F are " <<  firma_distributie<actor_principal>::getNrActori() << " actori.\n";
    std :: cout << "Echipa firmei de distributie F are " << firma_distributie<actor_principal>::getNrActoriPrinc() << " actori principali.\n";

    // TODO: copy constr si "=" la toate clasele
    return 0;
}
