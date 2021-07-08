#include <bits/stdc++.h> 
using namespace std; 
bool FindUnassignedLocation(int grid[7][7], 
                            int* row, int* col); 
bool isSafe(int grid[7][7],int row,int col, char s[7][7], int num); 

void printGrid(int grid[7][7]) 
{ 
    for (int row = 0; row < 7; row++) {
    	cout<<grid[row][0];
        for (int col = 1; col < 7; col++) 
            cout <<" "<<grid[row][col]; 
        if(row!=6)
        	cout << endl; 
    } 
}

bool SolveSudoku(int grid[7][7],char s[7][7]) 
{ 
    int row, col; 
    if (!FindUnassignedLocation(grid, &row, &col)) 
        return true; 
    for (int num = 1; num <= 7; num++) { 
        if (isSafe(grid, row, col,s, num)) { 
            grid[row][col] = num; 
            if (SolveSudoku(grid,s)) 
                return true; 
  
            grid[row][col] = 0; 
        } 
    } 
    return false; 
} 

bool FindUnassignedLocation(int grid[7][7], 
                            int* row, int* col) 
{ 
    for (*row = 0; *row < 7; (*row)++) 
        for (*col = 0; *col < 7; (*col)++) {
            if (grid[*row][*col] == 0) 
                return true; 
            }
    return false; 
} 
  
bool UsedInRow(int grid[7][7], int row, int num) 
{ 
    for (int col = 0; col < 7; col++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
bool UsedInCol(int grid[7][7], int col, int num) 
{ 
    for (int row = 0; row < 7; row++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
bool UsedInBox(int grid[7][7], char s[7][7] ,char a,int num) 
{ 
    for (int row = 0; row < 7; row++) 
        for (int col = 0; col < 7; col++) 
            if (s[row] [col] == a && grid[row][col] == num) 
                return true; 
    return false; 
} 
  
bool isSafe(int grid[7][7], int row,int col, char s[7][7], int num) 
{ 
    return !UsedInRow(grid, row, num) 
           && !UsedInCol(grid, col, num) 
           && !UsedInBox(grid, s,s[row][col], num) 
           && grid[row][col] == 0; 
} 
  

int main(){
	int suduko[7][7]={ {0, 0, 0, 0, 0, 6, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{2, 6, 5, 1, 7, 4, 3},
	{0, 0, 0, 3, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}};
	char s[7][7]={{'a', 'a', 'a', 'b', 'b', 'b', 'b'},
	{'a', 'a', 'a', 'a', 'b', 'b', 'c'},
	{'d', 'd', 'd', 'e', 'e', 'b', 'c'},
	{'d', 'd', 'd', 'd', 'e', 'e', 'c'},
	{'f', 'f', 'f', 'h', 'e', 'e', 'c'},
	{'f', 'f', 'h', 'h', 'e', 'c', 'c'},
	{'f', 'f', 'h', 'h', 'h', 'h', 'c'}};
//	for (int i=0;i<7;i++){
//		for (int j=0;j<7;j++){
//			cin>>suduko[i][j];
//		}
//	}
//	
//	for (int i=0;i<7;i++){
//		for (int j=0;j<7;j++){
//			cin>>s[i][j];
//		}
//	}
	
	if (!SolveSudoku(suduko,s)) 
        cout << "No solution exists";
    else
    	printGrid(suduko);
        
}

