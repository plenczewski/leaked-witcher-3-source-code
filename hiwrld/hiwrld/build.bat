set PATH=C:\Psyq\bin;
set PSX_PATH=C:\Psyq\bin
set LIBRARY_PATH=C:\Psyq\lib
set C_PLUS_INCLUDE_PATH=C:\Psyq\include
set C_INCLUDE_PATH=C:\Psyq\include
set PSYQ_PATH=C:\Psyq\bin
set COMPILER_PATH=C:\Psyq\bin
set GO32=DPMISTACK 1000000 
set G032TMP=C:\WINDOWS\TEMP
set TMPDIR=C:\WINDOWS\TEMP

mkdir build
cd build
del mem.map
del main.sym
del main.exe
del main.cpe
del *.o
cd ..

ccpsx -v -c -O0 -Xo$80010000 -Wall utils.c -obuild\utils.o
ccpsx -v -c -O0 -Xo$80010000 -Wall render.c -obuild\render.o
ccpsx -v -c -O0 -Xo$80010000 -Wall structs.c -obuild\structs.o
ccpsx -v -c -O0 -Xo$80010000 -Wall game.c -obuild\game.o

ccpsx -v -O0 -Wall -Xo$80010000 main.c build\*.o -obuild\main.cpe,build\main.sym,build\mem.map

cpe2x /ce build\main.cpe
del Z:\main.exe
copy build\main.exe Z:\main.exe