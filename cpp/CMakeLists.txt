cmake_minimum_required(VERSION 3.17)
project(cpp LANGUAGES CXX)

add_executable(cpp main.cpp shapes.hpp)
target_compile_features(cpp PRIVATE cxx_std_20)
target_compile_options(cpp
        PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wall;-Wextra;-pedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W3>)
