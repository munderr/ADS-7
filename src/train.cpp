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
    if (!first) {
        return 0;
    }

    int length = 1;
    Car* current = first;
    countOp = 0;

    while (true) {
        Car* temp = current;
        if (!temp->light) {
            temp->light = true;
            countOp++;
        }

        current = current->next;
        if (current == first) {
            break;
        }
        
        length++;
    }

    return length;
}

void Train::resetOpCount() {
    countOp = 0;
}
