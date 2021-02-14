set -e
g++ -o main  snake.cpp board.cpp main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./main