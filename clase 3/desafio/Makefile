local:
	gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o example desafio.c -lm
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./example
	rm example

docker:
	docker build --tag example .
	docker run -v "$(CURDIR)" example
	docker rmi example 
