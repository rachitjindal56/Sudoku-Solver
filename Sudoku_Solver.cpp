#include<bits/stdc++.h>
using namespace std;

//   [NxN] SUDOKU SOLVER

// This function ckecks for the valid case is a number 
// can be placed in the given block
bool issafe(int** arr,int x,int y,int N,int num){
    int row,col;

    // Checking for number in col
    for(row=0;row<N;row++){
        if(arr[row][y] == num){
            // If number exists return false
            return false;
        }
    }
    
    // Checking for number in col
    for(col=0;col<N;col++){
        if(arr[x][col] == num){
            // If number exists return false
            return false;
        }
    }
    
    // Find number in given 3x3 sub-matrix 
    // As the row and col are grouped into 3x3 we can 
    // take mod inorder to find the staring point of 
    // row and col of 3x3 sub-matrix
    int z = sqrt(N);
    int start_row = x - x%z;
    int start_col = y - y%z;

    for(row=0;row<z;row++){
        for(col=0;col<z;col++){
            if(arr[row+start_row][col+start_col] == num){
                // If number exists return false
                return false;
            }
        }
    }
    return true;
}

// A Recursive function for finding the valid numbers
bool sudoku(int** arr,int N,int row,int col){

    if(row >= N && col >= N-1){
        return true;
    }

    if(row==N){
        col += 1;
        row = 0;
    }

    // Check if given block already has any defined number
    if(arr[row][col]>0){
        // Recursively calling function by moving to other row
        return sudoku(arr,N,row+1,col);
    }

    // If the given block has value zero(0)
    for(int i=1;i<=N;i++){

        // Checking if a given number can be placed in the
        // present block 
        if(issafe(arr,row,col,N,i)){

            // Inserting number in the block
            arr[row][col] = i;
            
            // Recursively calling to check its validity
            if(sudoku(arr,N,row+1,col)){
                return true;
            }
            // Backtracking 
            arr[row][col] = 0;
        }
    }

    return false;
}


int main(){
    int N;
    cout<<"Enter the size of sudoku: ";
    // Reading the size of Sudoku
    cin>>N;

    // Initalizing NxN dynamic array
    int** arr = new int*[N];

    for(int i=0;i<N;i++){

        arr[i] = new int[N];

        // Inputting the sudoku elements
        // Here value in empty boxes should be set to zero(0)
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    // Ckecking validity of sudoku
    if(sudoku(arr,N,0,0)){
        cout<<endl;
    
        // If sudoku is valid printing the sudoku
        for(int i=0;i<N;i++){
    
            for(int j=0;j<N;j++){
    
                cout<<arr[i][j]<<" ";
    
            }cout<<endl;
        }
    }

    else{
    
        cout<<"Wrong Sudoku";
    
    }
    system("pasue");
    return 0;
}

// This is a sample 9x9 sudoku

// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0
