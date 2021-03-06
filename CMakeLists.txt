cmake_minimum_required(VERSION 3.13)
#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(vmrentsys)

enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        src/main.cpp
        include/vmr_system.h src/vmr_system.cpp
        include/pricing_behavior.h
        include/affiliative_discount.h src/affiliative_discount.cpp
        include/User.h src/User.cpp
        include/Services.h src/Services.cpp
        include/big_fish_af_discount.h src/big_fish_af_discount.cpp
        include/starter_discount.h src/starter_discount.cpp
        include/without_discount.h src/without_discount.cpp)

add_executable(vmrentsys ${SOURCE_FILES})

target_include_directories(vmrentsys PUBLIC include)

#TESTs
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        src/vmr_system.cpp
        src/User.cpp
        src/Services.cpp
        src/affiliative_discount.cpp
        src/big_fish_af_discount.cpp
        src/starter_discount.cpp
        src/without_discount.cpp
        test/affiliate_discount_test.cpp)

add_executable(Test_vmrentsys ${SOURCE_TEST_FILES})

target_include_directories(Test_vmrentsys PUBLIC include)

target_link_libraries (Test_vmrentsys
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})