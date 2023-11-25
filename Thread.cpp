#include "../Threads/Thread.h"

pthread_mutex_t Thread::mute(0);

Thread::Thread()
{
}

Thread::~Thread()
{
}

void Thread::start()
{
    pthread_create(&thread, NULL, Thread::runThread, ( void* )this );
    if((int) mute != -1)
        pthread_mutex_init(&Thread::mute, NULL);
}

void* Thread::runThread(void* add)
{
    Thread* pThread = static_cast<Thread*>(add);
    pThread->run();
}

void Thread::run()
{
    int i = 0;
    while(true)
    {
        std::cout << "thread funcionando" << std::endl;
        if ( i > 2000)
            break;
        i++;
    }
    
}

void Thread::join()
{
    pthread_join(thread, NULL);
}

void Thread::kill()
{
    pthread_kill(thread, 0);
}

void Thread::lock()
{
    pthread_mutex_lock(&Thread::mute);
}

void Thread::unlock()
{
    pthread_mutex_unlock(&Thread::mute);
}