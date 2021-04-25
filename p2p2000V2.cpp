// 23042021, 00:00
// problema 2 da prova de 2000
// primeiro exercicio da semana do gempro

#include <bits/stdc++.h>
using namespace std;

string solution(string toDecode);

// array struct
typedef struct tableToDecode
{
    string key; // key: string numerica que representa a sequencia de leds que forma uma letra
    string value; // value: char letra maiuscula representada pela string de numeros
} tableToDecode;


tableToDecode table[27] = {
    // os codigos devem ficar ordenados em ordem decrescente, pos strings menores podem ser substrings de string maiores e isso vai ocasionar substituicoes incorretas
    {"1234567","B"}, //8
    {"123457","A"}, // 7
    {"135790","W"},
    {"123459","R"},
    {"123567","O"},
    {"12456","E"},//6
    {"23456","Z"},
    {"13567","U"},
    {"12467","S"},
    {"12347","Q"},
    {"12357","M"},
    {"13459","K"},
    {"12569","G"},
    {"13457","H"},
    {"1580","D"}, // 5
    {"1347","Y"},
    {"1379","V"},
    {"1458","P"},
    {"3579","N"},
    {"3567","J"},
    {"1249","F"},
    {"456","C"}, //4
    {"278","T"},
    {"156","L"},
    {"37","I"}, //3
    {"90","X"},
    {"0"," "} //2
};

int main()
{
    vector<string> inputs;
    string toInsert;
    vector<string> outputs;
    clock_t t;
    
    t = clock();
    //open file to read
    ifstream Inputs("input.txt");
    while(getline(Inputs,toInsert))
    {
        inputs.push_back(toInsert);
    }
   
    for(int i = 1; i<= stoi(inputs[0]); i++)
    {
        //cout<<"\nreceived: "<<toDecode<<endl;
        outputs.push_back(solution(inputs[i]));
    }

    //create file do insert the output
    ofstream Outputs("outputs.txt");

    for(int i = 0; i< stoi(inputs[0]); i++)
    {
        Outputs<<"Phrase "<<to_string(i+1)<<": "<<outputs[i]<<endl;
        //cout<<"Phrase "<<to_string((i+1))<<": "<<outputs[i]<<endl; // output: a string modificada
    }

    Inputs.close();
    Outputs.close();
    t = clock() - t;
    float Time = (float)t/CLOCKS_PER_SEC;
    cout<<"\nTime: "<<Time<<endl;
    return 0;
}

// busca e substituicao
string solution(string toDecode)
{
  // pre condicao: recebe string contendo letras e numeros
  // pos condicao: retorna string modificada

  int index, until;
  bool replacing = true;
  string decoded;

  for(int i = 0; i<27 ;i++) 
  {
        // acha ocorrencia da substring key na string de input
        index = toDecode.find(table[i].key);
        if(index == string::npos) // the substring is not part of the string
            continue; // go to the next
        else 
        {
            while(replacing)
            {
            // substitui caracteres numericos na string de input: de find(posicao em que aparece a substring) ate find+substring.length, substitui pelo value associado a key
            until = table[i].key.length();
            //cout<<"\n i = "<<to_string(i)<<" | debug: toDecode before replacing: "<<toDecode<<endl;
            toDecode.replace(index,until,table[i].value);
            decoded = toDecode;
            //cout<<"\n i = "<<to_string(i)<<" | debug: toDecode after replacing: "<<toDecode<<" | decoded: "<<decoded<<endl;
            index = toDecode.find(table[i].key);
            if(index == string::npos)
                replacing = false;
            }
        }

        replacing = true;
    //}
    // faca isso enquanto achar for verdadeiro, se a funcao que busca ocorrencia retornar falso, para
  } // faca isso para cada caractere da struct

  return decoded;
}





/* v1

// busca e substituicao
string solution(string toDecode)
{
  // pre condicao: recebe string contendo letras e numeros
  // pos condicao: retorna string modificada

  int index, until;
  bool replacing = true;
  string decoded;

  for(int i = 0; i<27 ;i++) // i = 26, i>=0, i--
  {
      //while(replacing)
      //{
        // acha ocorrencia da substring key na string de input
        index = toDecode.find(table[i].key);
        if(index == string::npos)
            continue;
            //replacing = false; 
        else 
        {
            // substitui caracteres numericos na string de input: de find(posicao em que aparece a substring) ate find+substring.length, substitui pelo value associado a key
            until = table[i].key.length();
            cout<<"\n i = "<<to_string(i)<<" | debug: toDecode before replacing: "<<toDecode<<endl;
            toDecode.replace(index,until-1,table[i].value);
            decoded = toDecode;
            cout<<"\n i = "<<to_string(i)<<" | debug: toDecode after replacing: "<<toDecode<<" | decoded: "<<decoded<<endl;
        }

    //}
    // faca isso enquanto achar for verdadeiro, se a funcao que busca ocorrencia retornar falso, para
  } // faca isso para cada caractere da struct

  return decoded;
}


*/

/*
tableToDecode table[27] = {
    {"123457","A"},
    {"1234567","B"},
    {"456","C"},
    {"1589","D"},
    {"12456","E"},
    {"1249","F"},
    {"12569","G"},
    {"13457","H"},
    {"37","I"},
    {"3567","J"},
    {"13459","K"},
    {"156","L"},
    {"12357","M"},
    {"3579","N"},
    {"123567","O"},
    {"1458","P"},
    {"12347","Q"},
    {"123459","R"},
    {"12467","S"},
    {"278","T"},
    {"13567","U"},
    {"1379","V"},
    {"135790","W"},
    {"09","X"},
    {"1347","Y"},
    {"23456","Z"},
    {"0"," "}
};



*/