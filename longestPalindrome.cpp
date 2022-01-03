/*
2021

Apresentação no GEMPRO
O algoritmo de Manacher possibilita encontrar o palíndromo mais longo em uma string de forma eficiente O(n)

*/
#include <bits/stdc++.h>
using namespace std;

string findPalindrome1(string s);
bool isPalindrome(string s);
string findPalindrome2(string s);
int expandFromMiddle(string s, int left, int right);
string findPalindrome3(string s);
string modifyString(string s);

int main()
{
    int option;
    char choice;
    bool procceed = true;
    string entry;
    string answer;
    while(procceed == true)
    {
        cout<<"String 'entry':\n";
        cin>>entry;

        cout<<"1-N3\n2-N2\n3-Manacher's\n4-Quit"<<endl;
        cin>>option;
        if(option == 4)
            break;
        else 
        {
            switch(option)
            {
                case 1: answer = findPalindrome1(entry);
                cout<<"Answer: \n"<<answer<<"\n";
                break;
                case 2: answer = findPalindrome2(entry);
                cout<<"Answer: \n"<<answer<<"\n";
                break;
                case 3: answer = findPalindrome3(entry);
                cout<<"Answer: \n"<<answer<<"\n";
                break;
                default:
                cout<<"\nInvalid option!\n";
                break;
            }

            cout<<"Procceed? 'y' || 'n'\n";
            cin>>choice;
            if(choice == 'n') 
                procceed = false;
             
        }
    }
    return 0;
}


string findPalindrome1(string s)
{
    int longest = 0;
    string thePalindrome = " ";
    int len = s.length();

    if(len == 1)
        return s;
    else if(len < 1)
        return " ";
        
    for(int left = 0; left < len; left ++)
    {
        for(int right = left; right < len; right++)
        {
            int size = right - left + 1;
            string subs = s.substr(left,size);
        
            if(isPalindrome(subs) && size > longest)
            {
                
                longest = size;
                thePalindrome = subs;
            }
        }
    }
    
    
    return thePalindrome;
}

bool isPalindrome(string s)
{
    string reversedString = s;
    reverse(reversedString.begin(),reversedString.end());
    
    return (s == reversedString);
}
string findPalindrome2(string s)
{
    int size = s.length();

    if(size == 1)
        return s;
    else if(size < 1)
        return " ";
    
    int start = 0;
    int end = 0;
    for(int i = 0; i < size; i++)
    {
        int len1 = expandFromMiddle(s,i,i);
        int len2 = expandFromMiddle(s,i,i+1);
        int len = max(len1,len2);
       

        if(len > (end-start))
        {
            start = i - ((len-1)/2);
            end = i + (len/2);
        }
    }
    
    return s.substr(start, end-start+1);
}

int expandFromMiddle(string s, int left, int right)
{
    if(left > right)
        return 0;
    
    while(left >= 0 && right < s.length() && s[left] == s[right])
    {
        left --;
        right ++;
    }
    
    return (right - left -1);
}

string findPalindrome3(string s)
{   
    string ss = modifyString(s); // modified string that will serve our purposes
    vector <int> P(ss.length(),0);

    int center = 0;
    int rightBoundary = 0; // right boundary, it will change throughout the execution

    for(int i = 0; i< ss.length(); i++)
    {
        // the mirror value is important. this is the mirror of the current value
        // it is based on the previously defined center (which is the position of the center of the biggest palindrome calculated so far)
        // Ex: a b a a b c 
        int mirrorPosition = center - (i - center);

        // tells where the mirror index would be

        //check if i < right boundary
        if(i < rightBoundary) // use previously calculated values. mirror is useful here
            P[i] = min(rightBoundary -i,P[mirrorPosition]); // what this will tell us: i is the center of a palindrome if size AT LEAST P[i]
            // then, we can expand and see if it is bigger
        else 
            P[i] = 0;
        
        int right = i + 1 + P[i]; // by the previous calculation, we know that from i there is a palindrome of size P[i], at least
        int left = i - 1 - P[i]; // we can see this step as a "manual" expansion, going 1 position backwards and forward in order to enter the loop expansion or not
        
        // expansion
        while(right < ss.length() && left >= 0 && ss[left] == ss[right])
        {
            P[i]++;
            right++;
            left--;
        }

        // current position + size of substring
        if(i + P[i] > rightBoundary) // update the right boundary because the new palindrome has a right end farther than the previous
        {
            // se ha um palindromo maior a partir de i, ele sera o novo centro 
            center = i; // the current character is the new center
            rightBoundary = i + P[i]; // update de right boundary
        }
    }
    
    // this part is to get the index position and construct the substring that will be returned
    int longestPalindromeSize = *max_element(P.begin(),P.end());
    auto iterator = find(P.begin(),P.end(), longestPalindromeSize);
    int index = iterator - P.begin();
    
    stringstream answer;
    
    for(int j = index - longestPalindromeSize;j < index + longestPalindromeSize;j++)
        if(ss[j] != '#') answer<<ss[j];
    
    return answer.str();
}

string modifyString(string s)
{
    string newCharacter = "#";
    string newString = " ";

    for(int i = 0; i <=s.length();i++)
    {
        newString += newCharacter;
        newString += s[i];
    }

    return newString;
}

