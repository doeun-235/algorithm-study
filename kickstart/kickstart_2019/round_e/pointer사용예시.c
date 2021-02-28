#include <stdio.h>

int main(void)
{

    int col = 2, row = 2;

    int *arr = (int*)malloc(sizeof(int)*col*row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", arr[row*i + j]);
        }
    }

    return 0;
}

// c에서 2차원 포인터는 메모리문제가 생길 수 있음. 대신 cpp은 포인터 쓰지 않고도 동적할당 가능