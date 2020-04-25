class CString1 : public CString
{
    public:
        CString1();
        CString1(char* text);
        CString1(Line line);
        CString1& operator=(char* second);
        void output(const char *FileName = NULL);
        using CString::operator=;
        CString1(const CString& second);
};