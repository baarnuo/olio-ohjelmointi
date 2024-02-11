#include "devicemouse.h"

DeviceMouse::DeviceMouse():
    primaryButton(0)
{

}

void DeviceMouse::setPrimaryButton()
{
    while (true) {
        cin >> primaryButton;
        if (cin.fail()) {
            cout << "Invalid input. Primary button must be 1 or 2. Please enter a valid value: ";
            cin.clear();
            cin.ignore(256, '\n');
        } else if (primaryButton != 1 && primaryButton != 2) {
            cout << "Invalid input. Primary button must be 1 or 2. Please enter a valid value: ";
        } else {
            break;
        }
    }
}

short DeviceMouse::getPrimaryButton()
{
    return primaryButton;
}
