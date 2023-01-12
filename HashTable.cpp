#include "HashTable.h"

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array = new Pair[mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}

void HashTable::add(loginName log, int pas) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(log, i);
        if (array[index].status != enPairStatus::engaged) {
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }
    if (i >= mem_size) return; // все перебрали, нет места

    // кладем в свободную ячейку пару
    array[index] = Pair(log, pas);
    count++;
}

int HashTable::hash_func(loginName log, int pas) {
    // вычисляем индекс
    int sum = 0, i = 0;
    for (; i < strlen(log); i++) {
        sum += log[i];
    }
    // квадратичные пробы
    return (sum % mem_size + pas * pas) % mem_size;
}

void HashTable::del(loginName log) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(log, i);
        if (array[index].status == enPairStatus::engaged &&
            !strcmp(array[index].login, log)) {
            array[index].status = enPairStatus::deleted;
            count--;
            return;
        }
        else if (array[index].status == enPairStatus::free) {
            return;
        }
    }
}

int HashTable::find(loginName log) {

    for (int i = 0; i < mem_size; i++) {
        int index = hash_func(log, i);
        if (array[index].status == enPairStatus::engaged &&
            !strcmp(array[index].login, log)) {
            return array[index].pass;
        }
        else if (array[index].status == enPairStatus::free) {
            return -1;
        }
    }
    return -1;
}
