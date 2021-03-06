#include "readelf.h"

/**
 * get_symtype - retrieve a string representing symbol's type
 * @type: a numeric representation of the symbol's type
 * Return: a string representing symbol's type
 */
static char *get_symtype(unsigned char type)
{
	static char buf[16];

	switch (type)
	{
	case STT_NOTYPE:	return "NOTYPE";
	case STT_OBJECT:	return "OBJECT";
	case STT_FUNC:		return "FUNC";
	case STT_SECTION:	return "SECTION";
	case STT_FILE:		return "FILE";
	case STT_COMMON:	return "COMMON";
	case STT_TLS:		return "TLS";
	default:
		if (type >= STT_LOPROC && type <= STT_HIPROC)
			sprintf(buf, "<processor specific>: %d", type);
		return (buf);
	}
}

/**
 * get_symbind - retrieve a string representing the symbol's binding
 * @bind: a numeric representation of the symbol's bind
 * Return: a string representing the symbol's binding
 */
static char *get_symbind(unsigned char bind)
{
	static char buf[16];

	switch (bind)
	{
	case STB_LOCAL:		return "LOCAL";
	case STB_GLOBAL:	return "GLOBAL";
	case STB_WEAK:		return "WEAK";
	default:
		if (bind >= STB_LOPROC && bind <= STB_HIPROC)
			sprintf(buf, "processor specific>: %d", bind);
		return (buf);
	}
}

/**
 * get_symvis - retrieve a string representation of the symbol's visibility
 * @visibility: a numeric representation of the symbol's visibility
 * Return: a string representation of symbol's visibility
 */
static char *get_symvis(unsigned char visibility)
{
	switch (visibility)
	{
	case STV_DEFAULT:	return "DEFAULT";
	case STV_INTERNAL:	return "INTERNAL";
	case STV_HIDDEN:	return "HIDDEN";
	case STV_PROTECTED:	return "PROTECTED";
	case 4:			return "EXPORTED";
	case 5:			return "SINGLETON";
	case 6:			return "ELIMINATE";
	default:		return "<unknown>";
	}
}

/**
 * get_symndx - retrieve a string representation of the symbol's index
 * @index: a numeric representation of symbol's index
 * Return: a string representation of symbol's index
 */
static char *get_symndx(uint16_t index)
{
	static char buf[8];

	switch (index)
	{
	case SHN_UNDEF:		return "UND";
	case SHN_ABS:		return "ABS";
	case SHN_COMMON:	return "COM";
	default:
		sprintf(buf, "%3hu", index);
		return (buf);
	}
}

/**
 * print_symtable - prints the symbol table the elf file
 * @symtab: a pointer to a ElfN_Sym struct
 * @name: a pointer to a string with the section name
 * @size: the number of entries in the symbol table
 * @symstr: a pointer to a string with a string table section
 * @is_elf64: a _Bool representing the class of the elf file (32/64 bits)
 * Return: Always void.
 */
void
print_symtable(ElfN_Sym *symtab, char *name, uint16_t size, char *symstr,
	       _Bool is_elf64)
{
	uint16_t i;
	ElfN_Sym *symbol;
	char *format;

	printf("\nSymbol table '%s' contains %hu entries:\n", name, size);
	if (is_elf64)
	{
		format = "%6hu: %016lx %5lu %-7s %-6s %-8s %3s %s\n";
		printf("   Num:    Value          Size Type    Bind   Vis      Ndx Name\n");
	}
	else
	{
		format = "%6hu: %08lx %5lu %-7s %-6s %-7s  %3s %s\n";
		printf("   Num:    Value  Size Type    Bind   Vis      Ndx Name\n");
	}
	for (i = 0; i < size; i++)
	{
		symbol = (symtab + i);
		printf(format, i, symbol->st_value, symbol->st_size,
		       get_symtype(ELF_ST_TYPE(symbol->st_info)),
		       get_symbind(ELF_ST_BIND(symbol->st_info)),
		       get_symvis(symbol->st_other), get_symndx(symbol->st_shndx),
		       symstr + symbol->st_name);
	}
}
