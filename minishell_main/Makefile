# Компилятор
CC := cc

# Флаги компиляции
CFLAGS := -Wall -Wextra -g

# Пути к исходным файлам
SRC_DIRS := src/envp src/lexer src/minishell src/utils inc/libft src/cmd

# Исходные файлы
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Объектные файлы
OBJS := $(SRCS:.c=.o)

# Имя исполняемого файла
TARGET := minishell

# Библиотеки
LIBS := -lreadline -lncurses

# Путь к заголовочным файлам
INC_DIRS := inc libft

# Опции для компиляции, указывающие на пути к заголовочным файлам
INC_FLAGS := $(foreach dir,$(INC_DIRS),-I$(dir))

# Цель сборки
all: $(TARGET)

# Команда компиляции
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Правило для компиляции исходных файлов
%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJS)

# Полная очистка (удаляет также исполняемый файл)
distclean: clean
	rm -f $(TARGET)

# Неявное правило для создания объектных файлов из исходных
# %.o: %.c
# 	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Указываем, что цели clean и distclean не являются файлами
.PHONY: clean distclean
