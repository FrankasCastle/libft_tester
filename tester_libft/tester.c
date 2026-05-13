#include <stdio.h>
#include <string.h>

int	main(void)
{
	// //teste isalpha
	// int c = 'A';
	// int c1 = '*';
	// int c2 = '4';
	// int c3 = '\0';
	// printf("%d%d", isalpha(c),ft_isalpha(c));
	// printf("%d%d",isalpha(c1), ft_isalpha(c1));
	// printf("%d%d",isalpha(c2), ft_isalpha(c2));
	// printf("%d%d",isalpha(c3), ft_isalpha(c3));

	// //teste isdigit
	// int c = '4';
	// int c1 = '2';
	// int c2 = 'b';
	// printf("%d%d", isdigit(c), ft_isdigit(c));
	// printf("%d%d", isdigit(c1), ft_isdigit(c1));
	// printf("%d%d", isdigit(c2), ft_isdigit(c2));

	// //teste isalnum
	// int c = 'A';
	// int c1 = 'b';
	// int c2 = '4';
	// int c3 = '/';
	// printf("%d%d", isalnum(c), ft_isalnum(c));
	// printf("%d%d", isalnum(c1), ft_isalnum(c1));
	// printf("%d%d", isalnum(c2), ft_isalnum(c2));
	// printf("%d%d", isalnum(c3), ft_isalnum(c3));

	// //teste isascii
	// int c = 'a';
	// int c1 = 'B';
	// int c2 = '/';
	// int c3 = 500;
	// printf("%d%d", isascii(c), ft_isascii(c));
	// printf("%d%d", isascii(c1), ft_isascii(c1));
	// printf("%d%d", isascii(c2), ft_isascii(c2));
	// printf("%d%d", isascii(c3), ft_isascii(c3));

	// //teste isprint
	// int c = 'a';
	// int c1 = 0; //'\0'
	// printf("%d%d", isprint(c), ft_isprint(c));
	// printf("%d%d", isprint(c1), ft_isprint(c1));

	// //teste strlen
	// char s[] = "Olá";
	// char *s1;

	// printf("%d%d", strlen(s), ft_strlen(s));
	// printf("%d%d", strlen(s1), ft_strlen(s1));

	// //teste memset
	// int arr[10];
	// int arr1[5];

	// memset(arr, 42, sizeof(arr));
	// //ft_memset(arr, 42, sizeof(arr));
	// memset(arr1, 42, sizeof(arr));
	// //ft_memset(arr1, 42, sizeof(arr));
	// int i = 0;
	// while(i < 10)
	// 	printf("[%d] ", arr[i++]);
	// i = 0;
	// while (i < 5)
	// 	printf("[%d] ", arr[i++]);

	// //teste bzero

	// int arr[10];
	// int arr1[5];

	// bzero(arr, sizeof(arr));
	// //ft_bzero(arr, sizeof(arr));
	// bzero(arr1, sizeof(arr));
	// //ft_bzero(arr1, sizeof(arr));
	// int i = 0;
	// while(i < 10)
	// 	printf("[%d] ", arr[i++]);
	// i = 0;
	// while (i < 5)
	// 	printf("[%d] ", arr[i++]);

	// //teste memcpy

	// char dest[10];
	// char src[] = "123456789";
	// char dest2[6];
	// char src2[] = "teste";
	// memcpy(dest, src, 9);
	// //ft_memcpy(dest, src, 9);
	// printf("%s", dest);
	// memcpy(dest2, src2, 3);
	// //ft_memcpy(dest2, src2, 3);
	// printf("%s", dest2);

	// //teste memmove

	// char dest[] = "oldstring";
   	// const char src[]  = "newstring";
   	// printf("Before = %s", dest);
  	// memmove(dest, src, 9);
  	// //ft_memmove(dest, src, 9);
   	// printf("After = %s", dest);

	// //teste strlcpy

	// char dest[50];
	// const char src[] = "string";
	// strlcpy(dest, src, 7);
	// printf("dest = %s / src = %s / return = %zu", dest, src, strlcpy(dest, src, 7));
	// // ft_strlcpy(dest, src, 7);
	// // printf("dest = %s / src = %s / return = %zu", dest, src, ft_strlcpy(dest, src, 7));

	// //teste strlcat

	// char dest[] = "string ";
	// const char src[] = "teste";
	// strlcat(dest, src, 14);
	// printf("dest = %s / src = %s / retorno = %zu", dest, src, strlcat(dest, src, 14));
	// // ft_strlcat(dest, src, 14);
	// // printf("dest = %s / src = %s / retorno = %zu", dest, src, ft_strlcat(dest, src, 14));
	
	// //teste toupper

	// char s[] = "testEEEEeee";
	// int i = 0;

	// while (s)
	// {
	// 	printf("%s", toupper(&s[i]));
	// 	//printf("%s", ft_toupper(&s[i]));
	// 	i++;
	// }

	// //teste tolower

	// char s[] = "TESTeeeeeEE";
	// int i = 0;

	// while (s)
	// {
	// 	printf("%s", tolower(&s[i]));
	// 	//printf("%s", ft_tolower(&s[i]));
	// 	i++;
	// }

	// //teste strchr

	// char s[] = "aloooeiii";
	// printf("strchr = %c / ft_strchr = %c", strchr(s, 'e'), ft_strchr(s, 'e'));

	// //teste strrchr

	// char s[] = "teste";
	// printf("strrchr = %c / ft_strrchr = %c", strrchr(s, 'e'), ft_strrchr(s, 'e'));

	// //teste strncmp

	// char s1[] = "teste1";
	// char s2[] = "teste2";

	// printf("strncmp = %d / ft_strncmp = %d", strncmp(s1, s2, 8), ft_strncmp(s1, s2, 8));

	// //teste memchr

	// const char str[] = "te.ste";
	// const char ch[] = ".";

	// printf("memchr = %d / ft_memchr = %d", memchr(str, ch, strlen(str)), ft_memchr(str, ch, strlen(str)));

	// //teste memcmp

	// char s1[] = "teste";
	// char s2[] = "testa";

	// printf("memcmp = %d / ft_memcmp = %d", memcmp(s1, s2, 6), ft_memcmp(s1, s2, 6));

	// //teste strnstr

	// const char *s1 = "ola 42";
	// const char *s2 = "42";

	// printf("strnstr = %s / ft_strnstr = %s", strnstr(s1, s2, 7), ft_strnstr(s1, s2, 7));

	// //teste atoi

	// const char *s1 = "+2145abc451";

	// printf("atoi = %d / ft_atoi = %d", atoi(s1), ft_atoi(s1));

	return (0);
} 