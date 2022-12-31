bool fanarray(int array[], int n){
  int loopsize = 0;
  if (n%2 == 0){
    loopsize = n/2;
  } else{
    loopsize = (n+1)/2;
  }

  for (int i = 1; i<loopsize; i++){
    if (array[i] < array[i-1]){
      return false;
    } else if (array[i-1] != array[n-i]){
      return false;
    }
  }

  return true;
}
