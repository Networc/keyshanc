/*
KEYSHANC: KEYboard SHA-based eNCrypter

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

#ifndef KEYSHANC_H
#define KEYSHANC_H

/* SHA256 & SHA512
   These two functions are copied from
   http://stackoverflow.com/questions/5930056/
   "Can anybody give me a working example of generating a
   SHA256 hash in C++ with Crypto++, taking a string as
   input and outputting a string?"
*/
std::string SHA256(std::string data);

std::string SHA512(std::string data);

//keyshanc() requires that a char array[95] be passed to it
void keyshanc(char keys[], std::string password);

#endif // KEYSHANC_H
