#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <tchar.h>

void decipher() //복호화
{
	_wsetlocale(LC_ALL, L"korean"); // 프로그램의 전체 로캘이름을 "korean"으로 설정함
	//_wsetlocale: setlocale 함수를 사용하여 locale 및 category에 의해 지정된 현재 프로그램 로캘 정보의 일부 또는 전체를 설정, 변경 또는 쿼리하는 함수
	FILE* f;
	wchar_t p[2048] = { L"" }; // 와이드 문자열은 L을 붙임
	// wchar_t: 와이드 문자를 저장하기 위한 자료형 (유니코드는 2바이트 이상으로 표현하기때문에 wchar_t에 저장해야됨)
	int i = 0, j, k = 1, count = 3, string;
	wchar_t key[5] = { L"ABCD" };

	while (k)
	{
		scanf_s("%x", &k);
		p[i] = (unsigned short)k;
		i++;
	}
	string = wcslen(p); // wchar_t 문자열 처리 함수의 길이를 저장하는 변수

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < string; i++)
		{
			if (j < 3)
			{
				p[i] = ((p[i] << 8) & 0xff00) | (((p[i] >> 8) ^ ((p[i] ^ key[count]) & 0x00ff)) & 0x00ff);
			}
			else if (j == 3)
			{
				p[i] = ((((p[i] ^ key[count]) << 8) & 0xff00) ^ (p[i] & 0xff00)) | (p[i] & 0x00ff);
			}
		}

		if (j < 3)
		{
			printf("%d번째 라운드: ", j + 1);
			for (k = 0; k < string; k++)
			{
				printf("%x ", p[k]);
			}
			printf("\n\n");
		}
		else
		{
			printf("복호화한 문장: ");
			wprintf(L"%ls\n", p); // 와이드 p의 값을 출력함
			//wprintf: 와이드 문자로 데이터 형식화 및 출력

		}
		count--;
	}
	f = fopen("decipher.txt", "a"); //파일 입출력함수: "decipher.txt"파일의 내용을 맨뒤에서부터 편집하여 연다. 만약 파일이 존재하지 않는다면 새로 만듬
	fwprintf(f, p);
	//fwprintf: 와이드 문자의 수를 반환
	fwprintf(f, L"\n");
	fclose(f); //파일 입출력 함수: 파일을 닫음
}
void cryptograph() //암호화
{
	_wsetlocale(LC_ALL, L"korean");// 프로그램의 전체 로캘이름을 "korean"으로 설정함
	//_wsetlocale: setlocale 함수를 사용하여 locale 및 category에 의해 지정된 현재 프로그램 로캘 정보의 일부 또는 전체를 설정, 변경 또는 쿼리하는 함수
	FILE* f;
	wchar_t p[2048] = { L"" }; // 와이드 문자열은 L을 붙임
	// wchar_t: 와이드 문자를 저장하기 위한 자료형
	int i, j, k, count = 0, string;
	wchar_t key[5] = { L"ABCD" };

	_getws(p);
	string = wcslen(p);

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < string; i++)
		{
			if (j < 3)
			{
				p[i] = ((p[i] << 8) & 0xff00) | (((p[i] >> 8) ^ ((p[i] ^ key[count]) & 0x00ff)) & 0x00ff);
			}
			else if (j == 3)
			{
				p[i] = ((((p[i] ^ key[count]) << 8) & 0xff00) ^ (p[i] & 0xff00)) | (p[i] & 0x00ff);
			}
		}
		if (j < 3)
		{
			printf("%d번째 라운드: ", j + 1);
			for (k = 0; k < string; k++)
			{
				printf("%x ", p[k]);
			}
			printf("\n\n");
		}
		else
		{
			printf("암호화한 문장: ");
			for (k = 0; k < string; k++)
			{
				printf("%x ", p[k]);
			}
			printf("\n\n");
		}
		count++;
	}

	f = fopen("cryptograph.txt", "a");
	for (i = 0; i < string; i++)
		fprintf(f, "%x ", p[i]);

	fprintf(f, "0000\n");
	fclose(f);
}

int main()
{
	int menu;

	while (1)
	{
		printf("1. 암호화\n");
		printf("2. 복호화\n");
		printf("3. 프로그램 종료\n");
		printf("사용할 메뉴의 숫자를 입력해주세요. >> ");
		scanf_s("%d", &menu);

		if (menu == 1)
		{
			printf("암호화할 평문을 입력해 주세요.\n");
			while (getchar() != '\n');
			cryptograph();
		}
		else if (menu == 2)
		{
			printf("복호화할 암호문을 입력해 주세요.\n");
			while (getchar() != '\n');
			decipher();
		}
		else if (menu == 3)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else
			printf("잘못된 입력입니다.\n");
	}

	system("Pause");
	return 0;
}

