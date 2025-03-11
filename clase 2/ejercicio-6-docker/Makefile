local:
	gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o example max_product_of_substring_tests.c -lm
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./example
	rm example

docker:
	docker build --tag example .
	docker run -v "$(CURDIR)":/ejercicio-6-docker example
	docker rmi example 
