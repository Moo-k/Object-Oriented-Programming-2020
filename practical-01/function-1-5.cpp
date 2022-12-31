int count_even(int number){
  int count = 0;
  if (number < 1){
    return 0;
  } else{
    for (int i = 1; i < (number+1); i++){
    if (i%2 == 0){
      count++;
    }
  }
  }
  return count;
}
