#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

/*
changePossibilities(amount,amount): Your quirky boss collects rare, old coins. They found out you're a programmer 
and asked you to solve something they've been wondering for a long time. 

Write a function that, given an amount of money and an array of coin denominations, 
computes the number of ways to make the amount of money with coins of the available denominations. 

Example: for amount=4 (4¢) and denominations=[1,2,3] (1¢, 2¢ and 3¢), your program would output 4—
the number of ways to make 4¢ with those denominations: 

1¢, 1¢, 1¢, 1¢
1¢, 1¢, 2¢
1¢, 3¢
2¢, 2¢

*/
int changePossibilities(int amount, vector<int> denominations) {
    vector<int> possibilities(amount);

  for (int i = 1; i <= amount; i++) {
      possibilities[i] = 0; 
  }
  possibilities[0] = 1;

    //initialize possibilities array with zeroes, use first slot as 1 for first remainder operation
    //iterate through all denominations, and for each amount fill in possibilities
    
  for(int j = 0; j < denominations.size(); j++){
      int coin = denominations[j];  //assign coin denomination
        
      for (int a = coin; a <= amount; a++) {
          int remainder = a - coin; //find remainder for each coin amount
          possibilities[a] += possibilities[remainder]; //fill array with possibilities using sum of remainder and current slot
      }      
  }

  return possibilities[amount]; 
} 

int main(){
    int arr[] = {1,2,3};
    int amount = 4;
    std::vector<int> denominations (arr, arr + sizeof(arr) / sizeof(int) );
    cout<<"#num possibilities: "<<changePossibilities(amount,denominations);
    system("PAUSE");
}