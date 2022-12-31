int sumtwo(int array[], int secondarray[], int n){

int sum = 0;

if (n < 1){
  return 0;
} else{
  for (int i = 0; i < n; i++){
    sum += array[i];
    sum += secondarray[i];
  }
}

return sum;
}
