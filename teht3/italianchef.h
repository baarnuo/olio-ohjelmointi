#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef: public Chef
{
public:
    ItalianChef(string name, int vesi, int jauhot);
    ~ItalianChef();
    string getName();
    void makePasta();

private:
    int vesi;
    int jauhot;
};

#endif // ITALIANCHEF_H
