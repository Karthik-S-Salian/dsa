#include <string.h>
#include<stdbool.h>

bool isValidSudoku(char **board, int boardSize, int* boardColSize) {
    bool array[10];
    char c;
    int index;

    for(int i=0;i<9;i++){
        memset(array, false, sizeof(array));
        for(int j=0;j<9;j++){
            c = board[i][j];
            if(c!='.'){
                index = c - '0';
                if(array[index])
                    return false;
                array[index] = true;
            }
        }
    }

    for(int i=0;i<9;i++){
        memset(array, false, sizeof(array));
        for(int j=0;j<9;j++){
            c = board[j][i];
            if(c!='.'){
                index = c - '0';
                if(array[index])
                    return false;
                array[index] = true;
            }
        }
    }

    for(int i=0;i<9;i++){
        memset(array, false, sizeof(array));
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                c = board[(i/3)*3 + j][(i%3)*3 + k];
                if(c!='.'){
                    index = c - '0';
                    if(array[index])
                        return false;
                    array[index] = true;
                }
            }
        }
    }
    return true;
}