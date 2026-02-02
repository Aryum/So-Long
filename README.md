# So Long
A simple 2D game made using MiniLibX library to render the game where the player had to get some collectables to unlock a door and be able to leave the game.

# Main logic
To start the game we run the executable in the terminal with a map as argument, a .ber file that is just a text file with the map. The program then reads the file, and checks if its a valid map to be valid it needs:
  - To be surrounded by walls (1)
  - Needs to have one exit (E) and at least one collectible (C)
  - The player (P) needs to have a clear path to all the collectibles and exit
  - The map should be a rectangle or a square

After it validates the map it converts the assets to usable images, they need to be in .xpm format so the MiniLibx library can read them.
Then it starts the game window and places the assets to their places.To control the game we use W A S D to control the character and ESC to close the game.
The game ends when the player catches all the collectibles and goes to the exit.
