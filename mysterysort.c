#include<stdio.h>
#include<stdlib.h>

int largest(int array[], int start, int end){
    printf("was called with start = %d and end = %d\n", start, end);
    printf("Array: ");
    for(int i = 0; i <= end; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    if (start == end){
        return array[start];
    }

    int mid = start +(end - start) / 2;//start is being added to avoid overflow
    int left = largest(array, start, mid);
    int right = largest(array, mid + 1, end);

    if(left < right){
        return right;
    }else{
        return left;
    }
}

int main(){
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array)/sizeof(array[0]);
    int r = size - 1; // r = 9

    printf("\n");
    printf("Largest element in the array: %d\n", largest(array, 0, r));
    printf("\n");
    return 0;
}
