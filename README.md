## KEYSHANC
### KEYboard SHA-based eNCrypter

Keyshanc is an algorithm that produces a substitution cipher for the ASCII characters Space through ~ (32-126). It takes as input a "password" that is then sent to both a SHA-512 and SHA-256 hash function. The resulting hashes are used to produce a swap order that is then used to shuffle the ASCII characters.

My Intent: Keyshanc can provide a "good enough" method for privately communicating with applications on computers where the user has no administrative control.

Example Scenarios:

* A business wants to allow its workforce to login remotely to their virtual desktops using their personal computers. Upon login, the user would be presented with a CAPTCHA Keyshanc password that must be entered into the user's Keyshanc (or Keyshanc-enabled keyboard).
* A user wants/needs to conduct sensitive business on a Keyshanc-enabled website from an untrusted computer. The user would enter his/her Keyshanc password via a graphical keyboard on the website.

My Goal: Wide adoption of Keyshanc in both hardware (specifically keyboards) and software (e.g. web browser add-ons).

Further discussion of Keyshanc will be found on my blog at [Andrew C. Reed](http://andrewcreed.com).

### Suggested grammatical conventions

* Keyshanc:
    1. The Keyshanc algorithm, or
    2. The password supplied to the algorithm (e.g. "What's your Keyshanc?" "I'm not telling you!"), or
    3. A small device that, when inserted between a keyboard and computer, will encrypt keystrokes according to the Keyshanc algorithm
* Keyshanc-enabled: Hardware or software that uses the Keyshanc algorithm to encrypt/decrypt keystrokes (this usage is redundant if using #3 above).

### License

Keyshanc is licensed under the MIT License (see LICENSE.txt).

If you use it, or just think that it is a worthwhile effort, please +1 and Tweet it via my [projects](http://andrewcreed.com/projects.html) page. If it is used in any research, please email me, as well. Thanks!

### Installing Crypto++ on Ubuntu and Linking in Code::Blocks

1. apt-cache pkgnames | grep -i crypto++
2. sudo apt-get install libcrypto++9 libcrypto++9-dbg libcrypto++-dev
3. Code::Blocks "Project > Build Options > Linker Settings > /usr/lib/libcryptopp.so"

###Additional Notes

Even if you aren't interested in the entire Keyshanc function, you may still find the following pieces useful to your own project:

* The SHA-256 and SHA-512 functions that each take a string as input and return a string of hexadecimal characters
* The FOR loops (containing the SWITCH statements) that convert the strings of hexadecimal characters into binary
* The FOR loop that shuffles the keys[] array based on the "swap positions" contained in the shuffleCode[] array

 
