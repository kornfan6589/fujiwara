void setup() {
  int curInputSeq[6];
  
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
  int inputPins[] = {2,3,4,5,6,7};
  
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
  int outputPins[] = {31,33,34,35,36,
                      38,39,40,42,43,
					            44,45,46,48};
  
  // Input patterns from Trans CPU
  int firstInput[]   = {0,0,1,0,0,0};
  int secondInput[]  = {0,0,1,1,0,0};
  int thirdInput[]   = {0,0,0,1,0,0};
  int fourthInput[]  = {0,0,0,0,0,0};
  int parkInput[]    = {1,1,0,0,0,0};
  int reverseInput[] = {0,0,0,0,0,1};
  int neutralInput[] = {0,1,0,0,0,0};
  int LU3Input[]     = {0,0,0,1,1,0};
  int LU4Input[]     = {0,0,0,0,1,0};
  
  // Output patterns to Display
  int firstDisp[]   = {0,0,0,0,0,0,0,0,0,1,0,0,1,0};
  int secondDisp[]  = {1,0,0,1,0,1,1,1,0,0,1,1,1,1};
  int thirdDisp[]   = {1,0,0,1,0,0,1,1,0,1,0,1,1,1};
  int fourthDisp[]  = {0,0,1,1,0,0,0,0,0,1,0,1,1,0};
  int parkDisp[]    = {1,0,1,1,0,1,0,0,0,0,0,1,1,1};
  int reverseDisp[] = {1,0,1,1,0,1,0,0,0,0,1,1,1,1};
  int neutralDisp[] = {0,1,1,0,0,1,0,0,0,1,1,0,1,0};
  int LUDisp[]      = {0,0,0,0,0,0,0,0,1,0,0,0,0,0};
  
}

void getInputPins(){
	for(i = 2; i < 8; i++){
		curInputSeq[i] = digitalRead(i);
	}
}

bool detectMatch(int[] arr1, int[] arr2){
  for(i = 0; i < 6; i++){
    for(j = 0; j < 6; j++){
      if(i != j) return false;
    }
  }
  return true;
}

void setOutputPins(int[] gear){
  for(i = 0; i < 14; i++){
    digitalWrite(outputPins[i], gear[i])
  }
}

// the loop function runs over and over again forever
void loop() {
  getInputPins();
  
       if(detectMatch(curInputSeq,firstInput))   {setOutputPins(firstDisp)};
  else if(detectMatch(curInputSeq,secondInput))  {setOutputPins(secondDisp)};
  else if(detectMatch(curInputSeq,thirdInput))   {setOutputPins(thirdDisp)};
  else if(detectMatch(curInputSeq,fourthInput))  {setOutputPins(fourthDisp)};
  else if(detectMatch(curInputSeq,parkInput))    {setOutputPins(parkDisp)};
  else if(detectMatch(curInputSeq,reverseInput)) {setOutputPins(reverseDisp)};
  else if(detectMatch(curInputSeq,neutralInput)) {setOutputPins(neutralDisp)};
  else if(detectMatch(curInputSeq,LU3Input))     {setOutputPins(LUDisp)};
  else if(detectMatch(curInputSeq,LU4Input))     {setOutputPins(LUDisp)};

}
