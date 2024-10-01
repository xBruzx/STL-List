// TODO: INCLUDE LIBRARIES
#include "Character.h"


void printMenu(); 

// TODO: CREATE FUNCTION PROTOTYPES
void loadCharacters(string fileName, list<Character>* characterList);
void addCharacter(list<Character>* ll);

int main() { 
    // TODO: create our list object, specifying it handles Character objects.
    list<Character>* characterList = new list<Character>();

    // TODO: create two iterators
    list<Character>::iterator it1, it2; //Creating my two itterators. it1 is to start the list and it2 is to end the list.


    // input integer for our switch statement
    int choice = 0; 

    // TODO: load characters from file
    loadCharacters("threecharacters.txt", characterList);

    // TODO: set traversal iterator to the beginning 
    // set end "flag" iterator to end and decrement. 
    

    it1 = characterList->begin();
    it2 = characterList->end();

    // TODO: WHILE LOOP  & Switch Case
    // print current character 
    cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
    // take input
    // switch case for input 
   while (choice != 5) {
    printMenu();

    cin >> choice;

    switch(choice) {

        case 1:
        //First if statement to begin the list.
            if (it1 != it2) {
            it1++;
            cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
        }
        //If statement for the end of the list.
        if (it1 == it2) {
            cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
            cout << "This is the last character in the list." << endl; //If the user is at the end of the list they will get this warning since they are about to go out of the list.
        }
        if (it1 == characterList->end()) {
            it1 = characterList->begin();
        }
            break;
        case 2:
        if (it1 != characterList->begin()) {
            it1--;
            cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
        }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
    }
   }
   // case 1 : next character 
   // case 2 : prev character 
   // case 3 : add character 
   // case 4 : delete character
   // case 5 : exit program 

    delete characterList;

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

void loadCharacters(string fileName, list<Character>* characterList) {
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
        characterList->push_back(playerFromFile);
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