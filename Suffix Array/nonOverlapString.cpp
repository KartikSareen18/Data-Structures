#include <iostream>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;

string compare(string a,string b){
    string res;
    char temp[100];
    int i;
    for( i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]){
            temp[i]=a[i];
        }
        else
        break;
    }
    temp[i]='\0';
    res=temp;
    return res;
}

int main()
{
    string input;
    getline(cin,input);
    char storage[100][100];
    int size=0;
    int indexes[100]={0};
    for(int i=0;i<input.length();i++){
        char temp[100];
        int k=-1;
        for(int j=i;j<input.length();j++){
            k++;
            temp[k]=input[j];
        }
        k++;
        temp[k]='\0';
        strcpy(storage[size],temp);
        indexes[size]=i;
        size++;
    }
    char prev=input[0];
    int first=1,second=0;
    char temp[100];
    temp[0]=input[0];
    int sz=1;
    string result;
    for(int i=1;i<input.length();){
        sz=1;
        while(input[i]==prev && i<input.length()){
            i++;
            temp[sz]=input[i];
            sz++;
            first++;
        }
        prev=input[i];
        temp[sz/2]='\0';
        if(first>second){
        second=first;
        result=temp;
        }
        first=1;
        temp[0]=input[i];
        i++;
    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(strcmp(storage[i],storage[j])>0){
            char temp[100];
            strcpy(temp,storage[i]);
            strcpy(storage[i],storage[j]);
            strcpy(storage[j],temp);
            int t=indexes[i];
            indexes[i]=indexes[j];
            indexes[j]=t;
            }
            
        }
    }
    int max=0;
    for(int i=1;i<size;i++){
       int j=i-1;
       int i1=indexes[i];
       int i2=indexes[j];
       string a=storage[i];
       string b=storage[j];
       string temp=compare(a,b);
       if(abs(i1-i2)>=temp.length())
       {
           if(temp.length()>result.length())
           result=temp;
       }
    }
    cout<<result<<endl;
    return 0;
}
