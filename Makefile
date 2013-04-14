PROJ_DIR = .
INCLUDE_DIR     = $(PROJ_DIR)/include
SRC_DIR         = $(PROJ_DIR)/src
OBJ_DIR         = $(PROJ_DIR)/obj

INCLUDE = -I $(INCLUDE_DIR)
CFLAGS  = -march=x86-64 -fno-builtin -c -Wall $(INCLUDE)
CC      = /usr/bin/gcc
BIN	= main

SRC =	$(SRC_DIR)/main.c	\
	$(SRC_DIR)/tokenize.c		\
	$(SRC_DIR)/file_parser.c	\
	$(SRC_DIR)/my_config.c

#OBJ =   ${SRC:%.c=%.o}
OBJ =	$(OBJ_DIR)/main.o	\
	$(OBJ_DIR)/tokenize.o		\
	$(OBJ_DIR)/file_parser.o	\
	$(OBJ_DIR)/my_config.o
#---make targets
all:	$(BIN)
#%.o:	%.c
#	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/my_config.o: $(SRC_DIR)/my_config.c
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJ_DIR)/tokenize.o:	$(SRC_DIR)/tokenize.c
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJ_DIR)/file_parser.o: $(SRC_DIR)/file_parser.c
	$(CC) -c $(CFLAGS) $< -o $@

main: $(OBJ)
	$(CC) -o $(OBJ_DIR)/$(BIN) $(OBJ) 

.PHONY : clean
clean:	
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/main
