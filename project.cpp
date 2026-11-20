#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class String
{
    char *ptr;

public:

    // Default Constructor
    String()
    {
        ptr = 0;
    }

    // Parameterized Constructor
    String(const char *s)
    {
        int i;

        for(i=0; s[i]!='\0'; i++);

        ptr = new char[i+1];

        for(i=0; s[i]!='\0'; i++)
            ptr[i] = s[i];

        ptr[i] = '\0';
    }

    // Copy Constructor
    String(const String &s)
    {
        if(s.ptr == 0)
            ptr = 0;
        else
        {
            int i;

            for(i=0; s.ptr[i]!='\0'; i++);

            ptr = new char[i+1];

            for(i=0; s.ptr[i]!='\0'; i++)
                ptr[i] = s.ptr[i];

            ptr[i] = '\0';
        }
    }

    // Destructor
    ~String()
    {
        delete[] ptr;
    }

    // setData
    void setData()
    {
        char temp[100];

        cout<<"Enter String: ";
        cin.getline(temp,100);

        int i;

        for(i=0; temp[i]!='\0'; i++);

        delete[] ptr;
        ptr = new char[i+1];

        for(i=0; temp[i]!='\0'; i++)
            ptr[i] = temp[i];

        ptr[i] = '\0';
    }

    // getData
    void getData()
    {
        if(ptr != 0)
            cout<<ptr<<endl;
    }

    // Assignment Operator
    String& operator=(const String &s)
    {
        if(this != &s)
        {
            delete[] ptr;
            ptr = 0;

            if(s.ptr != 0)
            {
                int i;

                for(i=0; s.ptr[i]!='\0'; i++);

                ptr = new char[i+1];

                for(i=0; s.ptr[i]!='\0'; i++)
                    ptr[i] = s.ptr[i];

                ptr[i] = '\0';
            }
        }

        return *this;
    }

    // + Operator
    String operator+(const String &s)
    {
        String temp;

        int i,j;
        int len1 = strlen(*this);
        int len2 = strlen(s);

        temp.ptr = new char[len1+len2+1];

        for(i=0; i<len1; i++)
            temp.ptr[i] = ptr[i];

        for(j=0; j<len2; j++)
            temp.ptr[i+j] = s.ptr[j];

        temp.ptr[i+j] = '\0';

        return temp;
    }

    // == Operator
    bool operator==(const String &s)
    {
        return strcmp(*this,s) == 0;
    }

    // != Operator
    bool operator!=(const String &s)
    {
        return strcmp(*this,s) != 0;
    }

    // > Operator
    bool operator>(const String &s)
    {
        return strcmp(*this,s) > 0;
    }

    // < Operator
    bool operator<(const String &s)
    {
        return strcmp(*this,s) < 0;
    }

    // >= Operator
    bool operator>=(const String &s)
    {
        return strcmp(*this,s) >= 0;
    }

    // <= Operator
    bool operator<=(const String &s)
    {
        return strcmp(*this,s) <= 0;
    }

    // Friend Stream Operators
    friend ostream& operator<<(ostream&,const String&);
    friend ifstream& operator>>(ifstream&,String&);

    // Friend String Functions
    friend void strcpy(String&,String&);
    friend void strncpy(String&,String&,int);
    friend int strcmp(const String&,const String&);
    friend int strncmp(String&,String&,int);
    friend void strcat(String&,String&);
    friend void strncat(String&,String&,int);
    friend void strrev(String&);
    friend void strupr(String&);
    friend void strlwr(String&);
    friend int strchr(String&,char);
    friend int strrchr(String&,char);
    friend int strstr(String&,String&);
    friend int strlen(const String&);
};


// strcpy
void strcpy(String &s1,String &s2)
{
    int i;

    int n = strlen(s2);

    delete[] s1.ptr;
    s1.ptr = new char[n+1];

    for(i=0; s2.ptr[i]!='\0'; i++)
        s1.ptr[i] = s2.ptr[i];

    s1.ptr[i] = '\0';
}


// strncpy
void strncpy(String &s1,String &s2,int n)
{
    int i;

    if(n < 0)
        n = 0;

    int len = strlen(s2);

    if(n > len)
        n = len;

    delete[] s1.ptr;
    s1.ptr = new char[n+1];

    for(i=0; i<n; i++)
        s1.ptr[i] = s2.ptr[i];

    s1.ptr[i] = '\0';
}


// strcmp
int strcmp(const String &s1,const String &s2)
{
    int i=0;

    while(s1.ptr[i]!='\0' && s2.ptr[i]!='\0')
    {
        if(s1.ptr[i] != s2.ptr[i])
            return s1.ptr[i]-s2.ptr[i];

        i++;
    }

    return s1.ptr[i]-s2.ptr[i];
}


// strncmp
int strncmp(String &s1,String &s2,int n)
{
    int i;

    if(n < 0)
        n = 0;

    for(i=0; i<n && s1.ptr[i]!='\0' && s2.ptr[i]!='\0'; i++)
    {
        if(s1.ptr[i] != s2.ptr[i])
            return s1.ptr[i]-s2.ptr[i];
    }

    if(i == n)
        return 0;

    return s1.ptr[i]-s2.ptr[i];
}


// strcat
void strcat(String &s1,String &s2)
{
    int i,j;

    int a = strlen(s1);
    int b = strlen(s2);

    char *temp = new char[a+b+1];

    for(i=0; i<a; i++)
        temp[i] = s1.ptr[i];

    for(j=0; j<b; j++)
        temp[i+j] = s2.ptr[j];

    temp[i+j] = '\0';

    delete[] s1.ptr;
    s1.ptr = temp;
}


// strncat
void strncat(String &s1,String &s2,int n)
{
    int i,j;

    if(n < 0)
        n = 0;

    int a = strlen(s1);
    int b = strlen(s2);

    if(n > b)
        n = b;

    char *temp = new char[a+n+1];

    for(i=0; i<a; i++)
        temp[i] = s1.ptr[i];

    for(j=0; j<n; j++)
        temp[i+j] = s2.ptr[j];

    temp[i+j] = '\0';

    delete[] s1.ptr;
    s1.ptr = temp;
}


// strrev
void strrev(String &s)
{
    int i,j;
    char t;

    for(i=0; s.ptr[i]!='\0'; i++);

    i--;

    for(j=0; j<i; j++,i--)
    {
        t = s.ptr[j];
        s.ptr[j] = s.ptr[i];
        s.ptr[i] = t;
    }
}


// strupr
void strupr(String &s)
{
    int i;

    for(i=0; s.ptr[i]!='\0'; i++)
    {
        if(s.ptr[i]>='a' && s.ptr[i]<='z')
            s.ptr[i] -= 32;
    }
}


// strlwr
void strlwr(String &s)
{
    int i;

    for(i=0; s.ptr[i]!='\0'; i++)
    {
        if(s.ptr[i]>='A' && s.ptr[i]<='Z')
            s.ptr[i] += 32;
    }
}


// strchr
int strchr(String &s,char ch)
{
    int i;

    for(i=0; s.ptr[i]!='\0'; i++)
    {
        if(s.ptr[i] == ch)
            return i;
    }

    return -1;
}


// strrchr
int strrchr(String &s,char ch)
{
    int i,pos=-1;

    for(i=0; s.ptr[i]!='\0'; i++)
    {
        if(s.ptr[i] == ch)
            pos = i;
    }

    return pos;
}


// strstr
int strstr(String &s1,String &s2)
{
    int i,j;

    if(s2.ptr[0] == '\0')
        return 0;

    for(i=0; s1.ptr[i]!='\0'; i++)
    {
        for(j=0; s2.ptr[j]!='\0'; j++)
        {
            if(s1.ptr[i+j] != s2.ptr[j])
                break;
        }

        if(s2.ptr[j] == '\0')
            return i;
    }

    return -1;
}


// strlen
int strlen(const String &s)
{
    int i;

    if(s.ptr == 0)
        return 0;

    for(i=0; s.ptr[i]!='\0'; i++);

    return i;
}


// Output Operator
ostream& operator<<(ostream &out,const String &s)
{
    if(s.ptr != 0)
        out<<s.ptr;

    return out;
}


// File Input Operator >>
ifstream& operator>>(ifstream &in,String &s)
{
    char temp[100];

    in >> setw(100) >> temp;

    if(in)
    {
        int i;

        for(i=0; temp[i]!='\0'; i++);

        delete[] s.ptr;
        s.ptr = new char[i+1];

        for(i=0; temp[i]!='\0'; i++)
            s.ptr[i] = temp[i];

        s.ptr[i] = '\0';
    }

    return in;
}


int main()
{
    String s1,s2,s3;

    int ch,n,pos;
    char c;

    while(1)
    {
        cout<<"\n1.strcpy";
        cout<<"\n2.strncpy";
        cout<<"\n3.strcmp";
        cout<<"\n4.strncmp";
        cout<<"\n5.strcat";
        cout<<"\n6.strncat";
        cout<<"\n7.strrev";
        cout<<"\n8.strupr";
        cout<<"\n9.strlwr";
        cout<<"\n10.strchr";
        cout<<"\n11.strrchr";
        cout<<"\n12.strstr";
        cout<<"\n13.strlen";
        cout<<"\n14.Exit";

        cout<<"\nEnter Choice: ";
        cin>>ch;
        cin.ignore();

        switch(ch)
        {
            case 1:
                s1.setData();
                s2.setData();
                strcpy(s1,s2);
                s1.getData();
                break;

            case 2:
                s1.setData();
                s2.setData();
                cout<<"Enter n: ";
                cin>>n;
                strncpy(s1,s2,n);
                s1.getData();
                break;

            case 3:
                s1.setData();
                s2.setData();

                if(strcmp(s1,s2)==0)
                    cout<<"Equal"<<endl;
                else
                    cout<<"Not Equal"<<endl;
                break;

            case 4:
                s1.setData();
                s2.setData();
                cout<<"Enter n: ";
                cin>>n;

                if(strncmp(s1,s2,n)==0)
                    cout<<"Equal"<<endl;
                else
                    cout<<"Not Equal"<<endl;
                break;

            case 5:
                s1.setData();
                s2.setData();
                strcat(s1,s2);
                s1.getData();
                break;

            case 6:
                s1.setData();
                s2.setData();
                cout<<"Enter n: ";
                cin>>n;
                strncat(s1,s2,n);
                s1.getData();
                break;

            case 7:
                s1.setData();
                strrev(s1);
                s1.getData();
                break;

            case 8:
                s1.setData();
                strupr(s1);
                s1.getData();
                break;

            case 9:
                s1.setData();
                strlwr(s1);
                s1.getData();
                break;

            case 10:
                s1.setData();
                cout<<"Enter Character: ";
                cin>>c;

                pos = strchr(s1,c);

                if(pos != -1)
                    cout<<"Found at position: "<<pos<<endl;
                else
                    cout<<"Not Found"<<endl;
                break;

            case 11:
                s1.setData();
                cout<<"Enter Character: ";
                cin>>c;

                pos = strrchr(s1,c);

                if(pos != -1)
                    cout<<"Last position: "<<pos<<endl;
                else
                    cout<<"Not Found"<<endl;
                break;

            case 12:
                s1.setData();
                s2.setData();

                pos = strstr(s1,s2);

                if(pos != -1)
                    cout<<"Found at position: "<<pos<<endl;
                else
                    cout<<"Not Found"<<endl;
                break;

            case 13:
                s1.setData();
                cout<<"Length = "<<strlen(s1)<<endl;
                break;

            case 14:
                return 0;

            default:
                cout<<"Invalid Choice";
        }
    }
}
