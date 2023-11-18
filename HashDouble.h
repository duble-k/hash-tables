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

class HashDouble
{

private:
    // size of hash table
    int size;
    // current size of hash table
    int current_size;
    // hash table array
    std::vector<Node *> table;
public:
    HashDouble(int size);
    ~HashDouble();
    int hash1(unsigned int key);
    int hash2(unsigned int key);
    bool insertItem(unsigned int key, std::string value);
    bool deleteItem(unsigned int key);
    SearchResult* searchItem(unsigned int key);
};