# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 14:32:25 by dgaitsgo          #+#    #+#              #
#    Updated: 2018/09/13 11:21:03 by trecomps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scope

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./include

SRC_FILES = \
./src/core/event.c\
./src/core/transform.c\
./src/core/camera.c\
./src/core/geometry.c\
./src/core/main.c\
./src/core/scene.c\
./src/core/window.c\
./src/core/math.c\
./src/core/helpers2.c\
./src/core/helpers.c\
./src/core/event_tool.c\
./src/matrix/copy_matrix.c\
./src/matrix/inverse_rotation_matrix.c\
./src/matrix/inverse_transformations.c\
./src/matrix/matrix.c\
./src/matrix/matrix_getters.c\
./src/matrix/matrix_utility.c\
./src/matrix/object_matrix_build.c\
./src/matrix/opengl_matrix.c\
./src/matrix/perspective_matrix.c\
./src/matrix/rotation_matrix.c\
./src/matrix/screen_space.c\
./src/matrix/transformation_matrix.c\
./src/matrix/view_matrix.c\
./src/opengl/load_obj.c\
./src/opengl/error_log.c\
./src/opengl/exec_log.c\
./src/opengl/generate_vbo.c\
./src/opengl/render_obj.c\
./src/opengl/init_opengl.c\
./src/opengl/load_shaders.c\
./src/opengl/print_log.c\
./src/opengl/triangulate_object.c\
./src/opengl/load_texture_bmp.c\
./src/opengl/load_normals.c\
./src/opengl/load_values.c\
./src/opengl/activate_gl_options.c\
./src/opengl/free_obj_data.c\
./src/opengl/setup_vao.c\
./src/vector/vector.c\
./src/vector/vector_basic_ops.c\
./src/vector/vector_basic_ops2.c\
./src/vector/vector_basic_ops3.c\
./src/vector/vector_constructors.c\
./src/vector/vector_min_max.c\
./src/vector/vector_scale.c\
./src/vector/vector_transformations.c\
./src/parse/file_to_string.c\
./src/parse/parse_mesh.c\
./src/parse/parse_mesh2.c\
./src/parse/parse_mesh3.c\
./src/parse/parse_tools.c\
./src/parse/character_check.c\
./src/parse/parse_mtl.c\


OBJ_FILES = $(SRC_FILES:.c=.o) #$(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

INC_FILES = \
./include/camera.h\
./include/enums.h\
./include/external_headers.h\
./include/geometry.h\
./include/glew.h\
./include/libft.h\
./include/local_headers.h\
./include/macros.h\
./include/maths.h\
./include/matrix.h\
./include/obj_data.h\
./include/opengl.h\
./include/scope.h\
./include/transform.h\
./include/vector.h\
./include/window.h\
./include/parse.h\
./include/mtl.h\


LIB_DIR = ./lib/libft

FLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc -g $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft -F/Library/Frameworks \
		-framework SDL2 -framework OpenGL  -L./lib -lGLEW

all: $(NAME)

%.o:%.c $(INC_FILES)
	gcc -g -c -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
