#include "ls_header.h"

/**
 * print_dir - lists a directory
 * @dir: pointer to a directory stream
 * @mode: number representing the options
 *
 * Return: Void
 */
void print_dir(DIR *dir, int mode)
{
	int count;
	struct dirent *rdir;
	char *end;

	end = (mode == 1) ? "\n" : "  ";
	count = 0;
	while ((rdir = readdir(dir)) != NULL)
	{
		if (count != 0)
			printf("%s", end);

		if (rdir->d_name[0] != '.')
		{
			printf("%s",
			       rdir->d_name);
			count++;
		}
	}
	printf("\n");
}

/**
 * list_dir - list directories
 * @list: linked list of directories to list
 * @stat: variable to check previous listing
 * @mode: number representing the options
 *
 * Return: Void
 */
void list_dir(Dlist *list, int stat, int mode)
{
	int size;
	Dlist *node;

	size = list_size(list);
	node = list;
	while (node != NULL)
	{
		if (size > 1 || stat == 1)
			printf("%s:\n", node->str);
		if (parse_dir(node->str, mode) != 0)
			printf("Ops...\n");
		if (node->next != NULL)
			printf("\n");
		node = node->next;
	}

}

/**
 * print_long - print more details about a file
 * @str: the path to file
 *
 * Return: Void
 */
void print_long(char *str)
{

	struct stat buf;
	struct passwd *uid;
	struct group *gid;
	char *path, *perm, *time;

	path = string_concat("./", str);
	if (lstat(path, &buf) < 0)
		perror("lstat error");

	uid = getpwuid(buf.st_uid);
	gid = getgrgid(buf.st_gid);
	perm = f_perm(buf.st_mode);
	time = ctime(&buf.st_mtime);
	printf("%c%s %1ld %s %s %*ld %.*s %s",
	       f_type(buf.st_mode), perm, buf.st_nlink, uid->pw_name,
	       gid->gr_name, 5, buf.st_size, 12, &time[4], str);

	free(perm);
	free(path);
}
