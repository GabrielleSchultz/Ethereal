/*#pragma once

#include <iostream>
#include <time.h>
#include <pthread.h>

class Thread
{
public:
    Thread();
    ~Thread();
    void start();
    static void* runThread( void* add);
    virtual void run();
    void join();
    void kill();
    void lock();
    void unlock();
private:
    static pthread_mutex_t mute;
    pthread_t thread;

};*/