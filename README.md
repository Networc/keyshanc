## KEYSHANC
### KEYboard SHA-based eNCrypter

Keyshanc is an algorithm that produces a substitution cipher for the ASCII characters Space through ~ (32-126). It takes as input a "password" that is then sent to both a SHA-512 and SHA-256 hash function. The resulting hashes are used to produce a swap order that is then used to shuffle the ASCII characters.

My Intent: Keyshanc can provide a "good enough" method for privately communicating with applications on computers where the user has no administrative control.

My Goal: Wide adoption of Keyshanc in both hardware (specifically keyboards) and software (e.g. web browser add-ons).

Further discussion of Keyshanc will be found on my blog at [Andrew C. Reed](http://andrewcreed.com).

### Suggested grammatical conventions

* Keyshanc:
    1. The Keyshanc algorithm, or
    2. The password supplied to the algorithm (e.g. "What's your Keyshanc?" "I'm not telling you!")
* Keyshanc-enabled: Hardware or software that uses the Keyshanc algorithm to encrypt/decrypt keystrokes.

### License

Keyshanc is licensed under the MIT License (see LICENSE.txt).

If you use it, or just think that it is a worthwhile effort, please +1 and Tweet it via my [projects](http://andrewcreed.com/projects.html) page. If it is used in any research, please email me, as well. Thanks!
 
