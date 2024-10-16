#include <stdio.h>

#define MAX_ROW 20
#define MAX_COL 20

typedef struct {
    int row;
    int col;
} Position;

int maze[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];
char moves[MAX_ROW * MAX_COL];
int moveCount = 0;

int solveMaze(int row, int col, Position current, Position exit) {
    if (current.row == exit.row && current.col == exit.col) {
        return 1; // Exit found
    }

    if (current.row < 0 || current.row >= row || current.col < 0 || current.col >= col || maze[current.row][current.col] == '#' || visited[current.row][current.col]) {
        return 0; // Out of border or already visited
    }

    visited[current.row][current.col] = 1;

    // Here I try every possible move
    if (solveMaze(row, col, (Position){current.row - 1, current.col}, exit)) {
        moves[moveCount++] = 'U';
        return 1;
    }
    if (solveMaze(row, col, (Position){current.row + 1, current.col}, exit)) {
        moves[moveCount++] = 'D';
        return 1;
    }
    if (solveMaze(row, col, (Position){current.row, current.col - 1}, exit)) {
        moves[moveCount++] = 'L';
        return 1;
    }
    if (solveMaze(row, col, (Position){current.row, current.col + 1}, exit)) {
        moves[moveCount++] = 'R';
        return 1;
    }
}

int main() {
    int row, col;
    Position start, exit;

    printf("Enter the number of rows and columns needed to create the maze: ");
    scanf("%d %d", &row, &col);

    // Read the maze
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'S') {
                start = (Position){i, j};
            } else if (maze[i][j] == 'E') {
                exit = (Position){i, j};
            }
        }
    }

    // Solve the maze
    if (solveMaze(row, col, start, exit)) {
        printf("Maze solution found:\n");
        for (int i = 0; i < moveCount; i++) {
            printf("%c ", moves[i]);
        }
        printf("\n");
    } else {
        printf("Maze solution not found.\n");
    }
}

/*
int MazeReader(int maze[MAX_ROW][MAX_COL]) {
int const row;
int const col;
FILE *fp = fopen("maze.txt", "r");
printf("How many columns and rows does the maze has?\n");
scanf("%c %c", &rows, &cols);
fscanf(fp, "%d %d", rows, cols);

// Read the maze from a file
if (fp == NULL) {
printf("Error opening file.\n");
return 1;
}


for (int i = 0; i < rows; i++) {
fscanf(fp, "%s", maze[i]);
}

fclose(fp);

// Print the maze
printf("Maze:\n");
for (int i = 0; i < rows; i++) {
printf("%s\n", maze[i]);
}
return 0;
}
*/

