#include "kerros.h"

Kerros::Kerros()
{
    cout << "Kerros luotu" << endl;
}

void Kerros::maaritaAsunnot()
{
    cout << "Maaritetaan 4 kpl kerroksen asuntoja" << endl;
    as1.maarita(2, 100);
    as2.maarita(2, 100);
    as3.maarita(2, 100);
    as4.maarita(2, 100);
}

double Kerros::laskeKulutus(double hinta)
{
    double kokonaisKulutus = 0;
    kokonaisKulutus += as1.laskeKulutus(hinta);
    kokonaisKulutus += as2.laskeKulutus(hinta);
    kokonaisKulutus += as3.laskeKulutus(hinta);
    kokonaisKulutus += as4.laskeKulutus(hinta);
    return kokonaisKulutus;
}
