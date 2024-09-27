#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std; 

class Character {
    public:
    string name;
    string characterClass;
    string race;

    Character() : name(""), characterClass(""), race("") {}
    Character(string name, string characterClass, string race) : name(name), characterClass(characterClass), race(race) {}

    //Getters
    string getName() {return name;}
    string getClass() {return characterClass;}
    string getRace() {return race;}

    //Setters
    void setName(string name) {name;}
    void setCharacterClass(string characterClass) {characterClass;}
    void setRace(string race) {race;}

};



#endif