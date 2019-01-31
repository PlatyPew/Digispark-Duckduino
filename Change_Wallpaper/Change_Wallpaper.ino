#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(67,KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("mode con: cols=16 lines=1&color FE");
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd Desktop&powershell (wget '<your_image_url>' -outfile s0m3fi13n4m3.jpg)"); //Add image
  DigiKeyboard.delay(8000); //Waits for image to download
  DigiKeyboard.sendKeyStroke(7,MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.print("s0m3fi13n4m3");
  DigiKeyboard.sendKeyStroke(67,MOD_SHIFT_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("b");
  DigiKeyboard.sendKeyStroke(43,MOD_ALT_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("del s0m3fi13n4m3.jpg&exit");
}

void loop() {

}
