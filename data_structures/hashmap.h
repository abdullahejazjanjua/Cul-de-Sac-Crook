#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class HashMap {
private:
    static const int SIZE = 100; // Size of the hash table
    string keys[SIZE];           // Array for keys (names)
    int values[SIZE];            // Array for values (loot levels)
    int count;                   // Number of elements in the hash table

    // Hash function to determine index for insertion
    int hashFunction(const string& key) const {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % SIZE;
    }

public:
    HashMap() : count(0) {
        for (int i = 0; i < SIZE; ++i) {
            keys[i] = "";
            values[i] = 0;
        }
    }

    // Insert key-value pair in sorted order
    void insert(const string& key, int value) {
        if (count >= SIZE) {
            cout << "HashMap is full!" << endl;
            return;
        }

        // Find appropriate position for sorted order
        int i;
        for (i = count - 1; i >= 0 && values[i] < value; --i) {
            keys[i + 1] = keys[i];
            values[i + 1] = values[i];
        }
        keys[i + 1] = key;
        values[i + 1] = value;
        ++count;
    }

    // Display all entries
    void display() const {
    cout << setw(20) << "Name" << setw(15) << "Loot" << endl;
    cout << "----------------------------" << endl;
    
    // Display the leaderboard
    for (int i = 0; i < count; ++i) {
        cout << setw(20) << keys[i] << setw(15) << values[i] << endl;
    }
}

    // Find value by key
    int find(const string& key) const {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        return -1; // Key not found
    }
};

#endif