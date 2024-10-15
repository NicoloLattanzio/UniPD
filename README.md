I first think about the algorithm that scrolls the maze, at first tought i see that a recorsive algorithm is needed, doing so i have all the possible path checked up.
So, I make 4 "if" that runs every possible move, Up, down right and left; in every single "if" i call the SolveMaze function recursively.
In order to trace the single position i move on, as the single Start and End Positions, i create a struct called Position, that has a row and a column as variables.
After that, i need to find a way to remember the moves needed to find the end of the maze, if possible; so i create the "moves" variable which is an array of chars that has rows*column as the maximum number of chars and a MovesCount variable to store the moves in the right place of the array.
Now i notice that i need a variable to track the positions i already moved on, in order to avoid going back to the start during the scrolling; so i create the "visited" matrix.

