#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void read_ints(const char *file_name) {
  FILE *file = fopen(file_name, "r");
  int i, lines = 0;

  fscanf(file, "%d", &i);
  lines++;
  while (!feof(file)) {
    // printf("%d ", i);
    fscanf(file, "%d", &i);
    lines++;
  }
  fclose(file);
  printf("%d ", lines);
}

void save_ints(const char *file_name, Array *a) {
  FILE *file = fopen(file_name, "r");
  int i = 0;
  do {
    fscanf(file, "%d", &i);
    insertArray(a, i);
  } while (!feof(file));
  fclose(file);
}

void merge(Array *arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int X[n1], Y[n2];
  for (i = 0; i < n1; i++)
    X[i] = arr->array[l + i];
  for (j = 0; j < n2; j++)
    Y[j] = arr->array[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (X[i] <= Y[j]) {
      arr->array[k] = X[i];
      i++;
    } else {
      arr->array[k] = Y[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr->array[k] = X[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr->array[k] = Y[j];
    j++;
    k++;
  }
}

void mergeSort(Array *arr, int l, int r) {
  if (l < r) {
    // Το ίδιο με (l+r)/2 αλλά χωρίς υπερχείλιση για μεγάλα l, r
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  Array a;
  initArray(&a, 1);
  save_ints("integers.txt", &a);
  //Εμφάνιση πρώτων 10 στοιχείων του αρχείου
  for (int k = 0; k < 10; k++) {
    printf("%d\n", a.array[k]);
  }
  printf("\n");
  //Εμφάνιση 10 τελευταίων στοιχείων του αρχείου
  for (unsigned int k = a.used - 10; k < a.used; k++) {
    printf("%d\n", a.array[k]);
  }
  // Εμφάνιση πλήθους στοιχείων
  printf("Number of elements: %d\n", a.used - 1);
  mergeSort(&a, 0, a.used - 1);
  //Εκτύπωση στοιχείων μετά την ταξινόμηση
  // printf("\n");
  // for (unsigned int k = 0; k < a.used; k++) {
  //   printf("%d\n", a.array[k]);
  // }
  freeArray(&a);
  return 0;
}
