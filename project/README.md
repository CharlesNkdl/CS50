# TEN QUEENS PUZZLE
### Video demo : https://youtu.be/LLy96HwYoZM
### Description :
Hello everybody, my name is Charles Nkdl from Lille,France.

In this final project, i used C with command line argument and an algorithmic problem.
I studied and used a Backtracking algorithm to solve and give all the solutions of the "Ten Queens Puzzle".

The goal of the "Ten Queens Puzzle" is to place ten queens on a 10x10 chessboard so that no two queens threaten each other.
For reminder : A Queen in chess can move any number of squares vertically, horizontally or diagonally.

I wrote this in only one file so I will go to a breakthrough of each function i wrote.
# I began to wrote the program to find each of the solution first, when the user input 'soluce'.

### int	ft_ten_queens_puzzle(void)

        This is the base function, a kind of mini-main, to keep things clearer between the 2 sides of the program.
        It first initiate a 2D int array of 10 values to represent a 10x10 board.

        Then initiate a row integer to serve as value to navigate through the board.I only call a row and not a column parameter since i'll try to put a queen on each row before going to the next column.

        I initiate a counter integer. It will be send as a pointer to the backtraking algorithm to serve as a counter of solution and send it back as a result of the function.

        I then call the populate function.
#### void	populate(int array[10][10])

        The goal of the populate function is quite simple, i fill the 2D array of 0 to be clean and get a better use of the backtraking algorithm.

        Then i call the backtraking algorithm "queenplace" with the array, initialized as a 10x10 board and filled with 0, the row at 0 since it'll be called back recursively in the algorithm. Then the counter adress, so that his value can change each time a solution is validated !

### int	queenplace(int grid[10][10], int row, int *count)

        So this is the backtraking algorithm, the main part of this program.
        The goal is to place 1 queen per row.
        Why ? :
            - Since queen can move vertically and horizontally, we know that no 2 queen can be on the same row ! I could have gone by also iterating column per column but in my mind, row was easier at first. Thinking back, it made no difference.
        How ? :
            - The row value is send as a parameter so we don't need to modify it.
            - We initialize a col integer to navigate through each row of the array with a while loop.
            - To each column of the row, we call the backbone of the backtraking algorithm, the function "isgood_line" which return 1 if this is possible to put a queen here or 0 if not.
            -If the function return a 0, we iterate to the next column.
            -If the function return a 1, we place a queen at the row/col coordinate, then we call recursively the function Queenplace but by passing to the next row !
            -If there is no solution available at this certain placement of queen, this "way" will stop and backtrack to the last possible solution !
            -When row is equal to 10,the backtracking algorithm iterated through each row without error on the way ! We then call the printing function which print the solution, increment the counter for the base function, and return (1) to end the algorithm.

        Why just after placing a queen i then call the function and subsequently remove the queen by changing the value back to 0 ? : With this, the algorithm will always try to find EVERY way possible to solve the puzzle and not only one since the Ten Queens Puzzle do have multiple solutions !

### int	isgood_line(int grid[10][10], int row, int col)

        This function serve as a tester to know if this position is safe to put a queen on.
        Since we iterate through each row, we just need to check 3 directions : Up, left-up diagonal and right-up diagonal !
        If no already placed queen are met, the function return a 1, it is a safe position to put a queen on !

        if we iterated through each column, we would need to check 3 other directions : horizontally to the left, left-up diagonal and left-down diagonal !

### void	printing(int array[10][10])

        It'll quite simply print the solution as a line which each numbers is the position of a queen in the row !

# Then i implemented command-line arguments so that a user can try to resolve the puzzle himself !

### int	main(int argc, char **argv)

        The main take command line arguments, if none is entered, it'll send the instructions
        If more than 1 argument is sent, it'll return a error.
        If the argument is not 'no', 'soluce' or a solution, it'll return a error

### int ft_check(char *str)

        If the argument is not 'no' or 'soluce', it will check if the argument is a valid formatted solution.

### int	trysolve(char *str)

        If the argument is a valid solution, it'll try to check the solution, with a remixed check algorithm, which will iterate through each column this time !
        When the iterator is equal to the char value of the corresponding row and column, it will check the solution with the isgood_linecol function, if it is correct, place the queen and continue !
        If no obstacles are met, the user inputted a correct solution !We return a 1 So we can output a SUCESS and exit the program in the main.
        If there is an obstacle, the user sadly inputted a wrong solution... We then return a 0 so we can exit the program with a WRONG output.

### int	isgood_linecol(int grid[10][10], int row, int col)

        We iterated through each column, we would need to check 3 directions : horizontally to the left, left-up diagonal and left-down diagonal !
        If no already placed queen are met, the function return a 1, it is a safe position to put a queen on !

# Program is done ! Finishing it, i know there is some key point i could have been more efficient such as :

    - Dynamic memory allocation of the array
    - Trying to display the solution in some ascii art to be clearer to the user
    - Using the same checking algorithm to recycle it better in the second part of my program
    - Or even better, modify it so it can check for the user input AND send all the solutions when prompted

Overall, i'm pretty proud of myself after my project, and helped me dove deeper into understanding complex algorithmic principle such as backtracking !
