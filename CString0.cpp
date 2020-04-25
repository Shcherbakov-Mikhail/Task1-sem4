#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

CString0::CString0(): CString(""){}

CString0::CString0(char* text): CString(text){}

CString0::CString0(Line line): CString(line){}

CString0& CString0::operator=(char* second)
{
    str = second;
    len = static_cast<int>(strlen(second));
    return *this;
}

CString0::CString0(const CString& second) : CString(second) {}

void CString0::output(const char* FileName)
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

    if (isFabric) { str = line.Data; }
    else { str = this->str; }

    for (int i = 0; i < static_cast<int>(strlen(str)); i++)
    {
        if (str[i] == ' ')
        {
            file << word << " ";
            delete[] word;
            word = new char[1]();
            continue;
        }
        if (i == (static_cast<int>(strlen(str)) - 1) && str[i] != ' ')
        {
            char* tmp = new char[strlen(word) + 2]();
            tmp = strcat(tmp, word);
            tmp[strlen(word)] = str[i];
            swap(word, tmp);
            delete[] tmp;
            file << word << " ";
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