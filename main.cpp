

// TODO: INCLUDE LIBRARIES
#include "Character.h"


void printMenu(); 

// TODO: CREATE FUNCTION PROTOTYPES
void loadCharacter(string fileName, list<Character>*);
void addCharacter(list<Character>* ll);

int main() { 

    // TODO: create our list object, specifying it handles Character objects.
    list<Character>* characterList; //Character list object.

    // TODO: create two iterators
    list<int> it1, it2; //Creating my two itterators. it1 is to start the list and it2 is to end the list.


    // input integer for our switch statement
    int choice = 0; 

    // TODO: load characters from file
    loadCharacter("threecharacters.txt", characterList);

    // TODO: set traversal iterator to the beginning 
    // set end "flag" iterator to end and decrement. 

    // TODO: WHILE LOOP  & Switch Case
    // print current character 
    // take input
    // switch case for input 
   
   // case 1 : next character 
   // case 2 : prev character 
   // case 3 : add character 
   // case 4 : delete character
   // case 5 : exit program 

        

    return 0;
}

void printMenu() { 
    cout << "1. Next Character" << endl;
    cout << "2. Previous Character" << endl;
    cout << "3. Add Character" << endl; 
    cout << "4. Delete Current Character" << endl; 
    cout << "5. Exit Program" << endl; 
}

// TODO: MAKE YOUR FUNCTIONS GOOBER - NOT GOOBER! >:(

void loadCharacters(string fileName, list<Character>* list) {
    //If statement to check and make sure that the file exists.
    ifstream file(fileName);
    if(!file.is_open()) {
        cout << "Error! File not found. Try another file name." << endl;
    }
    else {
        cout << fileName << " is open!" << endl; //file opened successfully.
    }
    string playerName, playerClass, playerRace;
    //While loop to read each line of the file and store name, class, and race respectivly and not include the # character as a seperator.
    while (getline(file, playerName, '#') && getline(file, playerClass, '#') && getline(file, playerRace, '#')) {
        Character playerFromFile(playerName, playerClass, playerRace);
        list->push_back(playerFromFile);
    }
    file.close(); //Never forget to close the file after you are done!
}

void addCharacter(list<Character>* ll) {
    string playerName, playerClass, playerRace; //Variables for a new player character.

    cout << "Character name: " << endl;
    getline(cin, playerName, '#');
    cout << "Character Class: " << endl;
    getline(cin, playerClass, '#');
    cout << "Character Race: " << endl;
    getline(cin, playerRace, '#');

    Character newCharacter(playerName, playerClass, playerRace); //New character object to be appended to the linked list.

    ll->push_back(newCharacter); //Adds new character to the end of the list.
}