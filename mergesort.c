#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int start, int mid, int end){
    int leftElements = mid - start + 1; //leftElements means number of elements in left array
    int rightElements = end - mid; //rightElements means number of elements in right array

    int *left = (int*)malloc(leftElements * sizeof(int));
    int *right = (int*)malloc(rightElements * sizeof(int));

    for(int i = 0; i < leftElements; i++){ //copying elements to left array
        left[i] = array[start + i];
    }

    for(int j = 0; j < rightElements; j++){ //copying elements to right array
        right[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0;

    for(int l = 0; l <= end; l++){
        if(left[i] <= right[j]){
            array[l] = left[i];
            i++;
        }else{
            array[l] = right[j];
            j++;
        }
    }

    free(left);
    free(right);

    for(int i = 0; i <= end; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void mergeSort(int array[], int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main(){
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array)/sizeof(array[0]);
    int r = size - 1; // r = 9
    printf("Array before sorting: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    mergeSort(array, 0, r);
    printf("Array after sorting: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}