#include <iostream>
#include <vector>

class Node
{
public:
    unsigned int key;
    std::string value;

};

class SearchResult
{
public:
    std::string lastName;
    int pos;

};

class HashChain
{
private:
    // size of hash table
    unsigned int size;
    // hash table array of vectors
    std::vector<Node *> *table;
public:
    HashChain(int size);
    ~HashChain();
    int hash(unsigned int key);
    bool insertItem(unsigned int key, std::string value);
    bool deleteItem(unsigned int key);
    SearchResult* searchItem(unsigned int key);
    std::vector<Node *> positionCount(int pos);

};