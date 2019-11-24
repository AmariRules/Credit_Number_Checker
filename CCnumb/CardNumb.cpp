/*
 * File:   CardNumb.cpp
 * Author: AmariBolmer
 *
 * Created on July 5, 2018, 1:43 PM
 */
         
#include <iostream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;

bool isvalidcc(const string &);

int main()
 {
    // //
    // // main() contains examples of credit card numbers
    // //

    vector<string> cardnumbers = {

        "371449635398431", "4444444444444448", "4444424444444440", 
        "4110144110144115", "4114360123456785", "4061724061724061", 
        "5500005555555559", "5115915115915118", "5555555555555557", 
        "6011016011016011", "372449635398431", "4444544444444448", 
        "4444434444444440", "4110145110144115", "4124360123456785", 
        "4062724061724061", "5501005555555559", "5125915115915118", 
        "5556555555555557", "6011116011016011", "372449635397431", 
        "4444544444444448", "4444434444544440", "4110145110184115", 
        "4124360123457785", "4062724061724061", "5541005555555559", 
        "5125115115915118", "5556551555555557", "6011316011016011"

    };

    int i;

    vector<string>::iterator itr;

    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) //Checks size of numbers
 {
        cout << setw(2) << i << " "                         
                << setw(17) << *itr
                << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
    }
    return 0;
}

bool isvalidcc(const string &cc) { //Boolean function to check if credit card is a valid number
    int length = cc.length();
    if (length >= 13 && length <= 16) {
        if (cc[0] == '4' || cc[0] == '5' || (cc[0] == '3' && cc[1] == '7') || cc[0] == '6') {
            string s = cc;
            int sum = 0;
            for (int i = length - 2; i >= 0; i -= 2) {
                int d = (cc[i] - '0')*2;
                d = d % 10 + (d / 10) % 10;
                sum += d;
                s[i] = (d + '0');
            }
            for (int i = length - 1; i >= 0; i -= 2) {
                sum += cc[i] - '0';
            }
            return sum % 10 == 0;
        }
    }
    return false;
}
