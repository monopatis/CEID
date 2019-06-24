#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Η δομή του Digital Tree
struct TRIE {
  short leaf;
  struct TRIE *child[52];
};

//Συνάρτηση που επιστρέφει νέο κόμβο για κάποιο παιδί του TRIE,
// δεσμεύει τον κατάλληλο χώρο στην μνήμη και αρχικοποιεί
struct TRIE *new_node() {
  struct TRIE *new_n = (struct TRIE *)malloc(sizeof(struct TRIE));
  if (new_n == NULL)
    return NULL;
  new_n->leaf = 0;
  for (unsigned short i = 0; i < 52; i++)
    new_n->child[i] = NULL;
  return new_n;
}

//Συνάρτηση που μετατρέπει τους χαρακτήρες A-Z και a-z σε αριθμούς
//  από 0-25 και 26-51 αντίστοιχα
unsigned short char2index(const char c) {
  unsigned short r;
  if (c > 'Z') {
    r = ((int)c - (int)'a' + 26);
  } else
    r = ((int)c - (int)'A');
  if (r > 51) {
    r = 0;
    printf("\nTo %c megalitero apo 51!\n", c);
  }
  return r;
}

//Εισάγει μια νέα συμβολοσειρά στο Digital Tree
void TRIEadd(struct TRIE *T, const char *string) {
  struct TRIE *editNode = T;
  for (unsigned int i = 0; i < strlen(string); i++) {
    int index = char2index(string[i]);
    if (!editNode->child[index])
      editNode->child[index] = new_node();
    editNode = editNode->child[index];
  }
  editNode->leaf = 1;
}

//Αναζητεί να υπάρχει μια συμβολοσειρά στο Digital Tree
short TRIEsearch(struct TRIE *T, const char *string) {
  int index;
  struct TRIE *searchNode = T;
  for (unsigned int i = 0; i < strlen(string); i++) {
    index = char2index(string[i]);
    if (!searchNode->child[index]) {
      printf("Το %s δεν υπάρχει στο TRIE\n", string);
      return 0;
    }
    searchNode = searchNode->child[index];
  }
  if (searchNode != NULL && searchNode->leaf) {
    printf("Το %s υπάρχει στο TRIE\n", string);
    return 1;
  } else{
    printf("Το %s δεν υπάρχει στο TRIE\n", string);
    return 0;
  }
}

void TRIEdelete(struct TRIE *T, const char *string) {
  int index;
  struct TRIE *searchNode = T;
  for (unsigned int i = 0; i < strlen(string); i++) {
    index = char2index(string[i]);
    if (!searchNode->child[index]) {
      printf("Το %s δεν υπάρχει στο TRIE\n", string);
    }
    searchNode = searchNode->child[index];
  }
  if (searchNode != NULL && searchNode->leaf)
    searchNode->leaf = 0;
  else
    printf("Το %s δεν υπάρχει στο TRIE\n", string);
}

//Συνάρτηση που αφαιρεί τους ειδικούς χαρακτήρες νέας γραμμής από ένα string
//επιστρέφει το s χωρίς την νέα γραμμή
void chomp(char *s) {
  while (*s && *s != '\n' && *s != '\r')
    s++;
  *s = 0;
}

//Συνάρτηση που αποθηκεύει στην δομή TRIE τις γραμμές του αρχείου
void savetoTRIE(struct TRIE *T, const char *file_name) {
  FILE *file = fopen(file_name, "r");
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, file)) != -1) {
    // printf("%s", line);
    chomp(line);
    TRIEadd(T, line);
  }
  fclose(file);
}

int main() {
  struct TRIE *T = new_node();
  savetoTRIE(T, "words.txt");
  TRIEsearch(T, "Jedi");
  TRIEsearch(T, "again");
  TRIEdelete(T, "Jedi");
  TRIEsearch(T, "Jedi");
  free(T);
  return 0;
}
