#!/bin/bash
cc inc/libft/*.c src/envp/*.c src/lexer/*.c src/minishell_main/*.c src/utils/*.c inc/libft/*.c src/cmd/*.c -o minishell -lreadline -L/usr/include -lncurses