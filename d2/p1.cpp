#include<iostream>

using namespace std;

enum ME{
    ROCK = 1, 
    PAPER = 2, 
    SCISSORS = 3
};
enum OPPONENT{
    OROCK = 1, 
    OPAPER = 2, 
    OSCISSORS = 3
};

ME char_to_me(char i){
    switch(i){
        case 'X':
            return ROCK;
        case 'Y':
            return PAPER;
        case 'Z':
            return SCISSORS;
        default:
            return ROCK;
    }
}

OPPONENT char_to_op(char i){
    switch(i){
        case 'A':
            return OROCK;
        case 'B':
            return OPAPER;
        case 'C':
            return OSCISSORS;
        default:
            return OROCK;
    }
}

int main(){
    /*
    A - Rock
    B - Paper
    C- Scicors

    X-Rock
    Y - Paper
    Z - Scicors
    */
    char opponenent;
    unsigned int score = 0;
    while(cin >> opponenent){
        char me;
        cin >> me;
        ME move = char_to_me(me);
        score += move;
        if(char_to_op(opponenent) == OROCK){
            if(move == ROCK){
                score += 3;
            }else if(move == PAPER){
                score += 6;
            }else{
                score += 0;
            }
        }
        if(char_to_op(opponenent) == OPAPER){
            if(move == PAPER){
                score += 3;
            }else if(move == SCISSORS){
                score += 6;
            }else{
                score += 0;
            }
        }
        if(char_to_op(opponenent) == OSCISSORS){
            if(move == SCISSORS){
                score += 3;
            }else if(move == ROCK){
                score += 6;
            }else{
                score += 0;
            }
        }
    }

    cout << score << endl;

    return 0;
}