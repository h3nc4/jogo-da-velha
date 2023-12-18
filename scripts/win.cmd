echo 0 ICON "tic-tac-toe.ico" | windres -O coff -o i.o
gcc ..\src\* i.o -o ../jogo-da-velha.exe
del i.o
