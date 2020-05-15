#include <iostream>
#include "machineJ.h"

#include <thread>
#include <chrono>

//1 1 2 3 5 8 13 ...
u_int16_t fibb_program[] = {
    1, // i -1
    1, // i
    100, //maximum
    READ_X, 0, // i - 1
    READ_Y, 1,
    ADD, 1,
    WRITE_X, 1, // i + 1
    WRITE_Y, 0,
    DISP, 1,
    SUB, 2,
    CJMP, 3,
    STOP
};

u_int16_t simp_test[] = {
    1,
    1,
    DISP, 0x00,
    READ_X, 0x00,
    ADD, 0x01,
    WRITE_X, 0x00,
    JMP, 0x02
};

u_int16_t multiply[] = {
    0,
    0,
    0,
    1,
    0,
    READ, 0,
    READ, 2,
    READ_X, 1,
    ADD, 0,
    WRITE_X, 1,
    READ_X, 2,
    SUB, 3,
    WRITE_X, 2,
    CMP, 4,
    CJMP, 27,
    JMP, 9,
    DISP, 1,
    STOP
};


int main(){

    MachineJ computer;
    computer.write_program(0, sizeof(fibb_program) / sizeof(u_int16_t), fibb_program);
    //computer.write_program(0, sizeof(simp_test) / sizeof(u_int16_t), simp_test);
    //computer.write_program(0, sizeof(multiply) / sizeof(u_int16_t), multiply);

    computer.init(0x03);
    //for(int i = 0; i < 100; i++) computer.perform_tick();
    while(computer.running){
        computer.perform_tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}