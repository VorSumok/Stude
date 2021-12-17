#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <windows.h>
#include <iomanip>

namespace MS
{
    bool needChange(char n)
    {
        int k = 0;
        char cool[24] = { 'é','ö','ê','í','ã','ø','ù,','ç','õ','ú','ô','â','ï','ð','ë','ä','æ','÷','ñ','ì','ò','á','ü'};
        for (int i = 0; i < 24; i++)
        {
            if (n == cool[i])
                k++;
        }
        if (k == 1)
            return true;
        else
            return false;
    }


    int Programs(std::string s1, std::string s2)
    {
        std::string word;
        char carr[100];
        for (int j = 0; j < 100; j++)
        {
            carr[j] = ' ';
        }
        int l;
        bool prov;
        std::string mi;
        std::ifstream in(s1);
        std::ofstream out(s2);
        in >> carr;
        for (char* c = carr; *c; ++c)
        {
            if (MS::needChange(*c) == true)
            {
                mi = toupper(*c);
                out << mi;
            }
            else
            {
                out << *c;
            }

        }

        return 0;
    }

}