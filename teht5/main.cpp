#include "kerrostalo.h"
#include <iostream>

using namespace std;

int main()
{
    Kerrostalo* kerrostalo = new Kerrostalo();
    kerrostalo->laskeKulutus(1);

    delete kerrostalo;

    return 0;
}
