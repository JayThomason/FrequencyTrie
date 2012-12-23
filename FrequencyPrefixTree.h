/********************************************************** 
 * File: FrequencyPrefixTree.h
 * Author: Jay Thomason (jayt92@stanford.edu)
 *
 * Implementation of a simple trie, also known as a prefix
 * tree. Upon construction, the tree is populated by a
 * dictionary. In addition to storing the prefixes for each
 * word in the dictionary, the frequency with which each
 * prefix appears in the dictionary is also stored. For
 * example, after constructing a tree from a dictionary 
 * which contains two-thousand words beginning with the 
 * prefix "ab", then calling tree.getFrequency("ab") will
 * return 2000.
 */

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
