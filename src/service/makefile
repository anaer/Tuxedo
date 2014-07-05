all:
	proc service.pc
	cl /c -DWINDOWS service.c -I..\..\include -IC:\oracle\product\10.2.0\db_1\precomp\public -IC:\bea\tuxedo8.1\include
	buildserver -v -o service -f *.obj  -s sv_connect -s sv_update -s sv_check -f "C:\oracle\product\10.2.0\db_1\precomp\lib\orasql10.lib" -f "..\..\lib\public.obj" -f "..\..\lib\realize.obj"
	@mv service.exe ../../bin
	@rm service.c service.obj
