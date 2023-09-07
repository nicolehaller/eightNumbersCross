//Nicole Haller CSCI 211
//8 numbers in a cross

#include <iostream>
using namespace std;

//prints each valid cross
void print (int q[]){
    static int solutions = 0;
    solutions++;
    cout << "solution #" << solutions << endl;
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << "  " << q[6] << " " << q[7] << endl;
    cout << endl;
}

//function that makes sure the number you placed in a box is okay before moving on
bool okay(int q[], int c){ //c = what box you are currently in

    /*
    [0][1]
[2][3][4][5]
    [6][7]
    */

   //creates a helper array with 8 rows because there are 8 boxes, and with 5 columns because the largest column needed is 5
    static int helperArray[8][5]={ 
        //lists which boxes are adjacent to the current box in order to know which boxes to test
        //once reaches -1 there are no more adjacent boxes
        {-1}, //box 0 (c==0)
        {0, -1}, //box 1 
        {0, -1}, //box 2 
        {0, 1, 2, -1}, //box 3
        {0, 1, 3, -1}, //box 4
        {1, 4, -1}, //box 5
        {2, 3, 4, -1}, //box 6
        {3, 4, 5, 6, -1} //box 7
        };

    //test if a number has already been placed before it
    for (int i=0; i<c; i++) { //c is index of array you are in
        if (q[c]== q[i]){
                 return false;
        }
        // cant return true yet because have to check adjacent boxes
    }
    
    // check all adjacent boxes for a consecutive number 
    for (int i=0; helperArray[c][i] != -1; i++) { //IMP: helperArray[c][i] bc  want to check row of the helperarray where ur box ur in is(which is c)
        //if find a consecutive number in an adjacent box, it isnt an okay number to place
        if (q[helperArray[c][i]]== q[c] + 1 || q[helperArray[c][i]]== q[c] - 1){
        //same as
        //if (abs(q[helperArray[c][i]] - q[c]) == 1) return false;
        //same as
        //if (q[helperArray[c][i]] + 1 == q[c] || q[helperArray[c][i]] - 1 == q[c])
            return false;
        }
        
    }

    // only when passes both tests do we return true
    return true; 
}// end bool


int main(){
    int q[8] = {1, 1, 1, 1, 1, 1 ,1, 1}; //places 1 in every index 
    int c = 0;

    //while didnt find all solutions, continue though loop
    while (c != -1){

        //if exceeded last box (box 7) we have a solution                                                                                                                                                                                                                      
        if (c>7) {
            //prints solution 
            print (q);

            //reset number in box to one before we backtrack 
            q[c] = 1; 

            //backtrack
            c--;

            // check if we are off the board and if we are we are, then we are done with all solutions
            if (c==-1) return 0;

            //if we are still on the board then we increase the value in the box by one
            else q[c]++;
        }

        // if we've run out of numbers to try because none passed the okay test
        if (q[c] == 9){
            //resets value in that box to 1 before backtracking so that 9 doesnt stay in that box
            q[c]=1; 

            //backtrack
            c--; 
            if (c==-1) return 0;
            else q[c]++;
        } 

        else if (okay(q, c)){
            //if valid so far move onto next box
            c++;
        }

        //if not a valid configuration, increment number in the box 
         else {
            q[c]++;
           
        }
    }

    //when c==-1 all solutions have been found
    cout << "all done";
    return 0; 
}

