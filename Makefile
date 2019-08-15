TEST_DIR = ./test
TEST_SRC = $(TEST_DIR)/test.c
TEST_NAME = test
TEST_FILE = $(TEST_DIR)/$(TEST_NAME)
CC = gcc
RM = rm -rf

all: $(TEST_NAME)

$(TEST_NAME): $(TEST_FILE)
	$(CC) $(TEST_SRC) -o $(TEST_FILE)