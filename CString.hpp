#include <iostream>
#include <fstream>
using namespace std;

typedef struct Line
{
    int I;
    char* Name;
    char* Data;
}Line;

class CString
{
    public:
        int len;
        char* str = "";
        char* fname = "";
        Line line;
        bool isFabric;
        CString();
        CString(char* str);
        CString(Line line);
        CString(const CString& second);
        virtual ~CString();
        virtual void output(const char *FileName = NULL) = 0;
        CString& operator=(const CString& second);
};