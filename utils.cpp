#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>

using namespace std;

void cargarCadena(char *pal, int tam)
{
    std::string tmp;
    std::getline(cin, tmp);
    if (tmp.size() == 0)
    {
        std::getline(cin, tmp);
    }
    // copiar hasta tam-1 caracteres y asegurar terminación nula
    strncpy(pal, tmp.c_str(), tam - 1);
    pal[tam - 1] = '\0';
}

void waitForKey(const char* msg)
{
    cout << msg;
    std::string tmp;
    std::getline(cin, tmp);
    if (tmp.size() == 0)
    {
        std::getline(cin, tmp);
    }
}






void tolower_string(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

