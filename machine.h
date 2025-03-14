#pragma once

#include "op.h"
#include <vector>
struct machine{
    std::vector<uint8_t> cells;
    std::vector<operation> ops;
    size_t cell_ptr;

    machine() : cells{std::vector<uint8_t>(30000)}, ops{std::vector<operation>{}}, cell_ptr{0} {}
};
