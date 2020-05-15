## MachineJ
Emulation of theoretical computer with architecture J

## quick tour of commands:

# DO_NOTHING
    It is doing nothing just skips to another instruction

# WRITE_X, addr
    Writes whatever is in register X to memory address addr (specified in next memory cell)

# READ_X, addr
    Reads whatever is in memory address addr to X (addr specified in next memory cell)

# WRITE_Y, READ_Y same as for X

# ADD, addr
    Adds to register X value from address addr (if x is negative cmp_flag is set to true)

# SUB, addr
    Substitutes from register X value from addres addr (if x is negative cmp_flag is set to true)

# CMP, addr
    Compares X to value from addr if the same cmp_flag is set to true

# JMP, addr
    Jumpes to addres specified in addr

# CJMP, addr
    Jumpes to addr if cmp_flag is set to high

# DISP, addr
    Displays using std::cout value in addr

# READ, addr
    Reads value from std::cin and puts it in addr

# STOP
    Sets the flag running to false so you know when to stop emulation

## Example
Example of multiplication

    0,
    0,
    0,
    1,
    0,
    READ, 0,    //Take value from std::cin and put it to adress 0
    READ, 2,    //Take value from std::cin and put it to adress 2
    READ_X, 1,  //X reads value from address 1
    ADD, 0,     //Add value from address 0 to X
    WRITE_X, 1, //X writes to address 1
    READ_X, 2,  //X reads from address 2
    SUB, 3,     //substitute value from address 3 (value 1) from X
    WRITE_X, 2, //X writes to address 2
    CMP, 4,     //Check if X is equal to value from address 4 (value 0)
    CJMP, 27,   //If yes jump to diplay
    JMP, 9,     //If not jump to multiplying
    DISP, 1,    //Display the result stored in cell 1
    STOP        //Stop the execution

## Remarks
    Feel free to add new commands and microprograms there is definietly way to improve this. :wink: