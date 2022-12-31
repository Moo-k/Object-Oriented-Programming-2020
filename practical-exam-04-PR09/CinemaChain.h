#ifndef CINEMA_CHAIN_H
#define CINEMA_CHAIN_H
#include <string>
#include "Cinema.h"

class CinemaChain{
public:
    CinemaChain();
    Cinema **get_cinemas();
    Cinema **cinemas;
};

#endif
