/*
Rat In A Maze Problem

You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.

Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)

Output Format :
One Line for every possible solution. 

Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
*/

void printPath(int sol[][20],int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cout<<sol[i][j]<<" ";
    
    cout<<endl;
    return;
}

void ratInAMaze(int maze[][20],int sol[][20],int row,int col,int n)
{
    if(row == n - 1  &&  col == n - 1)
    {
        sol[row][col] = 1;
        printPath(sol,n);
        sol[row][col] = 0;
        return;
    }
    
    if(maze[row][col] == 0)
        return;
    
    if(sol[row][col] == 1)
        return;
    
    else
    {
        sol[row][col] = 1;
        if(col + 1 < n)
            ratInAMaze(maze,sol,row,col+1,n);
        
        if(col - 1 >= 0)
            ratInAMaze(maze,sol,row,col-1,n);
        
        if(row + 1 < n)
            ratInAMaze(maze,sol,row+1,col,n);
        
        if(row - 1 >= 0)
            ratInAMaze(maze,sol,row-1,col,n);
    
        sol[row][col] = 0;
    }
}

void ratInAMaze(int maze[][20], int n){

    int sol[20][20];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sol[i][j] = 0;
    
    ratInAMaze(maze,sol,0,0,n);
}

