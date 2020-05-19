#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "data.h"
#include "item.h"
#include "character.h"


int main()
{
    int numberItem = 76;
    Data* test = CreateData(numberItem);

    test = readData(test->numberOfItem);

    inGame(test);

    return 0;
}
