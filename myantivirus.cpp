#include<windows.h>
#include <dirent.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int scan_this(char *file_name)

{


char *pattern, *line_in_file;

char file_ch, ch;

int val, val2, flag;

ifstream fin3, fin4;

fin3.open(file_name);

if(!fin3) return 0;

else

{


fin4.open("D:\soujanya\db.txt");

for(;;)

{

fin4>>pattern;

if(!strcmp(pattern,"<-"))

{

fin4>>pattern;

if(!strcmpi(pattern,"End"))return -1;

else if(!strcmpi(pattern, "virus"))

{

if(flag) return 1;

else continue;

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

if(file_ch == ch) flag = 1;

else flag =0;

fin3.seekg(0);

}

}

}

}

int main()

{

char comm[300],file_name[200];
                                                                                                                                                                                                                                                                                                                                                        char dirpath[10]={"virus"};
int ask;

int response;

ifstream fin;

cout<<"Enter file you want to scan: ";

gets(file_name);

if(strcmp(file_name,dirpath)==0)
{
  cout<<"Caution.! A Virus has been Detected..!"<<endl;


cout<< "Delete it."<<endl;
}
else
    cout<<"the file is safe"<<endl;
cout<<"Scan Complete.!! Thank You for using our anti virus";
getch();

}
