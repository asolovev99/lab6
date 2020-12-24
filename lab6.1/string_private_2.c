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
	int distance[256];
	int i, j, k, length_target, length_substring;

	length_target = get_length(target);
	length_substring = get_length(substring);
	for (i = 0; i < 256; i++)
	{
		distance[i] = length_substring;
	}
	for (i = 0; i < length_substring - 1; i++)
	{
		distance[(unsigned char)substring->string[i]] = length_substring - i - 1;
	}
		/* поиск */
	i = length_substring - 1;
	do 
	{
		j = length_substring - 1;
		k = i; 

		while ((j >= 0) && (substring->string[j] == target->string[k])) 
		{
			k--; 
			j--;
		}

		if (j < 0) 
		{
			return k + 1;
		}
		i += distance[(unsigned)target->string[i]];

	} while (i < length_target);

	return -1;
}



//void print_CustomString(CustomString* string)
//{
//	printf("%s\n", string->string);
//}