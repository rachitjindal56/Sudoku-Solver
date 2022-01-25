## Sudoku-Solver
Interesting C++ project using concepts like recursion and backtracking for solving complex puzzle like sudoku.

This project uses the approach of backtracking in C++ for solving the sudoku for an NxN matrix i.e, 4x4, 9X9, 25x25. Due to implementation in C++, the execution is relatively faster.It takes an input of the size of the sudoku in variable 'n' and uses recursion and backtracking to check for the possibility of every number.

This packet consists of two functions: issafe and sudoku

### Function issafe:

    int row, col;

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
    
    // Find number in given zxz sub-matrix 
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
    
The above packet checks for the number in the given row, col, and a sub-matrix. First for loop checks for the presence of the number in the columns, second for loop checks for the number in the row.

In the third loop, the starting point of the sub-matrix is determined to check for the number in the sub-matrix. If any of the loops return false the program starts to backtrack. Else the function returns true.

### Function Sudoku:

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
        
This is the main function that gets recursively called and backtracked in order to check for every number possibility. If the given block already consists of a number more than 0 then the function goes into recursion. If the block is safe then the function checks for every possibility if number. If there is any case where the false is returned the function backtracks to the initial state.

The packet will execute till the value of row >= n and col >= n-1. After termination, the output is printed into the terminal. 
