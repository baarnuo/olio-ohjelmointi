#ifndef MYDEVICEUI_H
#define MYDEVICEUI_H

#include <iostream>

#include "devicemouse.h"
#include "devicetouchpad.h"
#include "devicedisplay.h"

using namespace std;

class MyDeviceUI
{
public:
    MyDeviceUI();
    ~MyDeviceUI();

    void uiShowMenu();
    void uiSetMouseInformation();
    void uiSetTouchPadInformation();
    void uiSetDisplayInformation();
    void uiShowDeviceInformation();

private:
    DeviceMouse* objectDeviceMouse;
    DeviceTouchPad* objectDeviceTouchPad;
    DeviceDisplay* objectDeviceDisplay;
};

#endif // MYDEVICEUI_H
