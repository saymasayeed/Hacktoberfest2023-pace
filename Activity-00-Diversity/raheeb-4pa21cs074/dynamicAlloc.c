#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inital_val 2
int main(void)
{
    // initialising values dynamic programming
    char answer[] = "y";
    double *scores = malloc(inital_val * sizeof(double));
    if (!scores)
    {
        fprintf(stderr, "failed to allocate scores array");
        return 1;
    }
    int capacity = inital_val;
    int numscores;

    // dynamically resize memory,control execution
    for (numscores = 0; strcmp(answer, "y") == 0; ++numscores)
    {
        if (numscores == capacity)
        {
            capacity *= 2;
            scores = realloc(scores, capacity * sizeof(double));
            if (!scores)
            {
                fprintf(stderr, "failed to allocate scores array");
                return 1;
            }
        }
        printf("Enter a score: ");
        scanf("%lf", &scores[numscores]); //lf is long float
        printf("Do you want to continue? (y/n)\n$");
        scanf("%s", &answer);
    }
    double sum=0;
    for(int i=0;i<=numscores;i++){
        sum += scores[i];
    }
    printf("the average marks is: %.2f",sum/numscores);
    free(scores);
    return 0;
}