roots :
make all

1st term:

	qemu-system-x86_64 -cdrom k.iso

debug :
	gdb -x gdb_command
	b k_main
	c

	lay src ou lay asm dans gdb pour afficher l'assembleur ou le c
