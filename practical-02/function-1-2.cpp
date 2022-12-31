int identity(int array[10][10]){

    for (int r = 0; r < 10; r++){
        for (int c = 0; c < 10; c++){
            if (r == c){
                if (array[r][c] != 1){
                    return 0;
                }
            }   else if (array[r][c] != 0) {
                return 0;
            }
        }
    }

    return 1;
}