#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void selectionSort(int arr[], int n) {
    // сортировка выбором
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
    // Заполнение массива случайными числами
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return 0;
}

int mark_rand_file(int arr[], int n) {
    // запись рандом массива в файл
    int i;
    FILE* filer = fopen("input.txt", "w");
    if (filer != NULL) {
        for (i = 0; i < n; i++) {
            fprintf(filer, "%d \n", arr[i]);
        }
        fclose(filer);
    }
    return 0;

}
int mark_sort_file(int arr[], int n) {
    // Запись сортированного массива в файл
    int i;
    FILE* file = fopen("output.txt", "w");
    if (file != NULL) {
        for (i = 0; i < n; i++) {
            fprintf(file, "%d \n", arr[i]);
        }
        fclose(file);
    }
    return 0;
}

int main() {
    int* arr;  // указатель на int для массива
    int i, n;
    clock_t timer;

    setlocale(LC_ALL, "RUS");
    n = 0;
    while ((n < 10000) or (n > 1100000)) {
        printf("Введите размер массива от 10000 до 1100000: ");
        scanf("%d", &n);
    }

    // Выделение памяти
    arr = (int*)malloc(n * sizeof(int));

    // Заполнение массива случайными числами
    rand_massive(arr, n);

    // запись рандом массива в файл
    mark_rand_file(arr, n);

    // Сортировка массива
    timer = clock();
    selectionSort(arr, n);
    timer = clock() - timer;
    printf("Time sort = ");
    printf("%f", (double)timer / CLOCKS_PER_SEC);


    // Запись сортированного массива в файл
    mark_sort_file(arr, n);

    return 0;
}