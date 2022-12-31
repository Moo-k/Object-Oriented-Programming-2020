double sumeven(double array[], int n){
  double sum = 0;
  if (n < 1){
    return 0;
  } else{
    for (int i = 0; i < n; i+=2){
      sum += array[i];
    }
    return sum;
  }
}
