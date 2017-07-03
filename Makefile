""Its a file for cmd for compiling a c++ file through a text editor
""In this case we have file called main.cpp
""Go to your main.cpp directory and type 'make' (without quota)
""After successful compilation type main.exe
""Thats it
""Dont name your makefile as simply 'make' it doesnt work
""For Windows

all:
    g++ main.cpp -o main
    
""For Linux

all:
    g++ main.cpp -o main
    ./main.out
