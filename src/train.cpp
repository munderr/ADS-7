// Copyright 2022 NNTU-CS
#include "train.h"
#include <cstdlib>

Train::Train() : countOp(0), head(nullptr) {}

void Train::addCar(bool lightOn) {
  Car* newCar = new Car{lightOn, nullptr, nullptr};

  if (!head) {
    head = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car* tail = head->prev;
    newCar->next = head;
    newCar->prev = tail;
    tail->next = newCar;
    head->prev = newCar;
    head = newCar;
  }
}

int Train::getLength() {
  if (!head) return 0;
  if (head->next == head) return 1;

  countOp = 0;
  Car* walker = head;
  int size = 1;

  if (!walker->light) {
    walker->light = true;
  }

  walker = walker->next;
  countOp += 2;

  while (!walker->light) {
    walker = walker->next;
    countOp += 2;
    size++;
  }

  walker->light = false;

  if (!head->light) {
    return size;
  }

  while (true) {
    walker = head;
    size = 1;

    if (!walker->light) {
      walker->light = true;
    }

    walker = walker->next;
    countOp += 2;

    while (!walker->light) {
      walker = walker->next;
      countOp += 2;
      size++;
    }

    walker->light = false;

    if (!head->light) {
      return size;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}

Train::~Train() {
  if (!head) return;

  if (head->next == head) {
    delete head;
    head = nullptr;
    return;
  }

  Car* current = head->next;
  while (current != head) {
    Car* temp = current;
    current = current->next;
    delete temp;
  }

  delete head;
  head = nullptr;
}
