Function Set-WallPaper($Value){
	Set-ItemProperty -path 'HKCU:\Control Panel\Desktop\' -name wallpaper -value $value;rundll32.exe user32.dll, UpdatePerUserSystemParameters 1 ,True
}
$a = Get-Random -min 1 -max 5
$set = "Set-WallPaper - value Wallpaper" + $a + ".jpg"
iex $set
