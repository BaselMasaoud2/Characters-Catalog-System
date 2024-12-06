#include "ShowCatalogSystem.h"
#include <iostream>
#include <fstream>
#include <cstring>


ShowCatalogSystem::ShowCatalogSystem() : head(nullptr) {}
ShowCatalogSystem::~ShowCatalogSystem() {
    while (head) {
        TVShow* temp = head;
        head = head->next;
        delete temp;
    }
}

void ShowCatalogSystem::addCharacter(const char* showName, const char* characterName, int age, const char* ability) {
    TVShow* current = head;
    while (current && strcmp(current->showName, showName) != 0) {
        current = current->next;
    }
    if (!current) {
        TVShow* newShow = new TVShow(showName);
        newShow->next = head;
        head = newShow;
        current = newShow;
    }
    current->addCharacter(characterName, age, ability);
}


void ShowCatalogSystem::deleteCharacter(const char* characterName) {
    TVShow* current = head;

    while (current) {
        current->deleteCharacter(characterName);
        current = current->next;
    }
}

void ShowCatalogSystem::displayAll() const {
    TVShow* current = head;
    while (current) {
        std::cout << "\nTV Show: " << current->showName << std::endl;
        current->displayCharacters();
        current = current->next;
    }
}

void ShowCatalogSystem::searchCharacter(const char* characterName) const {
    TVShow* current = head;

    while (current) {
        Character* found = current->findCharacter(characterName);
        if (found) {
            std::cout << "\n------------------------------\n";
            std::cout << "Character found in TV Show: " << current->showName << std::endl;
            std::cout << "Character Name : " << found->name
                      << ", Age : " << found->age
                      << ", Special Ability : " << found->specialAbility << std::endl;
            return;
        }
        current = current->next;
    }

std::cout << "\n******************************\n";
std::cout << "* Character not found!*\n";
std::cout << "* Please check the name and try again. *\n";
std::cout << "******************************\n";
}

void ShowCatalogSystem::updateCharacter(const char* characterName) {
    TVShow* current = head;

    while (current) {
        current->updateCharacter(characterName);
        current = current->next;
    }
}

void ShowCatalogSystem::loadData(const char* filename) {
    std::cout << "Inside loadData...\n"; // Debugging 
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    char line[256];
    while (file.getline(line, 256)) {
        std::cout << "Processing line: " << line << std::endl;
        char* showName = strtok(line, ",");
        char* characterName = strtok(nullptr, ",");
        int age = atoi(strtok(nullptr, ","));
        char* ability = strtok(nullptr, ",");

        addCharacter(showName, characterName, age, ability);
    }

    file.close();
    std::cout << "Exiting loadData...\n"; // Debugging 
}

void ShowCatalogSystem::menu() {
    std::cout << "Entering menu...\n";
    int choice;
    do {
        std::cout << "\n*** Welcome to the Catalog System ***\n";
        std::cout << "Please choose an option from the menu :\n";
        std::cout << "1. Display All TV Shows and Characters\n";
        std::cout << "2. Add a New Character\n";
        std::cout << "3. Remove a Character\n";
        std::cout << "4. Search for a Character\n";
        std::cout << "5. Update Character Details\n";
        std::cout << "6. Exit the Program\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();                // Clear the error flag
            std::cin.ignore(1000, '\n');     // Discard invalid input
            std::cout << "\nOops! That doesn't look like a valid option.\n";
            std::cout << "Please enter a number between 1 and 6.\n";
            continue;                        // Restart the loop
        }
        std::cin.ignore(1000, '\n'); 

        switch (choice) {
            case 1:
                displayAll();
                break;
            case 2: {
                char showName[100], characterName[100], ability[100];
                int age;
                std::cout << "Please Enter TV Show Name: ";
                std::cin.getline(showName, 100);
                std::cout << "Please Enter Character Name: ";
                std::cin.getline(characterName, 100);
                std::cout << "Please Enter The Age: ";
                std::cin >> age;
                std::cin.ignore();
                std::cout << "Please Enter Special Ability: ";
                std::cin.getline(ability, 100);
                addCharacter(showName, characterName, age, ability);
                break;
            }
            case 3: {
                char characterName[100];
                std::cout << "Please Enter Character Name to delete: ";
                std::cin.getline(characterName, 100);
                deleteCharacter(characterName);
                break;
            }
            case 4: {
                char characterName[100];
                std::cout << "Let's search for a character in the catalog!\n";
                std::cout << "Enter the name of the character you're looking for: ";
                std::cin.getline(characterName, 100);
                searchCharacter(characterName);
                break;
            }
            case 5: {
                char characterName[100];
                std::cout << "Let's update a character's information!\n";
                std::cout << "Enter the character's name you wish to update: ";
                std::cin.getline(characterName, 100);
                updateCharacter(characterName);
                break;
            }
            case 6:
            std::cout << "Thank you for using the Show Catalog System.\n";
            std::cout << "Goodbye, and see you next time!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
