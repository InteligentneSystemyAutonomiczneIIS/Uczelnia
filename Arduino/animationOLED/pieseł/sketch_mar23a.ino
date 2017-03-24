#include <SPI.h>
#include "SH1106_SPI.h"

#include "dog/f0.h"
#include "dog/f1.h"
#include "dog/f2.h"
#include "dog/f3.h"
#include "dog/f4.h"
#include "dog/f5.h"
#include "dog/f6.h"

//#define f(i) fi

SH1106_SPI_FB lcd;

int frames;
int frequency;



void setup(void)
{
  lcd.begin();
  frames=7;
  frequency=100;

}



void loop(void) 
{

  
  bitmapa(f0::width,f0::height,f0::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f1::width,f1::height,f1::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f2::width,f2::height,f2::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f3::width,f3::height,f3::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f4::width,f4::height,f4::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f5::width,f5::height,f5::header_data);
  lcd.renderAll();
  delay(100);

  bitmapa(f6::width,f6::height,f6::header_data);
  lcd.renderAll();
  delay(100);

}


void bitmapa(int wid, int hei, char bitmap[]){
  for(int i=hei;i>0;i--){
    for(int j=wid;j>0;j--){
      lcd.setPixel(j,i,bitmap[(i - 1)*wid + (j - 1)]);
    }
  }
}



