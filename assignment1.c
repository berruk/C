#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_score(int one, int two){
    printf("%d-%d",one,two);
}

bool isTie(int one, int two){
    if(one==two && one>= 40 && two >= 40)
        return true;
    return false; 

}

int win(int one,int two,bool tie,int point,int adv){
    if(adv==point){
        return point;
    }
    else if(one==41){
        return 1;
    }
    else if(two==41){
        return 2;
    }
    else{ //no win
        return -1;
    }

} 
int main(){
    int player1=0,player2=0; //initialize each player's scores  
    int point,winner=-1,adv,rounds=0;
    bool tie=false,prev_tie=false;
    printf("0-0");
    while(winner==-1){ 
    printf("\nPoint: ");
    scanf("%d",&point);
    if(point ==1){
        if(player1==30)
            player1+= 10;
        else if(player1<30){
        player1 += 15;
        }
        else{
            if(player2<30){
            printf("GAME: PLAYER 1");
            break;
            }
            else if(!tie){
                player1++;
            }
        }
    }
    else if(point ==2){
        if(player2==30)
            player2+= 10;
        else if(player2<30){
            player2 += 15;
        }
        else{
            if(player1<30){
            printf("GAME: PLAYER 2");
            break;
            }
            else if(!tie){
                player2++;
            }
        }
    }
   
    winner = win(player1,player2,tie,point,adv);
    tie = isTie(player1,player2);


    if(prev_tie && winner==-1 ){
        if(rounds%2==0){
        printf("ADVANTAGE: PLAYER %d",point);
        adv = point;
        }
        else{
            adv = 0;
            printf("DEUCE");
        }
    }
    else if(tie && !prev_tie){
        printf("DEUCE");
        prev_tie = true;
    }
    else if(winner!=-1){
        printf("GAME: PLAYER %d",winner);
    }
    else{
        print_score(player1,player2);
    }
        prev_tie = tie;
        rounds++;
    }

}