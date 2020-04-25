class CString0 : public CString
{
    public:
        CString0();
        CString0(char* text);
        CString0(Line line);
        CString0& operator=(char* second);
        void output(const char *FileName = NULL);
        using CString::operator=;
        CString0(const CString& second);
};