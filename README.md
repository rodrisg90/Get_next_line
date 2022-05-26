# Get_next_line
A function that returns a line, read from a file descriptor.

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out

gcc -g -Wall -Werror -Wextra -D BUFFER_SIZE=3 get_next_line_bonus.c get_next_line_utils_bonus.c && valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./a.out
