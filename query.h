#ifndef QUERY_H
#define QUERY_H

#include <iostream>

class Query
{
public:
    Query();

private:
    std::string inquirer;
    std::string giver;
    std::string weapon;
    std::string suspect;
    std::string room;
};

#endif // QUERY_H
