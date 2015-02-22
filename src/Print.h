#ifndef PRINT_H_
#define PRINT_H_

#include <Arduino.h>

template<class T>
inline Print &operator <<(Print &obj, T arg)
{ obj.print(arg); return obj; }

#endif
