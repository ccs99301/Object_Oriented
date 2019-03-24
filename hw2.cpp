#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void readfile(string*,char*);
void locate(string*,string,int);
void clear_text(string*);

void readfile(string *text,char* fname)
{
    bool state=1;
    int i=0,c;
    fstream fin;
    fin.open(fname, ios::in);
    if(!fin)
    {
        cout<<"ERROR: Error reading from file"<<endl;
        return;
    }
    clear_text(text);
    while((c=fin.get())!=EOF)
    {
        if(state==1&&(isalpha(c)||c==39||(c>='0'&&c<='9')))
            text[i]+=c;
        else if(state==1&&isalpha(c)==0&&c!=39&&(c<'0'||c>'9'))
            state=0;
        else if(state==0&&(isalpha(c)||c==39||(c>='0'&&c<='9')))
        {
            state=1;
            i++;
            text[i]+=c;
        }
    }
    fin.close();
}

void locate(string *text,string wfind,int wcount)
{
    int i=0;
    for(i=0;i<500;i++)
    {
        if(text[i]==wfind&&wcount==1)
        {
            cout<<wfind<<" at "<<i+1<<" words"<<endl;
            wcount=0;
        }
        else if(text[i]==wfind&&wcount>1)
            wcount--;
    }
    if(wcount!=0)
        cout<<"ERROR: No matching entry"<<endl;
}

void clear_text(string *text)
{
    int i=0;
    for(i=0;i<500;i++)
        text[i]="";
}
int main()
{
    int wcount=0;
    char fname[20];
    string text[500],command,wfind;
    while(1)
    {
        cout<<"Enter your command : ";
        cin>>command;
        if(command=="load")
        {
            cin>>fname;
            readfile(text,fname);
        }
        else if(command=="locate")
        {
            cin>>wfind>>wcount;
            if(wcount<=0)
            {
                cin.clear();
                cin.sync();
                cout<<"ERROR: Please enter the number > 0"<<endl;
            }
            else
                locate(text,wfind,wcount);
        }
        else if(command=="new")
            clear_text(text);
        else if(command=="end")
            break;
        else
            cout<<"ERROR: Invalid command"<<endl;
    }
    return 0;
}
