cmake_minimum_required(VERSION 3.14)
project(proto C)

include(CTest)

add_library(core_lib
    objects/core/typeobject.c
    # objects/core/coreObjects/uintarrobejct.c (if it exists)
    # ... other .c files
)
target_include_directories(core_lib
    PUBLIC
    ${PROJECT_SOURCE_DIR}/objects/core
)

add_executable(core_test
    objects/core/tests/main.c
    # any other test .c
)
target_link_libraries(core_test core_lib)
add_test(NAME typeobject_test COMMAND core_test)

