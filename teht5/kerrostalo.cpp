#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu" << endl;

    eka = new Katutaso();
    toka = new Kerros();
    kolmas = new Kerros();

    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;

    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
}

Kerrostalo::~Kerrostalo()
{
    delete eka;
    delete toka;
    delete kolmas;
}

double Kerrostalo::laskeKulutus(double hinta)
{
    double kokonaisKulutus = 0;
    kokonaisKulutus += eka->laskeKulutus(hinta);
    kokonaisKulutus += toka->laskeKulutus(hinta);
    kokonaisKulutus += kolmas->laskeKulutus(hinta);
    cout << "Kerrostalon kulutus = " << kokonaisKulutus << endl;
    return kokonaisKulutus;
}

