#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    double avg;
} Game;

int cmp(const void *a, const void *b) {
    double diff = ((Game*)b)->avg - ((Game*)a)->avg;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d\n", &n);
    Game games[n];

    for (int i = 0; i < n; i++) {
        char temp;
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp); // двоеточие
        int k;
        scanf("%d", &k);
        double sum = 0;
        for (int j = 0; j < k; j++) {
            int score;
            scanf("%d", &score);
            sum += score;
        }
        games[i].avg = sum / k;
    }

    qsort(games, n, sizeof(Game), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %.3f\n", games[i].title, games[i].avg);
    }

    return 0;
}
