#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

CString1::CString1(): CString(""){}

CString1::CString1(char* text): CString(text){}

CString1::CString1(Line line): CString(line){}

CString1::CString1(const CString& second) : CString(second) {}

CString1& CString1::operator=(char* second)
{
    str = second;
    len = static_cast<int>(strlen(second));
    return *this;
}

void CString1::output(const char *FileName)
{
    isFabric = false;
    if (FileName == NULL)
    {
        isFabric = true;
        FileName = fname;
    }

    ofstream file(FileName);
    if (!file)
    {
        cout << "Failed to open file (CString1.cpp: row 37)" << endl;
    }
    int len = 0;
    char* word = new char[1]();
    char* str;

    if (isFabric) {str = line.Data; }
    else {str = this->str; }

    for (int i = 0; i < static_cast<int>(strlen(str)); i++) 
    {
        if (str[i] == ' ')
        {
            file << word << endl;
            delete[] word;
            word = new char[1]();
            continue;
        }
        if (i == (static_cast<int>(strlen(str))-1) && str[i] != ' ')
        {
            char* tmp = new char[strlen(word) + 2]();
            tmp = strcat(tmp, word);
            tmp[strlen(word)] = str[i];
            swap(word, tmp);
            delete[] tmp;
            file << word << endl;
            delete[] word;
        }
        else
        {
            char* tmp = new char[strlen(word) + 2]();
            tmp = strcat(tmp, word);
            tmp[strlen(word)] = str[i];
            swap(word, tmp);
            delete[] tmp;
        }
    }
}