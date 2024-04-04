#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

char getComputerMove(){

    int move;
    srand(time(NULL));

    move = rand()%3;

    if(move == 0){
        return 'r';
    }
    else if(move == 1){
        return 'p';
    }
    else{
        return 's';
    }
}

int getResults(char playerMove, char computerMove){

    if(playerMove == computerMove){
        return 0;
    }


    if(playerMove == 'r' && computerMove == 'p'){
        return 2;
    }
    if(playerMove == 'r' && computerMove == 's'){
        return 1;
    }

    if(playerMove == 'p' && computerMove == 's'){
        return 1;
    }

    if(playerMove == 'p' && computerMove == 'r'){
        return 2;
    }

    if(playerMove == 's' && computerMove == 'r'){
        return 2;
    }

    if(playerMove == 's' && computerMove == 'p'){
        return 1;
    }
    return 0;
}

int main(){

    char playermove;

    cout<<"\n\n\n\t\t\t Welcome to Rock Paper Scissors\t\n\n";
    cout<<"\t\t\t Enter 'r' for Rock, 'p' for Paper or 's' for Scissors\n\n";

    while(true){
        cin>>playermove;

        if(playermove == 'r' || playermove == 'p' || playermove == 's'){
            break;
        }
        else{
            cout<<"\t\t\n Invalid Player Move, Please Try Again !! \t\t\n\n";
        }
    }

    // Find Computer Move
    char computerMove = getComputerMove();

    int result = getResults(playermove, computerMove);

    if(result == 0){
        cout<<"\n\n\t\t\t\t Game Draw !! \n";
    }
    else if(result == 1){
        cout<<"\n\n\t\t\t\t Congratulations, You Win\n\n";
    }
    else{
        cout<<"\n\n\t\t\t\t Oops !! Computer Wins the Game \n\n";
    }


    // Show moves 
    cout<<"\t\tYour Move -> "<<playermove<<endl;
    cout<<"\t\tComputer's Move -> "<<computerMove<<endl;

    return 0;
}