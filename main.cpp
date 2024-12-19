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
#include <random>   // For random number generation
#include <ctime>
#include <conio.h> // For _kbhit() and _getch()
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

struct diary_entry
{
    int house_id;
    string name;
    int house_lock_level;

    void print()
    {
        cout << "House id  " << house_id << " belongs to " << name << " and has lock level is " << house_lock_level;
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
    void typeTextt(const string& text, int delayMs = 0)
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

        if (!name.empty()) 
        {

            if (this->H.house_id != 3 && this->H.house_id != 4 && this->H.house_id != 5) 
            {
        
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
            Sleep(2000); 
            system("cls"); 
        } 
        else 
        {
            typeTextt("It seems like no one is home at House #" + to_string(this->H.house_id) + ".");
            cout << endl;
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

void typeText(const string& text, int delayMs = 0) 
{
    for (char c : text) 
    {
        cout << c << flush;
        Sleep(delayMs);
    }
}

void visit_neighbours(Graph& G, AVL<Person>& Tree, int startNode) 
{
    cout << endl << endl;

    typeText("Day :01 It's time to meet your neighbors. Let's begin the journey through the neighbourhood!");
    cout << endl;
    int *visited = G.BFS(startNode);

    for (int i = 1; i < 10; i++)
    {
        
        Tree.getResidentInfo(visited[i]);
        Sleep(1000);

    }

    system("cls");
    typeText("You have visited all your neighbors! The neighbourhood is alive and bustling with activity.");
    cout << endl;
}


void run_game(AVL<Person> Tree, Person &Player)
{
   system("cls");

    typeText("Day: 01 Welcome to the Neighbourhood Watch System!");
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


    Player.set(name, 100.0, 1, 8, 100.0, 1);
    // TODO: Make this better
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
        //cout << level;
        
        alert.push(level);
        cout << "\nYou stole: " << loot;
        cout << "\nLevel is: " << level;
        Player.weapon_level += level;   
        cout << "\nWeapon Level is: " << Player.weapon_level;
        Sleep(10000);
}


Queue<int> Move_player(Graph &G, AVL<Person> T, Person &Player, Stack<int> &alert)
{
    Sleep(1000);
    system("cls");
    typeText("Day: 03 - The time has come... The streets are empty, a blanket of silence drapes over the neighbourhood. The air is cold, but tonight you can feel the heat of opportunity.");
    cout << endl;

    int choice;
    // Input validation for house selection
    while (true)
    {
        typeText("You stand at the edge of the street, scanning the rows of dark houses.\nWhich house will you target? Choose wisely, for fortune favors the bold... ");
        cout << endl;
        cin >> choice;
        if (choice == 4)
        {
            typeText("What thief steals his own house? This much greed is not good! Try again");
            cout << endl;
        }
        else if (choice >= 0 && choice < 10)  
            break;
        else
            cerr << "Invalid house choice. Please select a valid house (0-9)." << endl;
    }

    Queue<int> q; // This will store the player's movements/choices as a path

    typeText("\nYou take one last look around before slipping into the shadows. The plan is simple, but execution is everything.");
    cout << endl;

    // Let's run DFS to determine the movement path
        
    int *movement = G.DFS(8);  // Assume 8 is the starting point; you might want to dynamically adjust this based on player state
    typeText("Step by step, you move cautiously. The pavement beneath your feet carries your ambition, but danger lingers at every corner.");
    cout << endl;

    // Enqueue the DFS path into the queue
    bool found = false;
    for (int i = 0; i < G.size; i++)
    {
        if (movement[i] == choice)  // Check if the movement path contains the player's chosen house
        {
            typeText("There it is... House #" + to_string(choice) + ". The lights are off, the windows dark. It's as if the house itself is holding its breath, waiting for your arrival.");
            cout << endl;
            found = true;
            q.enqueue(movement[i]);
            break;
        }
        q.enqueue(movement[i]);  // Enqueue the nodes from the DFS path
    }

    if (!found)
    {
        typeText("Your chosen house is not reachable through the available path. Something went wrong.");
        cout << endl;
        return q;  
    }

    typeText("You crouch behind a bush, eyes fixed on the house. You gather yourself, the calm before the storm.");
    cout << endl;

    Node_tree<Person>* person = T.getResidentInfo(choice, true);
    if (person == nullptr)
    {
        typeText("\nYour heart skips a beat. This house... it doesn't exist. A trick of the mind or a ghost on the map?\n");
        system("cls");
        return q;  // Returning the current path
    }

    cout << "\nYou check your notes. This house belongs to **" << person->obj.name << "**.";
    cout << "\nIts value is high—there's no room for mistakes tonight.";
    cout << endl;

    // Loop to ask for the choice again if weapon level is not sufficient
    while (true)
    {
        // Check if the player can steal the house
        if (Player.weapon_level >= person->obj.H.lock_level)
        {
            cout << "You can steal this house as your weapon level is " << Player.weapon_level << " and the house lock level is " << person->obj.H.lock_level;
            typeText("\nA sly grin crosses your face. You pull out the tools of your trade, each one a testament to your skills. Time bends as you work, every second ticking louder in your mind.");
            cout << endl;
            typeText("Hours seem to pass in a heartbeat. You map out the house's layout, avoid the creaks in the floorboards, and dance through shadows like a phantom.");
            cout << endl;
            typeText("Finally... success. You slip out, unseen and unheard. The house stands still, oblivious to your quiet triumph.");
            typeText("\nThe night grows deeper. You exhale, clutching your prize, as you fade back into the darkness, ready to plan your next move.");
            cout << endl;

            // Call the steal function here to apply the loot and alert levels
            steal(Player, choice, alert, person);
            break;  // Exit the loop after stealing
        }
        else
        {
            // If the player cannot steal, inform them and ask again
            cout << "You can't steal this house. Your level is " << Player.weapon_level << ", while the house lock level is " << person->obj.H.lock_level;
            cout << "\nThis is your diary: \n";
            Player.diary.display();

            string retry_choice;
            cout << "\nDo you want to try another house? (yes/no): ";
            cin >> retry_choice;
            
            if (retry_choice == "no")
            {
                typeText("\nYou take one last look at the house, the prize within tempting you to change your mind... but not tonight. You disappear into the night, leaving the house untouched.");
                cout << endl;
                break;  // Exit the loop if player decides not to retry
            }
            else
            {
                // If the player chooses to retry, break out of the loop and ask for a new house
                break;
            }
        }
    }
    return q;  // Return the final movement path
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

int randomInt(int min, int max) {

    return rand() % (max - min + 1) + min;
}

void end_game(AVL<Person> &Tree, Person &Player) 
{
    system("cls");
    srand(static_cast<unsigned int>(time(0)));

    typeText("Oops, seems like the police is after you. You will have to run now. Hurry, decide quickly!");

    int numKeyPresses = randomInt(3, 5);
    bool gameOver = false;

    for (int i = 0; i < numKeyPresses; ++i) {
        system("cls");
        
        // Generate a random key to be pressed
        char randomKey = static_cast<char>(randomInt(97, 122)); 
        
        int timeLimit = 1;  

        typeText("Press the key: **" + std::string(1, randomKey) + "** within " + std::to_string(timeLimit) + " seconds!");

        auto start_time = std::chrono::steady_clock::now();
        bool keyPressed = false;

        // Start the countdown timer
        while (chrono::steady_clock::now() - start_time < chrono::seconds(timeLimit)) 
        {
            auto elapsed = std::chrono::steady_clock::now() - start_time;
            auto remainingTime = timeLimit - chrono::duration_cast<std::chrono::seconds>(elapsed).count();
            
            // Print the remaining time, overwrite previous time left message using carriage return
            std::cout << "Time left: " << remainingTime << " seconds" << std::flush;

            // Move the cursor back to the beginning of the line (to overwrite the time left)
            std::cout << "\r" << std::flush << endl;

            // Wait for a short period before checking the time again
            //std::this_thread::sleep_for(std::chrono::seconds(1));
            Sleep(1000);

            // Check for user key press
            if (_kbhit()) {  
                char key = _getch();  
                if (key == randomKey) {
                    keyPressed = true;
                    break;  // Exit the loop once the correct key is pressed
                }
            }
        }

        // Check if the key was pressed correctly within the time limit
        if (keyPressed)
        {
            typeText("Correct! You pressed the key in time.");
        } 
        else 
        {
            typeText("You failed to press the correct key in time! The police caught you.");
            gameOver = true;
            break;  // End the game if the player fails
        }
    }

    // If the player managed to press all keys correctly
    if (!gameOver) 
    {
        typeText("Congratulations! You managed to escape the police!");
    }
}

void perform_thefts(Graph &G, AVL<Person> &Tree, Person &Player, Stack<int> &alert) 
{
    srand(time(0));  // Initialize the random seed

    // Generate a random number of thefts between 1 and 3
    int random_thefts = (rand() % 3) + 1;
    int current_thefts = 0;

    do 
    {
        Queue<int> player_path = Move_player(G, Tree, Player, alert);

        Queue<int> copy_player_path(player_path);

        bool theft_detected = compare_movement(copy_player_path, G, Tree);
        cout << "\nYour weapon level is: " << Player.weapon_level;

        if (theft_detected) 
        {
            current_thefts++;
            cout << "\nA robbery has been committed!" << endl;
            cout << "\nCurrent thefts: " << current_thefts <<  " AND random thefts is: " << random_thefts << endl;
            Sleep(1000);

        }

    } while (current_thefts < random_thefts);

    cout << endl << "Police is behind you!" << endl;
    cout << "You have done these levels of robbery: ";
    alert.sortStack();  
    alert.display(); 
}

void readLeaderBoard(HashMap &hashMap) 
{
    ifstream file("players.csv");

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << endl;
        return;
    }

    // Skip the header line
    string line;
    getline(file, line);
    //cout<<line;

    // Read each line from the CSV file
    while (getline(file, line)) 
    {
        stringstream ss(line);
        //cout<<line;
        string name, lootStr;

        // Extract the columns
        getline(ss, name, ',');
        getline(ss, lootStr, ',');

        // Convert loot string to integer
        int loot = stoi(lootStr);

        // Insert into the hashmap
        hashMap.insert(name, loot);
    }

    file.close();

}



void writeLeaderBoard(const string& name, int loot) 
{
    ofstream file("players.csv", ios::app); // Open file in append mode
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    } else {
        cout << "File opened successfully." << endl;  // Debug message
    }

    file << name << "," << loot << endl;
    file.flush();  // Force write to file
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

            Person P;
            P.set(name, stof(income) ,0, stoi(house_id) , stof(house_worth), stoi(lock_level), type, stof(type_worth));
            stringstream s(m);
            string loc;

            while (getline(s, loc, ' ')) 
            {
                P.movements.enqueue(stoi(loc)); // Convert to int and store in the vector
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
    
    /*Player.set("Qasim", 100.0, 1, 8, 100.0, 1);
    Player.movements.enqueue(8);
    Player.movements.enqueue(7);
    Player.movements.enqueue(6); 
    Player.movements.enqueue(3);
    Player.movements.enqueue(9);
    Player.movements.enqueue(2);
    Player.movements.enqueue(5);
    Player.movements.enqueue(0);
    Tree.insert(Player, Player.H.house_id);*/
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