/*********************
Name: Julian Cotto
Assignment 7 - Hash Tables
Purpose: source file for linkedlist.h
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize - 2] = ids[testdatasize - 3];
    strs[testdatasize - 2] = "known duplicate";
    ids[testdatasize - 1] = -1;
    strs[testdatasize - 1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;


    HashTable hashTable;
    cout << "HashTable created\n" << endl;
    // Show it is empty by calling getCount and printTable
    cout << "Initial count: " << hashTable.getCount() << endl;
    cout << "Initial table: \n" << endl;
    hashTable.printTable();

    cout << endl;
    // Try and put ALL the test data into the table and show what happens
    for (int i = 0; i < testdatasize; i++) {
        bool result = hashTable.insertEntry(ids[i], &strs[i]);
        cout << "Inserting entry with id " << ids[i] << " and data " << strs[i] << ": "
             << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after inserting test data: " << hashTable.getCount() << endl;
    cout << "Table after inserting test data:\n" << endl;
    hashTable.printTable();


    // Test getData function
    cout << "\nRetrieving test data..." << endl;
    for (int i = 0; i < testdatasize - 2; i++) {
        string data = hashTable.getData(ids[i]);
        cout << "Retrieving data for id " << ids[i] << ": " << data << "" << endl;
        if (data == strs[i]) {
            cout << "Data for id " << ids[i] << " is correct: " << data << "" << endl;
        } else {
            cout << "Data for id " << ids[i] << " is incorrect: expected " << strs[i] << ", got " << data << endl;
        }
    }

    // Test removeEntry function
    cout << "\nRemoving test data..." << endl;
    for (int i = 0; i < testdatasize - 2; i++) {
        bool result = hashTable.removeEntry(ids[i]);
        cout << "Removing entry with id " << ids[i] << ": " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after removing test data: " << hashTable.getCount() << endl;
    cout << "Table after removing test data: \n" << endl;
    hashTable.printTable();

    // Test inserting entries with duplicate data but unique ids
    cout << "\nInserting test data with duplicate data but unique ids..." << endl;
    for (int i = 0; i <= testdatasize - 2; i++) {
        bool result = hashTable.insertEntry(ids[i], &strs[i]);
        cout << "Inserting entry with id " << ids[i] << " and data \"" << strs[1] << "\": "
             << (result ? "success" : "failure") << endl;
    }

    // Test inserting an entry with an id of 0
    cout << "\nInserting entry with id 0 and data \"zero id\"..." << endl;
    bool result3 = hashTable.insertEntry(0, new string("zero id"));
    cout << "Inserting entry with id 0 and data \"zero id\": " << (result3 ? "success" : "failure") << endl;

    // Test inserting an entry with an empty data string
    cout << "\nInserting entry with id 3 and empty data..." << endl;
    bool result4 = hashTable.insertEntry(3, new string(""));
    cout << "Inserting entry with id 3 and empty data: " << (result4 ? "success" : "failure") << endl;

    // Test removing an entry that does not exist
    cout << "\nRemoving entry with id 999..." << endl;
    bool result5 = hashTable.removeEntry(999);
    cout << "Removing entry with id 999: " << (result5 ? "success" : "failure") << endl;

    // Test retrieving data for an id that does not exist
    cout << "\nRetrieving data for id 999..." << endl;
    string data = hashTable.getData(999);
    cout << "Data for id 999: \"" << data << "\"" << endl;

    // Test inserting more entries than the size of the table
    cout << "\nInserting more entries than table size..." << endl;
    for (int i = 1; i <= HASHTABLESIZE * OFFSET; i++) {
        int j = rand() % MAXID + 1;
        bool result = hashTable.insertEntry(i, new string("data_" + std::to_string(j)));
        cout << "Inserting entry with id " << i << " and data \"data" << i << "\": "
             << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after inserting more entries than table size: " << hashTable.getCount() << endl;
    cout << "Table after inserting more entries than table size: \n" << endl;
    hashTable.printTable();



    // Test removing all entries from the table
    cout << "\nRemoving all entries..." << endl;
    int counter = 0;
    for (int i = 1; i <= HASHTABLESIZE * OFFSET; i++) {
        bool result = hashTable.removeEntry(i);
        cout << "Removing entry with id " << i << ": " << (result ? "success" : "failure") << endl;
        counter++;
    }
    cout << counter << " entries removed.\n";
    cout << "\nCount after removing all entries: " << hashTable.getCount() << endl;
    cout << "Table after removing all entries: \n" << endl;
    hashTable.printTable();

    // Test inserting entries with negative ids
    cout << "\nInserting entries with negative ids..." << endl;
    for (int i = -1; i >= -5; i--) {
        bool result = hashTable.insertEntry(i, new string("data" + std::to_string(i)));
        cout << "Inserting entry with id " << i << " and data \"data" << i << "\": " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after inserting entries with negative ids: " << hashTable.getCount() << endl;
    cout << "Table after inserting entries with negative ids: \n" << endl;
    hashTable.printTable();

    // Test inserting entries with empty data strings
    cout << "\nInserting entries with empty data strings..." << endl;
    for (int i = 1; i <= 5; i++) {
        bool result = hashTable.insertEntry(i, new string(""));
        cout << "Inserting entry with id " << i << " and empty data: " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after inserting entries with empty data strings: " << hashTable.getCount() << endl;
    cout << "Table after inserting entries with empty data strings: \n" << endl;
    hashTable.printTable();

    // Test inserting entries with large ids
    cout << "\nInserting entries with large ids..." << endl;
    for (int i = 1000; i <= 1100; i++) {
        int j = rand() % MAXID + 1;
        bool result = hashTable.insertEntry(i, new string("data_" + std::to_string(j)));
        cout << "Inserting entry with id " << i << " and data \"data" << i << "\": " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after inserting entries with large ids: " << hashTable.getCount() << endl;
    cout << "Table after inserting entries with large ids: \n" << endl;
    hashTable.printTable();

    cout << "\nRemoving all entries..." << endl;
    counter = 0;
    for (int i = 1000; i <= 1100; i++) {
        bool result = hashTable.removeEntry(i);
        cout << "Removing entry with id " << i << ": " << (result ? "success" : "failure") << endl;
        counter++;
    }
    cout << counter << " entries removed.\n";
    cout << "\nCount after removing all entries: " << hashTable.getCount() << endl;
    cout << "Table after removing all entries: \n" << endl;
    hashTable.printTable();

    // Test removing entries that do not exist
    cout << "\nRemoving entries that do not exist..." << endl;
    for (int i = 1000; i <= 1005; i++) {
        bool result = hashTable.removeEntry(i);
        cout << "Removing entry with id " << i << ": " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after removing entries that do not exist: " << hashTable.getCount() << endl;
    cout << "Table after removing entries that do not exist: \n" << endl;
    hashTable.printTable();

    // Test inserting entries with the same id but different data
    cout << "\nInserting entries with the same id but different data..." << endl;
    bool result6 = hashTable.insertEntry(1, new string("data1"));
    bool result7 = hashTable.insertEntry(1, new string("data2"));
    cout << "Inserting entry with id 1 and data \"data1\": " << (result6 ? "success" : "failure") << endl;
    cout << "Inserting entry with id 1 and data \"data2\": " << (result7 ? "success" : "failure") << endl;

    // Test inserting entries with the same data but different ids
    cout << "\nInserting entries with the same data but different ids..." << endl;
    bool result8 = hashTable.insertEntry(2, new string("duplicate data"));
    bool result9 = hashTable.insertEntry(3, new string("duplicate data"));
    cout << "Inserting entry with id 2 and data \"duplicate data\": " << (result8 ? "success" : "failure") << endl;
    cout << "Inserting entry with id 3 and data \"duplicate data\": " << (result9 ? "success" : "failure") << endl;

    // empty table
    for (int i = 1; i <= HASHTABLESIZE + 1; i++) {
        bool result = hashTable.removeEntry(i);
        cout << "Removing entry with id " << i << ": " << (result ? "success" : "failure") << endl;
    }
    cout << "\nCount after removing all entries: " << hashTable.getCount() << endl;
    cout << "Table after removing all entries: \n" << endl;
    hashTable.printTable();

    cout << "\nTesting Complete\n" << endl;

    return 0;
}
