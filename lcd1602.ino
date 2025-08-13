void lcdStart() {
  lcd.begin();
  lcd.backlight();
}

void lc(String s, int b, int li) {
  lcd.setCursor(b, li);  // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print(s);
}

void offLcd(){
  lcd.clear();
  lcd.noBacklight();
}


// void lcd1602() {
//   delay(1000);
//   lcd("L To R");
//   ledRL(led, 'l', 1000, 3);
//   delay(1000);
//   lcd("R To L");
//   ledRL(led, 'r', 1000, 3);
//   ledAnalog();
// }

void welcome(){
  lc("Welcome", 5, 0);
  lc("My Project", 3, 1);
}