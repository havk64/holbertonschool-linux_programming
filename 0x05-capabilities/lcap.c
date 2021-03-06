#include "lcap.h"

void
print_capabilities(cap_t cap)
{
	int i, j;
	cap_flag_value_t cap_flags_value;
	char *cap_str;

	printf("%-20s %s\t%-10s %-10s %-10s\n", "CAPABILITY FLAG", "BIT #",
	       "EFFECTIVE", "PERMITTED", "INHERITABLE");
	for (i = 0; i < CAP_LAST_CAP + 1; i++)
	{
		cap_str = cap_to_name(i);
		printf("%-20s %d\t\t", cap_str, i);
		for (j = 0; j < 3; j++)
		{
			cap_get_flag(cap, i, j, &cap_flags_value);
			printf("%-10s ", (cap_flags_value == CAP_SET) ? "OK" : "-");
		}
		printf("\n");
		cap_free(cap_str);
	}
}

int main(void)
{
	cap_t cap;
	cap_value_t cap_list[1];

	cap = cap_get_proc();
	if (cap == NULL)
	{
		perror("cap_get_pid");
		exit(-1);
	}
	/* Effetive Cap */
	cap_list[0] = CAP_CHOWN;
	if (cap_set_flag(cap, CAP_EFFECTIVE, 1, cap_list, CAP_SET) == -1)
	{
		perror("cap_set_flag cap_chown");
		cap_free(cap);
		exit(-1);
	}
	/* Permitted Cap */
	cap_list[0] = CAP_MAC_ADMIN;
	if (cap_set_flag(cap, CAP_PERMITTED, 1, cap_list, CAP_SET) == -1)
	{
		perror("cap_set_flag cap_mac_admin");
		cap_free(cap);
		exit(-1);
	}
	/* Inherit Cap */
	cap_list[0] = CAP_SETFCAP;
	if (cap_set_flag(cap, CAP_INHERITABLE, 1, cap_list, CAP_SET) == -1)
	{
		perror("cap_set_flag cap_setfcap");
		cap_free(cap);
		exit(-1);
	}

	print_capabilities(cap);
	cap_free(cap);
	return (0);
}
