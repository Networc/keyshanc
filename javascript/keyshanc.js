/*
KEYSHANC: KEYboard SHA-based eNCrypter
Javascript Implementation

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

//NOTE: This script requires sha512-min.js and sha256-min.js
//Both can be obtained from http://pajhome.org.uk/crypt/md5/jshash-2.2.zip

//create keys[95]
var keys = new Array(95);

//initialize keys[95]
for (x = 0; x < 95; x++) {
    keys[x] = (x + 32);
}

function keyshanc(password) {
    var i = new String(hex_sha512(password));
    var j = new String(hex_sha256(password));

    //this loop resets keys[95] prior to shuffling
    for (x = 0; x < 95; x++) {
        keys[x] = (x + 32);
    }

    //exit function if no password provided
    //this effectively turns Keyshanc OFF
    if (password.length == 0) {
        return;
    }

    var shuffleCode = new Array(95);
    var hexString = new String("");
    var numByte;

    //build the first 64 positions in shuffleCode[] with the entire SHA512 hash
    for (x = 0; x < 64; x++) {
        hexString = hexString.concat(i.charAt(x*2));
        hexString = hexString.concat(i.charAt((x*2)+1));
        numByte = parseInt(hexString, 16);
        shuffleCode[x] = numByte%95;
        hexString = "";
    }

    //build the last 31 positions in shuffleCode[] with the first 31 bytes of the SHA256 hash
    for (x = 0; x < 31; x++) {
        hexString = hexString.concat(j.charAt(x*2));
        hexString = hexString.concat(j.charAt((x*2)+1));
        numByte = parseInt(hexString, 16);
        shuffleCode[x+64] = numByte%95;
        hexString = "";
    }

    //shuffle keys[] using shuffleCode[] for swap positions
    for (x = 0; x < 95; x++) {
        var temp = keys[x];
        keys[x] = keys[shuffleCode[x]];
        keys[shuffleCode[x]] = temp;        
    }
}

function decryptKeyshanc() {
    s1 = new String(document.getElementById('inText').value);

    var s2 = new String("");

    for (x = 0; x < s1.length; x++) {
        if (s1.charCodeAt(x) >= 32 && s1.charCodeAt(x) <= 126)
        {
            for (y = 0; y < 95; y++) {
                if (s1.charAt(x) == String.fromCharCode(keys[y]))
                {
                    s2 = s2.concat(String.fromCharCode(y+32));
                    break;
                }
            }
        }
        else
        {
            s2 = s2.concat(s1.charAt(x));
        }
    }

    document.getElementById('outText').value = s2;
}
