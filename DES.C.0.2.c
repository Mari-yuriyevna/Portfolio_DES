#define _CRT_SECURE_NOT_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>


void compared(int ret);
int password(char pass0[6], char pass1[6]);
char plain(char message0[321], int message1[1284], int gett);

int main()
{
	char pass0[6];
	char pass1[6];
	int isfull = 0;
	int index = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("HELLO! I am Mari, and I am the developer of this program :)\nThis program does its best to encrypt your messages.\n");
	printf("We will now enter the world of cryptography!");
	printf("\n\n=========================================================================================");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n\n >> Please enter a 5-character password : ");
	int ret = password(pass0, pass1);
	compared(ret);

	char message0[321] = { 0, };
	int message1[1284] = { 0, };
	int binary0[257][10] = { {0, }, {0, } };

	char gett = 0;

	plain(message0, message1, gett);
}

int password(char pass0[6], char pass1[6])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		pass0[i] = _getch();
		printf("*");
	}
	pass0[5] = '\0';
	printf("\n >> try again!: ");

	for (i = 0; i < 5; i++)
	{
		pass1[i] = _getch();
		printf("*");
	}
	pass1[5] = '\0';
	printf("\n");
	return strcmp(pass0, pass1);

}

void compared(int ret)
{
	if (ret == 0)
	{
		printf("");
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n=========================================================================================");
		printf("\n...Who are you?");
		exit(0);
	}
}

char plain(char message0[321], int message1[1284], char gett)
{
	printf("\n >> Now, Enter your message in 320 charactres!");
	printf("\n    If you have completed the input, please press the [ Enter key ].");
	printf("\n : ");
	int j = 0;
	int gettt = 0;
	int k = 0;

	gett = getchar();
	if (gett == '\n')
	{
		if (gett <= 320)
		{
			for (int l = 0; l < gett; l++)
			{
				message0[l++] = gett;
				for (int i = 320; i < 320 - gett; i--)
				{
					message0[i] = 0;
				}
			}
		}
		else 
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n >> The character limit of 320 has been exceeded... The program will now terminate...");

			return 0;
		}
	} 
	for (int o = 0; o < 1284; o++)
	{
		memcpy(message1, message0, sizeof(message0));
	}

	printf("\n >> GOOD JOB :)\n");
}
