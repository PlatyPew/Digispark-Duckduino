#!/usr/bin/python
import sys

if len(sys.argv) != 3:
	print 'Usage: python digispark-gen.py <duckos> <ino>'
	sys.exit()

print 'Author: PlatyPew'
dic = {'A':4, 'B':5, 'C':6, 'D':7, 'E':8, 'F':9, 'G':10, 'H':11, 'I':12, 'J':13, 'K':14, 'L':15, 'M':16, 'N':17, 'O':18, 'P':19, 'Q':20, 'R':21, 'S':22, 'T':23, 'U':24, 'V':25, 'W':26, 'X':27, 'Y':28, 'Z':29, '1':30, '2':31, '3':32, '4':33, '5':34, '6':35, '7':36, '8':37, '9':38, '0':39, 'F1':58, 'F2':59, 'F3':60, 'F4':61, 'F5':62, 'F6':63, 'F7':64, 'F8':65, 'F9':66, 'F10':67, 'F11':68, 'F12':69, 'CTRL': 'MOD_CONTROL_LEFT', 'SHIFT':'MOD_SHIFT_LEFT', 'ALT':'MOD_ALT_LEFT', 'GUI':'MOD_GUI_LEFT', 'TAB':43,'DELETE':42, 'UP':82, 'DOWN':81, 'LEFT':80, 'RIGHT':79}

f = open(sys.argv[2],'w')
p = open(sys.argv[1],'r')

f.write('#include\"DigiKeyboard.h\"\n#include <avr/pgmspace.h>\n\n')

i = 0
while True:
	code = p.readline().replace("\\","\\\\")
	code = code.replace('"','\\"')
	if 'STRING ' in code:
		i += 1
		f.write('const char line%d[] PROGMEM = \"%s\";\n' % (i, code[7:-1]))
	elif 'STRINGLN ' in code:
		i += 1
		f.write('const char line%d[] PROGMEM = \"%s\\n\";\n' % (i, code[9:-1]))
	elif code == '':
		break
f.write('char buffer[100];\n#define GetPsz(x) (strcpy_P(buffer,(char*)x))\n\n')

f.write('void printText(char*txt) {\n\tint l = strlen(txt);\n\tfor (int i = 0; i < l; i++) {\n\t\tDigiKeyboard.print(txt[i]);\n\t\tDigiKeyboard.update();\n\t}\n}\n')

f.write('void setup() {\n')

p.seek(0)
i = 0
while True:
	code = p.readline()
	if 'STRING ' in code:
		i += 1
		f.write('\tprintText(GetPsz(line%d));\n' % (i))
	elif 'STRINGLN ' in code:
		i += 1
		f.write('\tprintText(GetPsz(line%d));\n' % (i))
	elif 'DELAY ' in code:
		f.write('\tDigiKeyboard.delay(%s);\n' % (code[6:-1]))
	elif 'REM ' in code:
		f.write('\t//%s\n' % (code[4:-1]))
	elif 'CTRL' in code:
		if code[5:-1] == '':
			f.write('\tDigiKeyboard.sendKeyStroke(0,MOD_CONTROL_LEFT);\n')
		else:
			f.write('\tDigiKeyboard.sendKeyStroke(%s,MOD_CONTROL_LEFT);\n' % (dic[code[5:-1]]))
	elif 'ALT' in code:
		if code[4:-1] == '':
			f.write('\tDigiKeyboard.sendKeyStroke(0,MOD_ALT_LEFT);\n')
		else:
			f.write('\tDigiKeyboard.sendKeyStroke(%s,MOD_ALT_LEFT);\n' % (dic[code[4:-1]]))
	elif 'SHIFT' in code:
		if code[6:-1] == '':
			f.write('\tDigiKeyboard.sendKeyStroke(0,MOD_SHIFT_LEFT);\n')
		else:
			f.write('\tDigiKeyboard.sendKeyStroke(%s,MOD_SHIFT_LEFT);\n' % (dic[code[6:-1]]))
	elif 'GUI' in code:
		if code[4:-1] == '':
			f.write('\tDigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);\n')
		else:
			f.write('\tDigiKeyboard.sendKeyStroke(%s,MOD_GUI_LEFT);\n' % (dic[code[4:-1]]))
	elif 'UP' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,82);\n')
	elif 'DOWN' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,81);\n')
	elif 'LEFT' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,80);\n')
	elif 'RIGHT' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,79);\n')
	elif 'TAB' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,43);\n')
	elif 'DELETE' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,42);\n')
	elif 'SPACE' in code:
		f.write('\tDigiKeyboard.print(\" \")')
	elif 'ENTER' in code:
		f.write('\tDigiKeyboard.println(\"\");\n')
	elif 'F1' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,58);\n')
	elif 'F2' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,59);\n')
	elif 'F3' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,60);\n')
	elif 'F4' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,61);\n')
	elif 'F5' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,62);\n')
	elif 'F6' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,63);\n')
	elif 'F7' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,64);\n')
	elif 'F8' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,65);\n')
	elif 'F9' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,66);\n')
	elif 'F10' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,67);\n')
	elif 'F11' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,68);\n')
	elif 'F12' in code:
		f.write('\tDigiKeyboard.sendKeyStroke(0,69);\n')
	elif code == '':
		break
f.write('}\n\nvoid loop() {\n}\n')

f.close()
p.close()
print 'Saved as \'{}\''.format(sys.argv[2])
