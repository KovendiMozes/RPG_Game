#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "item.h"
#include "character.h"


int numberOfSpeach = 0;
int numberOfKillMonster = 0;


Data* CreateData(int numberItem){

    Data* auxData = (Data*)calloc(1,sizeof(Data));

    auxData->data = (Item**)calloc(numberItem,sizeof(Item*));

    auxData->numberOfItem = numberItem;

    for(int i = 0; i < numberItem; i++){
        auxData->data[i] = Create();
    }

    return auxData;
}


Data* readData(int numberItem){
    FILE* f = fopen("be.txt", "rt");

    Data* auxData;
    auxData = CreateData(numberItem);

    for(int i = 0; i < auxData->numberOfItem; ++i){
        fscanf(f, "%s\n", auxData->data[i]->id);
        fscanf(f, "%[^\n]\n", auxData->data[i]->parentId);
        fscanf(f, "%[^\n]s", auxData->data[i]->content);
    }

    return auxData;
}


void PrintData(Data* data){
    for(int i = 0; i < data->numberOfItem; i++){
        PrintItem(data->data[i]);
    }
}

int searchIdFromParentId(char* newId, Data* test){
    int result;
    for(int i = 0; i < test->numberOfItem; i++){
        result = splitAndSearchParentId(test->data[i]->id, newId);
        if(result == 1){
            return i;
        }
    }
    return NULL;
}

void gameStory(int numberId, Data* data, char* newId){
    char scanId[100] = "";
    printf("\n%s - %s\nValaszon es irja be a betut: ",data->data[numberId]->id , data->data[numberId]->content);
    scanf("%s", &scanId);
    strcpy(newId, scanId);
    if(strlen(newId) > 1){
        printf("\n Tobb karaktert irtal. Valasz ujra.\n");
        strcpy(newId, "");
        gameStory(numberId, data, newId);
    }
}

void computerStep(char* id, Data* data, char* myHeroIntensity, int myHeroLevel){
    char cId[100];
    int countCId;

    int numberId;

    srand(time(0));

    int randNumber = rand()%10;
    int randNumberHero = rand()%10;
    int cNumber = 0, wNumber = 0;
    int levelNumber = (myHeroLevel*5)/10;

    if(strcmp(myHeroIntensity,"Kommunikacio") == 0){
        cNumber = randNumber + randNumberHero + levelNumber;
    }
    else if(strcmp(myHeroIntensity,"Harcos") == 0){
        wNumber = randNumber + randNumberHero + levelNumber;
    }

    //printf("%i\n", myHero->level);

    FILE* f = fopen("computer.txt", "rt");
    fscanf(f, "%i", &countCId);

    for(int i = 0; i < countCId; i++){
        fscanf(f, "%s\n", &cId);
        if(strcmp(id, cId) == 0){
            if(strcmp(myHeroIntensity,"Kommunikacio") == 0 && cNumber >= 10 && wNumber == 0 || strcmp(myHeroIntensity,"Harcos") == 0 && wNumber >= 10 && cNumber == 0){
                numberOfSpeach++;
                strcat(id, "a");
                numberId = searchIdFromParentId(id, data);
                printf("\n%s - %s\nValaszon es irja be a betut: ",data->data[numberId]->id , data->data[numberId]->content);
                // ide bejon egy olyan par eset amikor tovabb mehet
                lastCharacterCutBackMove(id);
                break;
            }
            else{
                strcat(id, "b");
                numberId = searchIdFromParentId(id, data);
                printf("\n%s - %s\nValaszon es irja be a betut: ",data->data[numberId]->id , data->data[numberId]->content);
                // ide bejon egy olyan par eset amikor tovabb mehet
                lastCharacterCutBackMove(id);
                break;
            }
        }
    }
}


int splitAndSearchParentId(char* parentId, char* newId){
    int str_size = strlen(parentId);
    char delim[] = " ";

    char* ptr = strtok(parentId, delim);

    while(ptr != NULL){
        int result;
        result = strcmp(ptr, newId);
        if(result == 0){
            return 1;
        }
        ptr = strtok(NULL, delim);
    }
    return 0;
}


char* lastCharacterCutBackMove(char* id){
    int i = 0;
    while(id[i] != '\0'){
        i++;
    }
    id[i-1] = '\0';
    return id;
}



void specialCases(char* id){
    if(strcmp(id, "1aaaa") == 0){
        strcpy(id, "1a");
    }
    if(strcmp(id, "1bb") == 0){
        strcpy(id, "1b");
    }
}


void inGame(Data* data){

    char heroName[100] = "", intensity[100] = "";
    heroRegistration(heroName, intensity);
    Character* myHero = CreateCharacter(heroName, intensity);


    char id[1000] = "1";
    int first = 0;
    while(1){
        int numberId, answer;
        char newId[1000] = "";

        int numberIdOld = numberId;
        //valtozo numberId regi
        numberId = searchIdFromParentId(id, data);

        if(numberId == 0 && first == 1){
            if(strlen(id) < 3 ){
                strcpy(id, "1");
            }
            else{
                numberId = numberIdOld;
            }
        }
        first = 1;

        if(strcmp(data->data[numberId]->content, "Game over") == 0){
                printf("Game Over\n");
                break;
        }

        if(strcmp(data->data[numberId]->content, "Victory") == 0){
                printf("Victory\n");
                break;
        }

        gameStory(numberId, data, newId);

        specialEvents(id, newId, myHero);

        specialCases(id);

        computerStep(id, data, myHero->intensity, myHero->level);

        levelUp(myHero, numberOfSpeach, numberOfKillMonster);
    }
}

