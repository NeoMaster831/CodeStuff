#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "ImageLayer.h"

// Using Recursive Backtracking Algorithm; Maze Generation
#define WIDTH 31
#define HEIGHT 31

int maze[WIDTH][HEIGHT];
int visited[WIDTH][HEIGHT];

char screenBuffer[2][WIDTH][HEIGHT];
int currentBuffer = 0;

void initializeMaze() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            maze[x][y] = 1;
            visited[x][y] = 0;
        }
    }
}

typedef struct Vec2 {
    int x, y;
} Vec2;

Vec2 player = { 1, 1 };

void printMaze() {

    currentBuffer = 1 - currentBuffer;
    system("cls");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screenBuffer[currentBuffer][x][y] = ' ';
            if (maze[x][y] == 1) {
                screenBuffer[currentBuffer][x][y] = '#';
            }
            else if (maze[x][y] == 2) {
                screenBuffer[currentBuffer][x][y] = 'S';
            }
            else if (maze[x][y] == 3) {
                screenBuffer[currentBuffer][x][y] = 'E';
            }
            if (player.x == x && player.y == y) screenBuffer[currentBuffer][x][y] = 'P';
            printf("%c", screenBuffer[currentBuffer][x][y]);
        }
        printf("\n");
    }
}
void removeWall(int x, int y, int newX, int newY) {
    int midX = (x + newX) / 2;
    int midY = (y + newY) / 2;
    maze[midX][midY] = 0;
}

int isSafe(int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        return 1;
    }
    return 0;
}

void generateMaze(int x, int y) {
    visited[x][y] = 1;
    maze[x][y] = 0;

    while (isSafe(x - 2, y) && !visited[x - 2][y] ||
        isSafe(x + 2, y) && !visited[x + 2][y] ||
        isSafe(x, y - 2) && !visited[x][y - 2] ||
        isSafe(x, y + 2) && !visited[x][y + 2]) {
        int direction = rand() % 4;
        // Check each direction in a random order
        if (direction == 0 && isSafe(x - 2, y) && !visited[x - 2][y]) {
            removeWall(x, y, x - 2, y);
            generateMaze(x - 2, y);
        }
        else if (direction == 1 && isSafe(x + 2, y) && !visited[x + 2][y]) {
            removeWall(x, y, x + 2, y);
            generateMaze(x + 2, y);
        }
        else if (direction == 2 && isSafe(x, y - 2) && !visited[x][y - 2]) {
            removeWall(x, y, x, y - 2);
            generateMaze(x, y - 2);
        }
        else if (direction == 3 && isSafe(x, y + 2) && !visited[x][y + 2]) {
            removeWall(x, y, x, y + 2);
            generateMaze(x, y + 2);
        }
    }
}

typedef struct Dep2 {
    int x, y, depth;
} Dep2;

int visited2[WIDTH][HEIGHT];

Dep2 dfs(int x, int y) {
    visited2[x][y] = 1;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    Dep2 toret = { x, y, 0 };
    for (int i = 0; i < 4; i++) {
        int nxtx = x + dx[i];
        int nxty = y + dy[i];
        if (nxtx <= 0 || nxtx >= WIDTH - 1 || nxty <= 0 || nxty >= HEIGHT - 1 ||
            visited2[nxtx][nxty] == 1 || maze[nxtx][nxty]) {
            continue;
        }
        Dep2 ret = dfs(nxtx, nxty);
        ret.depth++;
        if (toret.depth < ret.depth) {
            toret = ret;
        }
    }
    return toret;
}

void play() {
    while (1) {
        //system("cls");
        if (maze[player.x][player.y] == 3) {
            printf("You clear! Don't you get a life?\nYou can't save the game since you beat this game\nExitCode?: ");

        }
        currentBuffer = 1 - currentBuffer;
        printMaze();
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (maze[player.x][player.y + 1] != 1) {
                player.y++;
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (maze[player.x][player.y - 1] != 1) {
                player.y--;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            if (maze[player.x - 1][player.y] != 1) {
                player.x--;
            }
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            if (maze[player.x + 1][player.y] != 1) {
                player.x++;
            }
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            return;
        }
        Sleep(50);
    }
}

void save() {
    FILE* fp = fopen("save", "w");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d\n", maze[i][j]);
        }
    }
    fprintf(fp, "%d %d\n", player.x, player.y);
    fflush(fp);
    fclose(fp);
}

void load() {
    FILE* fp = fopen("save", "r");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fscanf(fp, "%d %d", &player.x, &player.y);
    fclose(fp);
}

void gui() {
    system("cls");
    printf("Enter the Classic Maze\n[1] Play\n[2] Save\n[3] Load\n>> ");
    int d; scanf("%d", &d);
    switch (d) {
    case 1:
        play(); break;
    case 2:
        save(); break;
    case 3:
        load(); break;
    default:
        break;
    }
    return;
}

void grim() {
    Sleep(500);

    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
    imageLayer.initialize(&imageLayer); //초기화

    Image images[1] = {
        {L"bitmap1.bmp", 0, 0} //{이미지 이름, 시작 x좌표, 시작 y좌표, 크기 배율(쓰지 않으면 기본값인 16이 들어감)} 
    }; //배열의 첫 원소가 가장 아래 그려진다.

    imageLayer.imageCount = 1; //images 배열의 크기보다 작거나 같아야 한다.
    imageLayer.images = images;

    imageLayer.renderAll(&imageLayer);

    getchar();
}


void fullscreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}


int main() {
    srand(time(NULL));
    fullscreen();

    initializeMaze();
    generateMaze(1, 1); // (1, 1) to (n - 2, n - 2)
    Dep2 dep = dfs(1, 1);
    printf("%d %d %d\n", dep.x, dep.y, dep.depth);
    maze[dep.x][dep.y] = 3;
    maze[1][1] = 2;

    grim();

    while (1) gui();
    return 0;
}