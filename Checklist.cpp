#include<iostream>
#include <string>
#include <fstream>
using namespace std;
struct habit{
string goal;
string date;
int streak;
};
int main()
{
int choice;
do{
cout << "1) Add\n2) View\n3) Delete\n4) Check\n5) Exit" << endl;
cin >> choice;
switch(choice){
case 1:
{
ofstream file ("checklist.txt", ios::app);
if(!file){
cout << "error " << endl;
break;
}
string goal;
string date;
cout << "enter goal to add " << endl;
cin.ignore();
getline(cin,goal);
cout << "date: " << endl;
getline(cin,date);
if(goal.empty()){
cout << "so you have no goals in life " << endl;
file.close();
break;
}
file << goal << endl;
file << date << endl;
file << 0 << endl;
file.close();
break;
}

case 2:
{
ifstream file("checklist.txt");
habit h;
if(!file){
cout << "no list available " << endl;
break;
}
int num = 1;
while(getline(file, h.goal)){
getline(file,h.date);
file >> h.streak;
file.ignore();
cout << "[" << num << "]" << endl;
cout << "Goal: " << h.goal << endl;
cout << "Start Date: " << h.date << endl;
cout << "Streak: " << "(" <<  h.streak << ")" << endl;
num++;
}
break;
}
case 3:
{
ifstream file("checklist.txt");
int count = 0;
habit habits[100];
while(getline(file, habits[count].goal)){
getline(file,habits[count].date);
file >> habits[count].streak;
file.ignore();
count++;
}
file.close();
int del;
cout << "enter goal to delete: " << endl;
cin >> del;
if(del < 1 || del > count){
cout << "wrong habit number" << endl;
break;
}
ofstream outfile ("checklist.txt");
for(int i = 0; i < count; i++){
if(i == del - 1)
continue;
outfile << habits[i].goal << endl;
outfile << habits[i].date << endl;
outfile << habits[i].streak << endl;
}
outfile.close();
cout << "habit deleted " << endl;
break;
}
case 4:
{
ifstream file("checklist.txt");
int count = 0;
habit habits[100];
while(getline(file, habits[count].goal)){
getline(file,habits[count].date);
file >> habits[count].streak;
file.ignore();
count++;
}
file.close();
int del;
cout << "enter goal to update: " << endl;
cin >> del;
if(del < 1 || del > count){
cout << "wrong habit number" << endl;
break;
}
ofstream outfile ("checklist.txt");
habits[del -1].streak++;
for(int i = 0; i < count; i++){
outfile << habits[i].goal << endl;
outfile << habits[i].date << endl;
outfile << habits[i].streak << endl;
}
outfile.close();
cout << "habit updated " << endl;
break;
}
case 86:
{
ifstream file("checklist.txt");
string line;

while(getline(file, line))
{
    cout << line << endl;
}
}
default:
cout << "invalid choice \n" << endl;
break;
}//switch 
}while(choice != 5);
}