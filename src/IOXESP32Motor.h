#pragma once

#include <stdint.h>

class IOXESP32Motor {
    private:
        uint8_t ch;
        int a, b;

    public:
        IOXESP32Motor(int ch, int a, int b) ;
        
        void begin() ;
        void forward(int speed = 50) ;
        void backward(int speed = 50) ;
        void stop() ;

};

extern IOXESP32Motor M1;
extern IOXESP32Motor M2;
