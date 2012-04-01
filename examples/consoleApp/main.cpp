/*
KEYSHANC: KEYboard SHA-based eNCrypter
Console Example

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
#include "../Keyshanc/keyshanc.h"

using namespace std;

int main()
{
    string password;
    cout << "Enter your password: ";
    cin >> password;
    cout << endl;
    //The user's "password" is used as input to the two hash functions

    char keys[95];

    keyshanc(keys, password);

    //debugging code - displays keys[] now that it has been shuffled
    int count = 0;
    for (int x=0; x < 95; ++x)
    {
        count = int(keys[x])+count; //if all keys are present then the sum will be 7505
        cout <<char(x+32) << " => " << keys[x] << " " << int(keys[x]) << " " << count << endl;
    }

    //watch the decoding in action
    /*this code is adapted from
      C++ Primer Plus, 6th Edition
      Stephen Prata
      Example Listing 5.17
    */
    char inputChar, trueChar;
    cout << "Enter characters to test the encoding; enter # to quit:\n";
    cin.get(inputChar);
    for (int x=0; x < 95; ++x) {
        if (keys[x] == inputChar)
        {
            trueChar = char(x+32);
            break;
        }
    }
    while (trueChar != '#') {
        cout << trueChar;
        cin.get(inputChar);
        for (int x=0; x < 95; ++x) {
            if (keys[x] == inputChar)
            {
                trueChar = char(x+32);
                break;
            }
        }
    }

    return 0;
}
