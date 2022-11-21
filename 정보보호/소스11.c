//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <time.h>
//#include <locale.h>
//#include <tchar.h>
//
//void decipher()
//{
//	_wsetlocale(LC_ALL, L"korean");
//	FILE* f;
//	wchar_t p[2048] = { L"" };
//	int i = 0, j, k = 1, count = 3, string;
//	wchar_t key[5] = { L"ABCD" };
//
//	while (k)
//	{
//		scanf("%x", &k);
//		p[i] = (unsigned short)k;
//		i++;
//	}
//	string = wcslen(p);
//
//	for (j = 0; j < 4; j++)
//	{
//		for (i = 0; i < string; i++)
//		{
//			if (j < 3)
//			{
//				p[i] = ((p[i] << 8) & 0xff00) | (((p[i] >> 8) ^ ((p[i] ^ key[count]) & 0x00ff)) & 0x00ff);
//			}
//			else if (j == 3)
//			{
//				p[i] = ((((p[i] ^ key[count]) << 8) & 0xff00) ^ (p[i] & 0xff00)) | (p[i] & 0x00ff);
//			}
//		}
//		if (j < 3)
//		{
//			printf("%d번째 라운드: ", j + 1);
//			for (k = 0; k < string; k++)
//			{
//				printf("%x ", p[k]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("복호화한 문장: ");
//			wprintf(L"%ls\n", p);
//		}
//		count--;
//	}
//	f = fopen("decipher.txt", "a");
//	fwprintf(f, p);
//	fwprintf(f, L"\n");
//	fclose(f);
//}
//void cryptograph()
//{
//	_wsetlocale(LC_ALL, L"korean");
//	FILE* f;
//	wchar_t p[2048] = { L"" };
//	int i, j, k, count = 0, string;
//	wchar_t key[5] = { L"ABCD" };
//
//	_getws(p);
//	string = wcslen(p);
//
//	for (j = 0; j < 4; j++)
//	{
//		for (i = 0; i < string; i++)
//		{
//			if (j < 3)
//			{
//				p[i] = ((p[i] << 8) & 0xff00) | (((p[i] >> 8) ^ ((p[i] ^ key[count]) & 0x00ff)) & 0x00ff);
//			}
//			else if (j == 3)
//			{
//				p[i] = ((((p[i] ^ key[count]) << 8) & 0xff00) ^ (p[i] & 0xff00)) | (p[i] & 0x00ff);
//			}
//		}
//		if (j < 3)
//		{
//			printf("%d번째 라운드: ", j + 1);
//			for (k = 0; k < string; k++)
//			{
//				printf("%x ", p[k]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("암호화한 문장: ");
//			for (k = 0; k < string; k++)
//			{
//				printf("%x ", p[k]);
//			}
//			printf("\n");
//		}
//		count++;
//	}
//
//	f = fopen("cryptograph.txt", "a");
//	for (i = 0; i < string; i++)
//		fprintf(f, "%x ", p[i]);
//
//	fprintf(f, "0000\n");
//	fclose(f);
//}
//
//int main()
//{
//	int menu;
//
//	while (1)
//	{
//		printf("1. 암호화\n");
//		printf("2. 복호화\n");
//		printf("3. 프로그램 종료\n");
//		printf("사용할 메뉴의 숫자를 입력해주세요. >> ");
//		scanf("%d", &menu);
//
//		if (menu == 1)
//		{
//			printf("암호화할 평문을 입력해 주세요.\n");
//			while (getchar() != '\n');
//			cryptograph();
//		}
//		else if (menu == 2)
//		{
//			printf("복호화할 암호문을 입력해 주세요.\n");
//			while (getchar() != '\n');
//			decipher();
//		}
//		else if (menu == 3)
//		{
//			printf("프로그램을 종료합니다.\n");
//			break;
//		}
//		else
//			printf("잘못된 입력입니다.\n");
//	}
//
//	system("Pause");
//	return 0;
//}