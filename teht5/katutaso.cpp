#include "katutaso.h"

Katutaso::Katutaso()
{
    cout << "Katutaso luotu" << endl;

    as1 = new Asunto();
    as2 = new Asunto();
}

Katutaso::~Katutaso()
{
    delete as1;
    delete as2;
}

void Katutaso::maaritaAsunnot()
{
    cout << "Maaritetaan 2 kpl katutason asuntoja" << endl;
    as1->maarita(2, 100);
    as2->maarita(2, 100);
    cout << "Maaritetaan katutason kerrokselta perittyja asuntoja" << endl;
    Kerros::maaritaAsunnot();
}

double Katutaso::laskeKulutus(double hinta)
{
    double kokonaisKulutus = 0;
    kokonaisKulutus += as1->laskeKulutus(hinta);
    kokonaisKulutus += as2->laskeKulutus(hinta);
    kokonaisKulutus += Kerros::laskeKulutus(hinta);
    return kokonaisKulutus;
}
