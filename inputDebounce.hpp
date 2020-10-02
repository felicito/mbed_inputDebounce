/**
 * @file inputDebounce.hpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-10-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#ifndef __INPUTDEBOUNCE_HPP
#define __INPUTDEBOUNCE_HPP

    extern const int    SAMPLES_INPUT;

    int exeIgnition(DigitalIn *Ign, bool arrayIgn[], bool *actIgn, bool *preIgn, int *cont);
    int exeDigInput(DigitalIn *my_Input, bool my_arrayInput[], bool *my_Input_read, bool *my_Input_previous, int *cont);

#endif// __INPUTDEBOUNCE_HPP