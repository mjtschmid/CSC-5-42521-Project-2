/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Output formatting
#include <fstream>   //File input/output
#include <cstdlib>   //Rand/Srand
#include <ctime>     //Time
#include <vector>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void rllDice(int []);
void reroll(int [], vector<int>);
void selSort(int [], int);
void bublSrt(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variables
    int dice [5], rndScrg(1), score(0), round(1), hiScore;
    bool rndScrd(false), ones(false), twos(false), threes(false), fours(false), fives(false), sixes(false);
    const string title = "Yahtzee-lite";
    //Title text
    cout << title << endl << endl;

    //Initialize game, six rounds
    do{
        cout << "Round " << round << "/6" << endl;

        //Roll the dice each round
        rllDice(dice);

        //Determine score for round based on user selection
        //Stop displaying round options as they are used
        cout << "Select scoring for this round:\n";
        if (ones == false) {
            cout << "1. Ones" << endl;
        } else { cout << "1. USED" << endl; }
        if (twos == false) {
            cout << "2. Twos" << endl;
        } else { cout << "2. USED" << endl; }
        if (threes == false) {
            cout << "3. Threes" << endl;
        } else { cout << "3. USED" << endl; }
        if (fours == false) {
            cout << "4. Fours" << endl;
        } else { cout << "4. USED" << endl; }
        if (fives == false) {
            cout << "5. Fives" << endl;
        } else { cout << "5. USED" << endl; }
        if (sixes == false) {
            cout << "6. Sixes" << endl;
        } else { cout << "6. USED" << endl; }

        //Take user input, determine round scoring
        do {
            cin >> rndScrg;
            switch(rndScrg){
                case 1:
                    if (ones == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 1) {
                                score += 1;
                            }
                        }
                        ones = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
                 case 2:
                    if (twos == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 2) {
                                score += 2;
                            }
                        }
                        twos = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
                 case 3:
                    if (threes == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 3) {
                                score += 3;
                            }
                        }
                        threes = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
                case 4:
                    if (fours == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 4) {
                                score += 4;
                            }
                        }
                        fours = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
                 case 5:
                    if (fives == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 5) {
                                score += 5;
                            }
                        }
                        fives = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
                 case 6:
                    if (sixes == false) {
                        for (int i = 0; i <= 4; ++i) {
                            if (dice[i] == 6) {
                                score += 6;
                            }
                        }
                        sixes = true;
                        rndScrd = true;
                    } else {
                        cout << "You've already used that one!\nMake a different selection: ";
                    }
                    break;
            }
        } while (rndScrd == false);

        //advance to next round
        ++round;
        rndScrd = false;
    } while (round <= 6);

    //Final round over, display final score
    cout << endl << "Game complete!\nFinal score: " << score << endl;
    
    //Check current score vs high score
    ifstream highfile ("highscore.txt");
    highfile >> hiScore;
    highfile.close();
    
    //Update/display high score
    if(score > hiScore){
        ofstream highfile ("highscore.txt");
        highfile << score;
        highfile.close();
        cout << "New High Score!";
        
    } else{
        cout << "High score: " << setw(2) << hiScore;
    }

    //Exit stage right or left!
    return 0;
}

void rllDice(int dice[]) {
    //Initial roll
    for (int i = 0; i <= 4; i++){
            dice[i] = rand() % 6 + 1;
        }
    selSort(dice, 5);

    //Display dice values
    cout << "            [1] [2] [3] [4] [5]\nDice values: ";
    for (int i = 0; i <= 4; i++){
        cout << dice[i] << "   ";
    }
    cout << endl << endl;
    
    //Reroll once if desired
    cout << "Select dice to reroll. Enter selections separated by spaces " << endl
         << "Enter 'x' after inputting choices, or enter 'x' alone for no reroll: ";
    vector<int> rer;
    reroll(dice, rer);
    
}

void reroll(int dice[], vector<int> rer) {
    
    // Get user input for dice to reroll
    int value = 0;
    while (cin >> value)
        rer.push_back(value);
    
    //Clear input buffer to make
    //cin work correctly later
    cin.clear ();
    cin.ignore ( 100 , '\n' );
    
    // Put rerolled values into appropriate
    // positions in dice array
    for (int i = 0; i < rer.size(); i++) {
        dice[rer[i] - 1] = rand() % 6 + 1;
    }
    
    // Display adjusted dice values
    cout << "            [1] [2] [3] [4] [5]\nDice values: ";
    for (int i = 0; i <= 4; i++){
        cout << dice[i] << "   ";
    }
    cout << endl;
}

void selSort(int arr[],int size) {
    int minIndex, minValue;
    
    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = arr[start];
        for (int index = start + 1; index < size; index++) {
            if (arr[index] < minValue) {
                minValue = arr[index];
                minIndex = index;
            }
        }
    int temp = arr[minIndex];
    arr[minIndex] = arr[start];
    arr[start] = temp;
    }
}

void bublSrt(int arr[],int size) {
    int maxElement, index;
    
    for (maxElement = size - 1; maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (arr[index] > arr [index + 1]) {
                int temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
            }
        }
    }
}