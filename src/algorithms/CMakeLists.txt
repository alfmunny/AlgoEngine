file(GLOB algorithms_src
    "*h"
    "*cpp"
    )

add_library(
    algorithms
    ${algorithms_src}
    )
