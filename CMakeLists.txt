cmake_minimum_required(VERSION 3.7)
project(fdf)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set(SOURCE_FILES main.c ./gnl/get_next_line.c create_fill_matrix.c make_image.c rotate_matr.c additional_ft.c)

include_directories(inc libft/includes minilibx gnl)

link_directories(libft minilibx gnl)

add_executable(fdf ${SOURCE_FILES})

target_link_libraries(fdf libft.a libmlx.a "-framework OpenGL" "-framework AppKit")