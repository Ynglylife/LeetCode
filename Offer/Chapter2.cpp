#include <iostream>
#include<cstring>
using namespace std;

class CMyString{
public:
    CMyString(char* pData=NULL);
    CMyString(const CMyString&);
    const CMyString& operator=(const CMyString&);
    ~CMyString(void);
    char* m_pData;
};

CMyString::CMyString(char* pData){
    this->m_pData = new char[30];
    strcpy(m_pData, pData);
    cout<<"调用构造函数"<<endl;
}

CMyString::CMyString(const CMyString& data){
    this->m_pData = new char[30];
    strcpy(m_pData, data.m_pData);
    cout<<"调用复制构造函数"<<endl;
}

const CMyString& CMyString::operator=(const CMyString& data){
    //非常重要，避免自我赋值
    if(this == &data){
        return *this;
    }
    if(this->m_pData)
        delete[] m_pData;
    this->m_pData = new char[30];
    strcpy(m_pData, data.m_pData);
    cout<<"调用运算符重载"<<endl;
    return *this;
}

CMyString::~CMyString(void)
{
    delete m_pData;
}

int main()
{
    CMyString a1("jiji");
    CMyString a2("kiki");
    a2= a1;
    cout<<a2.m_pData<<endl;
    return 0;
}

