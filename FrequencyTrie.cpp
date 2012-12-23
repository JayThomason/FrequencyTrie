/* Dependencies */
#include "FrequencyTrie.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>


/* Constants */
const char ROOT_CHAR = '_';
const char START_CHAR = 'a';

/* Function Implementations */
FrequencyTrie::FrequencyTrie(string dictionaryFilename) {
  root = createNode(ROOT_CHAR);
  constructTree(dictionaryFilename);
}


FrequencyTrie::~FrequencyTrie() {
  deleteNode(root);
}

void FrequencyTrie::deleteNode(node *curr) {
  for (size_t i = 0; i < NUM_LETTERS; ++i) {
    if (curr->successors[i] != NULL) {
      deleteNode(curr->successors[i]);
    }
  }
  delete curr;
  return;
}

FrequencyTrie::node *FrequencyTrie::createNode(const char ch) {
  node *newNode = new node;
  newNode->ch = ch; 
  newNode->count = 0;
  newNode->isWord = false;
  memset(&(newNode->successors), 0x0, NUM_LETTERS);
  return newNode;
}

void FrequencyTrie::constructTree(string dictionaryFilename) {
  ifstream fileStream;
  fileStream.open(dictionaryFilename.c_str());
  string word;
  while (getline(fileStream, word)) {
    insertWord(word);
  }
  fileStream.close();
}

void FrequencyTrie::insertWord(string word) {
  node *curr = root;
  unsigned short letterCounter = 0;
  while (letterCounter < word.length()) {
    ++curr->count;
    unsigned short index = (unsigned short)(word[letterCounter] - START_CHAR);
    node *next = curr->successors[index];
    if (next == NULL) {
      curr->successors[index] = createNode(word[letterCounter]);
      next = curr->successors[index];
    }
    curr = next;
    ++letterCounter;
  }
  ++curr->count;
  curr->isWord = true;
}
