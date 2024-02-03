#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
uint16_t count;
void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.firstPage();
  do{
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(10,30,"Hello"); //numbers are the x and y coordinate
    u8g2.drawVLine(75, 00, 50); //draw a vertcal line starting at 75 across all the way at the top 50 units long
    u8g2.drawGlyph(80, 20, 51); //3
    u8g2.drawGlyph(90, 20, 46 ); //.
    u8g2.drawGlyph(93, 20, 49); //1
    u8g2.drawGlyph(100, 20, 52 );//4
    if(count<10){
    u8g2.drawGlyph(80, 35, count+48 );//4
    }
  }while(u8g2.nextPage());
  delay(1000);
  count++;
}
