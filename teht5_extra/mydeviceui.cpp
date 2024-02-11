#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI()
{
    objectDeviceMouse = new DeviceMouse();
    objectDeviceTouchPad = new DeviceTouchPad();
    objectDeviceDisplay = new DeviceDisplay();

    uiShowMenu();
}

MyDeviceUI::~MyDeviceUI()
{
    delete objectDeviceMouse;
    delete objectDeviceTouchPad;
    delete objectDeviceDisplay;
}

void MyDeviceUI::uiShowMenu()
{
    int userInput = 0;
    while (userInput != 5) {
        cout << "DEVICE MENU" << endl;
        cout << "===========" << endl;
        cout << "1: Set Mouse Information" << endl;
        cout << "2: Set Touch Pad Information" << endl;
        cout << "3: Set Display Information" << endl;
        cout << "4: Show Devices Information" << endl;
        cout << "5: Finish" << endl;
        cout << endl;
        cout << "Choose: ";
        cin >> userInput;
        cout << endl;
        if (userInput == 1) {
            uiSetMouseInformation();
        } else if (userInput == 2) {
            uiSetTouchPadInformation();
        } else if (userInput == 3) {
            uiSetDisplayInformation();
        } else if (userInput == 4) {
            uiShowDeviceInformation();
        }
    }
}

void MyDeviceUI::uiSetMouseInformation()
{
    cout << "SET MOUSE INFORMATION" << endl;
    cout << "=====================" << endl;
    cout << "Set Mouse Device ID: ";
    objectDeviceMouse->setDeviceID();
    cout << "Set Mouse Primary Button: ";
    objectDeviceMouse->setPrimaryButton();
    cout << endl;
}

void MyDeviceUI::uiSetTouchPadInformation()
{
    cout << "SET TOUCH PAD INFORMATION" << endl;
    cout << "=========================" << endl;
    cout << "Set Touch Pad Device ID: ";
    objectDeviceTouchPad->setDeviceID();
    cout << "Set Touch Pad Sensitivity: ";
    objectDeviceTouchPad->setTouchPadSensitivity();
    cout << endl;
}

void MyDeviceUI::uiSetDisplayInformation()
{
    cout << "SET DISPLAY INFORMATION" << endl;
    cout << "=======================" << endl;
    cout << "Set Display Device ID: ";
    objectDeviceDisplay->setDeviceID();
    cout << "Set Display Resolution: ";
    objectDeviceDisplay->setDisplayResolution();
    cout << endl;
}

void MyDeviceUI::uiShowDeviceInformation()
{
    cout << "SHOW DEVICES INFORMATION" << endl;
    cout << "========================" << endl;
    cout << "Mouse Device ID: " << objectDeviceMouse->getDeviceID() << endl;
    cout << "Mouse Primary Button: " << objectDeviceMouse->getPrimaryButton() << endl;
    cout << "Touch Pad Device ID: " << objectDeviceTouchPad->getDeviceID() << endl;
    cout << "Touch Pad Sensitivity: " << objectDeviceTouchPad->getTouchPadSensitivity() << endl;
    cout << "Display Device ID: " << objectDeviceDisplay->getDeviceID() << endl;
    cout << "Display Resolution: " << objectDeviceDisplay->getDisplayResolution() << endl;
    cout << endl;
}
