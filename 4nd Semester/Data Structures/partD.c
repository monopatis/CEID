#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[31m" /* Red */

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

typedef struct redblack redblack_t;

typedef struct tree_node {
  int key;             /* κλειδί αναζήτησης */
  struct tree_node *l; /* αριστερό παιδί */
  struct tree_node *r; /* δεξιό παιδί */
  struct tree_node *parent;
  short isRed;
} tree_node_t;

struct redblack {
  tree_node_t *root; /* ρίζα*/
  int nodes;         /* πλήθος κόμβων */
  int depth;         /* βάθος δέντρου */
};

tree_node_t *new_node(struct redblack *tree, int element) {
  tree_node_t *new_n = (tree_node_t *)malloc(sizeof *new_n);
  if (new_n == NULL)
    return NULL;
  new_n->isRed = 0;
  new_n->key = element;
  new_n->l = new_n->r = NULL;
  return new_n;
}

void initRedBlack(struct redblack *t, int element) {
  t->root = (tree_node_t *)malloc(sizeof(tree_node_t));
  t->root->key = element;
  t->root->isRed = 0;
  t->root->l = NULL;
  t->root->r = NULL;
  t->root->parent = NULL;
  t->nodes = 1;
}

int searchRedBlack(struct redblack *t, int element) {
  tree_node_t *node = t->root;
  while (node != NULL) {
    if (node->key == element) {
      return 0;
    } else if (node->key > element) {
      node = node->l;
    } else if (node->key < element) {
      node = node->r;
    }
  }
  return 1;
}
tree_node_t *insertToNodeleft(struct redblack *t, tree_node_t *node,
                              int element) {
  if (node->l == NULL) {
    node->l = new_node(t, element);
    if (node->l != NULL) {
      node->l->isRed = 1;
      node->l->parent = node;
      t->nodes++;
      return node->l;
    }
  }
  return NULL;
}

tree_node_t *insertToNoderight(struct redblack *t, tree_node_t *node,
                               int element) {
  if (node->r == NULL) {
    node->r = new_node(t, element);
    if (node->r != NULL) {
      node->r->isRed = 1;
      node->r->parent = node;
      t->nodes++;
      return node->r;
    }
  }
  return NULL;
}

tree_node_t *insertRedBlack(struct redblack *t, tree_node_t *node,
                            int element) {
  if (node->r == NULL && node->l == NULL)
    t->depth++;
  if (element > node->key) {
    if (node->r == NULL)
      return insertToNoderight(t, node, element);
    else
      return insertRedBlack(t, node->r, element);
  } else {
    if (node->l == NULL)
      return insertToNodeleft(t, node, element);
    else
      return insertRedBlack(t, node->l, element);
  }
}

tree_node_t *RightRotation(struct redblack *t, tree_node_t *node) {
  if (node != NULL) {
    // printf("RightRotation ston komvo %d\n", node->key);
    tree_node_t *R = new_node(t, node->key);
    //Ενημέρωση του πατέρα
    if (node->parent != NULL) {
      if ((node->parent->r != NULL) && (node == node->parent->r)) {
        node->parent->r = node->l;
      }
      if ((node->parent->l != NULL) && (node == node->parent->l)) {
        node->parent->l = node->l;
      }
      node->l->parent = node->parent;
    } else {
      t->root = node->l;
      // printf("New root is %d \n", t->root->key);
      t->root->isRed = 0;
    }
    R->isRed = node->isRed = 1;
    R->parent = node->l;
    if (node->r != NULL) {
      R->r = node->r;
      R->r->parent = R;
    }
    if (node->l->r != NULL) {
      R->l = node->l->r;
      R->l->parent = R;
    } else {
      R->l = NULL;
    }
    node = node->l;
    node->r = R;
  }
  return node;
}

tree_node_t *LeftRotation(struct redblack *t, tree_node_t *node) {
  if (node != NULL) {
    // printf("LeftRotation ston komvo %d\n", node->key);
    tree_node_t *L = new_node(t, node->key);
    if (node->parent != NULL) {
      if ((node->parent->r != NULL) && (node == node->parent->r)) {
        node->parent->r = node->r;
      }
      if ((node->parent->l != NULL) && (node == node->parent->l)) {
        node->parent->l = node->r;
      }
      node->r->parent = node->parent;
    } else {
      t->root = node->r;
      // printf("New root is %d \n", t->root->key);
      t->root->isRed = 0;
    }
    L->isRed = node->isRed = 1;
    L->parent = node->r;
    if (node->l != NULL) {
      L->l = node->l;
      L->l->parent = L;
    }
    if (node->r->l != NULL) {
      L->r = node->r->l;
      L->r->parent = L;
    } else {
      L->r = NULL;
    }
    node = node->r;
    node->l = L;
  }
  return node;
}

int compare(tree_node_t *a, tree_node_t *b) {
  if (a == NULL || b == NULL)
    return 0;
  else if (a == b)
    return 1;
  return 0;
}

void printRedBlack(struct redblack *t, tree_node_t *node) {
  if (node->l != NULL)
    printf("/");
  else
    printf(" ");
  if (node->r != NULL)
    printf("\\");
  else
    printf(" ");
  // printf("\n");
  if (node->l != NULL) {
    if (node->l->isRed)
      printf(RED);
    printf("%d " RESET, node->l->key);
  } else
    printf("\n ");
  if (node->r != NULL) {
    if (node->r->isRed)
      printf(RED);
    printf("%d " RESET, node->r->key);
  } else
    printf("  ");
  if (node->l != NULL) {
    if (node->l->l != NULL || node->l->r != NULL) {
      printf("\n");
      printRedBlack(t, node->l);
    }
  }
  if (node->r != NULL) {
    if (node->r->l != NULL || node->r->r != NULL) {
      // printf("e ");
      printRedBlack(t, node->r);
    }
  }
}

void repairTree(struct redblack *t, tree_node_t *node) {
  // printf("Repair gia ton komvo %d\n", node->key );
  tree_node_t *uncle;
  if (node->parent == NULL) {
    // case1
    node->isRed = 0;
    t->root = node;
    return;
  } else if (!node->parent->isRed) {
    // printf("case 2\n");
    return;
  } else if (node->parent->parent != NULL) {
    // printf("gp exist\n");
    if ((node->parent->parent->r != NULL) &&
        (node->parent->parent->l != NULL)) {
      // printf("exei duo paidia\n");
      if (node->parent->parent->r != node->parent)
        uncle = node->parent->parent->r;
      else if (node->parent->parent->l != node->parent)
        uncle = node->parent->parent->l;
      if (uncle->isRed) {
        // case3
        // printf("ο θείος είναι κοκκινος\n");
        uncle->isRed = 0;
        node->parent->isRed = 0;
        node->parent->parent->isRed = 1;
        repairTree(t, node->parent->parent);
      } else {
        // printf("ο θείος %d είναι μαύρος\n", uncle->key);
        if (node->parent->parent->l != NULL &&
            compare(node, node->parent->parent->l->r)) {
          // printf("o komvos einai l->r\n");
          node = LeftRotation(t, node->parent);
          node = node->l;
        } else if (node->parent->parent->r != NULL &&
                   compare(node, node->parent->parent->r->l)) {
          // printf("o komvos einai r->l\n");
          node = RightRotation(t, node->parent);
          node = node->r;
        } else if (node->parent->parent->r != NULL &&
                   compare(node, node->parent->parent->r->r)) {
          // printf("o komvos einai r->r\n");
          node = LeftRotation(t, node->parent);
          node->isRed = 0;
          return;
        } else if (node->parent->parent->l != NULL &&
                   compare(node, node->parent->parent->l->l)) {
          // printf("o komvos einai l->l\n");
          node = RightRotation(t, node->parent->parent);
          node->isRed = 0;
          return;
        }
        if (node->parent != NULL) {
          // printf("o neos komvos exei patera\n");
          if (node->parent->parent != NULL) {
            // printf("o neos komvos exei pappou!\n");
            if (compare(node, node->parent->l))
              node = RightRotation(t, node->parent->parent);
            else if (compare(node, node->parent->r))
              node = LeftRotation(t, node->parent->parent);
            node->isRed = 0;
            node->parent->isRed = 1;
          }
        }
      }
    } else {
      // printf("den exei duo paidia\n");
      if (node->parent->parent->l != NULL &&
          compare(node, node->parent->parent->l->r)) {
        // printf("o komvos einai l->r\n");
        node = LeftRotation(t, node->parent);
        node = node->l;
      } else if (node->parent->parent->r != NULL &&
                 compare(node, node->parent->parent->r->l)) {
        // printf("o komvos einai r->l\n");
        node = RightRotation(t, node->parent);
        node = node->r;
      } else if (node->parent->parent->r != NULL &&
                 compare(node, node->parent->parent->r->r)) {
        // printf("o komvos einai r->r\n");
        node = LeftRotation(t, node->parent);
        node->isRed = 0;
        return;
      } else if (node->parent->parent->l != NULL &&
                 compare(node, node->parent->parent->l->l)) {
        // printf("o komvos einai l->l\n");
        node = RightRotation(t, node->parent->parent);
        node->isRed = 0;
        return;
      }
      if (node->parent != NULL) {
        // printf("o neos komvos exei patera\n");
        if (node->parent->parent != NULL) {
          // printf("else o neos komvos exei pappou\n");
          if (compare(node, node->parent->l))
            node = RightRotation(t, node->parent->parent);
          else if (compare(node, node->parent->r))
            node = LeftRotation(t, node->parent->parent);
          node->isRed = 0;
          node->parent->isRed = 1;
        }
      }
    }
  }
}

void printTree(struct redblack *t) {
  if (t->root->isRed)
    printf(RED);
  printf("\n%d\n" RESET, t->root->key);
  printRedBlack(t, t->root);
}

// A recursive function to do level order traversal
void inorderHelper(tree_node_t *root) {
  if (root == NULL)
    return;

  inorderHelper(root->l);
  printf("%d ", root->key);
  inorderHelper(root->r);
}

void addtoRedBlack(struct redblack *t, int element) {
  if (searchRedBlack(t, element)) {
    // printf("Εισαγωγή του %d\n", element);
    tree_node_t *node = insertRedBlack(t, t->root, element);
    repairTree(t, node);
    repairTree(t, t->root);
    // printTree(t);
  }
}

void save_ints(const char *file_name, struct redblack *tree) {
  FILE *file = fopen(file_name, "r");
  int i, x = 0;
  fscanf(file, "%d", &i);
  // printf(".");
  x++;
  initRedBlack(tree, i);
  do {
    fscanf(file, "%d", &i);
    // printf(".");
    addtoRedBlack(tree, i);
    tree->root->isRed = 0;
    tree->root->parent = NULL;
    x++;
  } while (!feof(file));
  fclose(file);
}

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

void save_ints_toArray(const char *file_name, Array *a) {
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
      // printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, i);
      return;
    }
  }
  // printf("Το %d δεν βρέθηκε!\n", searching_el);
}

void binarySearch(Array *a, int searching_el) {
  int r = a->used - 1;
  int l = 0;
  int next = (r + l) / 2;
  // printf("%d\n", next);
  while (next >= 0) {
    if (searching_el == a->array[next]) {
      // printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, next);
      return;
    } else if (searching_el > a->array[next]) {
      l = next;
    } else {
      r = next;
    }
    if (next == (r + l) / 2)
      break;
    next = (r + l) / 2;
    // printf("%d\n", next);
  }
  // printf("Το %d δεν βρέθηκε!\n", searching_el);
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
      // printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, next);
      return;
    }
    // printf("(l,r,next) = (%d,%d,%d)\n", l,r,next);
  }
  // if (searching_el == a->array[l])
  //   printf("Το %d βρέθηκε επιτυχώς στην θέση %d\n", searching_el, l);
  // else
  //   printf("Το %d δεν βρέθηκε!\n", searching_el);
}

int main(int argc, char *argv[]) {
  Array a;
  initArray(&a, 1);
  save_ints_toArray("integers.txt", &a);
  mergeSort(&a, 0, a.used - 1);
  struct timespec start, end;
  unsigned long long delta_us;
  struct redblack t;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  save_ints("integers.txt", &t);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
  printf("\nTime for insertions: %llu usec\n", delta_us);
  // int step = 1, from = 10, to = 11;
  // int step = 1, from = 500000, to = 500001;
  // int step = 1, from = 200, to = 2000;
  int step = 4, from = 1000, to = 10000;
  printf("From %d to %d with step %d\n", from, to, step);
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = from; i < to; i += step){
    searchRedBlack(&t, i);
  }
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Time for search with RedBlack: %llu usec\n", delta_us);
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = from; i < to; i += step)
    linearSearch(&a, i);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Time for search with linearSearch: %llu usec\n", delta_us);
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = from; i < to; i += step)
    binarySearch(&a, i);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Time for search with binarySearch: %llu usec\n", delta_us);
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = from; i < to; i += step)
    interpolationSearch(&a, i);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Time for search with interpolationSearch: %llu usec\n", delta_us);
  freeArray(&a);
  return 0;
}
