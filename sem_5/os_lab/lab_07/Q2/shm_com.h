// shm_com.h
#ifndef SHM_COM_H
#define SHM_COM_H

#define TEXT_SZ 1

struct shared_use_st {
    int written_by_you;
    char some_text[TEXT_SZ];
};

#endif
