/*
  This is an initial sketch to be used as a "blueprint" to create apps which can be used with IOTappstory.com infrastructure
  Your code can be filled wherever it is marked.

  Copyright (c) [2016] [Andreas Spiess]

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  virginSoilBasic V2.1.2
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WEMOS_SHT3X.h>

#define COMPDATE __DATE__ __TIME__
#define MODEBUTTON 0										// Button pin on the esp for selecting modes. D3 for the Wemos!

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

SHT3X sht30(0x45);

#include <IOTAppStory.h>								// IotAppStory.com library
IOTAppStory IAS(COMPDATE, MODEBUTTON);	// Initialize IotAppStory



// ================================================ SETUP ================================================
void setup() {
  /*
  IAS.onFirstBoot([]() {
    IAS.eraseEEPROM('P');                   // Optional! What to do with EEPROM on First boot of the app? 'F' Fully erase | 'P' Partial erase
  });
  */
  
  IAS.begin();                          // Run IOTAppStory
	

  //-------- Your Setup starts from here ---------------
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.display();
}



// ================================================ LOOP =================================================
void loop() {
  IAS.loop();   // this routine handles the calling home functionality,
                // reaction of the MODEBUTTON pin. If short press (<4 sec): update of sketch, long press (>7 sec): Configuration
                // reconnecting WiFi when the connection is lost,
                // and setting the internal clock (ESP8266 for BearSSL)


  //-------- Your Sketch starts from here ---------------
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);

  if(sht30.get()==0){
    display.println("T: ");
    display.setCursor(35,8);
    display.print("Temp:");
    display.setTextSize(1);
    display.println(sht30.cTemp);

    display.setTextSize(1);
    display.println("H:% ");
    display.setCursor(35,21);
    display.print("Hum:");
    display.setTextSize(1);
    display.println(sht30.humidity);
  }
  else
  {
    display.println("Error!");
  }
  display.display();
  delay(1000);

}
