#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#define sz(a) ((a).length())
#define str(a) ((a).c_str())

using namespace std;

const  char *known_message [ ] = {
"El","veloz","murciélago","hindú",
"comía", "feliz", "cardillo", "y",
"kiwi", "cuando", "la", "cigüeña",
"tocaba","el", "saxofón","detrás",
"del",  "palenque", "de", "paja"};

vector <string> message(known_message, known_message+20);

int main()
{
    int testcases;
    string line, word;

    scanf("%d\n\n",&testcases);

    while( testcases-- )
    {
        vector < string > text;
        while( getline(cin,line) )
        {
            if( line.size() == 0 ) break;
            istringstream in (line);
            while(in >> word) text.push_back(word);
        }
        for( int i = 0; i < text.size(); i++ )
        {
            bool candidate = true;
            for( int j = 0; j < message.size(); j++ )
            {
                if( i + j > text.size() )
                {
                    printf("I %d out of boundary\n",i);
                    candidate = false;
                    break;
                }
                printf("Compare %s %s\n",str(message[j]),str(text[i+j]));
                printf("sz = %d , sz = %d\n",(int)sz(message[j]),(int)sz(text[i+j]));
                if( sz(message[j]) != sz(text[i+j]) )
                {
                    //puts("Missmatch");
                    candidate = false;
                    break;
                }
            }
            if( candidate )
            {
                //map <char,char> dictionary;
                printf("I = %d is a candidate\n",i);
            }
            puts("");
        }
        if( testcases > 1 ) puts("");
    }

    return 0;
}
