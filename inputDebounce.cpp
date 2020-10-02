/**
 * @file inputDebounce.cpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-10-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "mbed.h"

const int SAMPLES_INPUT   = 4;  

int exeIgnition(DigitalIn *Ign, bool arrayIgn[], bool *actIgn, bool *preIgn, int *cont) {
    bool are_equal = false;
    int answer = 0;

    arrayIgn[*cont] = Ign -> read();   
    *cont = *cont + 1; 

    if (*cont == SAMPLES_INPUT) {
        *cont = 0;                
        
        are_equal = (((arrayIgn[0] == arrayIgn[1]) == arrayIgn[2]) == arrayIgn[3]);
        if(are_equal) {
            *actIgn = arrayIgn[0];
            if (*actIgn != *preIgn) {
                *preIgn = *actIgn;
                if (*actIgn) {
                    answer = 1;
                } else {
                    answer = -1;              
                }
            } else {
                answer = 0;
            }
        }
    }
    return(answer);
}

int procesar_entradas(DigitalIn *my_Input, bool my_arrayInput[], bool *my_Input_read, bool *my_Input_previous, int *cont) {
    bool are_equal = false;
    int answer = 0;

    my_arrayInput[*cont] = my_Input -> read();
    *cont = *cont + 1; 
 
    if (*cont == SAMPLES_INPUT) {
        *cont = 0;                      
        are_equal = (((my_arrayInput[0] == my_arrayInput[1]) == my_arrayInput[2]) == my_arrayInput[3]);
        if (are_equal) {
            *my_Input_read = my_arrayInput[0];
            if (*my_Input_read != *my_Input_previous) {
                *my_Input_previous = *my_Input_read;
                if (*my_Input_read) {
                    answer = 1;
                } else {
                    answer = -1;
                }
            } 
        }
    }
    return(answer);
 }

