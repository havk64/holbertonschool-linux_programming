#include "lcap.h"

static const char *cap_name[CAP_LAST_CAP + 1] = {
	"CAP_CHOWN",
	"CAP_DAC_OVERRIDE",
	"CAP_DAC_READ_SEARCH",
	"CAP_FOWNER",
	"CAP_FSETID",
	"CAP_KILL",
	"CAP_SETGID",
	"CAP_SETUID",
	"CAP_SETPCAP",
	"CAP_LINUX_IMMUTABLE",
	"CAP_NET_BIND_SERVICE",
	"CAP_NET_BROADCAST",
	"CAP_NET_ADMIN",
	"CAP_NET_RAW",
	"CAP_IPC_LOCK",
	"CAP_IPC_OWNER",
	"CAP_SYS_MODULE",
	"CAP_SYS_RAWIO",
	"CAP_SYS_CHROOT",
	"CAP_SYS_PTRACE",
	"CAP_SYS_PACCT",
	"CAP_SYS_ADMIN",
	"CAP_SYS_BOOT",
	"CAP_SYS_NICE",
	"CAP_SYS_RESOURCE",
	"CAP_SYS_TIME",
	"CAP_SYS_TTY_CONFIG",
	"CAP_MKNOD",
	"CAP_LEASE",
	"CAP_AUDIT_WRITE",
	"CAP_AUDIT_CONTROL",
	"CAP_SETFCAP",
	"CAP_MAC_OVERRIDE",
	"CAP_MAC_ADMIN",
	"CAP_SYSLOG",
	"CAP_WAKE_ALARM",
	"CAP_BLOCK_SUSPEND"
};

void
dump_it(cap_t cap)
{
	int i, j;
	cap_value_t cap_list[CAP_LAST_CAP + 1];
	cap_flag_value_t cap_flags_value;
	flags_t flags[3] = {
		{"EFFECTIVE", CAP_EFFECTIVE},
		{"PERMITTED", CAP_PERMITTED},
		{"INHERITABLE", CAP_INHERITABLE}
	};

	printf("%-20s %s\t%-10s %-10s %-10s\n", "CAPABILITY FLAG", "BIT #",
	       "EFFECTIVE", "PERMITTED", "INHERITABLE");
	for (i = 0; i < CAP_LAST_CAP + 1; i++)
	{
		cap_from_name(cap_name[i], &cap_list[i]);
		printf("%-20s %d\t\t", cap_name[i], cap_list[i]);
		printf("flags: \t\t");
		for (j = 0; j < 3; j++)
		{
			cap_get_flag(cap, cap_list[i], flags[j].flag, &cap_flags_value);
			printf(" %s %-4s ", flags[j].str,
			       (cap_flags_value == CAP_SET) ? "OK" : "NOK");
		}
		printf("\n");
	}

	cap_free(cap);
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

	dump_it(cap);
	cap_free(cap);
	return (0);
}
