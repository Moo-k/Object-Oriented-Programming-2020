extern int *createArray(int n);
extern void displayArray(int *numbers, int length);
extern void bmiIndex(int weight);

int main(){
  const int n = 4;
  int *numbers = createArray(4);

  for (int i = 0; i < n; i++){
    bmiIndex(*(numbers + i));
  }

  return 0;
}
