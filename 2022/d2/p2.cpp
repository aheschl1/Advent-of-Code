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

    X-Lose
    Y - Draw
    Z - Win
    */
    char opponenent;
    unsigned int score = 0;
    while(cin >> opponenent){
        char me;
        cin >> me;
        if(char_to_op(opponenent) == OROCK){
            if(me == 'X'){
                //lose
                score += SCISSORS;
            }else if(me == 'Z'){
                //win
                score += 6 + PAPER;
            }else{
                //draw
                score += 3 + ROCK;
            }
        }
        if(char_to_op(opponenent) == OPAPER){
            if(me == 'X'){
                //lose
                score += ROCK;
            }else if(me == 'Z'){
                //win
                score += 6 + SCISSORS;
            }else{
                //draw
                score += 3 + PAPER;
            }
        }
        if(char_to_op(opponenent) == OSCISSORS){
            if(me == 'X'){
                //lose
                score += PAPER;
            }else if(me == 'Z'){
                //win
                score += 6 + ROCK;
            }else{
                //draw
                score += 3 + SCISSORS;
            }
        }
    }

    cout << score << endl;

    return 0;
}