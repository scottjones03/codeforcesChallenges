#include<stdio.h>

int main(void) {
    int num_cases;
    scanf("%d", &num_cases);
    for (int i = 0; i < num_cases; i++) {
        int num_people;
        scanf("%d", &num_people);
        char **people = (char **) malloc(num_people *sizeof(char *));
        for (int j = 0; j < num_people; j++) {
            people[j] = (char *) malloc(32 * sizeof(char));
            scanf("%s", people[j]);
        }

        int people_balance[num_people];
        for (int j = 0; j < num_people; j++) {
            people_balance[j]=0;
        }

        for (int j = 0; j < num_people; j++) {
            int current_index;

            char *person = (char *) malloc(32 * sizeof(char));
            scanf("%s", person);
            for (int k=0; k<num_people; k++) {
                if (strcmp(person, people[k]) == 0) {
                    current_index = k;
                    break;
                }
            }


            int shared;
            scanf("%d", &shared);

            int num_friends;
            scanf("%d", &num_friends);
            
            int amount=(int) ((double)shared/(double)num_friends);
            people_balance[current_index]-=amount*num_friends;
            
            for (int r=0; r<num_friends; r++) {
                char *person = (char *) malloc(32 * sizeof(char));
                scanf("%s", person);
                for (int s=0; s<num_people; s++) {
                    if (strcmp(person, people[s]) == 0) {
                        people_balance[s]+=amount;
                    }
                }

            }
            
        }
        for (int k=0; k<num_people; k++) {
            printf("%s %d\n", people[k], people_balance[k]);
        }
        printf("\n");

        
        
        
    }
    
}