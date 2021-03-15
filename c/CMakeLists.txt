cmake_minimum_required(VERSION 3.17)
project(c LANGUAGES C)

add_executable(c main.c shapes.h shapes.c)
target_compile_features(c PRIVATE c_std_11)
target_compile_options(c
        PRIVATE
        $<$<OR:$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:-Wall;-Wextra;-pedantic>
        $<$<C_COMPILER_ID:MSVC>:/W3>)
