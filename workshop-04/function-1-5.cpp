int size_of_array_arr(){
	int *arr = new int[3];
	
	int totalsize = 0;
	
	for (int i = 0; i < 3; i++){
		totalsize+=sizeof(*(arr+i));
	}
	
	return totalsize;
}
