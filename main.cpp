#include <iostream>
#include "data_structures/avl_tree.h"
#include "data_structures/Graph.h"
#include "data_structures/Queue.h"
#include "data_structures/stack.h"
#include "objects/node_info.h"
#include <fstream>
#include <string>
#include <sstream>


class house
{
    int house_id; // Which node has this house
    int lock_level;
    float house_worth;
    public:
        house() {}
        void set(int house_id, int lock_level, float house_worth)
        {
            this->house_id = house_id;
            this->lock_level = lock_level;
            this->house_worth = house_worth;
        }
};


class Non_Home
{
    string type;
    float worth;
    float lock_level;
    public:
        Non_Home() {}
        void set(string type, float worth, float lock_level)
        {
            this->type = type;
            this->worth = worth;
            this->lock_level = lock_level;
        }
};



class Person
{
    string name;
    float income;
    int weapon_level;
    house H;
    Non_Home nh;
    public:
        Person() {}
        void set(string name, float income,int house_id=0,int house_worth=0,int lock_level=0,string type="none", float worth=0.0,  int weapon_level=0)
        {
            this->income = income;
            this->name = name;
            this->weapon_level = weapon_level;
            this->H.set(house_id, lock_level, house_worth);
            this->nh.set(type, worth, lock_level);
        }
};


int main()
{
    Graph<obj<Person>> neighbourhood;
    cout << "IN MAIN\n";
    ifstream file("residents.csv");
    string line;

    if(!file.is_open())
    {
        return 1;
    }
    else
    {
        // Skip header
        std::getline(file, line);

        while (std::getline(file, line)) {
            stringstream ss(line);
            string name, house_id, income, house_worth, lock_level, type, type_worth, movements;

            // Read CSV columns
            getline(ss, name, ',');
            getline(ss, house_id, ',');
            getline(ss, income, ',');
            getline(ss, house_worth, ',');
            getline(ss, lock_level, ',');
            getline(ss, type, ',');
            getline(ss, type_worth, ',');
            getline(ss, movements, ',');

            cout << "Name: " << name <<  "House id: " << house_id << "Income: " << income << "house_worth: " << house_worth;  
            Person P;
            P.set(name, stoi(income), stoi(house_id), stoi(house_worth), stoi(lock_level), type, stof(type_worth));   
        }
    }

    return 0;

}

