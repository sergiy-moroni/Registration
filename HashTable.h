#pragma once
#include <string.h>
#define NAMELENGTH 10  // Зафиксируем длину имени

typedef char loginName[NAMELENGTH]; // тип имя фрукта

class HashTable { // хеш-таблица
public:

    HashTable();
    ~HashTable();
    void add(loginName log, int pas);
    void del(loginName log);
    int find(loginName log);


private:

    enum enPairStatus {
        free, // свободен
        engaged, //занят
        deleted //удален
    };

    struct Pair { // пара ключ-значение

        Pair() : // конструктор по умолчанию
            login(""),
            pass(-1),
            status(enPairStatus::free) {

        }
        Pair(loginName log, int pas) : // конструктор копирования
            pass(pas),
            status(enPairStatus::engaged) {
            strcpy(login, log);
        }
        Pair& operator = (const Pair& other) { //  оператор присваивания
            pass = other.pass;
            strcpy(login, other.login);
            status = other.status;

            return *this;
        }

        loginName login; // имя пользователя (ключ)
        int pass; // зфыы (значение)

        enPairStatus status; // состояние ячейки
    };

    int hash_func(loginName log, int pas);

    Pair* array;
    int mem_size;
    int count;
};

