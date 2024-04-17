#bin/bash!

gcc -g *.c -I. -o bin/PVM &&\
    rm *.sh~ \
    *.h~  \
    *.c~
