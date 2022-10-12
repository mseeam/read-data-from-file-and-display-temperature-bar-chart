/*
Author: Mohammad Seeam
Course: COSC 1337 Semester: Spring 2022
Section: DL9 ; Instructor: Thayer
Lab: 5 Purpose: Write a program to read the data from this file and display a temperature bar chart.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("lohiF.txt");                                             //opening file
    if (file.fail()){
        cout<<"Error opening file: lohiF.txt"<<endl;                    //if the program doesn't get the file, it will show an error.
            exit(0);                                                    //If the program doesn't get the file, it will exit.
    }else{ 
        cout<<"Seeam's bar chart: "<<endl; 
        string s;
        int month = 1;                                                  //Created this int month to count the months.
        bool firstLine = true;
        while(getline(file, s)){
            if(firstLine == true){                                      //This if statement will work just for the first line
                cout << s << endl;                                      //printing the first line of the file
                firstLine = false;
            }else{
                string low_temparature="";                              //created this low_temparature so that I can insert low temparatute to that string
                string high_temparature="";                             //created this high_temparature so that I can insert high temparature to that string
                bool spaceFound = false;
                for (int x=0; x<s.length();x++){
                    if(s.at(x)!=' ' && spaceFound==false){
                        low_temparature = low_temparature + s.at(x);    //inserting low temparature data to low_temparature
                    }else if(s.at(x)!=' ' && s.at(x)!='\r'){
                        high_temparature = high_temparature + s.at(x);  //inserting high temparature data to low_temparature
                    }else{
                        spaceFound = true;
                    }
                }
                int low  = stoi(low_temparature);                       //converting low temparature string to int and inserting to low
                int high = stoi(high_temparature);                      //converting high temparature string to int and inserting to high
                string s="";                                            //Created just a random string s, so that I can append spaces, star(*) , temparature data, months, and I will print that s to get my output.

                s = s + to_string(month); 
                month++;                                                //it will continue to increase months from 1 until the data finishes.

                for (int i=0;i<low-1;i++){                              
                    s = s + " ";                                        //it will append spaces to string s until actual temparature data and star (*) starts.
                }

                s = s + "(" + low_temparature + " F)";            
            
                for (int i=low;i<=high;i++){
                    s = s + "*";                                        //Actual temparature data will be displayed with *
                }

                s = s + "(" + high_temparature + " F)";
            
                cout <<s<< endl;                                        // I have append spaces, *, low temparature data, high temparature data , number of month to s. So just by printing s, I have printed everything.
            }
        }
    return(0);
    }
}

/*
Seeam's bar chart: 
Austin Average Monthly low high Temperatures (Fahrenheit) Years 2010 - 2019
1                                        (41 F)***********************(63 F)
2                                             (46 F)**********************(67 F)
3                                                    (53 F)***********************(75 F)
4                                                          (59 F)***********************(81 F)
5                                                                  (67 F)*********************(87 F)
6                                                                         (74 F)*********************(94 F)
7                                                                           (76 F)***********************(98 F)
8                                                                           (76 F)*************************(100 F)
9                                                                       (72 F)**********************(93 F)
10                                                            (61 F)***********************(83 F)
11                                                 (50 F)***********************(72 F)
12                                           (44 F)*********************(64 F)
*/