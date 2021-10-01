#include <iostream>
#include <string>
#include <Windows.h>



char Alphabet[] { ' ', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                       '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
					   '�', '�', '�', '�', '�', '�', '�', '�', '�' };

std::string Code(char* s, int n, const int SIZE)
{
	std::cout << sizeof(s)<< std::endl;
	std::string res;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < sizeof(Alphabet); j++)
			if (s[i] == Alphabet[j])
			{ 
				int shift = j + n;
				if (shift >= 33){ shift -= 34; }
				res += Alphabet[shift]; 
			}
	return res + "\0";
}

std::string DeCode(char* s, int n, const int SIZE)
{
	std::string res;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < sizeof(Alphabet); j++)
			if (s[i] == Alphabet[j])
			{
				int shift = j - n;
				if (shift < 0){ shift = 34 + shift; }
				res += Alphabet[shift];
			}
	return res + "\0";
}

int main()
{
	const int SIZE = 300;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "������ �����������: " << std::endl;
	char s[SIZE];
	std::cin.getline(s, SIZE);
	std::cout << "������ ����: ";
	int n;
	std::cin >> n;

	
	std::cout << "�� ������ ����������� �� �����������?\n1 - �����������\n2 - �����������" << std::endl;
	int c;
	std::cin >> c;
	switch (c)
	{
	case 1:
		std::cout << "����������� �����������: " << std::endl << Code(s, n, SIZE);
		break;
	case 2:
		std::cout << "������������ �����������: " << std::endl << DeCode(s, n, SIZE) << std::endl;
		break;
	}

	
	system("pause");
	return 0;
}