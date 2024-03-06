#!/bin/bash
cc src/envp/*.c src/lexer/*.c src/minishell/*.c src/utils/*.c inc/libft/*.c src/cmd/*.c -o minishell -lreadline -L/usr/include -lncurses