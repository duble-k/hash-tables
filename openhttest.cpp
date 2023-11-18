#include <iostream>
#include <vector>

#include "HashDouble.h"

int main()
{
    std::string command, lastName;
    unsigned int studentNumber;

    HashDouble *table;

    while(std::cin >> command)
    {
        if (command == "m")
        {
            int size;
            std::cin >> size;

            table = new HashDouble(size);
            std::cout << "success" << std::endl;
        }
        else if (command == "i")
        {
            std::cin >> studentNumber >> lastName;

            if (table->insertItem(studentNumber, lastName))
            {
                std::cout << "success" << std::endl;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
        }
        else if (command == "s")
        {
            SearchResult *result = new SearchResult;
            // initialize result to impossible values
            result->lastName = "";
            result->pos = -1;
            std::cin >> studentNumber;
            result = table->searchItem(studentNumber);

            if (result->pos != -1)
            {
                std::cout << "found " << result->lastName << " in " << result->pos << std::endl;
            }
            else
            {
                std::cout << "not found" << std::endl;
            }
        }
        else if (command == "d")
        {
            std::cin >> studentNumber;

            if (table->deleteItem(studentNumber))
            {
                std::cout << "success" << std::endl;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
        }
    }
    return 0;
}