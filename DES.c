#define _CRT_SECURE_NOT_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>


void compared(int ret);
int password(char pass0[6], char pass1[6]);
char plain(char message0[321], int message1[321], int gett); 
int returntobinary(int message1[321], int binary0[257][10]);



int main()
{
	char pass0[6];
	char pass1[6];
	int isfull=0;
	int index=0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("HELLO! I am Mari, and I am the developer of this program :)\nThis program does its best to encrypt your messages.\n");
	printf("We will now enter the world of cryptography!");
	printf("\n\n=========================================================================================");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n\n >> Please enter a 5-character password : ");
	int ret = password(pass0, pass1);
	compared(ret);

	char message0[321] = { 0, };
	int message1[321] = { 0, };
	int binary0[257][10] = { {0, }, {0, } };
	
	int gett = 0;

	plain(message0, message1, gett);
	returntobinary(message1,binary0);
}

int password(char pass0[6], char pass1[6])
{
	int i = 0;
	for (i = 0;i < 5;i++)
	{
		pass0[i] = _getch();
		printf("*");
	}
	pass0[5] = '\0';
	printf("\n >> try again!: ");

	for (i = 0;i < 5;i++)
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

char plain(char message0[321], int message1[321], int gett)
{
	printf("\n >> Now, Enter your message in 320 charactres!");
	printf("\n    If you have completed the input, please press the [ Enter key ].");
	printf("\n : ");
	int j = 0;

	while (j < 320)
	{
		gett = getchar();
		if (gett == '\n')
		{
			break;
		}
		message0[j++] = gett;
	}
	if (gett > 320)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n >> The character limit of 320 has been exceeded... The program will now terminate...");
		return 0;
	}
	message0[j] = '\0';
	printf("\n >> GOOD JOB :)\n");
	for (int k = 0; k < 320; k++)
	{
		message1[k] = message0[k];
	} // 여기서 0으로 320자 모두 채워진 message0 을 message1(char)으로 가져다 넘기기.
}

int returntobinary(int message1[321], int binary0[257][10])
{
	int binarysize = (sizeof(message1));
	
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < binarysize; i++) // 320자 중에 들어온 문자열 크기 세어서
	{
		char c = message1[i]; 
		for (int b = 7; b >= 0; b--) // binary0 배열에 2진수로 바꿔서 넣는 거
		{
			binary0[j][k] = (c >> b) & 1; // 2진수 바꾸기
			k++;
			if (k == 10) // 만약에 10번째 열까지 채워졌다면
			{
				k = 0; // 
				j++;
				if (j == 256) break; // 256번째 행에 넣고 그만 넣기
			}
		}
		
		int modbinary = (320 - binarysize);
		// 이 뒤부터 비어있는 행 0으로 채우기
		
	}	
}
