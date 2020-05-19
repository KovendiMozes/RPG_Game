#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "item.h"


typedef struct Character{
    char* name;
    char* intensity;
    int level;
}Character;


Character* CreateCharacter(char* heroName, char* heroIntensity);
void heroRegistration(char* heroName, char* intensity);
void levelUp(Character* myHero, int numberOfSpeach, int numberOfKillMonster);
void specialEvents(char* id, char* newId, Character* myHero);

#endif // CHARACTER_H_INCLUDED
