#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int *arrayToSort, int arrayLength){
    for(int i = 0; i < arrayLength; i++){
        for(int j = 0; j < (arrayLength - 1); j++){
            int var1 = arrayToSort[j];
            int var2 = arrayToSort[j+1];

            if (var2 < var1){
                arrayToSort[j] = var2;
                arrayToSort[j+1] = var1;
            }
        }
    }
}


int binarySearch(int *arrayToSearch, int arrayLength, int pivotPoint, int numberToFind, int numberOfSearches){
        
    if(numberToFind < arrayToSearch[pivotPoint]){
        numberOfSearches++;
        pivotPoint = floor(pivotPoint/2);
        if ((pivotPoint <= 0) && (arrayToSearch[pivotPoint] != numberToFind)){
            return 0;
        }
        binarySearch(arrayToSearch, arrayLength, pivotPoint, numberToFind, numberOfSearches);
    }
    else if(numberToFind > arrayToSearch[pivotPoint]){
        numberOfSearches++;
        pivotPoint = ceil(pivotPoint + ((arrayLength - pivotPoint)/2));
        if (pivotPoint >= arrayLength){
            return 0;
        } 
        binarySearch(arrayToSearch, arrayLength, pivotPoint, numberToFind, numberOfSearches);
    }
    else{ 
        return numberOfSearches;
    }
}


int main(){

    int mainArray[] = {3, 1, 2, 55, 69, 99, 12, 10, 11, 22, 33, 55}; 
    int arraySize = sizeof(mainArray)/sizeof(int);

    bubbleSort(mainArray, arraySize);
    int pivot = ceil(arraySize/2);
    int numberToFind = 0;
    int totalSearches = binarySearch(mainArray, arraySize, pivot, numberToFind, 0);

    if (totalSearches == 0){
        printf("The number %d was not found", numberToFind);
    }
    else{
        printf("The number %d was found in %d searches", numberToFind, totalSearches); 
    }
    return 0; 
}