#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string expand(const string &s) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9'){
            int times = s[i] - '0';
            for(int j = 0;j<times;j++){
                result = result + s[i-1];
            }
        }
        else{
            continue;
        }
    }
    return result;
}

string Frequency(const string &s) {
    string result = "";
    int n = s.size();
    result += s[0];
    int count = 1;
    for(int i = 1;i<n;i++){
        if(s[i] == s[i-1]){
            count++;
        }
        else{
            result += to_string(count);
            count = 1;
            result += s[i];
        }
    }
    result += to_string(count);
    return result;
}

bool Prime(int n) {
    if(n <= 1 ) return false;
    for(int i = 2;i<n;i++){
        if(n % i == 0) return false;
    }
    return true;
}

int Length(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n = n/10;
    }
    return cnt;
}

void numberToString(int n){
    if(n == 0) cout<<"zero"<<endl;
    else if(n == 1000) cout<<"one-thousand"<<endl;
    else{
    vector<string> singleDigit = {"one","two","three","four","five","six","seven","eight","nine"};
    vector<string> doubleDigit = {"ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    vector<string> threeDigit = {"one-hundred","two-hundred","three-hundred","four-hundred","five-hundred","six-hundred","seven-hundred","eight-hundred","nine-hundred"};
    while(n > 0){
            int len = Length(n);
            int dig = n%10;
            if(len == 1) {
                cout<<singleDigit[dig-1]<<" ";
            }
            else if(len == 2) cout<<doubleDigit[dig-1]<<" ";
            else cout<<threeDigit[dig-1]<<" ";
            n = n/10;
        }
    }
}

int reverse(int & n){
    int i = 0;
    int newNum = 0;
    while(n > 0){
        int dig = n % 10;
        newNum = newNum * 10 + dig;
        n = n/10;  
    }
    return newNum;
}


int lengthOfLongestSubstring() {
    cout << "Enter a string:";
    string inputString;
    cin >> inputString;

    vector<int> indices(26, -1);
    int maxLength = 0;
    int left = 0, right = 0;

    while (right < inputString.size()) {
        char currCharacter = inputString[right];
        if (indices[currCharacter - 'a'] >= left) {
            left = indices[currCharacter - 'a'] + 1;
        }
        int currLength = right - left + 1;
        if (currLength > maxLength) maxLength = currLength;
        indices[currCharacter - 'a'] = right;
        right++;
    }
    return maxLength;
}

int main() {
    cout << "Choose a task:\n";
    cout<<"1.Expand Characters in a String\n";
    cout<<"2.Character Frequency in a String\n";
    cout<<"3.Prime Number Checker\n";
    cout<<"4.Number to Words Converter\n";
    cout<<"5.Longest Substring Without Repeating Characters\n";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        {
        string s;
        cout << "Enter string (e.g. -> a1b4c3): ";
        cin >> s;
        cout << "Expanded: " << expand(s) << endl;
        break;
    }
    case 2:
        {
        string s;
        cout << "Enter string: ";
        cin >> s;
        cout << "Compressed Frequency: " <<Frequency(s) << endl;
        break;
    }
    case 3:
        {
        int n;
        cout << "Enter number: ";
        cin >> n;
        if (Prime(n)) cout << "The given number is PRIME\n";
        else cout << "The given number is NOT prime\n";
        break;
    }
    case 4:
        {
        int n;
        cout << "Enter number (1-1000): ";
        cin >> n;
        n = reverse(n);
        numberToString(n);
        break;
    }
    case 5:
        {
        int maxi = lengthOfLongestSubstring();
        cout<<maxi<<endl;
    }
    default:
        cout<<"Please enter a valid option"<<endl;
        break;
    }
    
    return 0;
}

