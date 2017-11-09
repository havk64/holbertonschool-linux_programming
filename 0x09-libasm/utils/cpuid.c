#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
	uint32_t eax, ebx, ecx, edx;

	/* Inline assembly to check CPU info */
	/* *cpuid* is a processor suplementary instruction for x86 architecture  */
	__asm__ __volatile__ ("cpuid\n\t"
			      : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d"(edx)
			      : "0" (0));

	/* Print hexadecimal representation of registers */
	printf("eax: %08x\n", eax);
	printf("ebx: %08x\n", ebx);
	printf("ecx: %08x\n", ecx);
	printf("edx: %08x\n", edx);

	/* Print processor info */
	printf("\nProcessor type: ");
	printf("%.4s", (char *)&ebx);
	printf("%.4s", (char *)&edx);
	printf("%.4s\n", (char *)&ecx);
	printf("Edx register as binary: ");
	fflush(stdout);
	asm_puti_base(edx, "01");
	printf("\n");
	return (0);
}
