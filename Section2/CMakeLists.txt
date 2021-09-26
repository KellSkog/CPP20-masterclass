add_executable(section2 
    hello_world.cpp)
set_target_properties(section2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section2 PUBLIC cxx_std_20)