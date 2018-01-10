# Duckduino.ino generator
I got too lazy to type out `DigiKeyboard.sendKeyStroke()` constantly, so I created this generator.

Converts `script.duckos` (Ducky On Steroids) to `duckduino.ino` for ease.

# Commands available
`STRING <abc>` - Types text.

`STRINGLN <abc>` - Types text and presses enter.

`DELAY <x>` - Waits for x number of milli seconds.

`REM <comments>` - Comments.

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

# Usage
`python digispark-gen.py <inputfile.duckos> <outputfile.ino>`

I did not put any error catching code so.... if the program fails, oh well.

# Notice
String must not be more than 99 characters long. Don't blame me, Digispark only has 512 puny bytes of memory. Be thankful that it is loaded to RAM only when required to. (You can always change the buffer size: https://github.com/PlatyPooper/Duckduino-Digispark/blob/master/generator/digispark-gen.py#L22)

Also, all characters you use needs to be capitalised.

Lastly, don't expect to be storing huge amounts of text with 3kb.
