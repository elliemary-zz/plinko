# Plinko Simulation
This is a simple Plinko simulation I whipped up for a coding challenge

This is a representation of what my plinko board looks like
![Plinko Board](https://github.com/elliemary/plinko/blob/master/Plinko_Board.png?raw=true)



Here is an explanation of how I translated my plinko board into coordinates.
![Plinko Board](https://github.com/elliemary/plinko/blob/master/Coordinates.png?raw=true)


My Game class initializes values and holds the functions for dropping a new disk, Drop(), and moving the disk one Y toward the end bins, Move().  The place where the disk is dropped is randomized.




*Assumptions*
1. The pegs are not random.  Each peg is vertically aligned with the other pegs in its row.
2. The highest row of pegs will be labeled row 1
3. The lowest row of pegs will be labeled row 6
4. Odd numbered rows have 7 pegs, each peg horizontally centered in one of the columns
5. Even numbered rows have 6 pegs, each peg horizontally centered exactly between two columns
6. The left side of the wall will be considered X position 0.5
7. The right side of the wall will be considered X position 7.5
8. If the disk hits a peg in X position 1 through 7, it will bounce either left or right. It will not not stay in the same column.
9. If the disk hits one of the walls (X position .5 or 7.5) it will move down and toward the center of the plinko board (X=1 or X=7, respectively)
10. The disk will always move one row down after hitting a peg/wall. This model will not acommodate the possibility of the peg bouncing up, horizontally, or down more than one unit at a time
11. The topmost row of pegs acts as dividers for placing the disk into the plinko board, therefore the disk will not bounce off of the first row of pegs.  The peg will first bounce off of either the wall or a peg in row 2.

*Pseudocode*
1. Randomly select drop position 1 through 8 (inclusive)
2. Drop peg
3. Fall down either left or right until hits bottom
4. If at edge, must go back towards center
5. Output the value of the bucket it landed in

