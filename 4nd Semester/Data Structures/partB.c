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

void linearSearch(Array *a, int searching_el) {
  for (int i = 0; i < a->used; i++) {
    if (searching_el == a->array[i]) {
      printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, i);
      return;
    }
  }
  printf("Το %d δεν βρέθηκε!\n", searching_el);
}

void binarySearch(Array *a, int searching_el) {
  int r = a->used - 1;
  int l = 0;
  int next = (r + l) / 2;
  printf("%d\n", next);
  while (next >= 0) {
    if (searching_el == a->array[next]) {
      printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, next);
      return;
    } else if (searching_el > a->array[next]) {
      l = next;
    } else {
      r = next;
    }
    if (next == (r + l) / 2)
      break;
    next = (r + l) / 2;
    printf("%d\n", next);
  }
  printf("Το %d δεν βρέθηκε!\n", searching_el);
}

void interpolationSearch(Array *a, int searching_el) {
  int r = a->used - 1;
  int l = 0;
  while ((l <= r) && (searching_el >= a->array[l]) &&
         (searching_el <= a->array[r])) {
    //Πολύ συμαντικό να γίνει casting με double
    int next = l +
               ((double)r - l) * (searching_el - a->array[l]) /
                   (a->array[r] - a->array[l]);
    if (searching_el > a->array[next])
      l = next + 1;
    else if (searching_el < a->array[next])
      r = next - 1;
    else {
      printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, next);
      return;
    }
    printf("(l,r,next) = (%d,%d,%d)\n", l, r, next);
  }
  if (searching_el == a->array[l])
    printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, l);
  else
    printf("Το %d δεν βρέθηκε!\n", searching_el);
}

int main(int argc, char *argv[]) {
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
    printf("%d\n", a.array[k]); // print 10th element
  }
  // Εμφάνιση πλήθους στοιχείων
  printf("Number of elements: %d\n", a.used - 1);
  mergeSort(&a, 0, a.used - 1);
  //Εκτύπωση στοιχείων μετά την ταξινόμηση
  printf("\n");
  // for (unsigned int k = 0; k < a.used; k++) {
  for (unsigned int k = 0; k < 15; k++) {
    printf("%d\n", a.array[k]);
  }
  //Εμφάνιση 10 τελευταίων στοιχείων του αρχείου
  for (unsigned int k = a.used - 10; k < a.used; k++) {
    printf("%d\n", a.array[k]);
  }
  int selection, searching_el = 0;
  if (argc < 3) {
    printf("Εισάγετε ακέραιο προς αναζήτηση: ");
    scanf("%d", &searching_el);
    printf("Επιλέξτε κάποια από τα παρακάτω: \n 1. Γραμμική Αναζήτηση\n 2. "
           "Binary search\n 3. Interpolation search\n");
    scanf("%d", &selection);
  } else {
    searching_el = atoi(argv[1]);
    selection = atoi(argv[2]);
  }
  switch (selection) {
  case 1:
    linearSearch(&a, searching_el);
    break;
  case 2:
    binarySearch(&a, searching_el);
    break;
  case 3:
    interpolationSearch(&a, searching_el);
    break;
  }
  freeArray(&a);
  return 0;
}
