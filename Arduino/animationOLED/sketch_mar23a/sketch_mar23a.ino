#include <SPI.h>
#include "SH1106_SPI.h"

#include "obraz.h"
#include "obraz2.h"

#include "dog/f0.h"
#include "dog/f1.h"
#include "dog/f2.h"
#include "dog/f3.h"
#include "dog/f4.h"
#include "dog/f5.h"
#include "dog/f6.h"

//#include "gear/gear0.h"
#include "gear/gear1.h"
//#include "gear/gear2.h"
#include "gear/gear3.h"
//#include "gear/gear4.h"
#include "gear/gear5.h"



SH1106_SPI_FB lcd;





void setup(void)
{
  lcd.begin();

}



void loop(void) 
{
  
  for(int i=0;i<5;i++){
    
//  bitmapa(g0::width,g0::height,g0::header_data);
//  lcd.renderAll();
//  delay(100);

  bitmapa(g1::width,g1::height,g1::header_data);
  lcd.renderAll();
  delay(100);

//  bitmapa(g2::width,g2::height,g2::header_data);
//  lcd.renderAll();
//  delay(100);

  bitmapa(g3::width,g3::height,g3::header_data);
  lcd.renderAll();
  delay(100);

//  bitmapa(g4::width,g4::height,g4::header_data);
//  lcd.renderAll();
//  delay(100);

//  bitmapa(g5::width,g5::height,g5::header_data);
//  lcd.renderAll();
//  delay(100);
  }
  
  for(int i=0;i<5;i++){
  
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

//  for(int i=0;i<20;i++){
//  bitmapa(obraz::width,obraz::height,obraz::header_data);
//  lcd.renderAll();
//  delay(100);
//  }
  
//  for(int i=0;i<20;i++){
//  bitmapa(obraz2::width,obraz2::height,obraz2::header_data);
//  lcd.renderAll();
//  delay(100);
//  }

  bitmapa(obraz::width,obraz::height,obraz::header_data);
  lcd.renderAll();
  delay(5000);

  bitmapa(obraz2::width,obraz2::height,obraz2::header_data);
  lcd.renderAll();
  delay(5000);
}


void bitmapa(int wid, int hei, char bitmap[]){
  for(int i=hei;i>0;i--){
    for(int j=wid;j>0;j--){
      lcd.setPixel(j,i,bitmap[(i - 1)*wid + (j - 1)]);
    }
  }
}



