#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

/*
    decodeString(s): Given an encoded string, return its corresponding decoded string. 

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times. Note: k is guaranteed to be a positive integer. 

For s = "4[ab]", the output should be decodeString(s) = "abababab" 
For s = "2[b3[a]]", the output should be decodeString(s) = "baaabaaa"

*/
//converts character to integer equivalent
int convertToInt(char c){
    int num = c - '0';
    return num;
}
//checks if value is between 0 and 9
bool checkRange(int num){
    if(num >= 0 && num <= 9)
        return true;
    return false;
}
int main(){
    stack<int> numStack;    //store coefficients
    stack<char> patternStack;   //store patterns inside brackets
    string input = "2[b3[a]]"; //initial pattern
    string result = ""; //final output

    for(int i = 0; i < input.length(); i++){
        int num = 0;
        string temp = "";

        //if number, push to numStack
        if(checkRange(convertToInt(input[i]))){
            num = convertToInt(input[i]);
            numStack.push(num);
        }
        //if close bracket, build temp string from what is on pattern stack and pop each character
        //if top of stack is open bracket, pop character from stack
        //store top of numstack and repeat temp that many times, then push to pattern stack
        else if(input[i] == ']'){
            while(patternStack.top() != '['){
                temp += patternStack.top();
                patternStack.pop();
            } 
            if(patternStack.top() == '[')
                patternStack.pop();
            
            if(!numStack.empty()){
                num = numStack.top();
                numStack.pop();
            }
            // Repeat pattern # of times of # on numStack
            for (int j = 0; j < num; j++)
                result += temp;
 
            // Push to pattern stack.
            for (int j = 0; j < result.length(); j++)
                patternStack.push(result[j]);
 
            result = "";
        }
        else{
            patternStack.push(input[i]);
        }
    } 

        while (! patternStack.empty())
    {
        result += patternStack.top();
        patternStack.pop();
    }

    cout<<result<<endl;
    system("PAUSE");

}