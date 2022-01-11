#include "LED.h"


int getTemp();


Strip<13, 12> moboLEDs(150);
Strip<12, 124> frontLEDs(150);
// Strip<12, 124> frontLeftLEDs(150, 0, 62);
// Strip<12, 124> frontRightLEDs(150, 62, 124, true);
Strip<11, 244> glassLEDs(150);
// Strip<11, 244> caseLEDs(150, 0, 115);
// Strip<11, 244> glassLEDs(150, 115, 244);
Strip<10, 7> reservoirLEDs(150);
Strip<9, 16> fanLEDs(150);
Strip<7, 1> indicatorLED(150);

const int switchOne = 22;
const int switchTwo = 26;
const int switchThree = 24;

const int tempSensor = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connected...");

  pinMode(switchOne, INPUT);
  pinMode(switchTwo, INPUT);
  pinMode(switchThree, INPUT);

  moboLEDs.init();
  frontLEDs.init();
  // frontLeftLEDs.init();
  // frontRightLEDs.init();
  // caseLEDs.init();
  glassLEDs.init();
  reservoirLEDs.init();
  fanLEDs.init();
  indicatorLED.init();

  moboLEDs.singleColor(0, 0, 255);
  frontLEDs.singleColor(0, 255, 0);
  // frontRightLEDs.singleColor(255, 0, 0);
  // frontLeftLEDs.singleColor(0, 255, 0);
  glassLEDs.singleColor(0, 255, 255);
  // caseLEDs.singleColor(255, 0, 255);
  reservoirLEDs.singleColor(255, 255, 0);
  fanLEDs.singleColor(255, 255, 255);
  indicatorLED.singleColor(255, 0, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

  //setup variables
  static int prevSwitchOneState = LOW;
  static int prevSwitchTwoState = LOW;
  static int prevSwitchThreeState = LOW;

  static bool powered = true;
  static int mode = 0; // current mode
  static int modes = 4; // total modes

  // check the switch states
  int switchOneState = digitalRead(switchOne);
  int switchTwoState = digitalRead(switchTwo);
  int switchThreeState = digitalRead(switchThree);

  // LED light logic
  if (powered)
  {
    switch (mode)
    {
    case 0:
      moboLEDs.temperatureSense();
      frontLEDs.temperatureSense();
      glassLEDs.temperatureSense();
      reservoirLEDs.temperatureSense();
      fanLEDs.temperatureSense();
      break;
    
    case 1:
      moboLEDs.singleColor(0, 0, 255);
      frontLEDs.singleColor(0, 0, 255);
      glassLEDs.singleColor(0, 0, 255);
      reservoirLEDs.singleColor(0, 0, 255);
      fanLEDs.singleColor(0, 0, 255);
      break;

    case 2:
      moboLEDs.singleColor(0, 255, 0);
      frontLEDs.singleColor(0, 255, 0);
      glassLEDs.singleColor(0, 255, 0);
      reservoirLEDs.singleColor(0, 255, 0);
      fanLEDs.singleColor(0, 255, 0);
      break;

    case 3:
      moboLEDs.singleColor(255, 0, 0);
      frontLEDs.singleColor(255, 0, 0);
      glassLEDs.singleColor(255, 0, 0);
      reservoirLEDs.singleColor(255, 0, 0);
      fanLEDs.singleColor(255, 0, 0);
      break;

    default:
      break;
    }
    indicatorLED.singleColor(255, 255, 255);
  }
  else
  {
    // turn off LEDs
    moboLEDs.clear();
    glassLEDs.clear();
    frontLEDs.clear();
    fanLEDs.clear();
    reservoirLEDs.clear();
    indicatorLED.singleColor(6, 0, 0);
  }


  // do things when switches are pressed
  // turn LEDs off if switch one is pressed
  if (switchOneState == HIGH && prevSwitchOneState == LOW)
  {
    powered = !powered;
  }
  // mode down when switch two is pressed
  if (switchTwoState == HIGH && prevSwitchTwoState == LOW)
  {
    mode--;
    if (mode < 0)
    {
      mode = modes - 1;
    }
  }
  // mode up when switch three is pressed
  if (switchThreeState == HIGH && prevSwitchThreeState == LOW)
  {
    mode++;
    if (mode >= modes)
    {
      mode = 0;
    }
  }
    
  // update previous states
  prevSwitchOneState = switchOneState;
  prevSwitchTwoState = switchTwoState;
  prevSwitchThreeState = switchThreeState;
}

int getTemp()
{
  int maxTemp = 125;
  int minTemp = -55;
  return (analogRead(tempSensor) / 1024.0) * (maxTemp - minTemp) + minTemp;
}