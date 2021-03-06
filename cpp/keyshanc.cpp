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

#include <iostream>
#include <bitset>
//The following library can be found at http://www.cryptopp.com
#include "cryptopp/sha.h"
#include "cryptopp/hex.h"


/* SHA256 & SHA512
   These two functions are copied from
   http://stackoverflow.com/questions/5930056/
   "Can anybody give me a working example of generating a
   SHA256 hash in C++ with Crypto++, taking a string as
   input and outputting a string?"
*/
std::string SHA256(std::string data)
{
    byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[CryptoPP::SHA256::DIGESTSIZE];

    CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( abDigest, sizeof(abDigest) );
    encoder.MessageEnd();
    return output;
}

std::string SHA512(std::string data)
{
    byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[CryptoPP::SHA512::DIGESTSIZE];

    CryptoPP::SHA512().CalculateDigest(abDigest, pbData, nDataLen);

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( abDigest, sizeof(abDigest) );
    encoder.MessageEnd();
    return output;
}

//keyshanc() requires that a char array[95] be passed to it
void keyshanc(char keys[], std::string password)
{
    std::string i = SHA512(password);
    std::string j = SHA256(password);

    //this loop serves to either initialize or reset keys[95] prior to shuffling
    for (int x=0; x < 95 ; ++x)
    {
        keys[x] = char(x+32);
    }

    int shuffleCode[95];
    std::string hexString = "";
    std::bitset<8> aByte;
    unsigned long numByte;
    //build the first 64 positions in shuffleCode[] with the entire SHA512 hash
    /* The switch statements are from
       "C++ Convert Hex String to Binary String"
       http://www.cplusplus.com/forum/beginner/41657/
    */
    for (int x=0; x < 64; ++x)
    {
        switch (i[x*2])
				{
					case '0': hexString.append ("0000"); break;
					case '1': hexString.append ("0001"); break;
					case '2': hexString.append ("0010"); break;
					case '3': hexString.append ("0011"); break;
					case '4': hexString.append ("0100"); break;
					case '5': hexString.append ("0101"); break;
					case '6': hexString.append ("0110"); break;
					case '7': hexString.append ("0111"); break;
					case '8': hexString.append ("1000"); break;
					case '9': hexString.append ("1001"); break;
					case 'A': hexString.append ("1010"); break;
					case 'B': hexString.append ("1011"); break;
					case 'C': hexString.append ("1100"); break;
					case 'D': hexString.append ("1101"); break;
					case 'E': hexString.append ("1110"); break;
					case 'F': hexString.append ("1111"); break;
				}
        switch (i[(x*2)+1])
				{
					case '0': hexString.append ("0000"); break;
					case '1': hexString.append ("0001"); break;
					case '2': hexString.append ("0010"); break;
					case '3': hexString.append ("0011"); break;
					case '4': hexString.append ("0100"); break;
					case '5': hexString.append ("0101"); break;
					case '6': hexString.append ("0110"); break;
					case '7': hexString.append ("0111"); break;
					case '8': hexString.append ("1000"); break;
					case '9': hexString.append ("1001"); break;
					case 'A': hexString.append ("1010"); break;
					case 'B': hexString.append ("1011"); break;
					case 'C': hexString.append ("1100"); break;
					case 'D': hexString.append ("1101"); break;
					case 'E': hexString.append ("1110"); break;
					case 'F': hexString.append ("1111"); break;
				}
        aByte = std::bitset<8>(hexString);
        numByte = aByte.to_ulong();
        shuffleCode[x] = numByte%95;
        hexString = "";
    }

    //build the last 31 positions in shuffleCode[] with the first 31 bytes of the SHA256 hash
    for (int x=0; x < 31; ++x)
    {
         switch (j[x*2])
				{
					case '0': hexString.append ("0000"); break;
					case '1': hexString.append ("0001"); break;
					case '2': hexString.append ("0010"); break;
					case '3': hexString.append ("0011"); break;
					case '4': hexString.append ("0100"); break;
					case '5': hexString.append ("0101"); break;
					case '6': hexString.append ("0110"); break;
					case '7': hexString.append ("0111"); break;
					case '8': hexString.append ("1000"); break;
					case '9': hexString.append ("1001"); break;
					case 'A': hexString.append ("1010"); break;
					case 'B': hexString.append ("1011"); break;
					case 'C': hexString.append ("1100"); break;
					case 'D': hexString.append ("1101"); break;
					case 'E': hexString.append ("1110"); break;
					case 'F': hexString.append ("1111"); break;
				}
        switch (j[(x*2)+1])
				{
					case '0': hexString.append ("0000"); break;
					case '1': hexString.append ("0001"); break;
					case '2': hexString.append ("0010"); break;
					case '3': hexString.append ("0011"); break;
					case '4': hexString.append ("0100"); break;
					case '5': hexString.append ("0101"); break;
					case '6': hexString.append ("0110"); break;
					case '7': hexString.append ("0111"); break;
					case '8': hexString.append ("1000"); break;
					case '9': hexString.append ("1001"); break;
					case 'A': hexString.append ("1010"); break;
					case 'B': hexString.append ("1011"); break;
					case 'C': hexString.append ("1100"); break;
					case 'D': hexString.append ("1101"); break;
					case 'E': hexString.append ("1110"); break;
					case 'F': hexString.append ("1111"); break;
				}
        aByte = std::bitset<8>(hexString);
        numByte = aByte.to_ulong();
        shuffleCode[x+64] = numByte%95;
        hexString = "";
    }

/*
    //debugging code - display shuffleCode[]
    for (int x=0; x < 95; ++x)
    {
        std::cout << x << " " << shuffleCode[x] << std::endl;
    }
*/

    //Shuffle keys[] using shuffleCode[] for swap positions
    for (int x=0; x < 95; ++x)
    {
        char temp = keys[x];
        keys[x] = keys[shuffleCode[x]];
        keys[shuffleCode[x]] = temp;
    }

    return;
}
