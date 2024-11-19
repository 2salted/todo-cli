cmake_minimum_required(VERSION 3.10)

# Project name
project(todo-cli VERSION 0.2.1)

# Define C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(todo src/main.cpp)

target_compile_definitions(todo PRIVATE APP_VERSION="${PROJECT_VERSION}")

install(TARGETS todo DESTINATION /usr/local/bin/)
# Include directories (optional)
# include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (optional)
# target_link_libraries(MyExecutable ${PROJECT_SOURCE_DIR}/lib/my_library.a)

