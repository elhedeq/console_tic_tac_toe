#include <iostream>

using namespace std;

char winCheck();
void welcomeScreen();
bool endOfGame();

int position=20,nums[9]={1,2,3,4,5,6,7,8,9}; //position is the input of user here initialized to 20 to allow the while loop to begin
                                             //nums is array holding the map(grid) positions
bool x=true,printed[9];                      //x is boolean specifying the turn x or o, printed is boolean array helping is specifying what to print
char xo[9],player;                           //array to record the inputs

int main() {
    while(position!=0){
        system("clear");
        welcomeScreen();
        int index=0;
        for (int i=0;i<3;i++){                                              //y dimension
            for (int j=0;j<13;j++){                                         //x dimension
                if(j==0||j==4||j==8||j==12)                                 //borders positions
                    cout<<"|";                                              //printing borders

                else if(j==2||j==6||j==10){                                 //playing positions (cells)
                    if(nums[index]==10){                                    //check if there was input X or O
                        for(int k=0;k<9;k++){                               //if so, for loop on the input
                            if((xo[k]=='X'||xo[k]=='O')&&!printed[k]){      //if there was input that wasn't printed yet at the grid
                                cout<<xo[k];                                //print it
                                printed[k]=true;                            //record that it was printed at the grid
                                break;                                      //break the loop so that it doesn't ruin the rest of the grid
                            }
                        }
                    }
                    else
                        cout<<nums[index];                                  //if there wasn't input at that cell print the map number
                    index++;                                                //incrementing index so that the next element is printed
                }
                else
                    cout<<" ";                                              //spaces between borders and contents
            }
            cout<<'\n';                                                     //breakline to go to the next row on grid
        }
        for(int i=0;i<9;i++){                                               //reseting the printed array values to be used in the next step
            printed[i]=false;
        }
        if(winCheck()=='X'||winCheck()=='O'){                               //checking if there was a win 
            cout<<winCheck()<<" wins\n";                                      //if so prints who won
            break;                                                          //breaking the loop and ending the game
        }
        if(winCheck()=='d'){
            cout<<"Draw\n";
            break;
        }
            
        player=(x==true)?'X':'O';
        cout<<player<<": which position you want to play?(from 1 to 9)\t(type 0 to exit)\n";
                                                                            //if there wasn't a win asking the player to choose position
        cin>>position;                                                      //getting position
        if(position==0)
            break;
        if(position<0||position>9)
            continue;
        nums[position-1]=10;                                                //recording input position by canceling the existance of a valid position number
        if(x!=true)                                                         //if the last input wasn't X
            xo[position-1]='O';                                             //put the input as O
        else
            xo[position-1]='X';                                             //else put the input as X
        x=!x;                                                               //switching between X and O
    }
    return 0;
}

char winCheck(){
    if(xo[0]||xo[4]||xo[8]){                                                                        //checking if there were inputs to avoid returning the default values on the array (default array values are all nulls {equal values})
        if((xo[0]==xo[3]&&xo[0]==xo[6])||(xo[0]==xo[1]&&xo[0]==xo[2])||(xo[0]==xo[4]&&xo[0]==xo[8]))//win cases
            return xo[0];
        if(xo[1]==xo[4]&&xo[1]==xo[7])                                                              //win cases
            return xo[1];
        if((xo[2]==xo[5]&&xo[2]==xo[8])||(xo[2]==xo[4]&&xo[2]==xo[6]))                              //win cases
            return xo[2];
        if(xo[3]==xo[4]&&xo[3]==xo[5])                                                              //win cases
            return xo[3];
        if(xo[6]==xo[7]&&xo[6]==xo[8])                                                              //win cases
            return xo[6];
        if(endOfGame())
            return 'd';
        return '\0';                                                                                //returning null if there wasn't any win
    }
}

void welcomeScreen(){
    cout<<"Welcome to CLI Tic Tac Toe\n";
    for(int i=0;i<26;i++)
        cout<<"-";
    cout<<'\n';
}

bool endOfGame(){
    for(int i=0;i<9;i++){
        if(!xo[i])
            return false;
    }
    return true;
}