#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "item.h"
#include "character.h"


Item* Create(){
    Item* item = (Item*)calloc(1,sizeof(Item));

    item->id = (char*)calloc(9999,sizeof(char));

    item->parentId = (char*)calloc(999999,sizeof(char));

    item->content = (char*)calloc(999999,sizeof(char));

    return item;
}


void PrintItem(Item* item){
    printf("%s\n", item->id);
    printf("%s\n", item->parentId);
    printf("%s\n", item->content);
}
