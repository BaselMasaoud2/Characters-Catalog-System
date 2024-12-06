#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
public:
    char* name;
    char* specialAbility;
    int age;
    Character* next;
    Character(const char* characterName, const char* ability, int characterAge);
    ~Character();
};

#endif
