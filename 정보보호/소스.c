#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <tchar.h>

void decipher() //��ȣȭ
{
	_wsetlocale(LC_ALL, L"korean"); // ���α׷��� ��ü ��Ķ�̸��� "korean"���� ������
	//_wsetlocale: setlocale �Լ��� ����Ͽ� locale �� category�� ���� ������ ���� ���α׷� ��Ķ ������ �Ϻ� �Ǵ� ��ü�� ����, ���� �Ǵ� �����ϴ� �Լ�
	FILE* f;
	wchar_t p[2048] = { L"" }; // ���̵� ���ڿ��� L�� ����
	// wchar_t: ���̵� ���ڸ� �����ϱ� ���� �ڷ��� (�����ڵ�� 2����Ʈ �̻����� ǥ���ϱ⶧���� wchar_t�� �����ؾߵ�)
	int i = 0, j, k = 1, count = 3, string;
	wchar_t key[5] = { L"ABCD" };

	while (k)
	{
		scanf_s("%x", &k);
		p[i] = (unsigned short)k;
		i++;
	}
	string = wcslen(p); // wchar_t ���ڿ� ó�� �Լ��� ���̸� �����ϴ� ����

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
			printf("%d��° ����: ", j + 1);
			for (k = 0; k < string; k++)
			{
				printf("%x ", p[k]);
			}
			printf("\n\n");
		}
		else
		{
			printf("��ȣȭ�� ����: ");
			wprintf(L"%ls\n", p); // ���̵� p�� ���� �����
			//wprintf: ���̵� ���ڷ� ������ ����ȭ �� ���

		}
		count--;
	}
	f = fopen("decipher.txt", "a"); //���� ������Լ�: "decipher.txt"������ ������ �ǵڿ������� �����Ͽ� ����. ���� ������ �������� �ʴ´ٸ� ���� ����
	fwprintf(f, p);
	//fwprintf: ���̵� ������ ���� ��ȯ
	fwprintf(f, L"\n");
	fclose(f); //���� ����� �Լ�: ������ ����
}
void cryptograph() //��ȣȭ
{
	_wsetlocale(LC_ALL, L"korean");// ���α׷��� ��ü ��Ķ�̸��� "korean"���� ������
	//_wsetlocale: setlocale �Լ��� ����Ͽ� locale �� category�� ���� ������ ���� ���α׷� ��Ķ ������ �Ϻ� �Ǵ� ��ü�� ����, ���� �Ǵ� �����ϴ� �Լ�
	FILE* f;
	wchar_t p[2048] = { L"" }; // ���̵� ���ڿ��� L�� ����
	// wchar_t: ���̵� ���ڸ� �����ϱ� ���� �ڷ���
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
			printf("%d��° ����: ", j + 1);
			for (k = 0; k < string; k++)
			{
				printf("%x ", p[k]);
			}
			printf("\n\n");
		}
		else
		{
			printf("��ȣȭ�� ����: ");
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
		printf("1. ��ȣȭ\n");
		printf("2. ��ȣȭ\n");
		printf("3. ���α׷� ����\n");
		printf("����� �޴��� ���ڸ� �Է����ּ���. >> ");
		scanf_s("%d", &menu);

		if (menu == 1)
		{
			printf("��ȣȭ�� ���� �Է��� �ּ���.\n");
			while (getchar() != '\n');
			cryptograph();
		}
		else if (menu == 2)
		{
			printf("��ȣȭ�� ��ȣ���� �Է��� �ּ���.\n");
			while (getchar() != '\n');
			decipher();
		}
		else if (menu == 3)
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else
			printf("�߸��� �Է��Դϴ�.\n");
	}

	system("Pause");
	return 0;
}

