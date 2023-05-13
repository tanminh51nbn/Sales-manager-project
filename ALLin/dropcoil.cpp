#pragma once 
#include <windows.h>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void gotoxy(short x, short y){
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

string time_in_life(){
    time_t now = time(0);
    char *dt = ctime(&now);
    char *pos = strchr(dt, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
 return dt;
}
string edit(int x){
    string s;
    s=to_string(x);
    char add=',';
    if(x>=1000 and x<1000000){
        s.insert(s.length()-3,1,add);
    }
    if(x>=1000000){
        s.insert(s.length()-3,1,add);
        s.insert(s.length()-7,1,add);
    }
    return s;
}
int edit(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]==','){
            s.erase(i, 1);
            n--;
            i--;
        }
    }
    for(int i=0;i<3;i++){
        s.pop_back();
    }
    return atoi(s.c_str());
}
int xuli_vetor(vector<int> a){
    int x=0;
    for(int i=0;i<a.size();i++){
        x+=a[i];
    }
    return x;
}