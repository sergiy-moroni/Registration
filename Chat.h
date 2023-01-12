#pragma once

#include "HashTable.h"
#include "string.h"

#define SIZE 10
#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    void reg(char _login[LOGINLENGTH], int _pass);
    bool login(char _login[LOGINLENGTH], int _pass);

    private:
        HashTable percons;
    int data_count;
};
