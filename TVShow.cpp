#include "TVShow.h"
#include <iostream>
#include <cstring>




void TVShow::displayCharacters() const {
    Character* current = characters;
    while (current) {
        std::cout << " - Name: " << current->name
                  << ", Age: " << current->age
                  << ", Special Ability: " << current->specialAbility << std::endl;
        current = current->next;
    }
}

void TVShow::addCharacter(const char* characterName, int age, const char* ability) {
    Character* newCharacter = new Character(characterName, ability, age);
    newCharacter->next = characters;
    characters = newCharacter;
}

TVShow::TVShow(const char* tvShowName) {
    showName = new char[strlen(tvShowName) + 1];
    strcpy(showName, tvShowName);
    characters = nullptr;
    next = nullptr;
}

TVShow::~TVShow() {
    delete[] showName;
    while (characters) {
        Character* temp = characters;
        characters = characters->next;
        delete temp;
    }
}

void TVShow::updateCharacter(const char* characterName) {
    Character* current = findCharacter(characterName);
    if (current) {
        int newAge;
        char newAbility[100];

        std::cout << "Enter new age: ";
        std::cin >> newAge;
        std::cin.ignore();

        std::cout << "Enter new special ability: ";
        std::cin.getline(newAbility, 100);

        current->age = newAge;
        delete[] current->specialAbility;
        current->specialAbility = new char[strlen(newAbility) + 1];
        strcpy(current->specialAbility, newAbility);

        std::cout << "Character details have been updated successfully!\n";

    } else {
        std::cout << "Sorry, the character could not be found.\n";

    }
}

void TVShow::deleteCharacter(const char* characterName) {
    Character* current = characters;
    Character* prev = nullptr;

    while (current && strcmp(current->name, characterName) != 0) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            characters = current->next;
        }
        delete current;
        std::cout << "Character has been successfully deleted.\n";

    } else {
        std::cout << "No character found with that name to delete.\n";

    }
}

Character* TVShow::findCharacter(const char* characterName) const {
    Character* current = characters;
    while (current) {
        if (strcmp(current->name, characterName) == 0) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
