cmake_minimum_required(VERSION 3.14)
project(proto C)

include(CTest)

add_library(core_lib
    objects/core/typeobject.c
    objects/core/coreObjects/uintarrobejct.c
    objects/core/coreObjects/arrobejct.c
    objects/core/coreObjects/arrobejct_alloc.c  # <-- new file
)

target_include_directories(core_lib
    PUBLIC
    ${PROJECT_SOURCE_DIR}/objects/core
    ${PROJECT_SOURCE_DIR}/objects/core/coreObjects
)

add_executable(typetest
    objects/core/tests/typetest.c
)

target_link_libraries(typetest core_lib)

target_include_directories(typetest
    PUBLIC
    ${PROJECT_SOURCE_DIR}/objects/core
    ${PROJECT_SOURCE_DIR}/objects/core/coreObjects
)

add_test(NAME typeobject_test COMMAND typetest)

