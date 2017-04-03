# Duckduino.ino generator
I got too lazy to type out `DigiKeyboard.sendKeyStroke()` constantly, so I created this generator

Convers `script.duckos` (Ducky On Steroids) to `duckduino.ino` for ease

# Commands available
`STRING <abc>` - Types text

`STRINGLN <abc>` - Types text and presses enter

`DELAY <x>` - Waits for x number of milli seconds

`REM <comments>` - Comments

You can also string multiple modifier keys (Up to 2)

`CTRL C`, `ALT F4` etc.

## List:
* `CTRL`
* `ALT`
* `SHIFT`
* `GUI`
* `UP`
* `DOWN`
* `LEFT`
* `RIGHT`
* `TAB`
* `DELETE`
* `SPACE`
* `ENTER`
* `F1 - F12`
