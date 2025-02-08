FROM gcc:11.3.0

WORKDIR /workdir
COPY ./code .
RUN gcc program1.c -o program1 && gcc program2.c -o program2 
RUN touch file.txt
RUN chmod +x program1 && chmod +x program2

CMD ["/bin/sh", "-c", "./program1 | ./program2"]

