//Declare global Variables
int curInputSeq[6];

/* Input pins are indexed as follows:
 *
 *     INDEX  PIN_NUM
 *     0      2
 *     1      3
 *     2      4
 *     3      5
 *     4      6
 *     5      7
 *
 */
int inputPins[6] = {2, 3, 4, 5, 6, 7};

/* Output pins are indexed as follows:
 *
 *   INDEX  PIN_NUM  ID
 *   0      31       1
 *   1      33       3
 *   2      34       4
 *   3      35       5
 *   4      36       6
 *   5      38       8
 *   6      39       9
 *   7      40       10
 *   8      42       12 DP
 *   9      43       13
 *   10     44       14
 *   11     45       15
 *   12     46       16
 *   13     48       18
 *
*/
int outputPins[14] = {31, 33, 34, 35, 36,
                    38, 39, 40, 42, 43,
                    44, 45, 46, 48};

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
int firstDisp[]     = {LOW,  LOW,  LOW,  LOW,  LOW, LOW,  LOW,  LOW,  LOW,  HIGH, LOW,  LOW,  HIGH, LOW};
int secondDisp[]    = {HIGH, LOW,  LOW,  HIGH, LOW, HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  HIGH, HIGH, HIGH};
int thirdDisp[]     = {HIGH, LOW,  LOW,  HIGH, LOW, LOW,  HIGH, HIGH, LOW,  HIGH, LOW,  HIGH, HIGH, HIGH};
int fourthDisp[]    = {LOW,  LOW,  HIGH, HIGH, LOW, LOW,  LOW,  LOW,  LOW,  HIGH, LOW,  HIGH, HIGH, LOW};
int parkDisp[]      = {HIGH, LOW,  HIGH, HIGH, LOW, HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH};
int reverseDisp[]   = {HIGH, LOW,  HIGH, HIGH, LOW, HIGH, LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, HIGH};
int neutralDisp[]   = {LOW,  HIGH, HIGH, LOW,  LOW, HIGH, LOW,  LOW,  LOW,  HIGH, HIGH, LOW,  HIGH, LOW};
int thirdLUDisp[]   = {HIGH, LOW,  LOW,  HIGH, LOW, LOW,  HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH, HIGH};
int fourthLUDisp[]  = {LOW,  LOW,  HIGH, HIGH, LOW, LOW,  LOW,  LOW,  HIGH, HIGH, LOW,  HIGH, HIGH, LOW};

void setup() {
  //set input pins to input mode
  for (int i = 0; i < 6; i++){
    pinMode(inputPins[i], INPUT);
  }
  
  //set output pins to output mode
  for (int i = 0; i < 14; i++){
    pinMode(outputPins[i], OUTPUT);
  }
}

void getInputPins() {
  for (int i = 0; i < 6; i++) {
    curInputSeq[i] = digitalRead(i);
  }
}

bool detectMatch(int arr1[], int arr2[]) {
  for (int i = 0; i < 6; i++) {
    if (arr1[i] != arr2[i]) return false;
  }
  return true;
}

void setOutputPins(int gear[]) {
  for (int i = 0; i < 14; i++) {
    digitalWrite(outputPins[i], gear[i]);
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
