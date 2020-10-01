//
//  main.cpp
//  CipherAlgorithms
//
//  Created by Jesus Ponce on 9/28/20.
//  Copyright © 2020 Jesus Ponce. All rights reserved.
//





#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cstring>

//terative Rotation Cipher (IRC)
//The encode method will receive two arguments — a positive integer n and a string value.
//
//The decode method will receive one argument — a string value.
//Output
//
//Each method will return a string value.
//How It Works
//Encoding and decoding are done by performing a series of character and substring rotations on a string input.
//
//Encoding: The number of rotations is determined by the value of n. The sequence of rotations is applied in the following order:
// Step 1: remove all spaces in the string (but remember their positions)
// Step 2: shift the order of characters in the new string to the right by n characters
// Step 3: put the spaces back in their original positions
// Step 4: shift the characters of each substring (separated by one or more consecutive spaces) to the right by n
//Repeat this process until it has been completed n times in total.
//The value n is then prepended to the resulting string with a space.

//Decoding: Decoding simply reverses the encoding process.
std::string encode(int n, std::string str);

std::string insertSpacesByPosition(std::string, std::vector<int> spaces);

std::string moveCharsInStringRightNumberOfXTimes(int n,std::string str);

std::string decode(std::string str);


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string intro ="If you wish to make an apple pie from scratch, you must first invent the universe.";
    std::cout << encode(10, intro)<<std::endl;
    std::cout <<encode(14,"True evil is a mundane bureaucracy.")<<std::endl;


    return 0;
}
std::string encode(int n, std::string str)
{
    std::vector <int> spacePositions;
    int j =0, num =n;
    std::string tempCode;
    for(auto i: str)
    {
        if(i == ' ')
        {
            spacePositions.push_back(j);
        }
        else
        {
            tempCode+=i;
        }
        j++;
    }
//    tempCode = tempCode.substr((tempCode.length()-n),tempCode.length()) + tempCode.substr(0,(tempCode.length()-n));
    while(num > 0){
    tempCode = moveCharsInStringRightNumberOfXTimes(n, tempCode);
//    for(int i: spacePositions)
//        tempCode.insert(i, " ");
    tempCode = insertSpacesByPosition(tempCode, spacePositions);
    
    //making string into c-string to be able tokenize
    
    char * cstr = new char [tempCode.length()+1];
    std::strcpy (cstr, tempCode.c_str());
    tempCode.clear();
    
//tokenizing the string passed
    char * p = strtok(cstr, " ");
    while(p != 0)
    {
        tempCode += moveCharsInStringRightNumberOfXTimes(n, p);
        p = strtok(NULL, " ");
    }
   num--;
    }
        tempCode = insertSpacesByPosition(tempCode, spacePositions);
    std::string m = std::to_string(n) + " ";
    tempCode.insert(0,m);
    return tempCode;
}

std::string insertSpacesByPosition(std::string str, std::vector<int> spaces)
{
    for(int i: spaces)
    str.insert(i, " ");
    
    return str;
    
}
std::string moveCharsInStringRightNumberOfXTimes(int n,std::string str)
{
    std::string tempCode;
    if(str.length()>n)
    {
    tempCode = str.substr((str.length()-n),str.length()) + str.substr(0,(str.length()-n));
    }
    else
    {
        int remainder = n%str.length();
        tempCode = str.substr((str.length()-remainder),str.length()) + str.substr(0,(str.length()-remainder));
    }
    return tempCode;
}

std::string decode(std::string str)
{
    return "";
}
