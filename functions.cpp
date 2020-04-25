#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include "factory.hpp"
#include "CString0factory.hpp"
#include "CString1factory.hpp"
#include "functions.hpp"

CString0 operator+(const CString& first, const CString& second)
{
    CString0 res;
    res.len = first.len + second.len;
    int length = static_cast<int>(res.len) + 1;
    res.str = new char[length]();
    res.str = strcat(res.str, first.str);
    res.str = strcat(res.str, second.str);
    return res;
}

void Test1()
{
    int len = 0;
    CString** v = new CString*[len]();
    CString0Factory* CString0_factory = new CString0Factory;
    CString1Factory* CString1_factory = new CString1Factory;

    ifstream file;
    Line line;
    line.I = 0;
    line.Data = "";
    line.Name = "";
    int p = 0;
    char* tmp;
    char* stroka = new char[256]();
    file.open(R"(E:\upr\data.txt)");
    if (!file)
    {
        cout << "Failed to open file (functions.cpp: row 27)" << endl;
    }
    //file.open(R"(полный путь к файлу)");
    while(file.getline(stroka, 256))
    {
          if(stroka[0] == '0')
          {
            line.I = 0;
          }
          else
          {
            line.I = 1;
          }
          
          for (int i = 2; i < strlen(stroka); i++)
          {
              if (stroka[i] == ' ')
            {
                p = i + 1;
                break;
            }
                tmp = new char[strlen(line.Name) + 2]();
                tmp = strcat(tmp, line.Name);
                tmp[strlen(line.Name)] = stroka[i];
                swap(line.Name, tmp);
          }
          
          for (int i = p; i < strlen(stroka); i++)
          {
              tmp = new char[strlen(line.Data) + 2]();
              tmp = strcat(tmp, line.Data);
              tmp[strlen(line.Data)] = stroka[i];
              swap(line.Data, tmp);
          }

          if (line.I == 0)
          {
              v[len] = CString0_factory->createString(line);
              len++;
          }
          else if (line.I == 1)
          {
              v[len] = CString1_factory->createString(line);
              len++;

          }

          p = 0;
          line.Data = "";
          line.Name = "";
          line.I = 0;
          delete[] tmp;
    }

    file.close();

    for(int i = 0; i < len; i++)
    {
        v[i]->output();
        delete(v[i]); 
    }


    cout << "TEST1: DONE. CHECK OUTPUT FILES" << endl;
}

void Test2()
{
    CString1 str = "hello world";
    str.output("test.txt");
    
    cout << "TEST2: DONE. CHECK OUTPUT FILE" << endl;
}

void Test3()
{
    CString1 a("Hello, ");
    CString0 b("world!");
    CString0 c;
    
    c = a + b;

    if (!strcmp(c.str, "Hello, world!"))
    {
        cout << "TEST3: PASSED!" << endl;
    }
    else
    {
        cout << "TEST3: FAILED!" << endl;
    }
}

void Test4()
{
    CString0 c;
    char* d = "Goodbye, world!";
    
    c = d;

    if (!strcmp(c.str, d))
    {
        cout << "TEST4: PASSED!" << endl;
    }
    else
    {
        cout << "TEST4: FAILED!" << endl;
    }
}