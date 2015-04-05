//
// Created by Daniel on 4/5/2015.
//

#include <cstdio>
#include "queue.h"

std::default_random_engine rng;

bool newPrintTask();

int Task::getTimeStamp() {
    return timeStamp;
}

int Task::getPages() {
    return pages;
}

int Task::getWaitTime(int currentTime) {
    return currentTime - timeStamp;
}

Task::Task(int timeStamp) {
    this->timeStamp = timeStamp;
    auto dist = std::uniform_int_distribution<int>(1, 20);
    pages = dist(rng);
}

Printer::Printer(int ppm) : ppm(ppm), currentTask(nullptr), timeRemaining(0) { };

bool Printer::isBusy() {
    return currentTask != nullptr;
}

void Printer::startNext(Task &task) {
    currentTask = &task;
    timeRemaining = task.getPages() * 60 / ppm;
}

void Printer::tick() {
    if (currentTask != nullptr) {
        timeRemaining--;
        if(timeRemaining <= 0) {
            currentTask = nullptr;
        }
    }
}


void PrinterQueue(int numSeconds, int pagesPerMinute) {
    auto labprinter = Printer(pagesPerMinute);
    auto printQueue = queue<Task>();
    auto waitingTimes = std::vector<int>();

    for (auto currentSecond = 0; currentSecond < numSeconds; ++currentSecond) {
        if(newPrintTask()){
            printQueue.enqueue(Task(currentSecond));
        }

        if(!labprinter.isBusy() && !printQueue.isEmpty()) {
            auto nexttask = printQueue.dequeue();
            waitingTimes.push_back(nexttask.getWaitTime(currentSecond));
            labprinter.startNext(nexttask);
        }

        labprinter.tick();
    }

    auto avg = 0.0;
    for (auto wt : waitingTimes) {
        avg += wt;
    }
    avg /= waitingTimes.size();

    printf("average wait: %6.2f seconds %3zu tasks remaining.\n", avg, printQueue.size());
}

bool newPrintTask() {
    auto dist = std::uniform_int_distribution<int>(1, 180);
    return dist(rng) == 180;
}

std::string hotPotato(const std::vector<std::string> names, int num) {
    auto q = queue<std::string>();
    for (auto name : names) {
        q.enqueue(name);
    }

    while (q.size() > 1) {
        for (int i = 0; i < num; ++i) {
            q.enqueue(q.dequeue());
        }

        q.dequeue();
    }
    return q.dequeue();
}