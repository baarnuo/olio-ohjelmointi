#include "asunto.h"

Asunto::Asunto():
    asukasMaara(0),
    neliot(0)
{
    cout << "asunto luotu" << endl;
}

void Asunto::maarita(int asukasMaara, int neliot)
{
    this->asukasMaara = asukasMaara;
    this->neliot = neliot;
    cout << "Asunto maaritetty asukkaita= " << asukasMaara << " nelioita= " << neliot << endl;
}

double Asunto::laskeKulutus(double hinta)
{
    double kulutus = hinta * asukasMaara * neliot;
    //cout << "asunnon kulutus, kun hinta=" << hinta << " on " << kulutus << endl;
    return kulutus;
}
