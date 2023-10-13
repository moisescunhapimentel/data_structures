cmake_minimum_required(VERSION 3.10)
project(MeuProjeto)

# Habilita o uso do CTest
enable_testing()

# Adicione aqui os nomes das pastas que você deseja compilar
set(PASTAS "queue" "stack" "circular_linked_list" "doubly_circular_linked_list" "doubly_linked_list" "linked_list")

foreach(PASTA ${PASTAS})
    add_library(${PASTA} ${PASTA}/${PASTA}.c)
    target_include_directories(${PASTA} PUBLIC ${PASTA})

    add_executable(${PASTA}_test ${PASTA}/test/${PASTA}_test.c)
    target_link_libraries(${PASTA}_test ${PASTA} cunit)

    # Adiciona o teste para o CTest
    add_test(NAME ${PASTA}_test COMMAND ${PASTA}_test)
endforeach()
