#ifndef SHOWCATALOGSYSTEM_H
#define SHOWCATALOGSYSTEM_H
#include "TVShow.h"


class ShowCatalogSystem {
private:
    TVShow* head;

public:
    ShowCatalogSystem();
    ~ShowCatalogSystem();
    void addCharacter(const char* showName, const char* characterName, int age, const char* ability);
    void updateCharacter(const char* characterName);
    void searchCharacter(const char* characterName) const;
    void deleteCharacter(const char* characterName);
    void displayAll() const;
    void loadData(const char* filename);
    void menu();
};

#endif
