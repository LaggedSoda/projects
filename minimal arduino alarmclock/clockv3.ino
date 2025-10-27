//Updates: Less Flicker. More efficient processing. Fixed "minor" flag issues.
//Ideas for improvement (check, if no buttons pressed [or, add another button] to toggle backlight/conserve power)


#include <LiquidCrystal.h>

//Display Pins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, cs = 9; // cs is the pin for constrast

//Contrast Setting
const int contrast = 100; //Default is 100



//Time Setting Buttons
const int button_hr = 11, button_min = 12; // button_hr (hours), button_min (minutes)

//Alarm Functionality
const int alarm = 10;
const int button_alarm = 13;

//Alarm Values
bool alarm_set = 0;
bool alarm_state = false;
int alm_hr = 0;
int alm_min = 0;
int alm_sec = 0;
int alm_flag = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Kudos to the guy for precision and better time formatting: https://projecthub.arduino.cc/plouc68000/simplest-uno-digital-clock-ever-03c185


//Initially set time to 0
int seconds = 0;
int minutes = 0;
int hours = 12;
int flag = 0;

//Flickering Experimental
int last_min = -1;
int last_hr = -1;
int last_flag = -1;

//Time Set Buttons (indicate buttons, not the pin)
int h_shift;
int m_shift;

//Alarm Button
int alm_shift;

//For accurate time reading
static uint32_t last_time, now = 0;

void setup() {
  //Debug
  //Serial.begin(9600);

  //Initialize Buttons
  pinMode(button_hr, INPUT_PULLUP);
  pinMode(button_min, INPUT_PULLUP);
  pinMode(button_alarm, INPUT_PULLUP);
  now = millis();
  
  //Begin Display
  lcd.begin(16,2);
  analogWrite(cs, contrast);
  
  //Display Alarm Set Time
  lcd.setCursor(0,1);
  lcd.print("ALM");
}

void loop() {

  //Display Formatting for hours
  if(last_min != hours)
  {
    lcd.setCursor(4,0);
    if(hours<10) {lcd.print("0");} // Always 2 digits 12 -> 01 and not just 1
    lcd.print(hours);
    lcd.print(":");
  }
  
   //Display Formatting for minutes
   if(last_hr != minutes)
   {
    lcd.setCursor(7,0);
    if(minutes<10) {lcd.print("0");}
    lcd.print(minutes);
    lcd.print(":");
   }

   //Display Formatting for seconds
   lcd.setCursor(10,0);
   if(seconds<10){lcd.print("0");}
   lcd.print(seconds);

   //Display Formatting for Flag (AM/PM)
   if(last_flag != flag)
   {
   lcd.setCursor(14,0);
   if(flag == 0) {lcd.print("AM");}
   if(flag == 1) {lcd.print("PM");}
   }

  //Display Formatting for Alarm
  if(alarm_set == false)
  {
    lcd.setCursor(13,1);
    lcd.print("OFF");
  }
  else
  {
    lcd.setCursor(13,1);
    lcd.print("SET");
  }
  
  //Better Timing and allows better button functionality
  for(int i = 0; i<5; i++)
  {
    while((now - last_time)<200){now = millis();}
    last_time=now;
  }

  
  //Read Buttons
  h_shift=digitalRead(button_hr);
  m_shift=digitalRead(button_min);
  alm_shift = digitalRead(button_alarm);

  
  //Adjust Time if Alarm Button is not being pressed
  if((h_shift==0) & (alm_shift==1)) {hours = hours + 1;}
  if((m_shift==0) & (alm_shift==1)) {seconds = 0; minutes = minutes + 1;}

  //Read Alarm Buttons
  if(alm_shift==0)
    {
    //Alarm Set Toggle
    if(alarm_set == 0) {alarm_set = 1;}
    else{alarm_set = 0; alarm_state = false;}

    //Adjust Alarm Time
    if(h_shift==0){alm_hr++; if(alm_hr == 13){alm_hr = 1; alm_flag++; if(alm_flag == 2){alm_flag = 0;}}}
    if(m_shift==0){alm_min++; if(alm_min == 60){alm_min = 1;}}

    //Display Alarm Setting if holding alm_button
    lcd.setCursor(4,1);
    if(alm_hr<10) {lcd.print("0");}
    lcd.print(alm_hr);
    lcd.print(":");
     
    lcd.setCursor(7,1);
    if(alm_min<10) {lcd.print("0");}
    lcd.print(alm_min);
     
    lcd.setCursor(10,1); 
    if(alm_flag == 0) {lcd.print("AM");}
    if(alm_flag == 1) {lcd.print("PM");}
    }
    else{ lcd.setCursor(0,1); lcd.print("            ");} //Don't show alarm time

  //Alarm Functionality
  if( (alm_hr == hours) & (alm_min == minutes) & (alm_sec == seconds) & (alm_flag == flag) & (alarm_set == 1))
  {
    alarm_state = true;
  }

  if(alarm_state == true) {tone(alarm, 200, 500);} //Piezo Speaker as Alarm

  //Set Last Values (for experimental flicker solution)
  last_hr = hours;
  last_min = minutes;
  last_flag = flag;

  
  //Counter
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

  //if((hours == 12) & (minutes == 0) & (seconds == 0)){flag++; if(flag==2){flag=0;}  //Fix this and do this for setting the alarm time.
  }
}
