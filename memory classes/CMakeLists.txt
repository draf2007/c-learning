cmake_minimum_required(VERSION 3.15)
project(MyCModuleProject LANGUAGES C)

# Требовать C11 и не откатываться на старые стандарты
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Создаём исполняемый файл 'app' из ваших исходников
add_executable(app 
    primera_s_zanyatiya.c 
    module.c
)

# Предупреждения применяем ТОЛЬКО к нашему проекту (современный подход)
target_compile_options(app PRIVATE 
    -Wall 
    -Wextra 
    -pedantic
)

# Опционально: включить отладочную информацию для GDB/VSCode
target_compile_options(app PRIVATE -g)