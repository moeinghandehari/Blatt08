#include <stdio.h>
#include <stdlib.h>

int menu();

void bubbleSort(int *, int);

void merge(int arr[], int, int, int);

void mergeSort(int *, int, int);

int wahl;
int array_groesse;
int *array;

int main() {
    while (1) {
        menu();
    }
    return 0;
}

int menu() {
    //Menu zeigen
    //
    printf("\n1) Array-Groesse festlegen");
    printf("\n2) Zahlen von Tastatur einlesen");
    printf("\n3) Zufallszahlen erzeugen");
    printf("\n4) Bubblesort (downwards)");
    printf("\n5) Mergesort");
    printf("\n6) Print Array");
    printf("\n7) Programm beenden");
    printf("\n");
    scanf("%d", &wahl);
    switch (wahl) {
        case 1:
            printf("\nGeben Sie die Groesse des Arrays ein: ");
            scanf("%d", &array_groesse);
            array = malloc(array_groesse * sizeof(int));
            break;
        case 2:
            printf("Geben Sie die Zahlen ein");
            for (int i = 0; i < array_groesse; ++i) {
                printf("\nGeben Sie die %d. Zahl ein: ", (i + 1));
                int temp;
                scanf("%d", &temp);
                array[i] = temp;
            }
            break;
        case 3:
            for (int j = 0; j < array_groesse; ++j)
                array[j] = rand() % 1000;
            break;
        case 4:
            bubbleSort(array, array_groesse);
            break;
        case 5:
            mergeSort(array, 0, array_groesse - 1);
            break;
        case 6:
            printf("\n");
            for (int j = 0; j < array_groesse; ++j) {
                printf("%d - ", array[j]);
            }
            break;
        case 7:
            return 0;
        default:
            break;
    }
}

void bubbleSort(int *array, int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}