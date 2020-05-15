#include "machineJ.h"

void MachineJ::init(u_int16_t startProg)
{
    curr_addr = startProg;
    mem_write();
}

void MachineJ::perform_tick()
{
    //reading instruction
    mem_write();
    uint16_t instruction = data_bus;
    //std::cout << "x:" << x_reg << " y:" << y_reg << std::endl;

    switch (instruction)
    {
    case DO_NOTHING:
        mem_incr_one();
        break;
    
    case WRITE_X:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        x_write();
        mem_read();
        curr_addr = stack_ptr; 
        mem_incr_one();
        break;

    case READ_X:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        x_read();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;
    
    case WRITE_Y:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        y_write();
        mem_read();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case READ_Y:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        y_read();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case ADD:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        alu_add();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case SUB:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        alu_sub();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case CMP:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        alu_cmp();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case JMP:
        mem_incr_one();
        mem_write();
        addr_read();
        mem_set_addr();
        break;

    case CJMP:
        mem_incr_one();
        if(cmp_flag){
            mem_write();
            addr_read();
            mem_set_addr();
        }else mem_incr_one();
        break;

    case DISP:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        mem_write();
        std::cout << data_bus << std::endl;
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case READ:
        mem_incr_one();
        stack_ptr = curr_addr;
        mem_write();
        addr_read();
        mem_set_addr();
        std::cout << "insert parameter: ";
        std::cin >> data_bus;
        mem_read();
        curr_addr = stack_ptr;
        mem_incr_one();
        break;

    case STOP:
        running = false;
        break;

    default:
        std::cout << "Illegal instruction exec! Code: " << instruction << std::endl;
    }
}

void MachineJ::write_program(u_int16_t begin, u_int16_t end, uint16_t* program)
{
    for(int i = begin; i < end; i++){
        memory[i] = program[i];
    }
}