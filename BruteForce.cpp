#include <bits/stdc++.h>
using namespace std;
char *removeSpaces(char *str) 
{ //for removing the space from the entered array
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if (str[i] != ' ') 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
}
void sortChar(char* str)
{//for sorting the array entered by the user to just create a good password
//creating a vector to stroring the value after solvingt it
	int length=0;
	while(true){if(str[length]=='\0')break;length++;}
	vector<int> listSort(length);
	char sorted[20];
	for(int i=0;i<length;i++){listSort[i]=(int)str[i];}
sort(listSort.begin(),listSort.end());
length=0;
for(vector<int>::iterator it=listSort.begin();it!=listSort.end();it++)//here we are just rearranging the array to series one value
	{str[length]=(char)(*it);length++;}
 } 
 //Main crunch algorithm
 void generate(char* arr, int i, string s, int len,string name) 
{ 

fstream file;
file.open(name,ios::app);
    // base case 
    if (i == 0) // when len has been reached 
    { 
        // print it out 
        cout << s << "\n"; 
		file<<s<<endl;
		        // cnt++; 
        return; 
    } 
  
    // iterate through the array 
    for (int j = 0; j < len; j++) { 
  
        // Create new string with next character 
        // Call generate again until string has 
        // reached its len 
        string appended = s + arr[j];
        generate(arr, i - 1, appended, len,name); 
    } 
  file.close();
    return; 
} 
  
// function to generate all possible passwords 
void crack(char* arr, int len,string name) 
{ 
ofstream file;
file.open(name);
file.close();
    // call for all required lengths 
    for (int i = 1; i <= len; i++) { 
        generate(arr, i, "", len,name); 
    } 
} 
  void banner()
  {
  	cout<<"# BY..... "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		s	ll      rr   rr     "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		    s   ll	rr rr       "<<endl;
cout<<"		sssss	llllll  rr   rr     "<<endl;
cout<<endl;
cout<<"#ENTER THE LETTERS WHOSE COMBINATION YOU WANT TO FIND OUT"<<endl;
  }
int main()
{
banner();
char digits[12];
gets(digits);
removeSpaces(digits);
sortChar(digits);
string name;
cout<<"#ENTER THE NAME OF YOUR FILE IN WHICH YOU WANT TO SAVE ALL PASSWORDS"<<endl;
cin>>name;
int length=0;
while(true){if(digits[length]=='\0')break;length++;}
crack(digits, length,name);
return 0;
}
