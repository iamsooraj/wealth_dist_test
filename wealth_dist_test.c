#ifdef _WIN64
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define WIDTH 7
#endif

#ifdef __APPLE__
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#endif


#ifdef __unix__
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#endif

#define HEAD 0
#define TAIL 1

int s32Wealth=0;
unsigned long u64TossCount;
int main()
{
    unsigned char u8Toss=10; //for initialize with random number
    float f32WealthforParty1 = 0, f32WealthforParty2 = 0;

    printf("Enter the amount of wealth to be distributed: ");
    scanf("%d", (int *)&s32Wealth);
    f32WealthforParty1 = s32Wealth;
    f32WealthforParty2 = s32Wealth;
    printf("Game is about to begin %d is for Player-1 and %d is for Player-2\n", HEAD, TAIL);
    srand( (unsigned)time( NULL ) ); // Seed for random number
    while (f32WealthforParty1 > 0 && f32WealthforParty2 > 0)
    {
        u8Toss = rand() % 2; // Selecting random number
        u64TossCount++;
        if(u8Toss == HEAD) {
            f32WealthforParty2--;
            f32WealthforParty1++;
            printf("It's a Head!");
        } else {
            f32WealthforParty1--;
            f32WealthforParty2++;
            printf("It's a Tail!");
        }
        printf(" Toss count: %lu\nCurrent wealth distribution is,\n\tPlayer-1: %d\n\tPlayer-2: %d \n\t(%d%%-%d%%)\n", 
                                                                u64TossCount,
                                                                (int)f32WealthforParty1, 
                                                                (int)f32WealthforParty2, 
                                                                (int)((f32WealthforParty1/(2*s32Wealth))*100),
                                                                (int)((f32WealthforParty2/(2*s32Wealth))*100));
        usleep(1000);
    }
    if(f32WealthforParty1 <= 0) {
        printf("Player-1 is bankrupt, and Player-2 have balance of %d\n", (int)f32WealthforParty2);
    } else {
        printf("Player-2 is bankrupt, and Player-1 have balance of %d\n", (int)f32WealthforParty1);
    }

}


