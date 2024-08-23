/*
*****************************************************************
argc, argv 예제 -> 인자로 수들을 받음 -> 배열에 char형태로 저장되니
정수로 형변환, qsort로 정렬 후 출력

c파일 실행 -> .exe 생성 확인 -> 터미널에서 인자 전달 -> 출력 확인 

ex) 
PS D:\c-coding> ./argc_argv 23 56 78 12 45     
12 23 45 56 78  

PS D:\c-coding> ./argc_argv 9 8 7 6 5 4 3 2 1 11 88 99 100
Error : Too many imput parameters
*****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main (int argc, char *argv[]){
	
    if (argc > 11) { // argv[0] -> 코드명이 저장됨. 때문에 argc > 11
        printf("Error : Too many imput parameters");
        return 1;
    }

    int array[10];
    int arr_size = argc - 1; // argv[0] : program name

    for (int i = 0; i < arr_size; i++){
        array[i] = atoi(argv[i+1]); //integer로 변환
    }

    qsort(array, arr_size, sizeof(int), compare);

    for (int i = 0; i < arr_size; i++){
        printf("%d ", array[i]);
    }

    return 0;

}
