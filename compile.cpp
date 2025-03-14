#include "op.h"
#include <cassert>
#include <stack>
#include "compile.h"

std::vector<operation>& assign_loop_values(std::vector<operation>& in){
    size_t loopval {0};
    std::stack<operation*> process{};

    for(size_t idx {0}; idx < in.size(); ++idx){
        auto& cur {in.at(idx)};
        if(cur.op == JPI){
            cur.val = loopval;
            process.push(&cur);
        }

        if(cur.op == JPO){
            assert(process.top()->op == JPI && "Double closing bracket");
            cur.val = process.top()->val;
            process.top()->val = loopval;
            process.pop();
        }
        loopval++;
    }
    assert(process.empty() && "Unmatched opening bracket");
    return in;
}

std::vector<operation> compile(std::string in){
    std::vector<operation> output{};
    size_t idx {0};
    size_t idx_end {in.size()};


    while(idx < idx_end){
        auto ch = in.at(idx);

        switch(ch){
            case '>':{
                output.push_back({MPR,1});
            }
            break;
            case '<':{
                output.push_back({MPL,1});
            }
            break;
            case '+':{
                output.push_back({IMC,1});
            }
            break;
            case '-':{
                output.push_back({DMC,1});
            }
            break;
            case '.':{
                output.push_back({OCC,0});
            }
            break;
            case ',':{
                output.push_back({ICC,0});
            }
            break;
            case '[':{
                output.push_back({JPI,0});
            }
            break;
            case ']':{
                output.push_back({JPO,0});
            }
            break;

        }

        idx++;

    }

    return assign_loop_values(output);

};
