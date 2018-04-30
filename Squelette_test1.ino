// compiler error handling
#include "Compiler_Errors.h"

// touch includes
#include <MPR121.h>
#include <Wire.h>
#define MPR121_ADDR 0x5C
#define MPR121_INT 4

// mp3 includes
#include <SPI.h>
#include <SdFat.h>
#include <FreeStack.h> 
#include <SFEMP3Shield.h>

// mp3 variables
SFEMP3Shield MP3player;
byte result;
int lastPlayed = 0;

// mp3 behaviour defines
#define REPLAY_MODE TRUE  // By default, touching an electrode repeatedly will 
                          // play the track again from the start each time.
                          //
                          // If you set this to FALSE, repeatedly touching an 
                          // electrode will stop the track if it is already 
                          // playing, or play it from the start if it is not.

// touch behaviour definitions
#define firstPin 0
#define lastPin 11



/*-------------------------------------------------------------------------------------------------------------------
                                                Definir les pin pour chaque zone de contact
 ---------------------------------------------------------------------------------------------------------------------*/
#define rArm 0
#define lArm 1
#define rLeg 2
#define lLeg 3

/*-------------------------------------------------------------------------------------------------------------------
                                                Initialisation des différents mode
 ---------------------------------------------------------------------------------------------------------------------*/
#define pinSwitchMode 13
bool isGameMode = false;

 
void setup() {
    Serial.begin(57600);
  
  pinMode(LED_BUILTIN, OUTPUT);
   
  //while (!Serial) ; {} //uncomment when using the serial monitor 
  Serial.println("Bare Conductive Touch MP3 player");

  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) sd.initErrorHalt();

  if(!MPR121.begin(MPR121_ADDR)) Serial.println("error setting up MPR121");
  MPR121.setInterruptPin(MPR121_INT);

  MPR121.setTouchThreshold(40);     // this is the threshold at which the board senses a touch
                                    // higher values are less sensitive, lower values are more sensitive
                                    // for proximity operation, you could try a value of 6

  MPR121.setReleaseThreshold(20);   // this is the threshold at which the board senses a release
                                    // higher values are less sensitive, lower values are more sensitive
                                    // for proximity operation, you could try a value of 3
                                    // this must ALWAYS be lower than the touch threshold
  

  result = MP3player.begin();
  MP3player.setVolume(10,10);
 
  if(result != 0) {
    Serial.print("Error code: ");
    Serial.print(result);
    Serial.println(" when trying to start MP3 player");
   }

}

void isRightArmTouched(){
  if MPR121.isNewTouch(rArm) return true;
  return false;
}

void isLeftArmTouched(){
  if MPR121.isNewTouch(lArm) return true;
  return false;
}

void isRightLegTouched(){
  if MPR121.isNewTouch(rLeg) return true;
  return false;
}

void isLeftLegTouched(){
  if MPR121.isNewTouch(lLeg) return true;
  return false;
}

void loop() {
 if(isRightArmTouched())
 {
  //mettre ici comment doit réagir le squelette
 }
 if(isLeftArmTouched())
 {
  //mettre ici comment doit réagir le squelette
 }
 if(isRightLegTouched())
 {
  //mettre ici comment doit réagir le squelette
 }
 if(isLeftLegTouched())
 {
  //mettre ici comment doit réagir le squelette
 }
  

}
