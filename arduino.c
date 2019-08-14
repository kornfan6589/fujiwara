//Declare global Variables
int curInputSeq[6], inputPins[6], outputPins[14], 
    firstInput[6], secondInput[6], thirdInput[6], fourthInput[6], 
    parkInput[6], reverseInput[6], neutralInput[6], LU3Input[6], LU4Input[6],
    firstDisp[14], secondDisp[14], thirdDisp[14], fourthDisp[14], parkDisp[14],
    reverseDisp[14], neutralDisp[14], LUDisp[14];

void setup() {
  /* Input pins are indexed as follows:
   *  
   * INDEX  PIN_NUM
   * 0      2
   * 1      3
   * 2      4
   * 3      5
   * 4      6
   * 5      7
   *
   */
  inputPins[] = {2,3,4,5,6,7};
  
  /* Output pins are indexed as follows:
   *  
   * INDEX  PIN_NUM  ID
   * 0      31       1
   * 1      33       3
   * 2      34       4
   * 3      35       5
   * 4      36       6
   * 5      38       8
   * 6      39       9
   * 7      40       10
   * 8      42       12 DP
   * 9      43       13
   * 10     44       14
   * 11     45       15
   * 12     46       16
   * 13     48       18
   *
   */
  outputPins[] = {31,33,34,35,36,
                      38,39,40,42,43,
                      44,45,46,48};
  
  // Input patterns from Trans CPU
  firstInput[]   = {0,0,1,0,0,0};
  secondInput[]  = {0,0,1,1,0,0};
  thirdInput[]   = {0,0,0,1,0,0};
  fourthInput[]  = {0,0,0,0,0,0};
  parkInput[]    = {1,1,0,0,0,0};
  reverseInput[] = {0,0,0,0,0,1};
  neutralInput[] = {0,1,0,0,0,0};
  LU3Input[]     = {0,0,0,1,1,0};
  LU4Input[]     = {0,0,0,0,1,0};
  
  // Output patterns to Display
  firstDisp[]   = {0,0,0,0,0,0,0,0,0,1,0,0,1,0};
  secondDisp[]  = {1,0,0,1,0,1,1,1,0,0,1,1,1,1};
  thirdDisp[]   = {1,0,0,1,0,0,1,1,0,1,0,1,1,1};
  fourthDisp[]  = {0,0,1,1,0,0,0,0,0,1,0,1,1,0};
  parkDisp[]    = {1,0,1,1,0,1,0,0,0,0,0,1,1,1};
  reverseDisp[] = {1,0,1,1,0,1,0,0,0,0,1,1,1,1};
  neutralDisp[] = {0,1,1,0,0,1,0,0,0,1,1,0,1,0};
  LUDisp[]      = {0,0,0,0,0,0,0,0,1,0,0,0,0,0};
  
}

void getInputPins(){
  for(int i = 2; i < 8; i++){   //added int fixed
    curInputSeq[i] = digitalRead(i);
  }
}

bool detectMatch(int arr1[], int arr2[]){  //fixed
  for(int i = 0; i < 6; i++){   //added int fixed
    if(arr1[i] != arr2[i]) return false;
  }
  return true;
}

void setOutputPins(int gear[]){   // fixed
  for(int i = 0; i < 14; i++){    // fixed
    digitalWrite(outputPins[i], gear[i])
  }
}

// the loop function runs over and over again forever
void loop() {
  setup();
  getInputPins();
  
       if(detectMatch(curInputSeq,firstInput))   {setOutputPins(firstDisp)};
  else if(detectMatch(curInputSeq,secondInput))  {setOutputPins(secondDisp)};
  else if(detectMatch(curInputSeq,thirdInput))   {setOutputPins(thirdDisp)};
  else if(detectMatch(curInputSeq,fourthInput))  {setOutputPins(fourthDisp)};
  else if(detectMatch(curInputSeq,parkInput))    {setOutputPins(parkDisp)};
  else if(detectMatch(curInputSeq,reverseInput)) {setOutputPins(reverseDisp)};
  else if(detectMatch(curInputSeq,neutralInput)) {setOutputPins(neutralDisp)};
  else if(detectMatch(curInputSeq,LU3Input))     {setOutputPins(LUDisp)};
  else if(detectMatch(curInputSeq,LU4Input))     {setOutputPins(LUDisp)};   //error 'curInputSeq' was not declared in this scope
  else return;
}
