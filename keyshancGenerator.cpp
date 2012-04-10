/*
KEYSHANC: KEYboard SHA-based eNCrypter
Keyshanc Generator

Copyright (c) 2012 Andrew C. Reed

License: The MIT License
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
//keyshanc.h and keyshanc.cpp are available from https://github.com/Networc/keyshanc
#include "../Keyshanc/keyshanc.h"

using namespace std;

int main()
{
    string f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;

    //The following lines retrieve the 11 user-defined Keyshanc passwords
    cout << "Enter your password for f1: ";
    cin >> f1;
    cout << endl;
    cout << "Enter your password for f2: ";
    cin >> f2;
    cout << endl;
    cout << "Enter your password for f3: ";
    cin >> f3;
    cout << endl;
    cout << "Enter your password for f4: ";
    cin >> f4;
    cout << endl;
    cout << "Enter your password for f5: ";
    cin >> f5;
    cout << endl;
    cout << "Enter your password for f6: ";
    cin >> f6;
    cout << endl;
    cout << "Enter your password for f7: ";
    cin >> f7;
    cout << endl;
    cout << "Enter your password for f8: ";
    cin >> f8;
    cout << endl;
    cout << "Enter your password for f9: ";
    cin >> f9;
    cout << endl;
    cout << "Enter your password for f10: ";
    cin >> f10;
    cout << endl;
    cout << "Enter your password for f11: ";
    cin >> f11;
    cout << endl;

    char keys[95];

    //The program computes the Keyshanc of the 11 passwords and outputs the
    //results in a format that can be copied and pasted directly into the
    //Keyshanc Teensyduino code
    cout << "---COPY THE FOLLOWING TO KEYSHANC.INO---" << endl;
    keyshanc(keys, f1);
    cout << "//keyshanc based on " << f1 << endl;
    cout << "char keyshancF1[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f2);
    cout << "//keyshanc based on " << f2 << endl;
    cout << "char keyshancF2[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f3);
    cout << "//keyshanc based on " << f3 << endl;
    cout << "char keyshancF3[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f4);
    cout << "//keyshanc based on " << f4 << endl;
    cout << "char keyshancF4[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f5);
    cout << "//keyshanc based on " << f5 << endl;
    cout << "char keyshancF5[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f6);
    cout << "//keyshanc based on " << f6 << endl;
    cout << "char keyshancF6[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f7);
    cout << "//keyshanc based on " << f7 << endl;
    cout << "char keyshancF7[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f8);
    cout << "//keyshanc based on " << f8 << endl;
    cout << "char keyshancF8[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f9);
    cout << "//keyshanc based on " << f9 << endl;
    cout << "char keyshancF9[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f10);
    cout << "//keyshanc based on " << f10 << endl;
    cout << "char keyshancF10[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;
    keyshanc(keys, f11);
    cout << "//keyshanc based on " << f11 << endl;
    cout << "char keyshancF11[95] = {";
    for (int x=0; x < 94; ++x)
    {
        cout << int(keys[x]) << ", ";
    }
    cout << int(keys[94]) << "};" << endl;

    cout << "---END COPY---" << endl;


    return 0;
}
