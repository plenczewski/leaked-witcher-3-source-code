all:
	#mkdir build
	cd build
	del mem.map
	del main.sym
	del main.exe
	del main.cpe
	cd ..
	#cls

	ccpsx -O3 -Wall -Xo$80010000 .\source\**.c -obuild\main.cpe,build\main.sym,build\mem.map
	cpe2x /ce build\main.cpe