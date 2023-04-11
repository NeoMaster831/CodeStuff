/*
A* Algorithm (distorted)
Made by Wane, 박종휘. Working for GNU GPP 17
*/

//#define _DEBUGMODE
#include <bits/stdc++.h>

using namespace std;
#define pp pair<int, int>
#define pdp pair<double, pp>
#define MAX 100
#define INF 1000000007

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { -1, 1, 0, 0 };

struct Cell {
	int parent_x, parent_y;
	double f, g, h;
};

// 0 = 갈 수 있음
// 1 = 갈 수 없음
// 2 = 시작점
// 3 = 도착점
#ifdef _DEBUGMODE
vector<vector<int> > v = {
    { 0, 2, 0, 1, 3 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0 }
};
int R = v.size(), C = v[0].size();
#endif
#ifndef _DEBUGMODE
vector<vector<int> > v(MAX);
int R, C;

void get_input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int inp; cin >> inp; v[i].push_back(inp);
        }
    }
}

#endif

bool is_dest(int row, int col, pp dst) {
    if (row == dst.first && col == dst.second) return true;
    return false;
}

bool is_valid(int row, int col) {
    if (row < 0 || row >= R || col < 0 || col >= C) return false;
    else return true;
}

bool is_unblocked(int row, int col) {
    return v[row][col] != 1;
}

double get_dist(int row, int col, pp dst) {
    return (double)sqrt(pow(row - dst.first, 2) + pow(col - dst.second, 2));
}

void trace_path(Cell cell[MAX][MAX], pp dst) {

    stack<pp> s;
    int y = dst.first;
    int x = dst.second;

    //cout << cell[0][1].parent_x << ' ' << cell[0][1].parent_y << '\n';
    s.push({ y, x });
    while (!(cell[y][x].parent_x == x && cell[y][x].parent_y == y)) {
        int tmpy = cell[y][x].parent_y;
		int tmpx = cell[y][x].parent_x;
        y = tmpy; x = tmpx;
        s.push({ y, x });
    }


    while (!s.empty()) {
        //cout << "(" << s.top().first << ", " << s.top().second << ") -> ";
        v[s.top().first][s.top().second] = 4;
        s.pop();
    }
}

bool astar(pp src, pp dst) {

    //cout << 1 << '\n';
    if (!is_valid(src.first, src.second) || !is_valid(dst.first, dst.second)) return false;
    //cout << !is_unblocked(src.first, src.second) << ' ' << !is_unblocked(dst.first, dst.second) << '\n';
    if (!is_unblocked(src.first, src.second) || !is_unblocked(dst.first, dst.second)) return false;
    //cout << 1;
    if (is_dest(src.first, src.second, dst)) return false;
    //cout << 1;

    bool closed[MAX][MAX];
    memset(closed, false, sizeof(closed));

    Cell cell[MAX][MAX];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cell[i][j].f = cell[i][j].g = cell[i][j].h = INF;
            cell[i][j].parent_x = cell[i][j].parent_y = -1;
        }
    }

    int sy = src.first;
    int sx = src.second;
    cell[sy][sx].f = cell[sy][sx].g = cell[sy][sx].h = 0.0;
    cell[sy][sx].parent_x = sx;
    cell[sy][sx].parent_y = sy;

    set<pdp> SET; // 정렬된 Set 사용
    SET.insert({ 0.0, {sy, sx}});

    while (!SET.empty()) {
        //cout << SET.size() << '\n';
        pdp p = *SET.begin();
        SET.erase(SET.begin());

        int y = p.second.first;
        int x = p.second.second;
        closed[y][x] = true;

        double ng, nf, nh;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (is_valid(ny, nx)) {
                if (is_dest(ny, nx, dst)) {
                    cell[ny][nx].parent_x = x;
                    cell[ny][nx].parent_y = y;
                    trace_path(cell, dst);
                    return true;
                }

                else if (!closed[ny][nx] && is_unblocked(ny, nx)) {

                    ng = cell[y][x].g + 1.0;
                    nh = get_dist(ny, nx, dst);
                    nf = ng + nh;

                    if (cell[ny][nx].f == INF || cell[ny][nx].f > nf) {
                        cell[ny][nx].f = nf;
                        cell[ny][nx].g = ng;
                        cell[ny][nx].h = nh;
                        cell[ny][nx].parent_x = x;
                        cell[ny][nx].parent_y = y;
                        SET.insert({ nf, {ny, nx}});
                    }
                }
            }
        }
    }

    return false;
}

void print_result() {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            switch (v[i][j]) {
            case 0: cout << '.'; break;
            case 1: cout << 'X'; break;
            case 2: cout << 'S'; break;
            case 3: cout << 'D'; break;
            case 4: cout << '*'; break;
            }
        }
        cout << '\n';
    }

}

int main() {
    
    /*
    입력은 다음과 같아야 합니다:
    <Rows> <Cols>
    <Input>
    */

#ifndef _DEBUGMODE
    get_input();
#endif
    
    pp src, dst;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] == 2) src = { i, j };
            else if (v[i][j] == 3) dst = { i, j };
        }
    }

    if (astar(src, dst)) {
        v[src.first][src.second] = 2;
        v[dst.first][dst.second] = 3;
        print_result();
    }
    else cout << "failed" << '\n';

    return 0;

}