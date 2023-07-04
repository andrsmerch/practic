#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void selectionSort(int arr[], int n) {
    // ���������� �������
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int rand_massive(int arr[], int n) {
    int i;
    // ���������� ������� ���������� �������
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return 0;
}




int main() {
    int* arr;  // ��������� �� int ��� �������
    int i, n;
    clock_t timer;

    setlocale(LC_ALL, "RUS");
    n = 0;
    while ((n < 10000) or (n > 1100000)) {
        printf("������� ������ ������� �� 10000 �� 1100000: ");
        scanf("%d", &n);
    }

    // ��������� ������
    arr = (int*)malloc(n * sizeof(int));

    // ���������� ������� ���������� �������
    rand_massive(arr, n);

    // ���������� �������
    timer = clock();
    selectionSort(arr, n);
    timer = clock() - timer;
    printf("Time sort = ");
    printf("%f", (double)timer / CLOCKS_PER_SEC);
�

    return 0;