#include <iostream>
#include "data_structures/avl_tree.h"
#include "data_structures/Graph.h"
#include "data_structures/Queue.h"
#include "data_structures/stack.h"
#include "objects/node_info.h"
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <thread>
#include <chrono>


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
    Person(const Person& other) 
    : name(other.name),
      income(other.income),
      weapon_level(other.weapon_level),
      H(other.H),
      nh(other.nh),
      movements(other.movements) {}
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
        cout << "\nMovements: ";
        this->movements.display();
        cout << endl;
    }

    void print_details()
    {
        cout << "Name: " << name <<  " House id: " << H.house_id << " Income: " << income << " house_worth: " << H.house_worth << " Movements: ";
        movements.display();
        cout << endl;
    }
    void typeTextt(const string& text, int delayMs = 1)
    {
        for (char c : text) 
        {
            cout << c << flush;
            Sleep(delayMs);
        }
    }
    void introduceNeightbour()
    {
        cout << "You approach House #" + to_string(this->H.house_id) + "...";
        cout << endl;

        // Check if the house is a regular home or a special non-home structure
        if (!name.empty()) 
        {
            // For regular houses
            if (this->H.house_id != 3 && this->H.house_id != 4 && this->H.house_id != 5) 
            {
                // Regular house
                typeTextt("This house belongs to " + name + ".");
                cout << endl;

                typeTextt("Lock Level: " + to_string(this->H.lock_level));
                cout << endl;

                typeTextt("Income: $" + to_string(income));
                cout << endl;

                typeTextt("You ring the doorbell. *Ding Dong!*");
                cout << endl;

                typeTextt(name + " greets you warmly. You have a brief chat about the neighbourhood.");
                cout << endl;


            } 
            else 
            {
                // Special case for Node 3 (Park), 4 (Office), and 5 (Market)
                if (this->H.house_id == 3)
                {
                    typeTextt("This is the Park. It's a peaceful place with trees and benches.");
                    cout << endl;
                    typeTextt("People are relaxing and enjoying the outdoor air.");
                    cout << endl;
                    typeTextt("You enjoy a brief stroll around the park, taking in the sights.");
                    cout << endl;
                }
                else if (this->H.house_id == 4)
                {
                    typeTextt("This is the Office building.");
                    cout << endl;
                    typeTextt("It looks modern with glass windows and a busy atmosphere.");
                    cout << endl;
                    typeTextt("You see employees moving in and out, working hard.");
                    cout << endl;
                }
                else if (this->H.house_id == 5)
                {
                    typeTextt("This is the Market.");
                    cout << endl;
                    typeTextt("There are vendors selling fresh produce, meats, and other goods.");
                    cout << endl;
                    typeTextt("You take a moment to browse and see the busy market life.");
                    cout << endl;
                }
            }
            
            typeTextt("Time to move on to the next house...");
            cout << endl;
            Sleep(2000); // Delay before clearing screen
            system("cls"); // Clears the screen
        } 
        else 
        {
            // If no one is home at a house
            typeTextt("It seems like no one is home at House #" + to_string(this->H.house_id) + ".");
            cout << endl;
            Sleep(2000); // Delay before clearing screen
            system("cls"); // Clears the screen
        }

    }


};

void typeText(const string& text, int delayMs = 1) 
{
    for (char c : text) 
    {
        cout << c << flush;
        Sleep(delayMs);
    }
}

void visit_neighbours(Graph& G, AVL<Person>& Tree, int startNode) 
{
    //system("cls");
    cout << endl << endl;

    typeText("Day :01 It's time to meet your neighbors. Let's begin the journey through the neighbourhood!");
    cout << endl;
    int *visited = G.BFS(startNode);

    //Tree.traverseTree();
    //cout << G.size;
    for (int i = 1; i < 10; i++)
    {
        
        Tree.getResidentInfo(visited[i]);
        Sleep(1000);
        //cout << visited[i] << " ";
    }

    system("cls");
    typeText("You have visited all your neighbors! The neighbourhood is alive and bustling with activity.");
    cout << endl;
}


void run_game(AVL<Person> Tree, Person P)
{
   system("cls");

    typeText("Day: 00 Welcome to the Neighbourhood Watch System!");
    cout << endl;
    
    typeText("Please enter your name: ");
    string name;
    cin >> name;
    typeText("Hello, " + name + "! Welcome to the neighbourhood.");
    cout << endl;
    
    typeText("You see a lovely house in the neighbourhood. Do you want to buy it? (yes/no): ");
    string decision;
    cin >> decision;
    cout << endl;

    if (decision == "yes") 
    {
        typeText("Congratulations, " + name + "! You just bought your dream house.");
        typeText("But there's a catch... that was your last penny!");
    } 
    else 
    {
        typeText("Oh no! Without a house, you can't stay in the neighbourhood. Game over.");
        return;
    }
    cout << endl;
    typeText("With no money left, you need to find a way to make some cash.");
    cout << endl;
    typeText("The only option is... stealing! But beware of the police.");
    cout << endl;
    typeText("As you steal, you can upgrade your equipment to take on bigger heists.");
    cout << endl;
    typeText("The police are always on the lookout. To succeed, you need to evade their eyes.");
    cout << endl;
    typeText("If caught, you'll have to find the shortest path to escape them.");
    cout << endl;
    typeText("Are you ready to begin your journey, " + name + "? Stay sharp and good luck!");
    cout << endl;

     P.set(name, 100.0, 1, 8, 100.0, 1);
    Tree.insert(P, P.H.house_id);
    

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

        }
    }
    
    Person P;
    run_game(Tree, P);
    P.set("Qasim", 100.0, 1, 8, 100.0, 1);
    P.movements.enqueue(8);
    P.movements.enqueue(7);
    P.movements.enqueue(3);
    
    Person market;
    market.set("Market", 0.0, 0, 5, 5000.0, 3, "Market", 5000.0);
    Tree.insert(market, market.H.house_id);

    Person office;
    office.set("Office", 0.0, 0, 4, 10000.0, 4, "Office", 10000.0);
    Tree.insert(office, office.H.house_id); // Insert into AVL Tree

    Person park;
    park.set("Park", 0.0, 0, 3, 0.0, 1, "Park", 0.0);
    Tree.insert(park, park.H.house_id); 


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
    visit_neighbours(G, Tree, 8);    
}