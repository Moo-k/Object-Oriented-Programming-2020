int sum_if_a_palindrome(int integers[], int length){ // returns sum of array if it's a palindrome
  if (length < 1){
    return -1;
  }
  int sum = 0;
  int loopsize = 0;
  if (length % 2 == 0){
    loopsize = length/2;
  } else{
    loopsize = (length-1)/2;
    sum += integers[loopsize];
  }

  for (int i = 0; i < loopsize; i++){ // calculating sum of palindrome the fancy way
    sum += 2*integers[i];
  }

  return sum;
}

bool is_a_palindrome(int integers[], int length){ // takes array and length and checks if it's a palindrome
  if (length < 1){
    return 0;
  }
  int loopsize = 0;
  if (length % 2 == 0){
    loopsize = length/2;
  } else{
    loopsize = (length-1)/2;
  }

  for (int i = 0; i < loopsize; i++){
    if (integers[i] != integers[length-1-i]){
      return 0; // if matching array positions not the same, return false
    }
  }

  return 1; // if everything passes, return true
}

int sum_elements(int integers[], int length){
  if (length < 1){
    return -1;
  }
  int sum = 0;
  for (int i = 0; i < length; i++){ // sum the stuff
    sum += integers[i];
  }
  return sum;
}
