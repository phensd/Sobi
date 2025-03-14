#include "machine.h"
#include "op.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "compile.h"
#include <fstream>
#include "run.h"


int main(int argc, char *argv[]){
    std::vector<std::string> args{argv+1,argc+argv};
    machine bmachine;

    bool cells {(std::find(args.begin(),args.end(),"-cells") != args.end())};
    bool operations {(std::find(args.begin(),args.end(),"-ops") != args.end())};

    if(args.size() >= 1){
        if(std::filesystem::is_regular_file(args.at(0))){
            std::string file_stream{};
            std::string line{};
            std::ifstream _file_handle(args.at(0));
            while(std::getline(_file_handle,line)){
                file_stream += line + "\n";
            }
            bmachine.ops = compile(file_stream);

        }else{
            std::cerr << "File not found ... " << std::quoted(args.at(0)) << ".\n";
            std::exit(1);
        }
    }else{
        std::cerr << "Please input a file to compile & run...\n";
        std::exit(1);
    }

    if(bmachine.ops.size() > 0){
        if(operations) {
            show_ops(bmachine);
            std::cerr << "Output of operations: \n";
        }
        run(bmachine);
        if(cells) show_cells(bmachine);

    }else{
        std::cerr << "No operations made from file ... "<< std::quoted(args.at(0)) << ". (Is it empty?) \n";
        std::exit(1);
    }
    return 0; 
}