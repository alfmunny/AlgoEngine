file(GLOB graphics_src
    "*h"
    "*hpp"
    "*cpp"
    "models/*"
    "shapes/*"
    "diagrams/*"
    )

add_library(
    graphics
    ${graphics_src}
    )
