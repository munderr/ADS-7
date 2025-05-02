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

    int k = 1;
    Car* current = first;
    countOp = 0;

    if (!current->light) {
        current->light = true;
        countOp++;
    }

    while (true) {
        Car* temp = current;
        for (int i = 0; i < k; ++i) {
            temp = temp->next;
            countOp++;
        }

        if (temp->light) {
            return k;
        } else {
            temp->light = true;
            countOp++;

            for (int i = 0; i < k; ++i) {
                temp = temp->prev;
                countOp++;
            }

            k++;
        }
    }
}

void Train::resetOpCount() {
    countOp = 0;
}
