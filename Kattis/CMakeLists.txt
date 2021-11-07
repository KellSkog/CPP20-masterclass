add_executable(rockband
    rockband.cpp)
set_target_properties(rockband PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(rockband PUBLIC cxx_std_20)