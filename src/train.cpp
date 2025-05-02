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

    int length = 0;
    Car* current = first;
    countOp = 0;

    do {
        length++;
        if (!current->light) {
            current->light = true;
            countOp++;
        }
        current = current->next;
    } while (current != first);

    return length;
}

void Train::resetOpCount() {
    countOp = 0;
}
