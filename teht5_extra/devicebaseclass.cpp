#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass():
    deviceID(0)
{

}

void DeviceBaseClass::setDeviceID()
{
    while (true) {
        cin >> deviceID;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid device ID: ";
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            break;
        }
    }
}

short DeviceBaseClass::getDeviceID()
{
    return deviceID;
}
