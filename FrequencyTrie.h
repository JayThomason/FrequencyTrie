/********************************************************** 
 * File: FrequencyTrie.h
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

/* A class representing a frequency trie, which is simply 
 * a prefix tree that also support frequency lookups
 * for prefixes.
 */
class FrequencyTrie
{
private:
  /* Struct: node
   * Usage: node *myNode = new node;
   *
   * Struct representing a node in the trie. Each node
   * includes a char for the prefix ending in that char,
   * a frequency for the prefix ending in that char, a
   * boolean representing whether or not the prefix 
   * ending in that char is also a word in the dictionary,
   * and an array of pointers to successor nodes.
   */
  struct node {
    char ch;
    size_t count;
    bool isWord;
    node *successors[NUM_LETTERS];
  };

  node *root;

  /* node *createNode(const char ch);
   * Usage: node *newNode = createNode('a');
   *
   * Allocates memory for a new node and populates its
   * fields accordingly. In particular the count is set
   * to zero and the successor array is nulled out.
   */
  node *createNode(const char ch);
  
  /* void constructTree(string dictionaryFilename);
   * Usage: constructTree("scrabbleDictionary.txt");
   *
   * Builds the trie from the supplied dictionary 
   * text file. Note that it is essential that the
   * dictionary file be formatted such that there
   * is precisely one word per line and nothing else.
   * Additionally, all words should either be purely
   * lower-case, or purely upper-case
   */
  void constructTree(string dictionaryFilename);

  /* void insertWord(string word);
   * Usage: insertWord("tree");
   *
   * Inserts the given word into the trie, incrementing
   * frequencies for prefixes as the trie is descended
   * and creating new nodes when necessary.
   */
  void insertWord(string word);

  /* void deleteNode(node *curr);
   * Usage: deleteNode(root);
   *
   * Recursively deletes the sub-tree rooted at the supplied
   * node.
   */
  void deleteNode(node *curr);

public:
  /* Constructor: FrequencyTrie(string dictionaryFilename)
   * Usage: FrequencyTrie trie("scrabbleDictionary.txt");
   *
   * Constructs a new FrequencyTrie from the dictionary
   * text file supplied.
   */
  FrequencyTrie(string dictionaryFilename);

  /* Destructor: ~FrequencyTrie()
   * Usage: (implicit)
   *
   * Deallocates all memory used by the trie.
   */
  ~FrequencyTrie();
};

#endif
