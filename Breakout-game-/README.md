# Breakout-game #
Breakout is an arcade game developed by Atari Inc. in 1976. Conceived by Nolan Bushnell, the game was influenced by Pong and became a huge success. The game’s objective is to destroy a wall of bricks by bouncing a ball with a paddle.

## Game preview ##
![breakoutgame](https://github.com/user-attachments/assets/b930c35a-8bcc-4077-85b0-f205042d2a3d)

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
You must then link the compiled file to the SFML libraries in order to get the final executable.
``` shell
g++ *.o -o breakout-game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
You can now execute the compiled program:
``` shell
./breakout-game
```

### Build and run the game with CMake ###

Install SFML using your package manager, for example, on Debian, Ubuntu you would do:
``` shell
sudo apt-get install libsfml-dev
```

Clone the repository
``` shell
git clone https://github.com/jkeresman01/Breakout-game-
```

Build and Run the game:

``` shell
cd Breakout-game-
mkdir build && cd build
cmake ..
make
./breakout-game
```


## Useful Resources ##

| Resource                                                    | Link                                                              |
|-------------------------------------------------------------|-------------------------------------------------------------------|
| Wikipedia: Breakout game                           | [Link](https://en.wikipedia.org/wiki/Breakout_(video_game))     |
