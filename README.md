##Keyshanc Teensyduino
###What is it?
The Keyshanc Teensyduino is a physical device that encrypts keystrokes using the [Keyshanc](https://github.com/Networc/keyshanc) algorithm. It has a PS/2 input and USB output. It can toggle between 11 user\-defined Keyshanc ciphers by pressing F1\-F11 and it can output plaintext by pressing F12.

It costs less than $30 \(minus shipping\) for all of the parts.

My Goal: The widespread use of my design and source code to enable privacy from the keyboard\-to\-the\-application even on compromised \(a.k.a. "monitored"\) workstations.

For a more detailed explanation of the Keyshanc Teensyduino and how to assemble one, please visit my blog at [andrewcreed.com](http://andrewcreed.com).

###File List
* <b>keyshanc.ino</b>: This is the source code for the Keyshanc Teensyduino.
* <b>keyshancGenerator.cpp</b>: This program creates 11 Keyshanc ciphers and outputs C++ code that can be copied and pasted into keyshanc.ino.

###What is required in order to use the Keyshanc Teensyduino?
Nothing is required to be installed on the workstation itself. That was one of the primary design goals.

What <b>is</b> required is that the receiving application must be Keyshanc\-enabled \(I have an example console application in my [Keyshanc](https://github.com/Networc/keyshanc) repo\). The best method would be for the receiving application to allow the user to graphically enter the Keyshanc password currently being used.

<b>This is where I need help from the open source community</b>. I have developed the algorithm and an inexpensive hardware implementation, but I need members of the community to adopt Keyshanc and incorporate it in their own programs/websites.

###License
Keyshanc is licensed under the MIT License (see LICENSE.txt).

If you use it, or just think that it is a worthwhile effort, please +1 and Tweet it via my [projects](http://andrewcreed.com/projects.html) page. If it is used in any research, please email me, as well. Thanks!