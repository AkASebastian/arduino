
const int led1Pin =  3;    
const int button1 =  2;
const int led2Pin =  5;
const int button2 =  4;
const int led3Pin =  6;
const int button3 =  7;

char bstate1 = 0;
char bstate2 = 0;
char bstate3 = 0;

unsigned long bcount1 = 0; 
unsigned long bcount2 = 0;
unsigned long bcount3 = 0;

boolean timeout(unsigned long *marker, unsigned long interval) {
  if (millis() - *marker >= interval) {
    *marker += interval;
    return true;
  }
  else return false;
}

boolean butndown(char button, unsigned long *marker, char *butnstate, unsigned long interval) {
  switch (*butnstate) {   
    case 0:
      if (button == HIGH) return false;
      else {
        *butnstate = 2;                 
        *marker = millis();             
        return false;                   
      }

    case 1: 
      if (button == LOW) return false; 
      else {
        *butnstate = 3;                 
        *marker = millis();             
        return false;                   
      }

    case 2: 
      if (button == HIGH) {
        *butnstate = 0;             
        return false;   
      }
      else {
        if (millis() - *marker >= interval) {
          *butnstate = 1;               
          return true;                  
        }
        else
          return false;                 
      }

    case 3: 
      if (button == LOW) {
        *butnstate = 1;             
        return false;                   
      }
      else {
        if (millis() - *marker >= interval) {
          *butnstate = 0;               
          return false;                 
        }
        else
          return false;                 
      }
    default:                            
      {
        *butnstate = 0;
        return false;                   
      }
  }
}

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(button2, INPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(button3, INPUT);

  digitalWrite (led1Pin, LOW);
  digitalWrite (led2Pin, LOW);
  digitalWrite (led3Pin, LOW);
  
}

void loop() {
 
  if (butndown(digitalRead(button1), &bcount1, &bstate1, 10UL )) {
    digitalWrite (led1Pin, HIGH);
    digitalWrite (led2Pin, LOW);
    digitalWrite (led3Pin, LOW);
    
  }

  if (butndown(digitalRead(button2), &bcount2, &bstate2, 10UL )) {
    digitalWrite (led1Pin, LOW);
    digitalWrite (led2Pin, HIGH);
    digitalWrite (led3Pin, LOW);
  }
 
  if (butndown(digitalRead(button3), &bcount3, &bstate3, 10UL )) {
    digitalWrite (led1Pin, LOW);
    digitalWrite (led2Pin, LOW);
    digitalWrite (led3Pin, HIGH);
  }
}
