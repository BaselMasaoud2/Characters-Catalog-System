#include "Character.h"
#include <cstring>



Character::Character(const char* characterName, const char* ability, int characterAge) {
    name = new char[strlen(characterName) + 1];
    strcpy(name, characterName);
    specialAbility = new char[strlen(ability) + 1];
    strcpy(specialAbility, ability);
    age = characterAge;
    next = nullptr;
}
Character::~Character() {
    delete[] name;
    delete[] specialAbility;
}
