  /*

  _Project Arduwear Sensor implementation
  
  Ports:
  -led1 = D9;
  -led2 = D10;
  -led3 = D11;
  -button = D2;
  -Mosfet = D3;
  -temp1 = A3;
  -temp2 = A2;

 */

int btnPin = 2;
int fetPin = 3;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int temp1 = A3;
int temp2 = A2;

int mode;

int tempThresh;

boolean btnPressed = false;

void setup() {                

  pinMode(btnPin, INPUT);  
  pinMode(fetPin, OUTPUT);  
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
}

void loop() {
  //Increment mode on depress, unless mode = 3, then reset to 0
  if (btnPressed && digitalRead(btnPin) == LOW && analogRead(temp2) < tempThresh && analogRead(temp1) < tempThresh)
    mode = mode == 3 ? 0 : mode + 1;
  //Assign button state
  btnPressed = digitalRead(btnPin);
  switch (mode)
  {
    case 0:
      analogWrite(fetPin, 0); //off
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
    case 1:
      analogWrite(fetPin, 85); //33% duty cycle
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
    case 2:
      analogWrite(fetPin, 170); //66% duty cycle
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;
    case 3:
      analogWrite(fetPin, 255); //100% duty cycle
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;
  }
}

