#ifndef Valve_h
#define Valve_h
#include <Arduino.h>


#define UNKNOWN = 0;
#define OPENING = 1;
#define OPEN = 2;
#define CLOSING = 3;
#define CLOSED = 4;

#define DISPLAY_W = 128;
#define DISPLAY_H = 128;

// Upper 10 px are for display label
#define LABEL_H = 10;


class Valve
{
    
public:
    Valve();
    void open();
    void close();
    int getStatus();

private:  
    int _state; // State indicates open, opening, closed, closing
    int _desiredState;

};

#endif