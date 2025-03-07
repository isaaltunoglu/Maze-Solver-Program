# Maze Solver Program (README)

## General Description
This program implements a pathfinding algorithm on a 5x5 maze grid. The program attempts to navigate from the starting point (0,0) to the target point (4,4). Passable paths are represented by `1`, while obstacles are represented by `0`. If a path to the goal is found, the traveled path is recorded and displayed.

## Program Logic
1. The `map` variable stores the current state of the maze. `1` represents passable paths, and `0` represents obstacles.
2. The `savedmap` variable records the solved path and visited points.
3. The `isValid(x, y)` function checks whether the given coordinates are within the boundaries of the grid.
4. The `pathfind(x, y)` function implements a Depth-First Search (DFS) algorithm to find a valid path:
   - If the target `(4,4)` is reached, the solution is considered complete.
   - If the current cell is valid and passable, it is marked as visited.
   - The algorithm explores four possible directions (`right, down, left, up`) to find a path.
   - If no valid path is found, the function backtracks and resets the cell.

## Code Explanation

### isValid Function
```c
int isValid(int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}
```
This function checks whether the given `(x, y)` coordinates are within the boundaries of the 5x5 grid. If they are outside the valid range, it returns `false (0)`, otherwise `true (1)`.

### pathfind Function
```c
int pathfind(int x,int y){
    if (x == 4 && y == 4) {
        printf("Maze is completed, path: %d\n", sumpath);
        savedmap[y][x]=2;
        return 1;
    }
    if (!isValid(x, y) || map[y][x] == 0) return 0;

    map[y][x] = 0;
    savedmap[y][x] = 2;
```
- If `(4,4)` is reached, the solution is found, and the program stops.
- If the current cell is invalid (`isValid == 0`) or an obstacle (`map[y][x] == 0`), the function terminates.
- The current cell is marked as `0`, and `savedmap` is updated to `2` (indicating the path traveled).

#### Movement Rules
```c
    if(isValid(x, y+1) && map[y+1][x] == 1){
        sumpath += 1;
        if(pathfind(x,y+1)) return 1;
        sumpath -= 1;
    }
```
- `isValid(x, y+1)` checks if moving down is possible.
- `map[y+1][x] == 1` ensures that the destination cell is passable.
- Similar conditions apply to moving right (`isValid(x+1, y)`), left (`isValid(x-1, y)`), and up (`isValid(y-1, x)`).
- If a move is made, `sumpath` is incremented; if backtracking occurs, it is decremented.

## savedmap Usage
When executed, the `savedmap` matrix stores the solved path:
- `2`: Cells that are part of the solution path
- `-1`: Backtracked cells
- `1`: Original passable cells
- `0`: Obstacles

For example, after solving the maze, the output might look like this:
```
2   0   2   2   2   
2   2   2   0   2   
0   0   0   0   2   
0   0   0   0   2   
0   0   0   0   2   
```

## Adding New Mazes
To test different mazes, modify the `map` and `savedmap` matrices accordingly:

```c
int map[5][5] ={{1,1,1,1,1},
                {0,0,1,0,1},
                {1,1,1,0,1},
                {1,0,0,0,1},
                {1,1,1,1,1}};
```
This will create a different maze scenario with unique pathfinding challenges.

## Running the Program
Compile and run the program using a C compiler:
```sh
gcc maze_solver.c -o maze_solver
./maze_solver
```
If a path to the target is found, the solution will be displayed. Otherwise, the message "There is no path" will appear.

