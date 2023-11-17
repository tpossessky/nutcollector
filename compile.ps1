# Compile and Link C files
gcc -Wall -Werror -c ./display.c -o ./display.o
gcc -Wall -Werror -c ./functions.c -o ./functions.o
gcc -Wall -Werror -c ./main.c -o ./main.o

# Link Object files into Executable
gcc -Wall -Werror ./main.o ./display.o ./functions.o -o nutcollector
./nutcollector