//*********************************************************   PLANY
//#: kolizja węża z ogonem
//#: wąż przenika przez ściany
//#: sterowanie joystickiem prawym oraz przyciskami strzałem (tymczasowo przyciskami 8,4,5,6)
//#: wynik na wyświetlaczu 7-segmentowym
//#: prędkość węża sterowana potencjometrem oraz pokazywana na diodach led
//#: dźwięk przy zjedzeniu, oraz przy śmierci
//#: komunikat o rozpoczęciu gry, oraz o śmierci na wyświetlaczu LCD
//#: jedzenie ma ciemniejszy odcień
//#:
//*********************************************************   PLANY



//*********************************************************   BIBLIOTEKI
#include <ISALedControl.h>
#include "Buttons.h"
#include <LiquidCrystal.h>
#include <DueTimer.h>
//*********************************************************   ZMIENNE GLOBALNE
ISALedControl matrix;
Buttons button;
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
//int timer=0;
bool gameOver = false;
int score = 0;
const int width = 8, height = 8;
int x, y, fruitX, fruitY;
int fX[100];
int fY[100];
enum direct {STOP = 0, LEFT, RIGHT, UP, DOWN};
direct dir;

//*********************************************************   SETUP
void setup() {
  randomSeed(analogRead(0));
  matrix.init();
  button.init();
  lcd.begin(16, 2);
  for (int i = 2; i < 10; i++)
    pinMode(i, OUTPUT);

  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = 6;
  fruitY = 6;
  matrix.setLed(8 - y, x - 1, true);

  //*********************************************************   TEKST ROZPOCZYNAJĄCY
  lcd.print("Rozpocznij gre");
  lcd.setCursor(0, 1);
  lcd.print("Wcisnij przycisk");

  //*********************************************************   GRAAAAAAAA
  
  Timer5.attachInterrupt(input);
  Timer5.start(5);
  Timer4.attachInterrupt(movment);
  sSpeed();
  //Timer6.attachInterrupt(sSpeed);
  //Timer6.start(3000000);
  

  //*********************************************************   TEKST KOŃCZĄCY
  if (gameOver) {
    lcd.setCursor(0, 0);
    lcd.print("Przegrales stary");
    lcd.setCursor(0, 1);
    lcd.print("Wcisnij reset");
  }
}
//*********************************************************   LOOP
void loop() { }

//*********************************************************   FUNKCJE

void input() {
  if (button.buttonPressed(1) && dir != DOWN) {
    dir = UP; Timer5.stop();
  }
  if (button.buttonPressed(7) && dir != RIGHT) {
    dir = LEFT; Timer5.stop();
  }
  if (button.buttonPressed(5) && dir != LEFT) {
    dir = RIGHT; Timer5.stop();
  }
  if (button.buttonPressed(6) && dir != UP) {
    dir = DOWN; Timer5.stop();
  }
  if (button.buttonPressed(0)) {
    dir = STOP; Timer5.stop();/*Timer4.stop();*/
  }
}

void movment() {
  matrix.clearDisplay();
  switch (dir)
  {
    case LEFT:
      x--;
      if (x < 1)x = 8;
      break;
    case RIGHT:
      x++;
      if (x > 8)x = 1;
      break;
    case UP:
      y++;
      if (y > 8)y = 1;
      break;
    case DOWN:
      y--;
      if (y < 1)y = 8;
      break;
    default:
      break;
  }
  matrix.setLed(8 - y, x - 1, true);
  Timer5.start(5);
  sSpeed();
}

void sSpeed() { //500000
  int value = analogRead(A9) / 128;
  //value++;
  Timer4.stop();

  for (int i = 2; i < 10; i++)
    digitalWrite(i, HIGH);

  for (int i = 8-value ; i >= 2; i--) 
    digitalWrite(i, LOW);
  

  Timer4.start((8-value) * 100000);
}

