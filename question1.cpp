#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
sortByStrings(s,t): Sort the letters in the string s by the order they occur in the string t.
You can assume t will not have repetitive characters. For s = "weather" and t = "therapyw",
the output should be sortByString(s, t) = "theeraw". For s = "good" and t = "odg",
the output should be sortByString(s, t) = "oodg".
*/
int main()
{

    string s = "weather";
    string t = "therapyw";

    unordered_map<char,int> stringMap;  //to represent each letter in t and the # of occurrences in s
    unordered_map<char,int>::iterator it = stringMap.begin();

    
    
    //insert each character of t into map
    for(int i = 0; i < t.length(); i++){
        stringMap.insert(it, pair<char,int>(t[i],0));
        it++;
    }
    
    
    //if character in s is found, increment
   for(int i = 0; i < s.length(); i++){
        if(stringMap.find(s[i]) != stringMap.end())
            stringMap[s[i]]++;
    }
    
    // showing contents:
    cout << "stringMap contains:\n";
    for (it=stringMap.begin(); it!=stringMap.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    
    //print in order
    for(int i = 0; i < t.length(); i++){
        while(stringMap[t[i]] != 0){
            cout<<t[i];
            stringMap[t[i]]--;
        }
    }

    system("PAUSE");

}