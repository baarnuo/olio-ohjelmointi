#include "chef.h"
#include "italianchef.h"

int main()
{
    /* Chef chef("Gordon Ramsay");
    chef.makeSalad();
    chef.makeSoup();

    ItalianChef italianChef("Anthony Bourdain");
    italianChef.makeSalad();
    italianChef.makeSoup(); */

    /* Chef chef("Jyrki");
    ItalianChef italianChef("Mario");
    chef.makeSalad();
    italianChef.makePasta();
    chef.makeSoup(); */

    ItalianChef italianChef("Mario", 100, 250);
    italianChef.makePasta();

    return 0;
}
