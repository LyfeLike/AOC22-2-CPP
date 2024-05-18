#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

enum class Move {Rock, Paper, Scissors};

struct Round{
    Move ours;
    Move theirs;
};

int main() {
    std::ifstream file("input.txt");
    std::stringstream buffer;

    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();

        std::string contents = buffer.str();
        std::cout<< "File contents:\n" << contents << std::endl;
    } else {
        std::cout << "Unable to open file :(" << std::endl;
    }
    //you need to iterate over contents and after that match the move, save that as ours or theirs, and calculate the outcoom;

    return 0;
}