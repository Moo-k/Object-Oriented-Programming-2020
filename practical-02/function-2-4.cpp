int max_integer(int integers[5], int length){
    int max = integers[0];
    for (int i = 1; i < length; i++){
        if (integers[i] > max){
            max = integers[i];
        }
    }

    return max;
}


int min_integer(int integers[5], int length){
    int min = integers[0];
    for (int i = 1; i < length; i++){
        if (integers[i] < min){
            min = integers[i];
        }
    }

    return min;
}


int sum_min_and_max(int integers[5], int length){
    int min = min_integer(integers,length);
    int max = max_integer(integers,length);

    return min + max; 
}