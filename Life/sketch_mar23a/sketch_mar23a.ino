#include <SPI.h>
#include "SH1106_SPI.h"
#include "map.h"
#include <LiquidCrystal.h>
LiquidCrystal lq(26, 28, 29, 30, 31, 32);

SH1106_SPI_FB lcd;

int tab[66][130];
int tab2[66][130];

void setup(void)
{
  lcd.begin();
  lq.begin(16, 2);

  for(int i=0;i<66;i++)
    for(int j=0;j<130;j++){
      tab[i][j]=0;
      tab2[i][j]=0;
    }

      
  //  przypisz(width,height,header_data);
  //  wysw();
  //  lcd.renderAll();
  przypisz(width, height, header_data);
  wysw();
  lcd.renderAll();
}



void loop(void)
{


  
  delay(100);
  druga();
  logika();
  wysw();
  lcd.renderAll();

  

}


void wysw() {
  bool x;
  for (int i = 1; i<65; i++) {
    for (int j = 1;j<129;j++) {
      lcd.setPixel(j-1, i-1, tab[i][j]);
    }
  }
}

void przypisz(int wid, int hei, char bitmap[]) {
  for (int i = 0; i<64;i++) {
    for (int j = 0;j<128;j++) {
      if (bitmap[i*width + j] == 1)
        tab[i+1][j+1] = 1;
      else
        tab[i+1][j+1] = 0;
    }
  }
}

int ile(int x, int y) {
  int suma = 0;
  
  if (tab2[x - 1][y + 1] == 1)
    suma++;
  if (tab2[x][y + 1] == 1)
    suma++;
  if (tab2[x + 1][y + 1] == 1)
    suma++;
  if (tab2[x - 1][y] == 1)
    suma++;
  if (tab2[x + 1][y] == 1)
    suma++;
  if (tab2[x - 1][y - 1] == 1)
    suma++;
  if (tab2[x][y - 1] == 1)
    suma++;
  if (tab2[x + 1][y - 1] == 1)
    suma++;

  return suma;
}

void logika() {
  int x;
  for (int i = 1; i < 65; i++) {
    for (int j = 1; j < 129; j++) {
      x = ile(i, j);
//      lq.print(x);
//      delay(5000);
      if (tab2[i][j] == 0) {
        if (x == 3)
          tab[i][j] = 1;
      }
      else {
        if (x == 2 || x == 3)
          tab[i][j] = 1;
        else
          tab[i][j] = 0;
      }
    }
  }
}

void druga(){
  for(int i=1;i<65;i++)
    for(int j=1;j<129;j++)
      tab2[i][j]=tab[i][j];
}

