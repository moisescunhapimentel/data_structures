cmake_minimum_required(VERSION 3.10)
project(data_structures)

enable_testing()

file(GLOB PASTAS RELATIVE ${CMAKE_SOURCE_DIR} "*")
list(FILTER PASTAS EXCLUDE REGEX "^\\..*") 
list(REMOVE_ITEM PASTAS "build")

# foreach(PASTA ${PASTAS})
# list(APPEND DIRS ${item})
# message("Pasta encontrada: ${PASTA}")
# endforeach()

foreach(PASTA ${PASTAS})
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${PASTA}")
        add_library(${PASTA} ${PASTA}/${PASTA}.c)
        target_include_directories(${PASTA} PUBLIC ${PASTA})

        add_executable(${PASTA}_test ${PASTA}/test/${PASTA}_test.c)
        target_link_libraries(${PASTA}_test ${PASTA} cunit)

        add_test(NAME ${PASTA}_test COMMAND ${PASTA}_test)
    endif()
endforeach()
