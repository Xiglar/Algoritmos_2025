FROM ubuntu:latest
RUN apt update -y && apt upgrade -y
RUN apt install gcc valgrind make time -y
COPY . .
CMD make local
