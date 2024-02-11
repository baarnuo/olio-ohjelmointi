#include "devicedisplay.h"

DeviceDisplay::DeviceDisplay():
    displayResolution(0)
{

}

void DeviceDisplay::setDisplayResolution()
{
    while (true) {
        cin >> displayResolution;
        if (cin.fail()) {
            cout << "Invalid resolution. Resolution must be within 1-10. Please enter a valid resolution: ";
            cin.clear();
            cin.ignore(256, '\n');
        } else if (displayResolution < 1 || displayResolution > 10) {
            cout << "Invalid resolution. Resolution must be within 1-10. Please enter a valid resolution: ";
        } else {
            break;
        }
    }
}

short DeviceDisplay::getDisplayResolution()
{
    return displayResolution;
}
