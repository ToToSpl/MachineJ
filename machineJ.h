#ifndef MACHINE_J
#define MACHINE_J
#include <iostream>
#include <cstdint>

/* 
 *  16 bit computer
 *  each instruction is occupying one byte world
 */


#define MEMORY_SIZE 128

class MachineJ{

private:
    int16_t data_bus, x_reg, y_reg, addr_reg, curr_addr;
    bool cmp_flag;
    int16_t stack_ptr;

    void x_read(){x_reg = data_bus;};
    void x_write(){data_bus = x_reg;};
    void y_read(){y_reg = data_bus;};
    void y_write(){data_bus = y_reg;};
    void addr_read(){addr_reg = data_bus;};

    void alu_add(){x_reg += data_bus; x_reg < 0 ? cmp_flag = 1 : cmp_flag = 0;};
    void alu_sub(){x_reg -= data_bus; x_reg < 0 ? cmp_flag = 1 : cmp_flag = 0;};
    void alu_cmp(){x_reg == data_bus ? cmp_flag = 1 : cmp_flag = 0;};

    void mem_set_addr(){curr_addr = addr_reg;};
    void mem_read(){memory[curr_addr] = data_bus;};
    void mem_write(){data_bus = memory[curr_addr];};
    void mem_incr_one(){curr_addr++;};

public:
    int16_t memory[MEMORY_SIZE];
    bool running = true;
    void init(u_int16_t startProg);
    void perform_tick();
    void write_program(u_int16_t begin, u_int16_t end, uint16_t* program);

};

//instructions takes parameters from cell below
#define DO_NOTHING 0x00

#define WRITE_X 0x01
#define READ_X 0x02
#define WRITE_Y 0x03
#define READ_Y 0x04

#define ADD 0x05
#define SUB 0x06
#define CMP 0x07

//#define WRITE_M 0x08
//#define READ_M 0x09

#define JMP 0x0A
#define CJMP 0x0B

#define DISP 0x0C
#define READ 0x0D
#define STOP 0x0E


#endif