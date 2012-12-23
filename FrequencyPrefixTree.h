#ifndef PREFIX_TREE_H
#define PREFIX_TREE_H


/* Dependencies */
#include <string>

/* Constants */
const size_t NUM_LETTERS = 26;

/* Namespace */
using namespace std;

class FrequencyPrefixTree
{
  private:
    struct node {
      char ch;
      size_t count;
      bool isWord;
      node *successors[NUM_LETTERS];
    };
    node *root;
    node *createNode(const char ch);
    void constructTree(string dictionaryFilename);
    void insertWord(string word);

  public:
    FrequencyPrefixTree(string dictionaryFilename);
    ~FrequencyPrefixTree();
};

#endif
