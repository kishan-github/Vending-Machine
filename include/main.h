#define INFO 1
#define ERR 2

#define PRINT(type, msg, ...)	\
		char *str;	\
		if(type == INFO)	\
			str = "INFO";	\
		if(type == ERR)	\
			str = "ERROR";	\
		printf("\n%s : %s : %s : %d : "msg"\n", str, __FILE__, __func__, __LINE__, ##__VA_ARGS__);\


