#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// OLED I2C address
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
void setup() {
// write your initialization code here
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("OLED not found"));
        while(true);
    }
    //clear display
    display.clearDisplay();

    //Set text properties
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    //Display text
    display.setCursor(0, 0);
    display.println("Hello, World!");
    display.println("How are you guys");
    display.println("Arduino UNO R4");

    //display on Screen
    display.display();
}

void loop() {
// write your code here
}