#include <iostream>
#include<fstream>
#include<string>

using namespace std;

string pun[]={"{","}","(",")",";","<"};
int puncount=6;
string keyword[]={"int","main","cout"};
int keycount=3;
string oparator[]={"="};
int opecount=1;

    bool iskeyword(string s){
        for(int i=0;i<keycount;i++){
            if (s == keyword[i])return true;
        }
        return false;
    }

    bool isoperator(string s) {
        for(int i=0;i<opecount;i++){
            if(s==oparator[i])return true;
        }
        return false;
    }


    bool ispun(string s){
    for (int i=0;i<puncount;i++){
        if(s==pun[i]) return true;
    }
    return false;
    }

void classifier(string token) {
    if (token.empty()) return;

    if(iskeyword(token)){
            cout<<"Keyword: "<<token<<endl;
    }
    else if(isoperator(token)){
            cout<<"Operator: "<<token<<endl;
    }
    else if(ispun(token)){
            cout<<"Punctuation: "<<token<<endl;
    }

    else{
        cout<<"Identifier: "<<token<<endl;
    }

}

int main()
{
    string line;
    string fulltext;
    ifstream read("myfile1.txt");
    while(!read.eof()){
        getline(read,line);
        cout<<line<<endl;
        fulltext=fulltext+line;
    }
    cout<<fulltext<<endl;

    string token="";
    for(int i=0;i<fulltext.length();i++){
        char c=fulltext[i];
        string ch;
        ch=c;

        if(c==' '){
            classifier(token);
            token="";
        }

        else if(ispun(ch)){
            classifier(token);
            token = "";
            classifier(ch);
        }

        else if(isoperator(ch)){
            classifier(token);
            token = "";
            classifier(ch);
        }

        else{
            token=token+c;
        }
    }
    classifier(token);
}

