all: holosplit

holosplit: holosplit.c
	clang holosplit.c -o holosplit
