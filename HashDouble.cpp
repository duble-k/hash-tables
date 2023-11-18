#include <iostream>
#include <vector>
#include "HashDouble.h"

HashDouble::HashDouble(int x)
{
    this->size = x;
    this->current_size = 0;
    std::vector<Node *> *table = new std::vector<Node *>;

    // fill has table with NULL to indicate empty entires
    for (int i = 0 ; i < this->size ; i++)
    {
        this->table.push_back(NULL);
    }
}

int HashDouble::hash1(unsigned int sn)
{
    return (sn % this->size);
}

int HashDouble::hash2(unsigned int sn)
{
    int val = (sn/this->size)%this->size;
    if (val % 2 == 0)
    {
        val +=1;
    }
    return val;
}

bool HashDouble::insertItem(unsigned int sn, std::string ln)
{
    // check if at max capacity or duplicate key
    if (this->current_size == this->size)
    {
        return false;
    }
    SearchResult *result = new SearchResult;
    result = searchItem(sn);
    if (result->pos != -1)
    {
        return false;
    }
    Node *itm = new Node;
    itm->key = sn;
    itm->value = ln;

    // from here to line x the logic was taken from the pseudo code from lecture 9 part b double hasing slide 9
    int probe = hash1(sn), offset = hash2(sn);
    // continue probing until index is not empty
    while (table[probe] != NULL)
    {
        probe = (probe + offset) % this->size;
    }
    table[probe] = itm;
    this->current_size += 1;
    return true;
}

SearchResult* HashDouble::searchItem(unsigned int sn)
{
    int probe = hash1(sn), offset = hash2(sn), initialPos = probe;
    bool initialItr = true;
    SearchResult *result = new SearchResult;
    // initialize result to impossible values
    result->lastName = "";
    result->pos = -1;

    while(true)
    {
        if(this->table[probe] == NULL)
        {
            return result;
        }
        else if (this->table[probe]->key == sn)
        {
            result->lastName = this->table[probe]->value;
            result->pos = probe;
            return result;
        }
        else if (probe == initialPos && !initialItr)
        {
            return result;
        }
        else
        {
            probe = (probe + offset) % this->size;
        }
        initialItr = false;
    }
    return result;
}

bool HashDouble::deleteItem(unsigned int sn)
{
    SearchResult *result = new SearchResult;
    result = searchItem(sn);
    if (result-> pos == -1)
    {
        // nothing to delete
        return false;
    }
    else
    {
        // delete result by setting back to NULL and decreasing size by 1
        this->table[result->pos] = NULL;
        this->current_size -= 1;
        return true;
    }
}

HashDouble::~HashDouble()
{
    this->table.clear();
}