#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
	uint64_t rax, rbx, rcx, rdx;

	/* Inline assembly to check CPU info */
	/* *cpuid* is a processor suplementary instruction for x86 architecture  */
	__asm__ __volatile__ ("cpuid\n\t"
			      : "=a" (rax), "=b" (rbx), "=c" (rcx), "=d"(rdx)
			      : "0" (0));

	/* Print hexadecimal representation of registers */
	printf("rax: %08lx\n", rax);
	printf("rbx: %08lx\n", rbx);
	printf("rcx: %08lx\n", rcx);
	printf("rdx: %08lx\n", rdx);

	/* Print processor info */
	printf("\nProcessor type: ");
	printf("%s", (char *)&rbx);
	printf("%s", (char *)&rdx);
	printf("%s\n", (char *)&rcx);
	printf("Edx register as binary: ");
	fflush(stdout);
	asm_puti_base(rdx, "01");
	printf("\n");
	return (0);
}
