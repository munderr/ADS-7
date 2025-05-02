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
    int length = 1;

    while (current->next != first) {
        current = current->next;
        length++;
        countOp++;
    }

    Car* marker = first;
    while (true) {
        current = marker;
        int steps = 0;

        while (!current->light && steps < length) {
            current = current->next;
            steps++;
            countOp++;
        }

        if (current->light) break;

        marker = current;
        marker->light = true;
    }

    current->light = false;
    countOp++;

    return length;
}

void Train::resetOpCount() {
    countOp = 0;
}
