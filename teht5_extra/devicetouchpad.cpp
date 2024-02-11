#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad():
    touchPadSensitivity(0)
{

}

void DeviceTouchPad::setTouchPadSensitivity()
{
    while (true) {
        cin >> touchPadSensitivity;
        if (cin.fail()) {
            cout << "Invalid input. Touch pad sensitivity must be within 1-5. Please enter a valid sensitivity: ";
            cin.clear();
            cin.ignore(256, '\n');
        } else if (touchPadSensitivity < 1 || touchPadSensitivity > 5) {
            cout << "Invalid input. Touch pad sensitivity must be within 1-5. Please enter a valid sensitivity: ";
        } else {
            break;
        }
    }
}

short DeviceTouchPad::getTouchPadSensitivity()
{
    return touchPadSensitivity;
}
