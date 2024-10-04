# 添加源文件
file(GLOB SOURCES "src/*.cpp")

# 检查 SOURCES 是否为空
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src directory")
endif()
