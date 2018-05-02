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

SdFat sd;
SdFile file;

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
#define rHand 0
#define lHand 1
#define rArm 2
#define lArm 3
#define rLeg 4
#define lLeg 5


#define pinMic A0
/*-------------------------------------------------------------------------------------------------------------------
                                                Initialisation des différents mode
 ---------------------------------------------------------------------------------------------------------------------*/
#define pinSwitchMode 13


void setup()
{

  /*------------------------------------------------------------------------------
                               Setup Touch
  ------------------------------------------------------------------------------*/
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
/*------------------------------------------------------------------------------
                                Setup Micro
 ------------------------------------------------------------------------------*/
 pinMode(pinMic, INPUT);

/*------------------------------------------------------------------------------
                             Jauge d'anxiété
------------------------------------------------------------------------------*/
int Anxiety = 0;
}

/*------------------------------------------------------------------------------
                             Détection des touche
------------------------------------------------------------------------------*/
bool isRightArmTouched(){
  if (MPR121.isNewTouch(rArm)) return true;
  return false;
}

bool isLeftArmTouched(){
  if (MPR121.isNewTouch(lArm)) return true;
  return false;
}

bool isRightLegTouched(){
  if (MPR121.isNewTouch(rLeg)) return true;
  return false;
}

bool isLeftLegTouched(){
  if (MPR121.isNewTouch(lLeg)) return true;
  return false;
}

bool isLeftHandTouched()
{
  if (MPR121.isNewTouch(lHand)) return true;
  return false;
}

bool isRightHandTouched()
{
  if(MPR121.isNewTouch(rHand)) return true;
  return false;
}
/*------------------------------------------------------------------------------
                             Gestion des Etats d'anxieté
------------------------------------------------------------------------------*/
void setStateToAnxious()
{

}

void setStateToVeryAnxious()
{

}

void setStateToQuiet()
{

}

void setStateToUnQuiet()
{

}
void loop()
{
  delay(500);
  int volume = analogRead(A0);
  Serial.print(volume);
  Serial.print('\n');

}


