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
#include <random>   
#include <ctime>
#include <conio.h> 
#include <cstdlib>
#include "data_structures/hashmap.h"
#include "data_structures/linked_list.h"


class house
{
public:
int house_id; 
int lock_level;
float house_worth;
bool robbed = false;
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

void typeText(const string& text, int delayMs = 75) 
{
    for (char c : text) 
    {
        cout << c << flush;
        Sleep(delayMs);
    }
}

struct diary_entry
{
    int house_id;
    string name;
    int house_lock_level;

    void print()
    {
        string content = "Today, I made an important observation:\n";
        content += "House ID " + to_string(house_id) + " belongs to " + name + " and has a lock level of " + to_string(house_lock_level) + ".\n";
        content += "I wonder what the future holds for it...\n";
        typeText(content);
    }
};

class Person
{
public:
    string name;
    float income;
    int weapon_level = 1;
    house H;
    Non_Home nh;
    Queue<int> movements;
    LinkedList<diary_entry> diary;
    float loot = 0.0;
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
 
    void introduceNeightbour()
    {
        typeText("You approach House #" + to_string(this->H.house_id) + "...\n");
        Sleep(500);  

        if (!name.empty()) 
        {
            if (this->H.house_id != 3 && this->H.house_id != 4 && this->H.house_id != 5) 
            {
                typeText("This house belongs to " + name + ".\n");
                Sleep(500);

                typeText("Lock Level: " + to_string(this->H.lock_level) + "\n");
                Sleep(500);

                typeText("Income: $" + to_string(income) + "\n");
                Sleep(500);

                typeText("You ring the doorbell. *Ding Dong!*\n");
                Sleep(500);

                typeText(name + " greets you warmly. You have a brief chat about the neighbourhood.\n");
                Sleep(500);
            } 
            else 
            {
                if (this->H.house_id == 3)
                {
                    typeText("This is the Park. It's a peaceful place with trees and benches.\n");
                    Sleep(500);
                    typeText("People are relaxing and enjoying the outdoor air.\n");
                    Sleep(500);
                    typeText("You enjoy a brief stroll around the park, taking in the sights.\n");
                    Sleep(500);
                }
                else if (this->H.house_id == 4)
                {
                    typeText("This is the Office building.\n");
                    Sleep(500);
                    typeText("It looks modern with glass windows and a busy atmosphere.\n");
                    Sleep(500);
                    typeText("You see employees moving in and out, working hard.\n");
                    Sleep(500);
                }
                else if (this->H.house_id == 5)
                {
                    typeText("This is the Market.\n");
                    Sleep(500);
                    typeText("There are vendors selling fresh produce, meats, and other goods.\n");
                    Sleep(500);
                    typeText("You take a moment to browse and see the busy market life.\n");
                    Sleep(500);
                }
            }

            typeText("Time to move on to the next house...\n");
            Sleep(2000);
            system("cls");
        } 
        else 
        {
            typeText("It seems like no one is home at House #" + to_string(this->H.house_id) + ".\n");
            Sleep(2000);
            system("cls");
        }
    }

};

void create_diary(Graph& G, AVL<Person>& Tree, Person &Player)
{
    int *visited = G.BFS(8);

    for (int i = 1; i < 10; i++)
    {
        
       Node_tree<Person> *person =  Tree.getResidentInfo(visited[i], true);
       diary_entry d;
       d.house_id =  person->obj.H.house_id;
       d.house_lock_level =  person->obj.H.lock_level;
       d.name =  person->obj.name;

       Player.diary.AddAtTail(d);
    }
}

void visit_neighbours(Graph& G, AVL<Person>& Tree, int startNode) 
{
    typeText("Day :01 It's time to meet your neighbors. Let's begin the journey through the neighbourhood!\n");
    Sleep(1000);

    int *visited = G.BFS(startNode);

    for (int i = 1; i < 10; i++)
    {
        Tree.getResidentInfo(visited[i]);
        Sleep(1000); 
    }

    system("cls");

    typeText("You have visited all your neighbors! The neighbourhood is alive and bustling with activity.\n");
    Sleep(1000);
}


void run_game(AVL<Person> Tree, Person &Player)
{
   system("cls");

    typeText("Day: 01 Welcome to the Neighbourhood Watch System!\n");
    
    typeText("Please enter your name: ");
    string name;
    cin >> name;
    typeText("Hello, " + name + "! Welcome to the neighbourhood.\n");
    
    typeText("You see a lovely house in the neighbourhood. Do you want to buy it? (yes/no): ");
    string decision;
    cin >> decision;
    typeText("\n");

    if (decision == "yes") 
    {
        typeText("Congratulations, " + name + "! You just bought your dream house.\n");
        typeText("But there's a catch... that was your last penny!\n");
    } 
    else 
    {
        typeText("Oh no! Without a house, you can't stay in the neighbourhood. Game over.\n");
        return;
    }
    typeText("\n");
    typeText("With no money left, you need to find a way to make some cash.\n");
    typeText("\n");
    typeText("The only option is... stealing! But beware of the police.\n");
    typeText("\n");
    typeText("As you steal, you can upgrade your equipment to take on bigger heists.\n");
    typeText("\n");
    typeText("The police are always on the lookout. To succeed, you need to evade their eyes.\n");
    typeText("\n");
    typeText("If caught, you'll have to find the shortest path to escape them.\n");
    typeText("\n");
    typeText("Are you ready to begin your journey, " + name + "? Stay sharp and good luck!\n");
    typeText("\n");


    Player.set(name, 100.0, 1, 8, 100.0, 1);
    Player.movements.enqueue(8);
    Player.movements.enqueue(7);
    Player.movements.enqueue(6); 
    Player.movements.enqueue(3);
    Player.movements.enqueue(9);
    Player.movements.enqueue(2);
    Player.movements.enqueue(5);
    Player.movements.enqueue(0);
    Tree.insert(Player, Player.H.house_id);
}


void steal(Person &Player, int id, Stack<int> &alert, Node_tree<Person> *person)
{
    
        float loot = person->obj.H.house_worth * 0.5;
        Player.loot += loot;
        person->obj.H.house_worth -= loot;
        person->obj.H.robbed = true;
        int level = person->obj.H.house_worth * 0.2 + person->obj.H.lock_level + (loot/person->obj.H.house_worth * 0.8 + person->obj.H.lock_level);
        level = level % 5;
        if (level == 0)
        {
            level++;
        }        
        alert.push(level);
        Player.weapon_level += level;   
}


Queue<int> Move_player(Graph &G, AVL<Person> T, Person &Player, Stack<int> &alert, int random_thefts, int day)
{
    Sleep(1000);
    system("cls");
    if (day == 1)
    {
        typeText("The city is quiet, and the air feels dense. It's your first night in this strange place. The tension builds, but you're ready for what’s coming...\n");
    }
    else if (day == random_thefts)
    {
            typeText("The final night. The stakes are higher, and the air feels electric. You can't afford any mistakes. This is it.\n");
    }
    else if (day == 2)
    {
        typeText("Daylight fades, and the darkness creeps in. You've been around long enough to get a feel for things. Now is the time to strike.\n");
    }
    else if (day == 3)
    {
            typeText("The pressure mounts. The streets are empty, but your instincts tell you that someone is watching. Every step is calculated.\n");
    }

    int choice;
    while (true)
    {
        typeText("You stand at the edge of the street, scanning the rows of dark houses.\nWhich house will you target? Choose wisely, for fortune favors the bold... \n");
        cin >> choice;
        if (choice == 4)
        {
            typeText("What thief steals his own house? This much greed is not good! Try again\n");
        }
        else if (choice >= 0 && choice < 10)  
            break;
        else
            cerr << "Invalid house choice. Please select a valid house (0-9)." << endl;
    }

    Queue<int> q;

    typeText("\nYou take one last look around before slipping into the shadows. The plan is simple, but execution is everything.\n");

    int *movement = G.DFS(8);
    typeText("Step by step, you move cautiously. The pavement beneath your feet carries your ambition, but danger lingers at every corner.\n");

    bool found = false;
    for (int i = 0; i < G.size; i++)
    {
        if (movement[i] == choice)
        {
            typeText("There it is... House #" + to_string(choice) + ". The lights are off, the windows dark. It's as if the house itself is holding its breath, waiting for your arrival.\n");
            found = true;
            q.enqueue(movement[i]);
            break;
        }
        q.enqueue(movement[i]);
    }

    if (!found)
    {
        typeText("Your chosen house is not reachable through the available path. Something went wrong.\n");
        return q;  
    }

    typeText("You crouch behind a bush, eyes fixed on the house. You gather yourself, the calm before the storm.\n");

    Node_tree<Person>* person = T.getResidentInfo(choice, true);
    if (person == nullptr)
    {
        typeText("\nYour heart skips a beat. This house... it doesn't exist. A trick of the mind or a ghost on the map?\n");
        system("cls");
        return q;  
    }

    typeText("\nYou check your notes. This house belongs to **" + person->obj.name + "**.\n");
    typeText("\nIts value is high. There's no room for mistakes tonight.\n");

    while (true)
    {
        if (Player.weapon_level >= person->obj.H.lock_level)
        {
            typeText("You can steal this house as your weapon level is " + to_string(Player.weapon_level) + " and the house lock level is " + to_string(person->obj.H.lock_level) + "\n");
            typeText("\nA sly grin crosses your face. You pull out the tools of your trade, each one a testament to your skills. Time bends as you work, every second ticking louder in your mind.\n");
            typeText("Hours seem to pass in a heartbeat. You map out the house's layout, avoid the creaks in the floorboards, and dance through shadows like a phantom.\n");
            typeText("Finally... success. You slip out, unseen and unheard. The house stands still, oblivious to your quiet triumph.\n");
            typeText("\nThe night grows deeper. You exhale, clutching your prize, as you fade back into the darkness, ready to plan your next move.\n");

            steal(Player, choice, alert, person);
            break;
        }
        else
        {
            typeText("You can't steal this house. Your level is " + to_string(Player.weapon_level) + ", while the house lock level is " + to_string(person->obj.H.lock_level) + "\n");
            typeText("\nThis is your diary: \n");
            Player.diary.display();

            string retry_choice;
            typeText("\nDo you want to try another house? (yes/no): ");
            cin >> retry_choice;
            
            if (retry_choice == "no")
            {
                typeText("\nYou take one last look at the house, the prize within tempting you to change your mind... but not tonight. You disappear into the night, leaving the house untouched.\n");
                break;
            }
            else
            {
                break;
            }
        }
    }
    return q;  
}

bool compare_movement(Queue<int> &P, Graph &G, AVL<Person> T) 
{
    if (P.isEmpty()) 
    {
        return false;
    }

    bool house_stolen = false;
    int *route = G.BFS(8);

    for (int i = 0; i < G.size; i++)
    {

        Node_tree<Person> *stolen_house = T.getResidentInfo(route[i], true);
        if (stolen_house->obj.H.robbed)
        {
            house_stolen = true;
            break;
        }
    }

    return (house_stolen);    
}

int randomInt(int min, int max) 
{

    return rand() % (max - min + 1) + min;
}

void end_game(AVL<Person> &Tree, Person &Player) 
{
    system("cls");
    srand(static_cast<unsigned int>(time(0)));

    typeText("Oops, seems like the police is after you. You will have to run now. Hurry, decide quickly!");

    typeText("\nInstructions: You will need to press a certain key several times to escape the police. For each key press, you will be given a limited amount of time to press the correct key.");
    typeText("\nIf you fail to press it in time, the police will catch you and the game will be over.");
    typeText("\nGood luck!\n");

    int numKeyPresses = randomInt(3, 5);
    bool gameOver = false;

    for (int i = 0; i < numKeyPresses; ++i) {
        system("cls");
        
        char randomKey = static_cast<char>(randomInt(97, 122)); 
        
        int timeLimit = 1;  

        typeText("Press the key: **" + std::string(1, randomKey) + "** within " + std::to_string(timeLimit) + " seconds!", 0);

        auto start_time = std::chrono::steady_clock::now();
        bool keyPressed = false;

        while (chrono::steady_clock::now() - start_time < chrono::seconds(timeLimit)) 
        {
            auto elapsed = std::chrono::steady_clock::now() - start_time;
            auto remainingTime = timeLimit - chrono::duration_cast<std::chrono::seconds>(elapsed).count();
            
            std::cout << "Time left: " << remainingTime << " seconds" << std::flush;

            std::cout << "\r" << std::flush << endl;

            Sleep(1000);

            if (_kbhit()) {  
                char key = _getch();  
                if (key == randomKey) {
                    keyPressed = true;
                    break;
                }
            }
        }

        if (keyPressed)
        {
            typeText("Correct! You pressed the key in time.", 0);
        } 
        else 
        {
            typeText("You failed to press the correct key in time! The police caught you.", 0);
            gameOver = true;
            break;
        }
    }

    if (!gameOver) 
    {
        typeText("Congratulations! You managed to escape the police!");
    }
}

void perform_thefts(Graph &G, AVL<Person> &Tree, Person &Player, Stack<int> &alert) 
{
    srand(time(0));

    int random_thefts = (rand() % 3) + 1;
    int current_thefts = 0;
    int day = 1;

    do 
    {
        Queue<int> player_path = Move_player(G, Tree, Player, alert, random_thefts, day);

        Queue<int> copy_player_path(player_path);

        bool theft_detected = compare_movement(copy_player_path, G, Tree);
        typeText("\nYour current weapon level is: " + to_string(Player.weapon_level));
        typeText("\nYour current loot is: " + to_string(Player.loot));

        if (theft_detected) 
        {
            current_thefts++;
            typeText("\nA robbery has been committed!");
            Sleep(1500);

        }
        day++;

    } while (current_thefts < random_thefts);
    alert.sortStack();  
    alert.display(); 
}


void readLeaderBoard(HashMap &hashMap) 
{
    ifstream file("players.csv");

    if (!file.is_open()) {
        cerr << "Error: Could not open file 'players.csv'" << endl;
        return;
    }

    string line;

    getline(file, line);

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string name, lootStr;

        getline(ss, name, ',');
        getline(ss, lootStr, ',');

        try 
        {
            int loot = stoi(lootStr);
            hashMap.insert(name, loot);
        } 
        catch (const std::invalid_argument& e) 
        {
            cerr << "Error: Invalid loot value for " << name << endl;
        } 
        catch (const std::out_of_range& e) 
        {
            cerr << "Error: Loot value out of range for " << name << endl;
        }
    }

    file.close();
}

void writeLeaderBoard(const string& name, int loot) 
{
    ofstream file("players.csv", ios::app); 
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << name << "," << loot << endl;
    file.flush();  
    file.close();
}


int main()
{
    ifstream file("residents.csv");
    string line;
    AVL<Person> Tree;
    HashMap hashMap;
    readLeaderBoard(hashMap);
    hashMap.display();
    Sleep(1000);
    system("cls");

    if(!file.is_open())
    {
        return 1;
    }
    else
    {
        getline(file, line);

        while (getline(file, line)) 
        {
            stringstream ss(line);
            string name, house_id, income, house_worth, lock_level, type, type_worth, m;

            getline(ss, name, ',');
            getline(ss, house_id, ',');
            getline(ss, income, ',');
            getline(ss, house_worth, ',');
            getline(ss, lock_level, ',');
            getline(ss, type, ',');
            getline(ss, type_worth, ',');
            getline(ss, m, ',');

            Person P;
            P.set(name, stof(income) ,0, stoi(house_id) , stof(house_worth), stoi(lock_level), type, stof(type_worth));
            stringstream s(m);
            string loc;

            while (getline(s, loc, ' ')) 
            {
                P.movements.enqueue(stoi(loc)); 
            }
            Tree.insert(P, P.H.house_id);
        }
    }
    file.close();
    Person Player;
    run_game(Tree, Player);

    Person market;
    market.set("Market", 0.0, 0, 5, 5000.0, 3, "Market", 5000.0);
    Tree.insert(market, market.H.house_id);

    Person office;
    office.set("Office", 0.0, 0, 4, 10000.0, 4, "Office", 10000.0);
    Tree.insert(office, office.H.house_id);

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

    create_diary(G, Tree, Player);
    
    Stack<int> alert;
    perform_thefts(G, Tree, Player, alert);
    end_game(Tree, Player);
    hashMap.insert(Player.name, Player.loot);
    writeLeaderBoard(Player.name, Player.loot);
    cout << endl;
    hashMap.display();

    return 0;
}