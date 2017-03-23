#include <ISALedControl.h>
#include "Buttons.h"
#include "ISA7SegmentDisplay.h"
#include <LiquidCrystal.h>
#include <DueTimer.h>
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
ISA7SegmentDisplay wysw;
//////////////////////////////////////////////////USTAWIENIA
ISALedControl matryca;
Buttons przycisk;
int licznik_czasu=0;

///////////////////////////////////////////////// ELEMENTY GRY
bool gameOver;                                    ///
int wynik;                                        ///
const int wys=8,szer=8;                           ///
int x,y,owocX,owocY;                              ///
                                                  ///
int oX[100];                                    ///
int oY[100];                                    ///
                                                  ///


enum kierunek {STOP=0,LEWO,PRAWO,GORA,DOL};
kierunek kier;

//////////////////////////////////////////////// ELEMENTY GRY


//////////////////////////////////////////////// FUNKCJE URUCHAMIANE NA POCZĄTKU
void setup() {
  ///////////////////////////////////////////////USTAWIENIA URZĄDZEŃ
  randomSeed(analogRead(0));
  matryca.init();
  przycisk.init();
  wysw.init();
  ///////////////////////////////////////////////USTAWIENIA GRY
  gameOver = false;
  kier = STOP;
  x = szer / 2;
  y = wys / 2;
  owocX = random(szer)+1;
  owocY = random(wys)+1;
  wynik = 0;
  

}
//////////////////////////////////////// GRA GRA GRA GRA GRA
void loop() {
  if(licznik_czasu%4==0)
    input();
  
  if(licznik_czasu%75==0){
    //delay(20);
    licznik_czasu=0;
    matryca.clearDisplay();
    wysw.displayDigit(wynik,0);
    //matryca.setLed(8-y,x-1,true);   
    logic(); 
    dlugiOgon();
    owoc();  
    ogon();
    
  }

  licznik_czasu++;
  delay(5);   
}

void input(){ /////////////////// ZMIANA KIERUNKU
  if(przycisk.buttonPressed(1)&&kier!=DOL)
    kier=GORA;
  if(przycisk.buttonPressed(7)&&kier!=PRAWO)
    kier=LEWO;
  if(przycisk.buttonPressed(5)&&kier!=LEWO)
    kier=PRAWO;
  if(przycisk.buttonPressed(9)&&kier!=GORA)
    kier=DOL;   
  if(przycisk.buttonPressed(6))
    kier=STOP;
}

void logic(){//////////////////// RUCH GŁOWY
  switch (kier)
  {
  case LEWO:    
    x--;
    if(x<1)x=8;
    break;
  case PRAWO:    
    x++;
    if(x>8)x=1;
    break;
  case GORA:    
    y++;
    if(y>8)y=1;
    break;
  case DOL:    
    y--;
    if(y<1)y=8;
    break;
  default:
    break;
  }

}

void owoc(){//////////////////////////// DZIAŁANIE JEDZENIA
  if(owocX==x&&owocY==y){
    wynik++;
    
    
    owocX = random(szer)+1;
    owocY = random(wys)+1;
  }
  
  matryca.setLed(8-owocY,owocX-1,true);
}

void ogon(){//////////////////////////// DZIAŁANIE OGONA? ALBO OGONU? NIE WIEM. TO NIE MA SENSU. I TAK NIKT TEGO NIE PRZECZYTA.
  for(int i=0;i<=wynik+1;i++){
    matryca.setLed(8-oY[i],oX[i]-1,true);
  }
}

void dlugiOgon(){
    for(int i=wynik;i>0;i--){
    oX[i]=oX[i-1];
    oY[i]=oY[i-1];

    
  }
  oX[0]=x;
  oY[0]=y;
}

