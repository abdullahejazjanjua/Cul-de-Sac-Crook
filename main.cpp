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
public:
int house_id; 
int lock_level;
float house_worth;
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
public:
    string type;
    float worth;
    float lock_level;
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
public:
    string name;
    float income;
    int weapon_level;
    house H;
    Non_Home nh;
    Queue<int> movements;
    Person() {}
    void set(string name, float income,int weapon_level=0, int house_id=0, float house_worth=0.0, int lock_level=0, string type="none", float worth=0.0)
    {
        this->income = income;
        this->name = name;
        this->weapon_level = weapon_level;
        this->H.set(house_id, lock_level, house_worth);
        this->nh.set(type, worth, lock_level);
    }

    void display()
    {
        cout << endl;
        cout << "Name: " << this->name;
        cout << "\nHouse ID: " << this->H.house_id;
        cout << "\nMovements: ";
        this->movements.display();
        cout << endl;
    }
};

void make_graph(){
    Graph G(10);
    G.addEdge(1,7);
    G.addEdge(7,6);
    G.addEdge(7,4);
    G.addEdge(7,6);
    G.addEdge(7,8);
    G.addEdge(8,0);
    G.addEdge(0,2);
    G.addEdge(2,3);
    G.addEdge(2,9);
    G.addEdge(9,6);
    G.addEdge(3,6);
    G.addEdge(3,4);
    G.addEdge(2,5);
    G.printGraph();
}


int main()
{

    ifstream file("residents.csv");
    string line;
    AVL<Person> Tree;

    if(!file.is_open())
    {
        return 1;
    }
    else
    {
        // Skip header
        getline(file, line);

        while (getline(file, line)) 
        {
            stringstream ss(line);
            string name, house_id, income, house_worth, lock_level, type, type_worth, m;

            // Read CSV columns
            getline(ss, name, ',');
            getline(ss, house_id, ',');
            getline(ss, income, ',');
            getline(ss, house_worth, ',');
            getline(ss, lock_level, ',');
            getline(ss, type, ',');
            getline(ss, type_worth, ',');
            getline(ss, m, ',');

            stringstream s(m);
            string loc01, loc02, loc03;
            getline(s, loc01, ' ');
            getline(s, loc02, ' ');
            getline(s, loc03, ' ');


            Person P;
            P.set(name, stof(income) ,0, stoi(house_id) , stof(house_worth), stoi(lock_level), type, stof(type_worth));
            P.movements.enqueue(stoi(loc01));
            P.movements.enqueue(stoi(loc02));
            P.movements.enqueue(stoi(loc03));

            Tree.insert(P, P.H.house_id);
            P.display();

        }
    }
    Tree.traverseTree();

}