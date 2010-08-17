/*
 * main.cc
 *
 *  Created on: Aug 16, 2010
 *      Author: fify
 */

int main()
{
	__asm__(
			"jmp forward\n\t"
		"backward: \n\t"
			"pop   %esi             # Get the address of \n\t"
			"                                       # hello world string \n\t"
			"mov   $4, %eax        # Do write system call \n\t"
			"mov   $2, %ebx \n\t"
			"mov   %esi, %ecx \n\t"
			"mov   $12, %edx \n\t"
			"int    $0x80 \n\t"
			"int3                           # Breakpoint. Here the \n\t"
			"                                       # program will stop and \n\t"
			"                                       # give control back to \n\t"
			"                                       # the parent \n\t"
			"forward: \n\t"
		"call   backward \n\t"
			".string \"Hello World\\n\" \n\t"

	);
}