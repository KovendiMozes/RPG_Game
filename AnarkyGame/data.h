#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "item.h"
#include "character.h"


typedef struct Data{
    Item** data;
    int numberOfItem;
}Data;

Data* CreateData(int numberItem);
Data* readData(int numberItem);
void PrintData(Data* data);

// inGame
int searchIdFromParentId(char* newId, Data* test);

void gameStory(int numberId, Data* data, char* newId);

void computerStep(char* id, Data* data, char* myHeroIntensity, int myHeroLevel);

int splitAndSearchParentId(char* parentId, char* newId);

char* lastCharacterCutBackMove(char* id);

void specialCases(char* id);

void inGame(Data* data);


#endif // DATA_H_INCLUDED
