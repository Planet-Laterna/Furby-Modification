
#include <Adafruit_NeoPixel.h>

// PIN used for Furby Interaction, adapt to pins used on your board
#define motorforward          10 
#define motorbackward         11
#define rotationcompleted     2 ///CAMHOME
#define gearrotation          3 // Encoder information
#define rightled              6 // Encoder information

#define eyesLEDPin            5 // Encoder information

#define NUMPIXELS 2

Adafruit_NeoPixel pixels(NUMPIXELS, eyesLEDPin, NEO_GRB + NEO_KHZ800);

volatile bool isHome = false;
volatile int camPos;
volatile int mDir;
String command;

void goToCamPos(int targetPos)
{
  while (camPos <targetPos -1 || camPos >targetPos +1)
  {
   if (camPos >targetPos +1) // Move Backward
   {
    moveBackward();
    mDir =-1;
   }
   else if (camPos < targetPos -1) // Move Forward
   {
    moveForward();   
    mDir =1;
   }
  } // Stop, target already reached
  moveStop();  
  
  // Serial.print("Cam pos ");
  // Serial.println(camPos);
  mDir =0;  
}

void mouth_open(){

  //Serial.println("Open mouth ");
  goToCamPos(20);  
  
}

void mouth_close(){

  //Serial.println("Close mouth "); 
  goToCamPos(2);
  
}

void talk(){

  if (camPos>=0 || camPos < 5  ){

    mouth_open();
    delay(200);
    mouth_close();
    delay(200);
    mouth_open();
    
  }else{

    mouth_close();
    delay(200);
    mouth_open();
    delay(200);
    mouth_close();
  }
}

void go_home(){

  // cam position 0 
  //Serial.println("Go Home "); 
  moveForward();   
  mDir =1;

  while(digitalRead(rotationcompleted) == HIGH){
    
  }

  //Serial.println("Sweet Home "); 

  moveStop();
  camPos = 0;
  mDir =0;

  //Serial.println("camPos "+ String(camPos)); 
}

void eyes_open(){

  //Serial.println("Open eyes "); 
  goToCamPos(150); 
  
}

void eyes_close(){

  //Serial.println("Close eyes "); 
  goToCamPos(60); 
  
}

void rock()
{
  //Serial.println("Rock");
  goToCamPos(190); 
  delay(100);
  goToCamPos(80);     
  delay(100);
}

void color_white(){

   pixels.setPixelColor(0, pixels.Color(255, 255, 255));
   pixels.setPixelColor(1, pixels.Color(255, 255, 255));
   pixels.show();   // Send the updated pixel colors to the hardware.
  
}

void color_black(){
   pixels.setPixelColor(0, pixels.Color(0, 0, 0));
   pixels.setPixelColor(1, pixels.Color(0, 0, 0));
   pixels.show();   // Send the updated pixel colors to the hardware.
  
}

void color_blue(){
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.setPixelColor(1, pixels.Color(0, 0, 255));
  pixels.show();   // Send the updated pixel colors to the hardware. 
}

void color_green(){
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.  
}

void color_red(){
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.setPixelColor(1, pixels.Color(1, 255, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void color_violet(){
  pixels.setPixelColor(0, pixels.Color(0, 255, 255));
  pixels.setPixelColor(1, pixels.Color(0, 255, 255));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void color_orange(){
  pixels.setPixelColor(0, Adafruit_NeoPixel::Color(100,   35,   0));
  pixels.setPixelColor(1, Adafruit_NeoPixel::Color(100,   35,   0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  
}

void color_yellow(){
  pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  pixels.setPixelColor(1, pixels.Color(255, 255, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void moveForward(){
  digitalWrite(motorforward, HIGH);
  digitalWrite(motorbackward, LOW);   
}

void moveBackward(){ 
  digitalWrite(motorforward, LOW);
  digitalWrite(motorbackward, HIGH); 
}

void moveStop(){
  digitalWrite(motorforward, LOW);
  digitalWrite(motorbackward, LOW);
  }

void isr_rising_home()
{
  //isHome = true;
  camPos =0;
  //Serial.println("Reached beginning");
}

void isr_change_encoder()
{
  //camPos = camPos +1;
  camPos += mDir;
  //Serial.println("Motor changed: " + camPos);
  
}

void help(){
        
        Serial.println("Following commands are supported:");
        Serial.println("");
        Serial.println("'h:'   move to initial position");
        Serial.println("'f:'   move Motor forward");
        Serial.println("'r:'   move Motor backward");
        Serial.println("'s:'   stop Motor");
        Serial.println("'1:'   open mouth");
        Serial.println("'2:'   close mouth");
        Serial.println("'4:'   open eyes");
        Serial.println("'3:'   make it talk");
        Serial.println("'5:'   make it talk");
        Serial.println("'6:'   make it dance");
        Serial.println("'p:'   list command options");
        Serial.println("'7:'   change eyes to white");
        Serial.println("'8:'   turn off LEDs");
        Serial.println("'r:'   change eyes to red");
        Serial.println("'b:'   change eyes to blue");
        Serial.println("'g:'   change eyes to green");
        Serial.println("'y:'   change eyes to yellow");
        Serial.println("'v:'   change eyes to violet");
        Serial.println("'o:'   change eyes to orange");
        Serial.println("end");
  
}

void handleSerial() {
 
   while (Serial.available() > 0) {
     bool executed = false;
     
     //char incomingCharacter = Serial.read();
     command = Serial.readStringUntil('\n');
     Serial.println("This is what I got .. " + command);

    
     if(command.equals("h")){
        executed = true;
        go_home();
     }
     else if(command.equals("f")){
        executed = true;
        moveForward();
     }
     else if(command.equals("r")){
        executed = true;
        moveBackward();
     }
     else if(command.equals("s")){
        executed = true;
        moveStop();
     }
     else if(command.equals("1")){
        executed = true;
        mouth_open();
     }
     else if(command.equals("2")){
        executed = true;
        mouth_close();
     }
     else if(command.equals("3")){
        executed = true;
        talk();
     }
     else if(command.equals("4")){
        executed = true;
        eyes_open();
     }
     else if(command.equals("5")){
        executed = true;
        eyes_close();
     }
     else if(command.equals("6")){
        executed = true;
        rock();
     }
     else if(command.equals("p")){
        executed = true;
        help();
     }
     else if(command.equals("7")){
        executed = true;
        color_white();
     }
     else if(command.equals("8")){
        executed = true;
        color_black();
     }
     else if(command.equals("d")){
        executed = true;
        color_red();
     }
     else if(command.equals("b")){
        executed = true;
        color_blue();
     }
     else if(command.equals("g")){
        executed = true;
        color_green();
     }
     else if(command.equals("y")){
        executed = true;
        color_yellow();
     }
     else if(command.equals("v")){
        executed = true;
        color_violet();
     }
     else if(command.equals("o")){
        executed = true;
        color_orange();
     }
    
     else{
        executed = false;     
     }

     //provide feedback, command valid ?
     if (executed) {
      Serial.println("Valid Command"); 
     }
     else{
      Serial.println("Invalid Command");
     }
   }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Start Init functions");

  //****** INIT *****
  pinMode(rotationcompleted, INPUT); 
  digitalWrite(rotationcompleted, HIGH );            //pullup
  pinMode(gearrotation, INPUT); 
  digitalWrite(gearrotation, HIGH );            //pullup

  attachInterrupt(digitalPinToInterrupt(gearrotation), isr_change_encoder, FALLING);
  attachInterrupt(digitalPinToInterrupt(rotationcompleted), isr_rising_home, RISING); 

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setBrightness(50);
  pixels.show();

  //Go Home to start always in same way
  //Remark: Recommended to run this function to calibrate Furby before using other commands
  //go_home();
   
}

void loop() {

    //Serial.println("Tell me what to do....");
    handleSerial();    
}
