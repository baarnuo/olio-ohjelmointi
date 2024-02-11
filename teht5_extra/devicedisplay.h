#ifndef DEVICEDISPLAY_H
#define DEVICEDISPLAY_H

#include <iostream>

#include "devicebaseclass.h"

using namespace std;

class DeviceDisplay: public DeviceBaseClass
{
public:
    DeviceDisplay();

    void setDisplayResolution();
    short getDisplayResolution();

private:
    short displayResolution;
};

#endif // DEVICEDISPLAY_H
