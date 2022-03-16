#include <stdio.h>

void loadArray(int[], int);
void printArray(int[], int);
void sortArray(int[], int);
int ricercaDicotomica(int[], int, int);


int main(){
	
	const int SIZE = 5;
	int array[SIZE];
	int key = 0;
	int ricerca = 0;

	loadArray(array, SIZE);
	sortArray(array, SIZE);
	printArray(array, SIZE);
	printf("Quale numero vuoi cercare?\n");
	scanf("%d", &key);
	ricerca = ricercaDicotomica(array, SIZE, key);
	if(ricerca >= 1){
		printf("Numero trovato all'indice: %d", ricerca);
	} else {
		printf("Il numero non è presente all'interno dell'array\n");
	}

	return 0;
}

void loadArray(int array[], int SIZE){
	for(int i = 0; i < SIZE; i++){
		scanf("%d", &array[i]);
	}
}

void printArray(int array[], int SIZE){
	for(int i = 0; i < SIZE; i++){
		if (i == 4)
		{
			printf("%d.\n",array[i]);
		} else {
			printf("%d,",array[i]);
		}
		
	}
}

void sortArray(int array[], int SIZE){
	for(int j = 0; j < SIZE-1; j++){
		for(int i = j + 1; i < SIZE; i++){
			if (array[j] > array[i])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int ricercaDicotomica(int array[], int SIZE, int key){
	
	int sizeD;
	int fine = SIZE-1; 
	int inizio = 0;

	while(inizio <= fine){

		sizeD = (fine + inizio)/2;
		if (array[sizeD] == key){
			return sizeD;

		} else if (array[sizeD] < key){
			inizio = inizio + 1;

		} else if (array[sizeD] > key){
			fine = fine - 1;
		}
		
	}

	return -1;
}