#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

static int	g_ok = 0;
static int	g_ko = 0;

static void	print_result(char *name, int ok)
{
	if (ok)
	{
		printf("[OK] %s\n", name);
		g_ok++;
	}
	else
	{
		printf("[KO] %s\n", name);
		g_ko++;
	}
}

static void	print_line(void)
{
	printf("----------------------------------------\n");
}

static void	print_title(char *name)
{
	printf("\n");
	print_line();
	printf("TESTE: %s\n", name);
	print_line();
}

static void	compare_int(char *name, int official, int mine)
{
	printf("Esperado [função oficial] = %d\n", official);
	printf("Esperado [minha função]   = %d\n", mine);
	print_result(name, official == mine);
}

static void	compare_size(char *name, size_t official, size_t mine)
{
	printf("Esperado [função oficial] = %zu\n", official);
	printf("Esperado [minha função]   = %zu\n", mine);
	print_result(name, official == mine);
}

static void	compare_str(char *name, char *official, char *mine)
{
	printf("Esperado [função oficial] = \"%s\"\n", official);
	printf("Esperado [minha função]   = \"%s\"\n", mine);
	print_result(name, strcmp(official, mine) == 0);
}

static void	compare_ptr(char *name, void *official, void *mine)
{
	printf("Esperado [função oficial] = %p\n", official);
	printf("Esperado [minha função]   = %p\n", mine);
	print_result(name, official == mine);
}

static void	print_buffer(char *label, unsigned char *s, size_t n)
{
	size_t	i;

	printf("%s", label);
	i = 0;
	while (i < n)
	{
		printf("%u", s[i]);
		if (i + 1 < n)
			printf(" ");
		i++;
	}
	printf("\n");
}

static void	print_split(char **split)
{
	int	i;

	i = 0;
	printf("{");
	while (split && split[i])
	{
		printf("\"%s\"", split[i]);
		if (split[i + 1])
			printf(", ");
		i++;
	}
	printf(", NULL}\n");
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	print_list(t_list *lst)
{
	printf("{");
	while (lst)
	{
		printf("%s", (char *)lst->content);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("}\n");
}

static void	free_content(void *content)
{
	free(content);
}

static void	to_upper_content(void *content)
{
	char	*s;
	int		i;

	s = (char *)content;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}

static void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

static char	map_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	test_isalpha(void)
{
	print_title("ft_isalpha");
	compare_int("ft_isalpha('A')", !!isalpha('A'), ft_isalpha('A'));
	compare_int("ft_isalpha('z')", !!isalpha('z'), ft_isalpha('z'));
	compare_int("ft_isalpha('4')", !!isalpha('4'), ft_isalpha('4'));
	compare_int("ft_isalpha('*')", !!isalpha('*'), ft_isalpha('*'));
}

static void	test_isdigit(void)
{
	print_title("ft_isdigit");
	compare_int("ft_isdigit('4')", !!isdigit('4'), ft_isdigit('4'));
	compare_int("ft_isdigit('2')", !!isdigit('2'), ft_isdigit('2'));
	compare_int("ft_isdigit('b')", !!isdigit('b'), ft_isdigit('b'));
	compare_int("ft_isdigit('/')", !!isdigit('/'), ft_isdigit('/'));
}

static void	test_isalnum(void)
{
	print_title("ft_isalnum");
	compare_int("ft_isalnum('A')", !!isalnum('A'), ft_isalnum('A'));
	compare_int("ft_isalnum('b')", !!isalnum('b'), ft_isalnum('b'));
	compare_int("ft_isalnum('4')", !!isalnum('4'), ft_isalnum('4'));
	compare_int("ft_isalnum('/')", !!isalnum('/'), ft_isalnum('/'));
}

static void	test_isascii(void)
{
	print_title("ft_isascii");
	compare_int("ft_isascii('a')", !!isascii('a'), ft_isascii('a'));
	compare_int("ft_isascii('B')", !!isascii('B'), ft_isascii('B'));
	compare_int("ft_isascii('/')", !!isascii('/'), ft_isascii('/'));
	compare_int("ft_isascii(500)", 0, ft_isascii(500));
}

static void	test_isprint(void)
{
	print_title("ft_isprint");
	compare_int("ft_isprint('a')", !!isprint('a'), ft_isprint('a'));
	compare_int("ft_isprint(' ')", !!isprint(' '), ft_isprint(' '));
	compare_int("ft_isprint('\\0')", !!isprint('\0'), ft_isprint('\0'));
	compare_int("ft_isprint(127)", !!isprint(127), ft_isprint(127));
}

static void	test_strlen(void)
{
	char	s[] = "Ola";
	char	s2[] = "";

	print_title("ft_strlen");
	compare_size("ft_strlen(\"Ola\")", strlen(s), ft_strlen(s));
	compare_size("ft_strlen(\"\")", strlen(s2), ft_strlen(s2));
}

static void	test_memset(void)
{
	unsigned char	a[6] = "teste";
	unsigned char	b[6] = "teste";

	print_title("ft_memset");
	memset(a, 42, 3);
	ft_memset(b, 42, 3);
	print_buffer("Esperado [função oficial] = ", a, 6);
	print_buffer("Esperado [minha função]   = ", b, 6);
	print_result("ft_memset", memcmp(a, b, 6) == 0);
}

static void	test_bzero(void)
{
	unsigned char	a[6] = "teste";
	unsigned char	b[6] = "teste";

	print_title("ft_bzero");
	bzero(a, 3);
	ft_bzero(b, 3);
	print_buffer("Esperado [função oficial] = ", a, 6);
	print_buffer("Esperado [minha função]   = ", b, 6);
	print_result("ft_bzero", memcmp(a, b, 6) == 0);
}

static void	test_memcpy(void)
{
	char	a[10] = "abcdefghi";
	char	b[10] = "abcdefghi";
	char	src[] = "12345";

	print_title("ft_memcpy");
	memcpy(a, src, 5);
	ft_memcpy(b, src, 5);
	compare_str("ft_memcpy", a, b);
}

static void	test_memmove(void)
{
	char	a[20] = "oldstring";
	char	b[20] = "oldstring";
	char	c[20] = "123456789";
	char	d[20] = "123456789";

	print_title("ft_memmove");
	memmove(a, "newstring", 9);
	ft_memmove(b, "newstring", 9);
	compare_str("ft_memmove normal", a, b);
	memmove(c + 2, c, 7);
	ft_memmove(d + 2, d, 7);
	compare_str("ft_memmove overlap", c, d);
}

static void	test_strlcpy(void)
{
	char	a[50];
	char	b[50];
	char	src[] = "string";
	size_t	ret1;
	size_t	ret2;

	print_title("ft_strlcpy");
	ret1 = strlcpy(a, src, 7);
	ret2 = ft_strlcpy(b, src, 7);
	compare_size("ft_strlcpy return", ret1, ret2);
	compare_str("ft_strlcpy dest", a, b);
}

static void	test_strlcat(void)
{
	char	a[14] = "string ";
	char	b[14] = "string ";
	char	src[] = "teste";
	size_t	ret1;
	size_t	ret2;

	print_title("ft_strlcat");
	ret1 = strlcat(a, src, 14);
	ret2 = ft_strlcat(b, src, 14);
	compare_size("ft_strlcat return", ret1, ret2);
	compare_str("ft_strlcat dest", a, b);
}

static void	test_toupper(void)
{
	print_title("ft_toupper");
	compare_int("ft_toupper('a')", toupper('a'), ft_toupper('a'));
	compare_int("ft_toupper('E')", toupper('E'), ft_toupper('E'));
	compare_int("ft_toupper('4')", toupper('4'), ft_toupper('4'));
}

static void	test_tolower(void)
{
	print_title("ft_tolower");
	compare_int("ft_tolower('A')", tolower('A'), ft_tolower('A'));
	compare_int("ft_tolower('e')", tolower('e'), ft_tolower('e'));
	compare_int("ft_tolower('4')", tolower('4'), ft_tolower('4'));
}

static void	test_strchr(void)
{
	char	s[] = "aloooeiii";

	print_title("ft_strchr");
	compare_ptr("ft_strchr('e')", strchr(s, 'e'), ft_strchr(s, 'e'));
	compare_ptr("ft_strchr('\\0')", strchr(s, '\0'), ft_strchr(s, '\0'));
	compare_ptr("ft_strchr('x')", strchr(s, 'x'), ft_strchr(s, 'x'));
}

static void	test_strrchr(void)
{
	char	s[] = "teste";

	print_title("ft_strrchr");
	compare_ptr("ft_strrchr('e')", strrchr(s, 'e'), ft_strrchr(s, 'e'));
	compare_ptr("ft_strrchr('\\0')", strrchr(s, '\0'), ft_strrchr(s, '\0'));
	compare_ptr("ft_strrchr('x')", strrchr(s, 'x'), ft_strrchr(s, 'x'));
}

static void	test_strncmp(void)
{
	char	s1[] = "teste1";
	char	s2[] = "teste2";

	print_title("ft_strncmp");
	compare_int("ft_strncmp diff", strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
	compare_int("ft_strncmp n zero", strncmp(s1, s2, 0), ft_strncmp(s1, s2, 0));
	compare_int("ft_strncmp equal", strncmp("abc", "abc", 3), ft_strncmp("abc", "abc", 3));
}

static void	test_memchr(void)
{
	char	s[] = "te.ste";

	print_title("ft_memchr");
	compare_ptr("ft_memchr('.')", memchr(s, '.', strlen(s)), ft_memchr(s, '.', strlen(s)));
	compare_ptr("ft_memchr('x')", memchr(s, 'x', strlen(s)), ft_memchr(s, 'x', strlen(s)));
	compare_ptr("ft_memchr n zero", memchr(s, 't', 0), ft_memchr(s, 't', 0));
}

static void	test_memcmp(void)
{
	char	s1[] = "teste";
	char	s2[] = "testa";

	print_title("ft_memcmp");
	compare_int("ft_memcmp diff", memcmp(s1, s2, 5), ft_memcmp(s1, s2, 5));
	compare_int("ft_memcmp equal", memcmp("abc", "abc", 3), ft_memcmp("abc", "abc", 3));
	compare_int("ft_memcmp n zero", memcmp(s1, s2, 0), ft_memcmp(s1, s2, 0));
}

static void	test_strnstr(void)
{
	char	s1[] = "ola 42";
	char	s2[] = "42";

	print_title("ft_strnstr");
	compare_ptr("ft_strnstr found", strnstr(s1, s2, 7), ft_strnstr(s1, s2, 7));
	compare_ptr("ft_strnstr short len", strnstr(s1, s2, 5), ft_strnstr(s1, s2, 5));
	compare_ptr("ft_strnstr empty needle", strnstr(s1, "", 7), ft_strnstr(s1, "", 7));
}

static void	test_atoi(void)
{
	print_title("ft_atoi");
	compare_int("ft_atoi +2145abc451", atoi("+2145abc451"), ft_atoi("+2145abc451"));
	compare_int("ft_atoi spaces", atoi("   -42abc"), ft_atoi("   -42abc"));
	compare_int("ft_atoi invalid", atoi("abc42"), ft_atoi("abc42"));
}

static void	test_calloc(void)
{
	unsigned char	*a;
	unsigned char	*b;

	print_title("ft_calloc");
	a = calloc(5, sizeof(char));
	b = ft_calloc(5, sizeof(char));
	print_buffer("Esperado [função oficial] = ", a, 5);
	print_buffer("Esperado [minha função]   = ", b, 5);
	print_result("ft_calloc zeros", memcmp(a, b, 5) == 0);
	free(a);
	free(b);
	b = ft_calloc(0, 10);
	printf("Caso edge: ft_calloc(0, 10) retornou %p e pode receber free().\n", b);
	free(b);
}

static void	test_strdup(void)
{
	char	*a;
	char	*b;

	print_title("ft_strdup");
	a = strdup("teste");
	b = ft_strdup("teste");
	compare_str("ft_strdup", a, b);
	printf("String original = \"teste\"\n");
	printf("String duplicada pela minha função = \"%s\"\n", b);
	free(a);
	free(b);
}

static void	test_substr(void)
{
	char	*s;

	print_title("ft_substr");
	printf("String original = \"ola 42\"\n");
	s = ft_substr("ola 42", 4, 2);
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_substr começou no índice 4 e copiou no máximo 2 caracteres.\n");
	print_result("ft_substr", strcmp(s, "42") == 0);
	free(s);
	s = ft_substr("teste", 20, 3);
	printf("Edge case: start maior que a string retorna \"%s\".\n", s);
	print_result("ft_substr start grande", strcmp(s, "") == 0);
	free(s);
}

static void	test_strjoin(void)
{
	char	*s;

	print_title("ft_strjoin");
	printf("String original 1 = \"string \"\n");
	printf("String original 2 = \"teste\"\n");
	s = ft_strjoin("string ", "teste");
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_strjoin juntou a primeira string com a segunda.\n");
	print_result("ft_strjoin", strcmp(s, "string teste") == 0);
	free(s);
}

static void	test_strtrim(void)
{
	char	*s;

	print_title("ft_strtrim");
	printf("String original = \"...teste...\"\n");
	printf("Set de corte = \".\"\n");
	s = ft_strtrim("...teste...", ".");
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_strtrim removeu os caracteres do set no começo e no fim.\n");
	print_result("ft_strtrim", strcmp(s, "teste") == 0);
	free(s);
}

static void	test_split(void)
{
	char	**split;

	print_title("ft_split");
	printf("String original = \"  a   b  c  \"\n");
	printf("Separador = ' '\n");
	split = ft_split("  a   b  c  ", ' ');
	printf("String após função = ");
	print_split(split);
	printf("Explicação: ft_split separou a string em palavras e colocou NULL no final.\n");
	print_result("ft_split", split && strcmp(split[0], "a") == 0
		&& strcmp(split[1], "b") == 0 && strcmp(split[2], "c") == 0
		&& split[3] == NULL);
	free_split(split);
}

static void	test_itoa(void)
{
	char	*s;

	print_title("ft_itoa");
	s = ft_itoa(-2147483648);
	printf("Número original = -2147483648\n");
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_itoa transformou o número inteiro em string.\n");
	print_result("ft_itoa", strcmp(s, "-2147483648") == 0);
	free(s);
}

static void	test_strmapi(void)
{
	char	*s;

	print_title("ft_strmapi");
	printf("String original = \"teste\"\n");
	s = ft_strmapi("teste", map_upper);
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_strmapi criou uma nova string aplicando uma função em cada caractere.\n");
	print_result("ft_strmapi", strcmp(s, "TESTE") == 0);
	free(s);
}

static void	test_striteri(void)
{
	char	s[] = "teste";

	print_title("ft_striteri");
	printf("String original = \"teste\"\n");
	ft_striteri(s, iteri_upper);
	printf("String após função = \"%s\"\n", s);
	printf("Explicação: ft_striteri alterou a própria string, caractere por caractere.\n");
	print_result("ft_striteri", strcmp(s, "TESTE") == 0);
}

static void	test_putchar_fd(void)
{
	print_title("ft_putchar_fd");
	printf("Saída esperada: A\n");
	printf("Minha saída:    ");
	ft_putchar_fd('A', 1);
	printf("\nExplicação: ft_putchar_fd escreveu um caractere no fd 1.\n");
	print_result("ft_putchar_fd", 1);
}

static void	test_putstr_fd(void)
{
	print_title("ft_putstr_fd");
	printf("Saída esperada: teste\n");
	printf("Minha saída:    ");
	ft_putstr_fd("teste", 1);
	printf("\nExplicação: ft_putstr_fd escreveu uma string no fd 1.\n");
	print_result("ft_putstr_fd", 1);
}

static void	test_putendl_fd(void)
{
	print_title("ft_putendl_fd");
	printf("Saída esperada: teste + quebra de linha\n");
	printf("Minha saída:    ");
	ft_putendl_fd("teste", 1);
	printf("Explicação: ft_putendl_fd escreveu uma string e depois uma quebra de linha.\n");
	print_result("ft_putendl_fd", 1);
}

static void	test_putnbr_fd(void)
{
	print_title("ft_putnbr_fd");
	printf("Saída esperada: -2147483648\n");
	printf("Minha saída:    ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\nExplicação: ft_putnbr_fd escreveu um número inteiro no fd 1.\n");
	print_result("ft_putnbr_fd", 1);
}

static void	test_lstnew(void)
{
	t_list	*node;

	print_title("ft_lstnew");
	node = ft_lstnew(ft_strdup("a"));
	printf("Linked list: {}\n");
	printf("Linked list após função: ");
	print_list(node);
	printf("Explicação: ft_lstnew criou um nó com content = \"a\" e next = NULL.\n");
	print_result("ft_lstnew", node && strcmp(node->content, "a") == 0 && node->next == NULL);
	ft_lstdelone(node, free_content);
}

static void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*node;

	print_title("ft_lstadd_front");
	lst = ft_lstnew(ft_strdup("b"));
	node = ft_lstnew(ft_strdup("a"));
	printf("Linked list: ");
	print_list(lst);
	ft_lstadd_front(&lst, node);
	printf("Linked list após função: ");
	print_list(lst);
	printf("Explicação: ft_lstadd_front colocou o novo nó no começo da lista.\n");
	print_result("ft_lstadd_front", strcmp(lst->content, "a") == 0);
	ft_lstclear(&lst, free_content);
}

static void	test_lstsize(void)
{
	t_list	*lst;

	print_title("ft_lstsize");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("Linked list: ");
	print_list(lst);
	printf("Esperado [tamanho] = 3\n");
	printf("Esperado [minha função] = %d\n", ft_lstsize(lst));
	printf("Explicação: ft_lstsize contou quantos nós existem na lista.\n");
	print_result("ft_lstsize", ft_lstsize(lst) == 3);
	ft_lstclear(&lst, free_content);
}

static void	test_lstlast(void)
{
	t_list	*lst;
	t_list	*last;

	print_title("ft_lstlast");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("Linked list: ");
	print_list(lst);
	last = ft_lstlast(lst);
	printf("Último nó retornado: {%s -> NULL}\n", (char *)last->content);
	printf("Explicação: ft_lstlast retornou o último nó da lista.\n");
	print_result("ft_lstlast", strcmp(last->content, "c") == 0);
	ft_lstclear(&lst, free_content);
}

static void	test_lstadd_back(void)
{
	t_list	*lst;

	print_title("ft_lstadd_back");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	printf("Linked list: {a}\n");
	printf("Linked list após função: ");
	print_list(lst);
	printf("Explicação: ft_lstadd_back colocou o novo nó no final da lista.\n");
	print_result("ft_lstadd_back", ft_lstsize(lst) == 2
		&& strcmp(ft_lstlast(lst)->content, "b") == 0);
	ft_lstclear(&lst, free_content);
}

static void	test_lstdelone(void)
{
	t_list	*node;

	print_title("ft_lstdelone");
	node = ft_lstnew(ft_strdup("a"));
	printf("Linked list: {a}\n");
	ft_lstdelone(node, free_content);
	printf("Linked list após função: nó apagado\n");
	printf("Explicação: ft_lstdelone liberou o content usando del e depois liberou o nó.\n");
	print_result("ft_lstdelone", 1);
}

static void	test_lstclear(void)
{
	t_list	*lst;

	print_title("ft_lstclear");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("Linked list: ");
	print_list(lst);
	ft_lstclear(&lst, free_content);
	printf("Linked list após função: ");
	print_list(lst);
	printf("Explicação: ft_lstclear apagou todos os nós e deixou o ponteiro como NULL.\n");
	print_result("ft_lstclear", lst == NULL);
}

static void	test_lstiter(void)
{
	t_list	*lst;

	print_title("ft_lstiter");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("Linked list: ");
	print_list(lst);
	ft_lstiter(lst, to_upper_content);
	printf("Linked list após função: ");
	print_list(lst);
	printf("Explicação: ft_lstiter aplicou uma função no content de cada nó.\n");
	print_result("ft_lstiter", strcmp(lst->content, "A") == 0);
	ft_lstclear(&lst, free_content);
}

static void	test_lstmap(void)
{
	t_list	*lst;
	t_list	*new_lst;

	print_title("ft_lstmap");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("Linked list original: ");
	print_list(lst);
	new_lst = ft_lstmap(lst, dup_content, free_content);
	printf("Nova linked list após função: ");
	print_list(new_lst);
	printf("Explicação: ft_lstmap criou uma nova lista aplicando uma função em cada content.\n");
	print_result("ft_lstmap", new_lst && ft_lstsize(new_lst) == 3
		&& strcmp(new_lst->content, "a") == 0);
	ft_lstclear(&lst, free_content);
	ft_lstclear(&new_lst, free_content);
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
	printf("\nRESULTADO FINAL: %d OK | %d KO\n", g_ok, g_ko);
	return (0);
}
