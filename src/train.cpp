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

    Car* current = first;
    int step = 1;
    countOp++;

    while (true) {
        Car* marker = current;
        marker->light = true;
        countOp++;

        Car* runner = marker;
        for (int i = 0; i < step; ++i) {
            runner = runner->next;
            countOp++;
            if (runner->light) {
                int length = 1;
                Car* temp = runner->next;
                countOp++;
                while (temp != runner) {
                    temp = temp->next;
                    length++;
                    countOp++;
                }
                return length;
            }
        }

        marker->light = false;
        countOp++;

        current = runner;
        step *= 2;
    }
}

void Train::resetOpCount() {
    countOp = 0;
}
