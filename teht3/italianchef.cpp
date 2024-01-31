#include "italianchef.h"

ItalianChef::ItalianChef(string name, int vesi, int jauhot):
    Chef(name),
    vesi(vesi),
    jauhot(jauhot)
{
    cout << "Chef " << name << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{

}

string ItalianChef::getName()
{
    return name;
}

void ItalianChef::makePasta()
{
    cout << "Chef " << name << " makes pasta with special recipe" << endl;
    cout << "Chef " << name << " users jauhot = " << jauhot << endl;
    cout << "Chef " << name << " users vesi = " << vesi << endl;
}
