/*
KEYSHANC: KEYboard SHA-based eNCrypter
Keyshanc Teensyduino

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

//Remember to use my custom special key values in PS2Keyboard.h
//They are listed in the README at https://github.com/Networc/keyshanc-teensyduino
#include <PS2Keyboard.h>

const int DataPin = 8;
const int IRQpin =  5;

//Use keyshancGenerator.cpp to easily create the following arrays using 11 of your own passwords
//keyshanc based on aragorn
char keyshancF1[95] = {74, 61, 37, 73, 93, 64, 59, 97, 55, 79, 104, 100, 92, 78, 34, 105, 50, 102, 39, 72, 71, 35, 48, 119, 94, 117, 43, 86, 98, 90, 80, 107, 41, 54, 60, 81, 45, 32, 82, 91, 58, 116, 96, 118, 123, 69, 42, 38, 95, 76, 89, 51, 83, 67, 110, 124, 44, 112, 53, 103, 106, 114, 46, 101, 57, 109, 70, 121, 40, 120, 126, 36, 56, 85, 108, 47, 113, 68, 84, 125, 87, 111, 75, 122, 49, 115, 88, 99, 52, 77, 62, 65, 66, 63, 33};
//keyshanc based on bilbo
char keyshancF2[95] = {33, 41, 123, 46, 44, 48, 83, 66, 103, 90, 51, 47, 77, 105, 85, 88, 40, 54, 84, 42, 37, 109, 92, 61, 43, 71, 49, 125, 64, 121, 74, 106, 118, 104, 93, 59, 34, 50, 114, 76, 32, 81, 116, 58, 72, 45, 107, 55, 120, 117, 52, 115, 89, 87, 95, 124, 126, 38, 57, 78, 99, 101, 108, 70, 35, 80, 122, 98, 94, 111, 56, 39, 82, 75, 110, 112, 53, 97, 65, 69, 96, 73, 100, 86, 60, 91, 63, 119, 68, 79, 113, 102, 67, 36, 62};
//keyshanc based on boromir
char keyshancF3[95] = {38, 90, 77, 44, 71, 114, 67, 99, 98, 79, 68, 100, 58, 112, 51, 101, 54, 47, 119, 65, 105, 122, 75, 86, 117, 94, 113, 74, 96, 120, 82, 73, 39, 91, 40, 46, 87, 72, 56, 110, 88, 45, 97, 106, 123, 115, 48, 83, 111, 84, 85, 118, 107, 76, 43, 121, 109, 59, 69, 92, 64, 49, 55, 53, 50, 124, 34, 103, 60, 52, 37, 108, 95, 78, 57, 61, 102, 81, 62, 116, 63, 66, 42, 41, 125, 104, 33, 36, 80, 93, 35, 89, 70, 126, 32};
//keyshanc based on frodo
char keyshancF4[95] = {74, 58, 100, 98, 79, 84, 62, 96, 78, 91, 77, 99, 66, 93, 75, 104, 48, 60, 110, 32, 64, 118, 123, 47, 63, 109, 92, 69, 53, 119, 86, 61, 80, 42, 97, 73, 81, 59, 76, 114, 115, 117, 54, 56, 105, 112, 57, 122, 126, 44, 40, 46, 45, 95, 121, 52, 106, 107, 68, 55, 70, 88, 72, 50, 90, 37, 108, 124, 89, 116, 43, 65, 71, 103, 49, 120, 125, 111, 101, 94, 113, 34, 82, 83, 35, 51, 38, 67, 36, 87, 39, 41, 85, 102, 33};
//keyshanc based on gandalf
char keyshancF5[95] = {82, 57, 90, 86, 76, 67, 95, 33, 35, 44, 98, 123, 119, 122, 51, 59, 83, 34, 124, 40, 113, 50, 64, 65, 69, 71, 66, 91, 80, 100, 61, 112, 55, 78, 79, 32, 105, 77, 89, 115, 68, 96, 106, 62, 117, 85, 87, 45, 36, 118, 56, 107, 116, 111, 109, 93, 72, 41, 114, 52, 108, 104, 70, 97, 88, 73, 75, 46, 63, 84, 53, 126, 101, 120, 54, 102, 48, 110, 39, 121, 103, 38, 58, 49, 125, 47, 74, 81, 92, 94, 43, 60, 37, 99, 42};
//keyshanc based on gimli
char keyshancF6[95] = {40, 101, 55, 114, 77, 85, 63, 61, 52, 37, 106, 74, 35, 110, 88, 69, 102, 103, 104, 42, 44, 87, 123, 120, 50, 38, 39, 78, 97, 64, 98, 54, 53, 60, 49, 83, 99, 72, 117, 62, 73, 82, 47, 56, 105, 126, 76, 113, 34, 116, 79, 58, 80, 81, 121, 68, 100, 109, 84, 48, 46, 45, 59, 107, 32, 96, 95, 115, 108, 90, 51, 92, 75, 86, 91, 43, 94, 119, 70, 66, 118, 36, 89, 112, 57, 122, 93, 111, 65, 124, 125, 41, 33, 67, 71};
//keyshanc based on gollum
char keyshancF7[95] = {80, 87, 60, 67, 42, 63, 96, 74, 49, 59, 106, 56, 94, 52, 103, 91, 97, 34, 81, 124, 111, 102, 114, 79, 69, 65, 105, 66, 44, 72, 45, 55, 40, 53, 93, 95, 48, 119, 98, 54, 99, 43, 112, 107, 32, 110, 39, 90, 109, 57, 78, 86, 85, 71, 118, 46, 35, 68, 41, 100, 126, 113, 121, 61, 89, 82, 92, 101, 104, 83, 75, 73, 125, 33, 88, 51, 36, 70, 47, 58, 84, 50, 38, 62, 77, 123, 120, 76, 122, 64, 37, 116, 115, 117, 108};
//keyshanc based on legolas
char keyshancF8[95] = {92, 40, 42, 44, 80, 87, 67, 79, 70, 43, 77, 106, 122, 94, 37, 99, 91, 111, 47, 34, 117, 119, 51, 46, 100, 59, 68, 45, 83, 113, 55, 58, 116, 82, 120, 62, 54, 57, 71, 60, 53, 102, 69, 98, 105, 56, 109, 96, 32, 95, 101, 48, 63, 118, 81, 114, 89, 110, 115, 90, 103, 104, 64, 125, 36, 73, 41, 50, 93, 75, 76, 97, 33, 107, 38, 65, 126, 86, 72, 49, 35, 124, 85, 39, 74, 123, 88, 84, 121, 112, 108, 61, 78, 52, 66};
//keyshanc based on meriadoc
char keyshancF9[95] = {47, 62, 73, 94, 57, 68, 78, 117, 88, 49, 80, 35, 56, 105, 66, 34, 58, 71, 106, 76, 122, 59, 42, 75, 109, 77, 41, 108, 100, 36, 81, 55, 114, 99, 70, 43, 48, 85, 61, 115, 97, 82, 116, 113, 126, 40, 51, 89, 87, 98, 123, 69, 67, 65, 83, 96, 95, 90, 60, 38, 107, 120, 79, 93, 118, 101, 54, 91, 50, 86, 125, 92, 110, 112, 45, 37, 52, 44, 53, 104, 74, 103, 64, 63, 121, 46, 119, 111, 33, 84, 72, 124, 39, 32, 102};
//keyshanc based on peregrin
char keyshancF10[95] = {33, 39, 90, 56, 55, 114, 115, 59, 110, 51, 35, 117, 38, 81, 42, 60, 54, 121, 53, 52, 70, 58, 75, 32, 78, 88, 65, 77, 79, 122, 44, 84, 69, 91, 40, 74, 71, 83, 95, 104, 48, 76, 96, 108, 120, 82, 73, 103, 97, 37, 124, 86, 92, 112, 102, 123, 46, 80, 36, 62, 66, 64, 89, 47, 126, 125, 107, 43, 57, 85, 63, 101, 61, 34, 113, 118, 87, 50, 106, 109, 116, 119, 98, 41, 100, 67, 111, 93, 49, 99, 45, 68, 94, 105, 72};
//keyshanc based on samwise
char keyshancF11[95] = {38, 75, 44, 43, 74, 92, 81, 50, 102, 109, 119, 77, 62, 42, 88, 53, 79, 101, 94, 67, 54, 57, 66, 96, 111, 104, 120, 118, 34, 107, 93, 76, 52, 115, 55, 98, 80, 33, 122, 64, 100, 72, 90, 68, 112, 95, 41, 121, 99, 125, 71, 51, 116, 124, 97, 89, 91, 84, 39, 32, 48, 106, 49, 103, 35, 45, 47, 78, 86, 46, 110, 114, 36, 73, 108, 63, 83, 85, 117, 59, 56, 82, 70, 105, 58, 61, 37, 65, 126, 87, 69, 123, 40, 60, 113};

//The default setting is to disable Keyshanc
int passwordNumber = 12;

PS2Keyboard PS2keyboard;

void setup() {
  delay(1000);
  PS2keyboard.begin(DataPin, IRQpin);
}

void loop() {
  if (PS2keyboard.available()) {
    
    // read the next key
    char c = PS2keyboard.read();
    
    // check for the special keys
    if (c == PS2_ENTER) {
      Keyboard.set_key1(KEY_ENTER);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_DELETE) {
      Keyboard.set_key1(KEY_DELETE);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_TAB) {
      Keyboard.set_key1(KEY_TAB);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_BACKSPACE) {
      Keyboard.set_key1(KEY_BACKSPACE);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_INSERT) {
      Keyboard.set_key1(KEY_INSERT);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_ESC) {
      Keyboard.set_key1(KEY_ESC);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_PAGEUP) {
      Keyboard.set_key1(KEY_PAGE_UP);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_PAGEDOWN) {
      Keyboard.set_key1(KEY_PAGE_DOWN);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_UPARROW) {
      Keyboard.set_key1(KEY_UP);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_DOWNARROW) {
      Keyboard.set_key1(KEY_DOWN);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_LEFTARROW) {
      Keyboard.set_key1(KEY_LEFT);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if (c == PS2_RIGHTARROW) {
      Keyboard.set_key1(KEY_RIGHT);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else if ((c == PS2_F1) || (c == PS2_F2) || (c == PS2_F3) || (c == PS2_F4) || (c == PS2_F5) || (c == PS2_F6) || (c == PS2_F7) || (c == PS2_F8) || (c == PS2_F9) || (c == PS2_F10) || (c == PS2_F11) || (c == PS2_F12) ) {
      //switch passwords based on Function keys
      //F1-F11 are the user-defined passwords, F12 disables Keyshanc
      switch (c)
      {
        case PS2_F1: passwordNumber = 1; break;
        case PS2_F2: passwordNumber = 2; break;
        case PS2_F3: passwordNumber = 3; break;
        case PS2_F4: passwordNumber = 4; break;
        case PS2_F5: passwordNumber = 5; break;
        case PS2_F6: passwordNumber = 6; break;
        case PS2_F7: passwordNumber = 7; break;
        case PS2_F8: passwordNumber = 8; break;
        case PS2_F9: passwordNumber = 9; break;
        case PS2_F10: passwordNumber = 10; break;
        case PS2_F11: passwordNumber = 11; break;
        case PS2_F12: passwordNumber = 12; break;
      }
    } else if (c >= 32 && c <= 126) {      
      // send the character based on the current Keyshanc password
      switch (passwordNumber)
      {
        case 1: Keyboard.print(keyshancF1[c-32]); break;
        case 2: Keyboard.print(keyshancF2[c-32]); break;
        case 3: Keyboard.print(keyshancF3[c-32]); break;
        case 4: Keyboard.print(keyshancF4[c-32]); break;
        case 5: Keyboard.print(keyshancF5[c-32]); break;
        case 6: Keyboard.print(keyshancF6[c-32]); break;
        case 7: Keyboard.print(keyshancF7[c-32]); break;
        case 8: Keyboard.print(keyshancF8[c-32]); break;
        case 9: Keyboard.print(keyshancF9[c-32]); break;
        case 10: Keyboard.print(keyshancF10[c-32]); break;
        case 11: Keyboard.print(keyshancF11[c-32]); break;
        case 12: Keyboard.print(c); break;
      }
    }
  }
}

