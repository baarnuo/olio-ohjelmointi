#ifndef KERROSTALO_H
#define KERROSTALO_H

#include "katutaso.h"

class Kerrostalo
{
public:
    Kerrostalo();
    ~Kerrostalo();
    double laskeKulutus(double hinta);

private:
    Katutaso* eka;
    Kerros* toka;
    Kerros* kolmas;
};

#endif // KERROSTALO_H
