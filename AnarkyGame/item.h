#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "character.h"


typedef struct Item{
    char* id;
    char* parentId;
    char* content;
}Item;

Item* Create();
void PrintItem(Item* item);


#endif // ITEM_H_INCLUDED
