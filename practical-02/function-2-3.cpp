bool is_a_palindrome(int integers[], int length){
  if (length < 1){
      return false;
  }
  int loopsize = 0;
  if (length%2 == 0){
    loopsize = length/2;
  } else{
    loopsize = (length+1)/2;
  }

  for (int i = 1; i<loopsize; i++){
    if (integers[i-1] != integers[length-i]){
      return false;
    }
  }
  return true;
}

int sum_if_a_palindrome(int integers[], int length){
    if (length < 1){
      return -1;
    }
    int loopsize = 0;
    if (length%2 == 0){
        loopsize = length/2;
    } else{
        loopsize = (length+1)/2;
    }

    int sum = 0;

    for (int j = 0; j < length; j++){
        sum += integers[j];
    }

    return sum;

}

int sum_elements(int integers[], int length){
    if (length < 1){
      return -1;
    }

    int sum = 0;

    for (int j = 0; j < length; j++){
        sum += integers[j];
    }

    return sum;
}