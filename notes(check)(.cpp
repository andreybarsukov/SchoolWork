/*
String Char

__________\0

terminated by the null character  (ascii 0)

HELLO\0

char *str = (char *)"Hello";
	
how to change H to y:	
	*str = 'y';
or 
	str[0] = 'y';       //a string is treated like an array
	
change e to 0

	str[1] = 'o';
or
	*(str + 1);
	
	
*/
