// Maria Vitoria - 2021
// icpc problem

#include <bits/stdc++.h>
using namespace std;

void findMatch(int n,vector<string> genteco, vector<string> genco);
void makeArray(string l1,string l2, vector<string> &gentec, vector<string> &genco);

int main()
{
    
    /*
    input file is like:

   0  n 
   1  l1
   2  l2
   3  n
   4  l1
   5  l2
   6  0 -> end

    */

   // read input file

   string line;
   int countLines=0;
   vector<string> input;

   ifstream Inputs("inputGC.txt");
    while(getline(Inputs,line))
    {
        input.push_back(line);
        countLines++;
    }
    
    int n = 1;
    string l1,l2;
    vector<string> gentec,genco;

    for(int i=0;i<=countLines;i+=3) // 0, 0+3 = 3, 3+3 = 6
    {
        
        n = stoi(input[i]);
        if(n==0)
            break;
        l1 = input[i+1];
        l2 = input[i+2];
        makeArray(l1,l2,gentec,genco);
        findMatch(n,gentec,genco);
        //cout<<"i = "<<to_string(i)<<", l1: "<<l1<<endl;
        //cout<<"i = "<<to_string(i)<<", gentec: "<<gentec[1]<<endl;
        /*for(int k = 0; k< gentec.size();k++)
        {
            cout<<" k = "<<to_string(k)<<":"<<gentec[k]<<endl;
        }*/
        gentec.clear();
        genco.clear();
    }
      

    return 0;
}

void makeArray(string l1,string l2, vector<string> &gentec, vector<string> &genco)
{
    int j;
    int size = l1.length();
    int until = size - 4;
    for(j=0;j<=until;j += 5)
    {
        gentec.push_back(l1.substr(j,4));
        genco.push_back(l2.substr(j,4));

    }
}

void findMatch(int n,vector<string> genteco, vector<string> genco)
{   
    string match;
    int matchSize;
    vector<string>::iterator toDelete;
    char toCheck;
    string output[4][5];
    // call function to initiliaze this string
    int l=0,c=0;

    for(int j = 0; j<n;j++) // for each variaton of gentec
    {
        for(int i = 65; i<=84;i++) // find if letter is in the variation
        {
            if(genteco[j].find(char(i))!= string::npos) // letter is in aspect
            {
                 match.append(genco[j]); // put possibilities of matches in this string
                 for(int k = j+1;k<n;k++) // search in the next intervals for the letter
                 {
                     // for each aspect, there are 4 letters, ex: AGNP and egmr
                     if(genteco[k].find(char(i))!= string::npos) // if the letter is in another interval of genteco
                     {
                         for(int x = 0;x<match.size();i++) // delete the possibilities of match comparing the string match with the correspondent genco string
                         {
                             
                             if(genco[k].find(match[x])==string::npos) // if a character of match is not in the correspondent genco string, it can not be a match possibilitie for character i
                             {
                                match.erase(match.begin()+x); // CHECK IF IT IS X -1 OR X
                             }
                             // else: match remains the same
                             else 
                                continue;
                         }
                     }
                     // else: go to next variation/interval/string
                     else 
                        continue;
                 }
                if(match.size()==1) // the character was in variation[j] of gentec and after searching in the next variations, found a match
                {
                    output[l][c] = char(i)+"-"+match;
                    l++;c++; 
                    
                }    
                    // apagar a letra de todos os intervalos!
                else
                {
                    output[l][c] = char(i)+"-"+ '?';
                    l++; c++; 
                } 
            }
            else 
                continue; // letter is not in this substring
        }
    }

   
}
     // from char(65) = A to char(84) = T
     // is A in genteco[1] ? if it is, is string match empty? yes: match = genco[2], no: (next case)
     // is A in genteco[2] ? if it is, erase the characters in match that are not in genco[2]
     // ...
     // after searching from 0 to 4 (5 sets os strings), if match,length() == 1 -> there is a unequivocall match -> output[l][c] = "A"-"match"
     // erase A from genteco and match from genco, match = " "
     // else: no good match -> output[l][c] = "A"-"?"
     // go to B and so on
