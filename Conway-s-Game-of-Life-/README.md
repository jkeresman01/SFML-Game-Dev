# Conway's Game of Life! #

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. In this particular instance, the initial configuration is generated randomly, with each cell having a 20% chance to be alive and an 80% chance to be dead.

At each step in time (in this case, every 2 seconds), the following transitions occur:

* Any live cell with fewer than two live neighbors dies, as if by underpopulation.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by overpopulation.
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

## Running the game ##

If the version of SFML that you want to install is available in the official repository, then install it using your package manager.

For example, on Debian, Ubuntu you would do:
``` shell
sudo apt-get install libsfml-dev
```

Now you will need to compile the program:
``` shell
g++ -std=c++17 -c *.cpp
```

In case you installed SFML to a non-standard path, you'll need to tell the compiler where to find the SFML headers:
``` shell
g++ -std=c++17 -c *.cpp -I<sfml-install-path>/include
```

You must then link the compiled file to the SFML libraries in order to get the final executable.
``` shell
g++ *.o -o game-of-life -lsfml-graphics -lsfml-window -lsfml-system
```
You can now execute the compiled program:
``` shell
./game-of-life
```

### Build and run the game with CMake ###

Install SFML using your package manager, for example, on Debian, Ubuntu you would do:
``` shell
sudo apt-get install libsfml-dev
```

Clone the repository
``` shell
git clone https://github.com/jkeresman01/Conway-s-Game-of-Life-
```

Build and Run the game:

``` shell
cd Conway-s-Game-of-Life-
mkdir build && cd build
cmake ..
make
./game-of-life
```


## Useful Resources ##

| Resource                                                    | Link                                                              |
|-------------------------------------------------------------|-------------------------------------------------------------------|
| Wikipedia: Conway's Game of Life                            | [Link](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)     |
| YouTube: Conway's Game of Life                              | [Link](https://www.youtube.com/watch?v=CgOcEZinQ2I)               |
| SFML: Documentation                                         | [Link](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)    |

