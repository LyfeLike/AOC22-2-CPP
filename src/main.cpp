#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

enum class Move {Rock, Paper, Scissors};

struct Round{
    Move theirs;
    Move ours;
};

Move move_matcher(char input){
    Move matched_move;
    if (input == 'A'|| input == 'X') {
        matched_move = Move::Rock;  
        std::cout<< input << "= rock" << std::endl;  
    } else if (input == 'B'|| input == 'Y') {
        matched_move = Move::Paper;    
        std::cout<< input << "= paper" << std::endl;  
    } else if (input == 'C' || input == 'Z') {
        matched_move = Move::Scissors;
        std::cout<< input <<"= Scissors" << std::endl;     
    } else {
        std::cout<< "invalid input." << std::endl;
        throw std::runtime_error("Unexpected case occurred");
    }
    return matched_move;
}

Round round_matcher(char left, char right){
    Move thrown_move_left = move_matcher(left);
    Move thrown_move_right = move_matcher(right);
    Round matched_round = { thrown_move_left, thrown_move_right};
    std::cout<< "returning a matched round\n";
    return matched_round;
}

int round_resolution(Round round){
    int score = 0;
    if (round.theirs == Move::Rock && round.ours == Move::Paper){
        score += 8;
    }else if (round.theirs == Move::Paper && round.ours == Move::Rock) {
        score += 1;
    }else if (round.theirs == Move::Scissors && round.theirs == round.ours){
        score += 6;
    }else{
        std::cout<< "sad boom :(\n";
    }
    return score;
}

int main() {
    std::ifstream file("input.txt");
    std::stringstream buffer;
    int final_score = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)){
            std::istringstream iss(line);
            char a, b;
            if(!(iss >> a >> b)) { break; }//error
            Round round = round_matcher(a,b);
            final_score += round_resolution(round);
        }
        file.close();
    } else {
        std::cout << "Unable to open file :(" << std::endl;
    }
    std::cout<< "Final score= " << final_score <<std::endl;
    return 0;
}