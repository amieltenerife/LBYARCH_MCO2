nasm -f win64 MCO2.asm
gcc -c MCO2.c -o CMCO2.obj -m64
gcc CMCO2.obj MCO2.obj -o MCO2.exe
MCO2.exe