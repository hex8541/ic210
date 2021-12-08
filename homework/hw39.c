//Nicholas Heil 242628
//Print out all words from a list in reverse order that start with certain char

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char word[128];
  struct Node* next;
};

// Adds to the front!
struct Node* add2front(char* val, struct Node* L) {
  struct Node* T = malloc(sizeof(struct Node));
  strcpy(T->word, val);
  T->next = L;
  return T;
}

// Recursive, prints it backwards!
// Since the list is built backwards, this prints forward!
void printList(struct Node* L) {
  if( L == NULL )
    printf("\n");
  else {
    printList(L->next);
    printf("%s ", L->word);
  }
}

int main() {
  //Read in list of words
  struct Node* mylist = NULL;
  char word[20];
  printf("Enter words followed by END: ");
  while(scanf("%s", word) && strcmp(word, "END") != 0 ) {
    mylist = add2front(word, mylist);
  }

  //Ask for and search for letter
  char term;
  printf("What letter? ");
  scanf(" %c", &term);
  for(struct Node* temp = mylist; temp != NULL; temp = temp->next){
    if(temp->word[0] == term)
      printf("%s\n", temp->word);
  }

  return 0;
}
