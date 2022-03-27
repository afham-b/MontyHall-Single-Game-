#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std; 

bool monty(char strategy);
int monty(char strategy, int n_games); 

int main(){
  srand(time(0)); 
  cout<< monty('k')<< endl;
  cout<< monty('s')<< endl;
  cout <<monty('r')<< endl;
  cout <<monty('r', 10000)<< endl;
  return 0; 
}

bool monty(char strategy) { 
    int doors[3]= {0,0,0}; 
    int win_door= rand()%3;
    doors[win_door]= 1; 
    int door_selection= rand()%3; 

    if (strategy== 'r'){
        int coin_flip= rand()%2; //0 means orginal door,1 is switch
        if (coin_flip == 0){
          strategy= 'k';
        }else strategy= 's'; 
    }

    switch (strategy){
      case 'k':
        if (door_selection == win_door){
          return true; 
        } else return false; 
        break;  
      case 's':
        if (door_selection == win_door){
          return false;  
        }else return true; 
        break; 
      default: return false; 
    }

  return false;
}

int monty ( char strategy, int n_games){
  int n_wins=0; 
  for( int i=0; i< n_games; i++){
    if (monty(strategy) == true){
      n_wins++; 
    } 
  }
  return n_wins; 
}
