#include <dirent.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<sys/types.h>

using namespace std;

int scan_this(char *file_name)
{
    char *pattern, *line_in_file;
    char file_ch, ch;
    int val, val2, flag=1;
    ifstream fin3(file_name, ios::in | ios::binary);
    if(!fin3)
        return 0;
    else
        {
        ifstream fin4("db.txt");
        for(;;)
        {
            fin4>>pattern;
            if(!strcmp(pattern,"<-"))
            {
                fin4>>pattern;
                if(!strcmpi(pattern,"End"))
                    return -1;
                else if(!strcmpi(pattern, "virus"))
                {
                    if(flag)
                        return 1;
                else
                    continue;
                }
            }
        else if(!strcmpi(pattern,"LINE"))
        {
            fin4>>val;
            for(int i=0;i<val-1;i++)
            {
                fin3.getline(line_in_file, 300);
            }
            fin4>>val;
            fin4>>file_ch;
            for(int i=0;i<val-1;i++)
            {
                fin3.get(ch);
            }
            if(file_ch == ch)
                flag = 1;
            else
                flag =0;
            fin3.seekg(0);
        }
    }
    return flag;
}
}

void listdir(const char *path)
{
    char ask;
    int response;
    struct dirent *entry;
    DIR *dir = opendir(path);
    if(dir==NULL)
    {
        return;
    }
    while((entry = readdir(dir))!=NULL)
    {
       response = scan_this(entry->d_name);
       if(response == 1)
        {
        cout<<"<–!! Caution.! A Virus has been Detected..!";
        cout<<"\n"<<entry->d_name;
        cout<<"\nPress Enter Key to Delete it.";
        ask= getch();
        if(ask == 13)
        {
        remove(entry->d_name);
        }
        break;
        }
    }
    closedir(dir);
    }

int main()
{
    char directory[100];
    cout<<"Enter Directory you want to scan: ";
    cin>>directory;
    listdir("");
    cout<<"Scan Complete!! Thank You for using our anti virus";
    getch();
}
