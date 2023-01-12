#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], int _pass) {
   
    percons.add(_login, _pass);
}

bool Chat::login(char _login[LOGINLENGTH], int _pass) {


    if (percons.find(_login) == _pass) {
        return true;
    }
    return false;
    
}
