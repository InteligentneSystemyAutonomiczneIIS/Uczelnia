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
#include <ISA7SegmentDisplay.h>
//*********************************************************   ZMIENNE GLOBALNE
ISALedControl matrix;
Buttons button;
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
ISA7SegmentDisplay seg;
//int timer=0;
bool gameOver = false;
int score = 0;
const int width = 8, height = 8;
int x, y, fruitX, fruitY;
int fX[100];
int fY[100];
enum direct {STOP = 0, LEFT, RIGHT, UP, DOWN};
direct dir;

bool dark = true;


//*********************************************************   SETUP
void setup() {
  randomSeed(analogRead(0));
  matrix.init();
  button.init();
  seg.init();
  lcd.begin(16, 2);
  pinMode(24, OUTPUT);
  for (int i = 2; i < 10; i++)
    pinMode(i, OUTPUT);

  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = 6;
  fruitY = 6;
  matrix.setLed(8 - y, x - 1, true);

  //*********************************************************   TEKST ROZPOCZYNAJĄCY
  txt(1);

  //*********************************************************   GRAAAAAAAA
  
  Timer5.attachInterrupt(input);
  Timer5.start(5);
  Timer4.attachInterrupt(movment);
  sSpeed();
  fruit();

  //*********************************************************   TEKST KOŃCZĄCY dodać do funkcji odpowiadającej za logikę (kolizję i śmierć)

}
//*********************************************************   LOOP
void loop() {
    
}

//*********************************************************   FUNKCJE

//*********************************************************   INPUT - PRZYCISKI
void input() {
  if ((button.buttonPressed(1) || analogRead(A10) > 900 )&& dir != DOWN) {
    dir = UP; Timer5.stop();
  }
  if ((button.buttonPressed(7) || analogRead(A11) < 100 )&& dir != RIGHT) {
    dir = LEFT; Timer5.stop();
  }
  if ((button.buttonPressed(5) || analogRead(A11) > 900) && dir != LEFT) {
    dir = RIGHT; Timer5.stop();
  }
  if ((button.buttonPressed(6) || analogRead(A10) < 100 )&& dir != UP) {
    dir = DOWN; Timer5.stop();
  }
  if (button.buttonPressed(0)) {
    dir = STOP; Timer5.stop();
  }
  digitalWrite(24, LOW);
}

//*********************************************************   RUCH GŁOWY
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

  tail();
  Timer5.start(5);
  sSpeed();
  fruit();

  if(dir!=STOP)
    txt(3);
  else
    txt(4);
    
    collision();
}

//*********************************************************   PRĘDKOŚĆ GRY
void sSpeed() {
  int value = analogRead(A9) / 128;
  //value++;
  Timer4.stop();

  for (int i = 2; i < 10; i++)
    digitalWrite(i, HIGH);

  for (int i = 8-value ; i >= 2; i--) 
    digitalWrite(i, LOW);
  

  Timer4.start((8-value) * 100000);
}

//********************************************************* GENEROWANIE OWOCA
void fruit(){
  dark = !dark;
  if(fruitX==x&&fruitY==y){
    score++;
    points(score);
    digitalWrite(24, HIGH);
        //////////////////////////////////dodać tutaj do-while X/y fruit będzie rózne od ogona
    do{
    fruitX = random(width)+1;
    fruitY = random(height)+1;
    }while(fruitCollision());
  }
  matrix.setLed(8 - fruitY, fruitX - 1, dark);
  
  
}

//********************************************************* TWORZENIE OGONU
void tail(){
  for(int i=score;i>0;i--){
    fX[i]=fX[i-1];
    fY[i]=fY[i-1];
  }
  
  fX[0]=x;
  fY[0]=y;
  for(int i=0;i<=score+1;i++){
    matrix.setLed(8-fY[i],fX[i]-1,true);
  }
}

//********************************************************* KOLIZJA OGONU
void collision(){
    for(int i=1;i<score+1;i++)
      if(fX[i]==x&&fY[i]==y)gameOver=true;

    if(gameOver==true){
      txt(2);
      Timer5.stop();
      Timer4.stop();
  }
}

//********************************************************* KOLIZJA OWOCU  ==================================== NIE DZIAŁA!!!!!!!!!!!!!!!!!

bool fruitCollision(){
  for(int i=1;i<score+1;i++)
    if(fX[i]==fruitX&&fY[i]==fruitY)return true;
  return false;  
}

//********************************************************* TEKSTY NA WYŚWIETLACZU 16x2
void txt(int tx){
  lcd.clear();
  switch(tx)
  {
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Rozpocznij gre");
      lcd.setCursor(0, 1);
      lcd.print("Wcisnij przycisk");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Przegrales stary");
      lcd.setCursor(0, 1);
      lcd.print("Wcisnij reset ;(");
      break;
    case 3:
      lcd.clear();
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("Kontynuuj gre");
      lcd.setCursor(0, 1);
      lcd.print("Wcisnij przycisk");
      break;
    default:
      lcd.clear();
      break;  
  }
}

//********************************************************* WYŚWIETLANIE PUNKTÓW
void points(int score){
  seg.displayDigit(score%10,0);
  seg.displayDigit(score/10,1);
}

