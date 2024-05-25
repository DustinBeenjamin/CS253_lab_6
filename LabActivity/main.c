#include <stdio.h>
#define TEAM_SIZE 3
#define MAX_STRING_SIZE 100

int registerPlayer(int i, int player_ratings[], int jersey_nums[]);
int get_index_by_value(int value, int values[]);
int printMenu(int ratings[], int jersey_nums[]);
int updateRating(int ratings[], int jerseys[]);
int filter(int ratings[], int jerseys[]);
int replace(int ratings[], int jerserys[]);
int printRoster(int ratings[], int jerseys[]);


int main() {

    int jersey_nums[TEAM_SIZE];
    int player_ratings[TEAM_SIZE];
    
    //FILL ARRAY WITH DEFAULT DATA
    for (int i = 0; i < TEAM_SIZE; i++) {
        jersey_nums[i] = -1;
        player_ratings[i] = -1;
    }

    //REGISTER INITIAL PLAYERS
    for (int i = 0; i < TEAM_SIZE; i++) {
        registerPlayer(i, player_ratings, jersey_nums);
    }

    //Print Menu and Handle Inputs
    printMenu(player_ratings, jersey_nums);

}

//FUNCTION TO REGISTER A PLAYER
int registerPlayer(int i, int player_ratings[], int jersey_nums[]) {
    char garbage[MAX_STRING_SIZE];
    //PROMPT FOR A JERSEY NUMBER, MAKE SURE IT IS NOT ALREADY TAKEN
    printf("Enter player %d's jersey number:\n", i + 1);
    scanf("%d", &jersey_nums[i]);
    while (get_index_by_value(jersey_nums[i], jersey_nums) != i) {
        printf("That jersey number is already taken. Try again.\n");
        scanf("%d", &jersey_nums[i]);
    }
    //PROMPT FOR THE PLAYER RATING
    printf("Enter player %d's rating:\n", i + 1);
    scanf("%d", &player_ratings[i]);
    getchar();
}

//SEARCH AN ARRAY FOR THE INDEX OF A VALUE (THERE WILL BE NO REPEAT VALUES)
int get_index_by_value(int value, int values[]) {
    for (int i = 0; i < TEAM_SIZE; i++) {
        if (values[i] == value) {
            return i;
        }
    }
    //RETURN -1 IF THE VALUE IS NOT FOUND
    return -1;
}

int printMenu(int ratings[], int jersey_nums[]){
    

    char command = '0';

    while (command != 'q'){
        printf("\nMENU\n");
        printf("u - Update player rating\n");
        printf("a - Output players above a rating\n");
        printf("r - Replace a player\n");
        printf("o - Output roster\n");
        printf("q - Quit\n\n");
        printf("Choose an option:\n");
        command = getchar();

        switch (command) {
            case 'u':
                updateRating(ratings, jersey_nums);
                break;
            case 'a':
                filter(ratings, jersey_nums);
                break;
            case 'r':
                replace(ratings, jersey_nums);
                break;
            case 'o':
                printRoster(ratings, jersey_nums);
                break;
            case 'q':
                // DO NOTHING TO LET THE PROGRAM TERMINATE
                break;
            default:
                printf("Error: That is not a valid option\n");
                command = '0';
        }
    getchar();
    }
}


int updateRating(int ratings[], int jerseys[]) {
    int jersey = 0;
    int newRating = 0;
    int i;
    printf("Enter a jersey number:\n");
    scanf("%d", &jersey);
    i = get_index_by_value(jersey, jerseys);
    printf("Enter the new rating:\n");
    scanf("%d", &newRating);
    ratings[i] = newRating;
}

int filter(int ratings[], int jerseys[]) {
    int rating = 0;
    printf("\nEnter a player rating:\n");
    scanf("%d", &rating);
    for (int i = 0; i < TEAM_SIZE; i++) {
        if (ratings[i] >= rating) {
            printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseys[i], ratings[i]);
        }
    }
}

int replace(int ratings[], int jerserys[]) {
    int jersey_num;
    int i;
    printf("\nEnter a jersey number:\n");
    scanf("%d", &jersey_num);
    i = get_index_by_value(jersey_num, jerserys);
    registerPlayer(i, ratings, jerserys);
}

int printRoster(int ratings[], int jerseys[]) {
    printf("\nROSTER\n");
    for(int i = 0; i < TEAM_SIZE; i++) {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseys[i], ratings[i]);
    }
    printf("\n");
    return 1;
}













