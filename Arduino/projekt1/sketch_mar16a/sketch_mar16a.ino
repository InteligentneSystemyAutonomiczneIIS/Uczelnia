#include <ISALedControl.h>
#include "Buttons.h"

ISALedControl matryca;
Buttons przycisk;

bool gameOver;
int wynik;
const int wys=8,szer=8;
int x,y,owocX,owocY;

int tabX[100];
int tabY[100]; 

enum kierunek {STOP=0,LEWO,PRAWO,GORA,DOL};
kierunek kier;


void setup() {
  randomSeed(analogRead(0));
  matryca.init();
  przycisk.init();
  
  gameOver = false;
  kier = STOP;
  x = szer / 2;
  y = wys / 2;

  owocX = random(szer);
  owocY = random(wys);
  wynik = 0;


}
int i=0;
void loop() {
  
  
  
  

  
  
  if(i%15==0){
    i=0;
    matryca.clearDisplay();
    matryca.setLed(8-y,x-1,true);
    logic();
  }
  input();
  i++;
  delay(25);   
}

void input(){
  if(przycisk.buttonPressed(1))
    kier=GORA;
  if(przycisk.buttonPressed(7))
    kier=LEWO;
  if(przycisk.buttonPressed(5))
    kier=PRAWO;
  if(przycisk.buttonPressed(9))
    kier=DOL;   
  if(przycisk.buttonPressed(6))
    kier=STOP;
}

void logic(){
  switch (kier)
  {
  case LEWO:
    x--;
    break;
  case PRAWO:
    x++;
    break;
  case GORA:
    y++;
    break;
  case DOL:
    y--;
    break;
  default:
    break;
  }
}

