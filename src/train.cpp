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
    countOp++;

    int power = 1;
    int count = 0;
    Car* marker = current;
    marker->light = true;
    countOp++;

    while (true) {
        current = marker;
        count = 0;
        countOp++;

        while (!current->light && count < power) {
            current = current->next;
            count++;
            countOp++;
        }

        if (current->light) break;

        power *= 2;
        marker = current;
        marker->light = true;
        countOp++;
    }

    current->light = false;
    countOp++;

    int length = 1;
    Car* runner = current->next;
    countOp++;

    while (runner != current) {
        runner = runner->next;
        length++;
        countOp++;
    }

    return length;
}

void Train::resetOpCount() {
    countOp = 0;
}
