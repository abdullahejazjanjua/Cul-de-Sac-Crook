#include <iostream>
#include <data_structures/avl_tree.h>
#include <data_structures/Graph.h>
#include <data_structures/Queue.h>
#include <data_structures/stack.h>
#include <objects/node_info.h>


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
        void set(string name, float income, int weapon_level=0, int house_id, float house_worth, int lock_level, string type="none", float worth=0.0)
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
    // Read data into a 
}