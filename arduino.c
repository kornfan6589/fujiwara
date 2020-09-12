/*
Arduino transmission display program by Kenneth Gibson, 2020
Complain to Ken if things break

Last Update: 9/12/2020
*/

//Declare global Variables
int curInputSeq[6];

/* Input pins (analog) are indexed as follows:
 *
 *     INDEX  PIN_NUM
 *     0      A0
 *     1      A1
 *     2      A2
 *     3      A3
 *     4      A4
 *     5      A5
 *
 */
int inputPins[6] = {A0, A1, A2, A3, A4, A5};

/* Output pins are indexed as follows:
 *
 *   INDEX  PIN_NUM  ID
 *   0      2        1
 *   1      3        3
 *   2      4        4
 *   3      5        5
 *   4      6        6
 *   5      7        8
 *   6      8        9
 *   7      9        10
 *   8      10       12 DP
 *   9      11       13
 *   10     12       14
 *   11     13       15
 *   12     44       16
 *   13     45       18
 *
*/
int outputPins[14] = {2,  3,  4,  5,  6,
                      7,  8,  9,  10, 11,
                      12, 13, 44, 45};

// Input patterns from Trans CPU
int firstInput[]   = {LOW,  LOW,  HIGH, LOW,  LOW,  LOW};
int secondInput[]  = {LOW,  LOW,  HIGH, HIGH, LOW,  LOW};
int thirdInput[]   = {LOW,  LOW,  LOW,  HIGH, LOW,  LOW};
int fourthInput[]  = {LOW,  LOW,  LOW,  LOW,  LOW,  LOW};
int parkInput[]    = {HIGH, HIGH, LOW,  LOW,  LOW,  LOW};
int reverseInput[] = {LOW,  LOW,  LOW,  LOW,  LOW,  HIGH};
int neutralInput[] = {LOW,  HIGH, LOW,  LOW,  LOW,  LOW};
int LU3Input[]     = {LOW,  LOW,  LOW,  HIGH, HIGH, LOW};
int LU4Input[]     = {LOW,  LOW,  LOW,  LOW,  HIGH, LOW};

// Output patterns to Display
int firstDisp[]     = {0,   0,   0,   0,   0, 0,   0,   0,   0,   255, 0,   0,   255, 0};
int secondDisp[]    = {255, 0,   0,   255, 0, 255, 255, 255, 0,   0,   0,   255, 255, 255};
int thirdDisp[]     = {255, 0,   0,   255, 0, 0,   255, 255, 0,   255, 0,   255, 255, 255};
int fourthDisp[]    = {0,   0,   255, 255, 0, 0,   0,   0,   0,   255, 0,   255, 255, 0};
int parkDisp[]      = {255, 0,   255, 255, 0, 255, 0,   0,   0,   0,   0,   255, 255, 255};
int reverseDisp[]   = {255, 0,   255, 255, 0, 255, 0,   0,   0,   0,   255, 255, 255, 255};
int neutralDisp[]   = {0,   255, 255, 0,   0, 255, 0,   0,   0,   255, 255, 0,   255, 0};
int thirdLUDisp[]   = {255, 0,   0,   255, 0, 0,   255, 255, 255, 255, 0,   255, 255, 255};
int fourthLUDisp[]  = {0,   0,   255, 255, 0, 0,   0,   0,   255, 255, 0,   255, 255, 0};

void setup() {
  //set input pins to input mode
  for (int i = 0; i < 6; i++){
    pinMode(inputPins[i], INPUT);
    digitalWrite(inputPins[i],LOW);
  }
  
  //set output pins to output mode
  for (int i = 0; i < 14; i++){
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins[i],LOW);
  }
  /* Serial.begin(9600); */
}

void getInputPins() {
  memset(curInputSeq, 0, sizeof(curInputSeq));
  for (int i = 0; i < 6; i++) {
    curInputSeq[i] = digitalRead(inputPins[i]);
    /* String output = String(i) + String(curInputSeq[i]);
    Serial.println(output);
    delay(1000); */
  }
}

// Compare the current input to expected array values
bool detectMatch(int arr1[], int arr2[]) {
  for (int i = 0; i < 6; i++) {
    if (arr1[i] != arr2[i]) return false;
  }
  return true;
}

// Make the output pins match the required pattern
void setOutputPins(int gear[]) {
  for (int i = 0; i < 14; i++) {
    if (digitalRead(A7) == HIGH){
      analogWrite(outputPins[i], gear[i] / 12);
    }
    else digitalWrite(outputPins[i], gear[i]);
  }
}

// the loop function runs over and over again forever
void loop() {
  getInputPins();

  if      (detectMatch(curInputSeq, firstInput))   setOutputPins(firstDisp);
  else if (detectMatch(curInputSeq, secondInput))  setOutputPins(secondDisp);
  else if (detectMatch(curInputSeq, thirdInput))   setOutputPins(thirdDisp);
  else if (detectMatch(curInputSeq, fourthInput))  setOutputPins(fourthDisp);
  else if (detectMatch(curInputSeq, parkInput))    setOutputPins(parkDisp);
  else if (detectMatch(curInputSeq, reverseInput)) setOutputPins(reverseDisp);
  else if (detectMatch(curInputSeq, neutralInput)) setOutputPins(neutralDisp);
  else if (detectMatch(curInputSeq, LU3Input))     setOutputPins(thirdLUDisp);
  else if (detectMatch(curInputSeq, LU4Input))     setOutputPins(fourthLUDisp);
  else return;
}
