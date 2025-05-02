// Copyright 2022 NNTU-CS
#include "train.h"
#include <cstdlib>

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        newCar->next = newCar->prev = newCar;
        first = newCar;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (!first) return 0;

    countOp = 0;
    Car* ptr = first;

    while (true) {
        if (!ptr->light) {
            ptr->light = true;
            countOp++;
            ptr = ptr->next;
            countOp++;
        } else {
            ptr->light = false;
            countOp++;
            break;
        }
    }

    int length = 1;
    ptr = ptr->next;
    countOp++;
    while (!ptr->light) {
        ptr = ptr->next;
        length++;
        countOp++;
    }

    ptr->light = false;
    countOp++;

    return length;
}

void Train::resetOpCount() {
    countOp = 0;
}
