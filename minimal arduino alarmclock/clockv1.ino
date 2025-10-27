#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, cs = 9, button_hr = 11, button_min = 12;
const int contrast = 100;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Kudos to the guy for precision and better time formatting: https://projecthub.arduino.cc/plouc68000/simplest-uno-digital-clock-ever-03c185


  //Initially set time to 0
  int seconds = 0;
  int minutes = 0;
  int hours = 12;
  int flag = 0;

  //Time Set Buttons
  int h_shift;
  int m_shift;

  //For accurate time reading
  static uint32_t last_time, now = 0;

void setup() {

  //Initialize Buttons
  pinMode(button_hr, INPUT_PULLUP);
  pinMode(button_min, INPUT_PULLUP);
  now = millis();
  //Begin Display
  lcd.begin(16,2);
  analogWrite(cs, contrast);
}

void loop() {
  //lcd.print("    " + hours + ":" + minutes + ":" + seconds + "    ", 10);
   lcd.setCursor(4,0);
   if(hours<10)lcd.print("0");// always 2 digits
   lcd.print(hours);
   lcd.print(":");
   if(minutes<10)lcd.print("0");
   lcd.print(minutes);
   lcd.print(":");
   if(seconds<10)lcd.print("0");
   lcd.print(seconds);

   lcd.setCursor(0,1);
   if(flag == 0) {lcd.print("AM");}
   if(flag == 1) {lcd.print("PM");}
  
  //witchcraft
  for(int i = 0; i<5; i++)
  {
    while((now-last_time)<200){now = millis();}
    last_time=now;
  }

  
  //Read Buttons
  h_shift=digitalRead(button_hr);
  m_shift=digitalRead(button_min);
  if(h_shift==0) {hours = hours = hours + 1;}
  if(m_shift==0) {seconds = 0; minutes = minutes + 1;}




  

  
  seconds++;

  if(seconds == 60){
    seconds = 0;
    minutes++;
  }
  if(minutes == 60){
    minutes = 0;
    hours++;
  }
  if(hours == 13){
    hours = 1;
    flag++;
    if(flag==2){flag=0;}
  }


}
