#pragma once

#include <cstdint>
#include <string>
enum opcode : uint8_t {
    MPR,
    MPL,
    IMC,
    DMC,
    OCC,
    ICC,
    JPI,
    JPO
};


inline std::string conv(opcode op){
    if(op == MPR) return "MOVE POINTER RIGHT";
    if(op == MPL) return "MOVE POINTER LEFT";
    if(op == IMC) return "INCREMENT CURRENT MEMORY CELL";
    if(op == DMC) return "DECREMENT CURRENT MEMORY CELL";
    if(op == OCC) return "OUTPUT CURRENT CELL AS CHARACTER";
    if(op == ICC) return "INPUT CHARACTER, STORE IN CURRENT CELL";
    if(op == JPI) return "IF NOT 0";
    if(op == JPO) return "JUMP BACK IF NOT 0";
}
struct operation{
    opcode op;
    size_t val;
};