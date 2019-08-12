#pragma once

#include "utils/fragmented_temporary_buffer.h"

#include <seastar/core/unaligned.hh>

#include <array>
#include <cstdint>
#include <vector>

struct pod {
    int16_t x = 1;
    int32_t y = 2;
    int64_t z = 3;
};
struct [[gnu::packed]] very_packed_pod {
    unaligned<int16_t> x = 1;
    unaligned<int8_t> y = 2;
};
struct complex_custom {
    pod pit;
    fragmented_temporary_buffer oi;
};
struct pod_with_vector {
    pod pit;
    std::vector<int> v{1, 2, 3};
};
struct pod_with_array {
    pod pit;
    std::array<int, 3> v{1, 2, 3};
};
