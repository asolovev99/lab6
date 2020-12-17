#include<stdlib.h>
#include"string_private.h"
#include<stdio.h>

struct CustomString
{
	char* string;
};

CustomString* create(char* raw)
{
	CustomString* result = malloc(sizeof(CustomString));
	int length_of_result = 0;

	result->string = (char*)malloc(sizeof(char));
	*(result->string) = '\0';
	if (!((raw == NULL) || (*raw == '\0')))
	{
		for (length_of_result = 0; raw[length_of_result] != '\0'; length_of_result++)
		{
			result->string = (char*)realloc(result->string, sizeof(char) * (length_of_result + 2));
			result->string[length_of_result] = raw[length_of_result];
			result->string[length_of_result + 1] = '\0';

			/*printf("%d: %c\n", length_of_result, result->string[length_of_result]);*/
		}
	}

	return result;
}

int get_length(CustomString* string)
{
	int result = 0;

	if (string->string == NULL)
	{
		return 0;
	}

	while (string->string[result] != '\0')
	{
		result++;
	}

	return result;
}

int compare(CustomString* string, CustomString* right)
{
	int i = 0;

	if ((string->string == NULL) && (right->string == NULL))
	{
		return 0;
	}
	else if (string->string == NULL)
	{
		return '\0' - right->string[0];
	}
	else if (right->string == NULL)
	{
		return string->string[i] - '\0';
	}
	else
	{
		while ((string->string[i] == right->string[i]) && (string->string[i] != '\0') && (right->string[i] != '\0'))
		{
			i++;
		}

		return string->string[i] - right->string[i];
	}
}

CustomString* concat(CustomString* left, CustomString* right)
{
	int lenght_of_left = get_length(left);
	int lenght_of_right = get_length(right);
	CustomString* result = malloc(sizeof(CustomString));
	result->string = (char*)malloc(sizeof(char) * (lenght_of_left + lenght_of_right + 1));

	for (int i = 0; i < lenght_of_left; i++)
	{
		result->string[i] = left->string[i];
	}

	for (int i = lenght_of_left; i < lenght_of_left + lenght_of_right; i++)
	{
		result->string[i] = right->string[i - lenght_of_left];
	}

	result->string[lenght_of_left + lenght_of_right] = '\0';

	return result;
}

int index_of(CustomString* target, CustomString* substring)
{
	int d[256];
	int i, j, k, N, M;

	N = get_length(target);
	M = get_length(substring);
	for (i = 0; i < 256; i++)
	{
		d[i] = M; /* изначально М во всех позициях */
	}
	for (i = 0; i < M - 1; i++) /* M – i - 1 - расстояние до конца d */
	{
		d[(unsigned char)substring->string[i]] = M - i - 1;/* кроме последнего символа*/
	}
		/* поиск */
	i = M - 1;
	do 
	{
		j = M - 1; /* сравнение строки и шаблона */
		k = i; /* j – по шаблону, k – по строке */

		while ((j >= 0) && (substring->string[j] == target->string[k])) 
		{
			k--; j--;
		}

		if (j < 0) 
		{
			return k + 1; /* шаблон просмотрен полностью */
		}
		i += d[(unsigned)target->string[i]];/*сдвиг на расстояние d[s[i]]вправо*/

	} while (i < N);

	return -1;
	/*int lenght_target = get_length(target);
	int lenght_string = get_length(substring);
	int is_find = 0;
	int i = 0;
	int j = 0;

	if (substring->string == NULL)
	{
		return 0;
	}
	else
	{
		i = 0;
		while (i + lenght_string <= lenght_target)
		{
			is_find = 1;
			for (j = i; (j < i + lenght_string) && is_find; j++)
			{
				if (target->string[j] != substring->string[j - i])
				{
					is_find = 0;
				}
			}
			if (is_find) // Нашли
			{
				return i;
			}

			i++;
		}

		return -1; // Не нашли
	}*/
}



void print_CustomString(CustomString* string)
{
	printf("%s\n", string->string);
}