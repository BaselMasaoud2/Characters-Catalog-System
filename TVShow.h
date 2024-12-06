#ifndef TVSHOW_H
#define TVSHOW_H

#include "Character.h"

class TVShow {
public:
    char* showName;
    Character* characters;
    TVShow* next;
    TVShow(const char* tvShowName);
    ~TVShow();
    void displayCharacters() const;
    void addCharacter(const char* characterName, int age, const char* ability);
    void updateCharacter(const char* characterName);
    void deleteCharacter(const char* characterName);
    Character* findCharacter(const char* characterName) const;
};

#endif
