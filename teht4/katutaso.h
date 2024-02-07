#ifndef KATUTASO_H
#define KATUTASO_H

#include "asunto.h"
#include "kerros.h"
#include <iostream>

using namespace std;

class Katutaso: public Kerros
{
public:
    Katutaso();

    void maaritaAsunnot() override;
    double laskeKulutus(double);

private:
    Asunto as1;
    Asunto as2;
};

#endif // KATUTASO_H
