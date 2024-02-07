#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu" << endl;
    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
}

double Kerrostalo::laskeKulutus(double hinta)
{
    double kokonaisKulutus = 0;
    kokonaisKulutus += eka.laskeKulutus(hinta);
    kokonaisKulutus += toka.laskeKulutus(hinta);
    kokonaisKulutus += kolmas.laskeKulutus(hinta);
    cout << "Kerrostalon kulutus = " << kokonaisKulutus << endl;
    return kokonaisKulutus;
}

