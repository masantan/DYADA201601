// To solve wide char problem
// Consult http://www.cprogramming.com/tutorial/unicode.html
// http://www.nubaria.com/en/blog/?p=289

#include <iostream>
#include <string>
#include <cwctype>
#include <cwchar>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <clocale>
#include <locale>
#include <codecvt>
#include <fstream>
#include <cstdlib>

#define ln(a)  ( (a).length())
#define str(a) ( (a).c_str() )

using namespace std;

vector < wstring > known_message;

int main()
{
    int testcases;
    wstring line, word;


    const locale empty_locale = locale::global();
    typedef codecvt_utf8<wchar_t> converter_type;
    const converter_type* converter = new converter_type;
    const locale utf8_locale = locale(empty_locale, converter);
    wifstream stream(L"test.txt");
    stream.imbue(utf8_locale);
    wstring line;
    getline(stream, line);
    system("pause");

    // Get the original message and split it in words
    getline( wcin, line );
    wistringstream msg (line);
    while(msg >> word)
    {
        known_message.push_back(word);
        wcout << word << " " << wcslen(word.c_str()) << " " << ln(word)  << " "<< endl << endl;
    }


    /*scanf("%d\n\n",&testcases);

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
    */

    return 0;
}
