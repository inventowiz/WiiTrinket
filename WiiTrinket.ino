#include <WiiChuck.h>
#include <Keyboard.h>
#include <Adafruit_DotStar.h>

Accessory nc; 
Adafruit_DotStar ds(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);
uint8_t r,g,b;

void setup() {
  Serial.begin(115200);
  nc.begin();
    // TODO print detected type
  Keyboard.begin();
  ds.begin(); 
  ds.setBrightness(80);
  r=0; g=0; b=0;
  ds.show();
}

void loop() {
  r=0; g=0; b=0;
  
  Serial.println("-------------------------------------------");
  nc.readData();    // Read inputs and update maps
  nc.printInputs(); // Print all inputs

  //nc.getStickXGuitar();
  //nc.getStickYGuitar();
  //nc.getWhammyBar();

  if(nc.getPlusButtonGuitar()){
    Keyboard.press('+');
    r+=255; g+=0; b+=255;
  }else {
    Keyboard.release('+');
  }
  if(nc.getMinusButtonGuitar()){
    Keyboard.press('-');
    r+=0; g+=255; b+=255;
  }else {
    Keyboard.release('-');
  }
  if(nc.getGreenButton()){
    Keyboard.press('q');
    r+=0; g+=255; b+=0;
  }else {
    Keyboard.release('q');
  }
  if(nc.getRedButton()){
    Keyboard.press('w');
    r+=255; g+=0; b+=0;
  }else {
    Keyboard.release('w');
  }
  if(nc.getYellowButton()){
    Keyboard.press('e');
    r+=255; g+=255; b+=0;
  }else {
    Keyboard.release('e');
  }
  if(nc.getBlueButton()){
    Keyboard.press('r');
    r+=0; g+=0; b+=255;
  }else {
    Keyboard.release('r');
  }
  if(nc.getOrangeButton()){
    Keyboard.press('t');
    r+=255; g+=165; b+=0;
  }else {
    Keyboard.release('t');
  }
  if(nc.getStrumUp()){
    Keyboard.press(KEY_DOWN_ARROW);
    r+=255; g+=255; b+=255;
  }else {
    Keyboard.release(KEY_DOWN_ARROW);
  }
  if(nc.getStrumDown()){
    Keyboard.press(KEY_UP_ARROW);
    r+=128; g+=128; b+=128;
  }else {
    Keyboard.release(KEY_UP_ARROW);
  }

  ds.setPixelColor(0,r,g,b);
  ds.show();
}
