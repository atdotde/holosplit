all: holosplit holojoin

holosplit: holosplit.c finite_field.h
	clang holosplit.c -o holosplit

holojoin: holojoin.c finite_field.h
	clang holojoin.c -o holojoin
