#include <SPI.h>
#include "SH1106_SPI.h"
#include "obraz2.h"

SH1106_SPI_FB lcd;





void setup(void)
{
  lcd.begin();
  
  bitmapa();

  lcd.renderAll();
}



void loop(void) 
{
  
}


void bitmapa(){
  for(int i=height;i>0;i--){
    for(int j=width;j>0;j--){
      lcd.setPixel(j,i,header_data[(i - 1)*width + (j - 1)]);
    }
  }
}

