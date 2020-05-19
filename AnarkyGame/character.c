#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "item.h"
#include "character.h"

Character* CreateCharacter(char* heroName, char* heroIntensity){
    Character* hero = (Character*)calloc(1,sizeof(Character));

    hero->name = (char*)calloc(1,sizeof(char));
    hero->name = heroName;

    hero->intensity = (char*)calloc(1,sizeof(char));
    hero->intensity = heroIntensity;

    hero->level = 1;

    return hero;
}


void heroRegistration(char* heroName, char* intensity){
    int chose;
    char name[100] = "";
    printf("Adjon meg egy karakter nevet:\n");
    scanf("%s", &name);
    strcat(heroName, name);
    printf("\nValaszon egy erosseget.\n1.Kommunikacio\n2.Harcban jartas\n");
    scanf("%i", &chose);
    if(chose == 1){
        strcat(intensity, "Kommunikacio");
    }
    else if(chose == 2){
        strcat(intensity, "Harcos");
    }
    else{
        printf("\nHibas regisztracio.\n");
    }
}

void levelUp(Character* myHero, int numberOfSpeach, int numberOfKillMonster){
    if(numberOfSpeach == 1 && strcmp(myHero->intensity,"Kommunikacio") == 0){
        myHero->level++;
        numberOfSpeach = 0;
    }
    else if(numberOfKillMonster == 1 && strcmp(myHero->intensity,"Harcos") == 0){
        myHero->level++;
        numberOfKillMonster = 0;
    }
}

void specialEvents(char* id, char* newId, Character* myHero){

    if(strcmp(newId, "v") == 0){
        lastCharacterCutBackMove(id);
    }
    else if(strcmp(newId, "i") == 0){
        printf("Nev: %s\nErosseg: %s\nSzint: %i\n", myHero->name, myHero->intensity, myHero->level);
    }
    else{
        strcat(id, newId);
    }
}
