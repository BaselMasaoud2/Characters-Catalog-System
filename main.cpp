#include "ShowCatalogSystem.h"
#include <iostream>

int main() {
    std::cout << "Inside the main...\n";
    ShowCatalogSystem catalog;
    std::cout << "Loading data from file...\n"; 
    catalog.loadData("characters.txt");
    catalog.menu();
    std::cout << "Starting menu...\n"; 
    return 0;
}
