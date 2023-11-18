#include <iostream>
#include <vector>

#include "HashChain.h"

// constructor
HashChain::HashChain(int x)
{
    this->size = x;
    table = new std::vector<Node *>[size];
    
}

int HashChain::hash(unsigned int sn)
{
    return (sn % this->size);
}

bool HashChain::insertItem(unsigned int sn, std::string ln)
{
    int index = hash(sn);
    // call search function to check if key is duplicate
    SearchResult *result = new SearchResult;
    // initialize result to impossible values
    result->lastName = "";
    result->pos = -1;
    result = searchItem(sn);
    if (result->pos != -1)
    {
        return false;
    }

    //create new node to insert in hash table
    Node *itm = new Node;
    itm->key = sn;
    itm->value = ln;
    
    this->table[index].push_back(itm);

    return true;
}

SearchResult* HashChain::searchItem(unsigned int sn)
{
    SearchResult *result = new SearchResult;
    // initialize result to impossible values
    result->lastName = "";
    result->pos = -1;
    int index = hash(sn);

    // check if key in the chain 
    for(int i = 0 ; i < this->table[index].size() ; i++)
    {
        if (this->table[index][i]->key == sn)
        {
            result->lastName = this->table[index][i]->value;
            result->pos = index;
            break;
        }
    }

    return result;
}

bool HashChain::deleteItem(unsigned int sn)
{
    int index = hash(sn);
    // check if chain is empty
    if (this->table[index].empty())
    {
        return false;
    }
    else
    {
        for (int i = 0 ; i < this->table[index].size() ; i++)
        {
            if (this->table[index][i]->key == sn)
            {
                //line 42 ".begin()+i" part was retrieved from a stack overflow post explaining this part is necessary to erase at position i
                this->table[index].erase(this->table[index].begin()+i);
                return true;
            }
        }
    }
    return false;
}

std::vector<Node *> HashChain::positionCount(int pos)
{
    return this->table[pos];
}

// deconstructor
HashChain::~HashChain()
{
    for (int i = 0 ; i < this->size ; i++)
    {
        this->table[i].clear();
    }
    delete[] this->table;
}