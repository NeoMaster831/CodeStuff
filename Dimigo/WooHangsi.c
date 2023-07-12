#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

typedef struct pair {
    int f, s;
} pair;

typedef struct map {
    int sz;
    pair time[101];
} map;

map parse(const char* where) {
    FILE* fp;
    char buf[1024];
    map toret;
    if (fp = fopen(where, "r")) {
        int ptr = 0;
        while (1) {
            char* res;
            if ((res = fgets(buf, sizeof(buf), fp)) == 0) break;
            pair t;
            t.f = atoi(buf);
            if ((res = fgets(buf, sizeof(buf), fp)) == 0) break;
            t.s = atoi(buf);
            toret.time[ptr] = t;
            ptr++;
        }
        toret.sz = ptr;
        fclose(fp);
    } else {
        toret.sz = 0;
    }
    return toret;
}

#define REFRESH_TIME 30
#define RHY_SIZE 25

void print_ig(map *m, int tm) {
    for (int i = 0; i < 100; i++) printf("\n");
    for (int i = RHY_SIZE; i >= 0; i--) {
        printf("|");
        for (int j = 0; j < 4; j++) {
            int yes = 0;
            for (int k = 0; k < m->sz; k++) {
                if (m->time[k].s != j) {
                    continue;
                }
                if (m->time[k].f >= tm + REFRESH_TIME * i && m->time[k].f < tm + REFRESH_TIME * (i+1)) {
                    printf("___");
                    yes = 1;
                }
            }
            if (!yes) printf("   ");
        }
        printf("|\n");
    }
    printf("==============\n");
}

void gui() {
    for (int i = 0; i < 100; i++) printf("\n");
    printf("Woothmgame v1\n");
    printf("[s] Start | [x] exit\n");

    int l = getch();
    while (l != 's' && l != 'x') {
        printf("%d", l);
        l = getch();
    }
    if (l == 's') {
        map map = parse("./aaaaa.txt");
        int timestamp = 0;
        int ptr = 0;
        while (1) {
            print_ig(&map, timestamp);
            Sleep(REFRESH_TIME);
            timestamp += REFRESH_TIME;
            if (timestamp >= 6000) break;
        }
    } else {
        exit(0);
    }
}

int main() {
    gui();
}