#include "op.h"
#include <climits>
#include <iomanip>
#include <iostream>
#include "run.h"


uint8_t& ccellv(machine& bmachine){
    return bmachine.cells.at(bmachine.cell_ptr);
}

void show_ops(machine& bmachine){
    size_t idx {0};
    for(auto& op : bmachine.ops){
        std::cerr << "INSTR "<< idx << ": " << conv(op.op) << " : " << (int)op.val << '\n';
        idx++;
    }
}


void show_cells(machine& machine){
    std::cerr << '\n';
    for(size_t idx {0}; idx < machine.cells.size(); ++idx){
        auto crnt {machine.cells.at(idx)};
        if(idx > 0 && idx % 40 == 0) std::cerr << '\n';
        std::cerr  << (int) crnt << std::setw(4);
    }
    std::cerr << '\n';
}
void run(machine& bmachine){

    for(size_t pc {0}; pc < bmachine.ops.size(); ++pc){
        auto co {bmachine.ops.at(pc)};

        switch(co.op){
            case MPR:{
                bmachine.cell_ptr += co.val;
                if(bmachine.cell_ptr >= bmachine.cells.size()){
                    bmachine.cell_ptr = 0;
                }
            }
            break;
            case MPL:{
                bmachine.cell_ptr -= co.val;
                if(bmachine.cell_ptr >= bmachine.cells.size()){
                    bmachine.cell_ptr = bmachine.cells.size()-1;
                }
            }
            break;
            case IMC:{
                ccellv(bmachine) += co.val;
            }
            break;
            case DMC:{
                ccellv(bmachine) -= co.val;
            }
            break;
            case OCC:{
                std::cerr << (char)ccellv(bmachine);
            }
            break;

            case ICC:{
                char c;
                std::cin >> c;
                ccellv(bmachine) = (uint8_t) c;
                std::cin.clear(); std::cin.ignore(INT_MAX,'\n'); 
            }
            break;
            
            case JPI:{
                if(ccellv(bmachine) == 0){
                    pc = (co.val);
                }
            }
            break;

            case JPO:{
                if(ccellv(bmachine) != 0){
                        pc = (co.val);
                }
            }
            break;




        }
    }

}
