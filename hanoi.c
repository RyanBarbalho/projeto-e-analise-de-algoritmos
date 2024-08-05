#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char start, char aux, char end){
    printf("hanoi(%d, %c, %c, %c) called\n", n, start, aux, end); // Debugging statement
    if(n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    hanoi(n-1, start, end, aux);
    printf("Move disk %d from rod %c to rod %c (not inside if)\n", n, start, end);
    hanoi(n-1, aux, start, end);
}

int main(){
    int n;
    //rod A is the source rod, rod B is the auxiliary rod, rod C is the destination rod IN THIS EXAMPLE
    char start = 'A', end = 'C', aux = 'B';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Starting Tower of Hanoi with %d disks\n", n); // Debugging statement
    hanoi(n, start, aux, end);
    printf("Tower of Hanoi completed\n"); // Debugging statement
    return 0;
}