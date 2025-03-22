#include <stdio.h>
void sort(int *a, int b){//b-> 10,9,8,7,,,,,2
    int max = a[10-b];//a[0], a[1], a[2]
    int max_index = 10-b;
    for(int i=10-b; i<10; i++){
        if(max<a[i]){
            max = a[i];
            max_index = i;
        }
    }
    int temp;
    temp = a[10-b];
    a[10-b] = a[max_index];
    a[max_index] = temp;
}
int main(){
    int arr[10] = {0};
    int *ptr = arr;
    int i;
    for(i=0; i<10;i++){
        scanf("%d", &arr[i]);
    }
    for(i=10; i>1; i--){
        sort(ptr, i);
    }
    for(i=0; i<10;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}