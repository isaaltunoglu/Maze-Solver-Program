#include <stdio.h>
#include <stdlib.h>
int sumpath = 1;
int map[5][5] ={{1,0,1,1,1},
                {1,1,1,0,1},
                {0,0,0,0,1},
                {0,0,0,0,1},
                {0,0,0,0,1}};

int savedmap[5][5]={{1,0,1,1,1},
                    {1,1,1,0,1},
                    {0,0,0,0,1},
                    {0,0,0,0,1},
                    {0,0,0,0,1}};




int isValid(int x,int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

int pathfind(int x,int y){
    if (x == 4 && y == 4) {
        printf("Maze is completed, path: %d\n", sumpath);
        savedmap[y][x]=2;
        return 1;
    }
    if (!isValid(x, y) || map[y][x] == 0) return 0;

    map[y][x] = 0;
    savedmap[y][x] = 2;
    
        if(isValid(x, y+1) && map[y+1][x] == 1){
            sumpath += 1;
            if(pathfind(x,y+1)) return 1;
            sumpath -= 1;
        }
        if(isValid(x+1, y) && map[y][x+1] == 1){
            sumpath += 1;
            if(pathfind(x+1,y)) return 1;
            sumpath -= 1;
        }
        if(isValid(x-1, y) && map[y][x-1] == 1){
            sumpath += 1;
            if(pathfind(x-1,y)) return 1;
            sumpath -= 1;
        }
        if(isValid(y-1, x) && map[y-1][x] == 1){
            sumpath += 1;
            if(pathfind(x,y-1)) return 1;
            sumpath -= 1;
        }


        map[y][x]= 1;
        savedmap[y][x] = -1;
        return 0;


}

int main(){
    int i,j;
    if (!pathfind(0, 0)) {
        printf("There is no path\n");
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d\t",savedmap[i][j]);
        }
        printf("\n");
    }
    return 0;
}