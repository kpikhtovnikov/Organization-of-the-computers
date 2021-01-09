#include<iostream>
#include <string>
#include <conio.h>
#include "windows.h"
#include <iomanip> 
#include <stack>
#include<math.h>
#include<vector>
#include<stack>
#include<deque>
#include <algorithm>
#include <bitset>
#include <map>
#include<cstdlib>
#include<ctime>
#include<utility>

using namespace std;
const int down = 80, up = 72, _enter = 13, _esc = 27, _backspace = 8,_space=32,_left=75,_right=77,_tab=9;
int color_bit_one = 3, color_bit_two = 10, color_for_graphic = 3;
map <string, int> alphabet = { {"0",0 },{"1", 1},{"2", 2},{"3", 3},{"4", 4},{"5", 5},{"6", 6},{"7", 7},{"8", 8},{"9", 9},{"A", 10},{"B", 11},{"C", 12},{"D", 13},{"E", 14},
	   {"F", 15},{"G", 16},{"H", 17},{"I", 18},{"J", 19},{"K", 20},{"L", 21},{"M", 22},{"N", 23},{"O", 24},{"P", 25},{"Q", 26},{"R", 27},{"S", 28},{"T", 29},{"U", 30},
	   {"V", 31},{"W", 32},{"X", 33},{"Y", 34},{"Z", 35},{"a", 36},{"b",37},{"c",38},{"d",39},{"e",40},{"f",41},{"g",42},{"h",43},{"i",44},{"j",45},{"k",46},{"l",47},{"m",48},{"n",49},
   {"o",50},{"p",51},{"q",52},{"r",53},{"s",54},{"t",55},{"u",56},{"v",57},{"w",58},{"x",59},{"y",60},{"z",61},{"�",62},{"�",63},{"�",64},{"�",65},{"�",66},{"�",67},{"�",68},{"�",69},{"�",70},{"�",71},
	   {"�",72},{"�",73},{"�",74},{"�",75},{"�",76},{"�",77},{"�",78},{"�",79},{"�",80},{"�",81},{"�",82},{"�",83},{"�",84},{"�",85},{"�",86},{"�",87},{"�",88},{"�",89},{"�",90},{"�",91},{"�",92},{"�",93},{"�",94},{"�",95},{"�",96},{"�",97},{"�",98},
	   {"�",99},{"�",100},{"�",101},{"�",102},{"�",103},{"�",104},{"�",105},{"�",106},{"�",107},{"�",108},{"�",109},{"�",110},{"�",111},{"�",112},{"�",113},{"�",114},{"�",115},{"�",116},{"�",117},{"�",118},{"�",119},{"�",120},{"�",121},{"�",122},
	   {"�",123},{"�",124},{"�",125},{"�",126},{"�",127} };
void gotoxy(int x, int y)//��������� ������� �� ������� x y 
{
	COORD coord;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void clear_screen(int x1, int x2, int y1, int y2) {
	for (int i = y1; i <= y2; ++i)
		for (int j = x1; j <= x2; ++j)
		{
			gotoxy(j, i);
			cout << ' ';
		}
}
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(int text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 0) | text));
}

ConsoleColor getColor()
{
	int key = 0;
	int x = 30, y = 3;
	//system("cls");
	gotoxy(0, 1);
	cout << endl << "�������� ���� �� 1 �� 12";
	SetColor(Blue, Black);
	cout <<endl<< "1.Blue" << endl;
	SetColor(Green, Black);
	cout << "2.Green" << endl;
	SetColor(Cyan, Black);
	cout << "3.Cyan" << endl;
	SetColor(Red, Black);
	cout << "4.Red" << endl;
	SetColor(Magenta, Black);
	cout << "5.Magenta" << endl;
	SetColor(LightGreen, Black);
	cout << "6.LightGreen" << endl;
	SetColor(LightMagenta, Black);
	cout << "7.LightMagenta" << endl;
	SetColor(Yellow, Black);
	cout << "8.Yellow" << endl;
	SetColor(LightBlue, Black);
	cout << "9.LightBlue" << endl;
	SetColor(LightCyan, Black);
	cout << "10.LightCyan" << endl;
	SetColor(LightRed, Black);
	cout << "11.LightRed" << endl;
	SetColor(Brown, Black);
	cout << "12.Brown" << endl;
	//SetColor(LightRed, Black);
	SetColor(White, Black);
	gotoxy(30,3);
	cout << "<==";
	while (true) {
		if (key == down && y < 14) {
			clear_screen(30, 33, y, y);
			y++;
			gotoxy(x, y);
			cout << "<==";
		}
		if (key == up && y>3) {
			clear_screen(30, 33, y, y);
			y--;
			gotoxy(x, y);
			cout << "<==";
		}
		if (key == _enter)
		{
			switch (y) {
			case 3:
				return Blue;
			case 4:
				return Green;
			case 5:
				return Cyan;
			case 6:
				return Red;
			case 7:
				return Magenta;
			case 8:
				return LightGreen;
			case 9:
				return LightMagenta;
			case 10:
				return Yellow;
			case 11:
				return LightBlue;
			case 12:
				return LightCyan;
			case 13:
				return LightRed;
			case 14:
				return Brown;
			}
		}
		key = _getch();
	}
}

template<class T> T entering_number(T, int, int);
void color(int background, int text)
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, background << 4 | text);
}

template <class T>
union types {
	T d;
	char c[sizeof(T)];
};

template<class T>
void dynamic_output(T number, int x = 30, int y = 10)
{
	system("color F0");
	bool bit;
	int k = sizeof(T) - 1, i = 0, count = 0, y_bites = 0;
	types<T> u;
	u.d = number;
	bool ch[8 * sizeof(T)];
	while (k >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			bit = u.c[k] & (1U << i);
			ch[count] = bit;
			i--;
			count++;
		}
		k--;
	}
	count = 8 * sizeof(T);
	i = 0;
	while (i < count)
	{
		bit = ch[i];
		if (i % 2 == 0)
		{
			y_bites = 0;
			while (y_bites != y)
			{
				gotoxy(x, y_bites);
				color(0, 11);
				cout << bit;
				Sleep(3);
				gotoxy(x, y_bites);
				cout << ' ';
				y_bites++;
			}
			gotoxy(x, y_bites);
			color(0, 15);
			cout << bit;
		}
		else
		{
			y_bites = 30;
			while (y_bites != y)
			{
				gotoxy(x, y_bites);
				color(0, 10);
				cout << bit;
				Sleep(3);
				gotoxy(x, y_bites);
				cout << ' ';
				y_bites--;
			}
			gotoxy(x, y_bites);
			color(0, 15);
			cout << bit;
		}
		i++;
		x++;
	}
}	
	//���� ������� �� ����������												
void phase_modulation(string ch,int k) {						
	int x=30,y=500,i=0,count=0,flag=20;
	HWND hWnd = FindWindowA("ConsoleWindowClass", NULL);
	HDC hDC = GetDC(hWnd);
	SelectObject(hDC, GetStockObject(DC_PEN));
	SetDCPenColor(hDC,RGB(45, 2, 221));
	int size = ch.length();
	if (k == 1)
	{
		count = 0;
	}
	else if (k == 2) {
		count = 3;
	}
	else if (k == 3) {
		count = 7;
	}
	system("cls");
	gotoxy(0, 0);
	cout << "��� ���������� � ���������� �������� ����������� -> � <-";
	gotoxy(0, 1);
	cout << "esc-����������� ������ ���������";
	int j = 0;
	gotoxy(30, 20);
	while (ch[j] != '\0')
	{
		cout << ch[j];
		j++;
	}
	while (i < size) {
		MoveToEx(hDC, x, y, 0);
		if (ch[i]=='1' && ch[i+1] == '0') {
			y += 20;
			x += count;
			LineTo(hDC, x, y );
		}  
		if (ch[i] == '0' && ch[i + 1] == '1') {
			y -= 20;
			x += count;
			LineTo(hDC, x, y);
		}
		if(count==0)
		{
			x += 20 ;
			LineTo(hDC, x, y);
		}
		if (count != 0 && ch[i] == ch[i + 1]) {
			//x += 20;
			_asm
			{
				mov eax,x
				mov ebx,20
				add eax,ebx
				mov x,eax
			}
			LineTo(hDC, x, y);
		}
		if(count !=0 && ch[i]!=ch[i+1]){
			x += 20 - 2 * count;
			LineTo(hDC, x, y);
		}
		i++;
	}
}	

void menu_for_color() {
	gotoxy(0, 0);
	cout << "����� �����" << endl;
	//cout << "������" << endl;
	gotoxy(90, 0);
	cout << "��� ������ ������� esc";
}

void show_menu_for_color()
{
	const int x = 25;
	int ch = 0, k = 1, y = 0;
	setlocale(0, "");
	system("cls");
	menu_for_color();
	gotoxy(x, 0);
	cout << "<==";
	while (k == 1)
	{
		if (ch == _enter)
		{
				system("cls");
				gotoxy(0, 0);
				color(0, 10);
				cout << "���� 1 ����";
				color(0, 15);
				color_bit_one = getColor();
				clear_screen(30, 33, 3, 14);
				gotoxy(0, 0);
				color(0, 5);
				cout << "���� 2 ����";
				color(0, 15);
				color_bit_two = getColor();
				return;
		}
		if (ch == _esc)
		{
			system("cls");
			return;
		}
		ch = _getch();
	}
}
//���� ������������ �������
template<class T>
void output_bynary_system(T number) {
	bool bit;
	int k = sizeof(T) - 1, i = 0;
	types<T> u;
	u.d = number;
	bool ch[8 * sizeof(T)];
	while (k >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			bit = u.c[k] & (1U << i);
			cout << bit;
			//i--;
			_asm
			{
				mov eax,i
				dec i
			}
		}
		//k--;
		_asm
		{
			mov eax,k
			dec k
		}
	}
}

template<class T>
void chart(T number)
{
	string s;
	bool bit;
	int k = sizeof(T) - 1, i = 0, count = 0,input=0;
	types<T> u;
	u.d = number;
	system("cls");
	dynamic_output(number,30,20);
	while (k >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			bit = u.c[k] & (1U << i);
			if (!bit)
				s = s + '0';
			else
				s = s + '1';
			i--;
			count++;
		}
		k--;
	}
	int coefficient = 0;
	gotoxy(0, 0);
	cout << "��� ���������� � ���������� �������� ����������� -> � <-";
	gotoxy(0, 1);
	cout << "esc-����������� ������ ���������";
	gotoxy(130, 3);
	cout << "TAB-����� ����� �������";
	while (input != _esc) {
		gotoxy(5, 25);
		if (input == _right && coefficient <3) {
			clear_screen(41, 80, 8, 9);
			coefficient++;
			phase_modulation(s, coefficient);
		}
		if (input == _left && coefficient > 0) {
			clear_screen(41, 80, 8, 9);
			coefficient--;
			phase_modulation(s, coefficient);
		}
		if (input == _tab)
		{
			show_menu_for_color();
			system("cls");
		}
		if (input == _esc)
			break;
		input = _getch();
	}
	system("pause");
}

template<class T>
void output_bites_for_swap(T number, deque<int>s1 = { -1 }, deque<int>s2 = { -1 })
{
	bool bit;
	int k = sizeof(T) - 1, i ,x=0,y=10,number_bites=8*sizeof(T)-1;
	types<T> u;
	u.d = number;
	if (s1.size() > 0)
		sort(s1.begin(), s1.end());
	if (s2.size() > 0)
		sort(s2.begin(), s2.end());
	while (k >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			gotoxy(30 + x, y);
			if(s1.back()!=number_bites && s2.back()!=number_bites)
			{
				bit = u.c[k] & (1U << i);
				color(0, 15);
				cout << bit;
			}
			else
			{
				if (s1.back() == number_bites)
				{
					bit = u.c[k] & (1U << i);
					color(0, color_bit_one);
					cout << bit;
					if (s1.size() == 1 && s1.back() != -1)
					{
						s1.pop_back();
						s1.push_back(-1);
					}
					else
					{
						if (s1.size() > 0)
							s1.pop_back();
					}
				}
				else
				{
					bit = u.c[k] & (1U << i);
					color(0, color_bit_two);
					cout << bit;
					if (s2.size() == 1 && s2.back() != -1)
					{
						s2.pop_back();
						s2.push_back(-1);
					}
					else
					{
						if (s2.size() > 0)
							s2.pop_back();
					}
				}
			}
			number_bites--;
			x++;
			i--;
		}
		k--;
	}
}

template<class T>
T assigning_bits_to_an_array(T number,int array_bites_number[8*sizeof(T)])
{
	types<T>u;
	u.d = number;
	int k = sizeof(T) - 1,i=0,count=8*sizeof(T)-1;
	bool bit1,bit2,bit;
	int x = 0;
	while (k >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			bit1 = array_bites_number[count];
			bit2 = u.c[k] & (1U << i);
			if (bit1 != bit2)
			{
				u.c[k] = u.c[k] ^ ((1U << i));
			}
			--i;
			count--;
			x++;
		}
		k--;
	}
	number = u.d;
	return number;
}

template<class T>
T swap_bites(T number,deque<int> s1,deque<int>s2,int number_system)
{
	bool bit;
	char ch[8 * sizeof(number)];
	int k1, k2, k = 0, i = 0, count = 0, min = 0;
	int size_number_byte = sizeof(T) - 1, array_bites_number[8*sizeof(T)];
	deque<int>bites_one_group, bites_two_group;
	types<T> u;
	u.d = number;
	count = 8*sizeof(T) - 1;
	while (size_number_byte >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			array_bites_number[count]= u.c[size_number_byte] & (1U << i);;
			count--;
			i--;
		}
		size_number_byte--;
	}
	if (s2.size() > s1.size())
		swap(s1, s2);
	k1 = s1.back();
	k2 = s2.back();
	while (k1>=s1.front())
	{
		bites_one_group.push_front(k2);
		k1--;
		k2--;
	}
	k1 = s1.back();
	k2 = s2.back();
	while (k2 >= s2.front())
	{
		bites_two_group.push_front(k1);
		k1--;
		k2--;
	}
	if (s1.size() == s2.size())
	{
		k1 = s1.front();
		k2 = s2.front();
		while (k1 <= s1.back())
		{
			bit = array_bites_number[k2];
			array_bites_number[k2] = array_bites_number[k1];
			array_bites_number[k1] = bit;
			k1++;
			k2++;
		}
	}
	k1 = s1.back();
	i = 0;
	while (i < s1.size())
	{
		ch[i] = array_bites_number[k1];
		k1--;
		++i;
	}
	ch[i] = '&';
	if (s1.back() > s2.back() && s1.size()!=s2.size())
		{
			k = s1.front() - 1;
			k1 = s1.front(); k2 = s2.front();
			min = s2.front();
			i = 0;
			while (!s1.empty())
			{
				if (!s2.empty())
				{
					bit = array_bites_number[k2+s2.size()-1-i];
					array_bites_number[k1+s1.size()-1-i] = bit;
					k2++;
					k1++;
					++i;
					s1.pop_back();
					s2.pop_back();
				}
				else
				{
					int _swap = s1.size();
					while (k >= k2 )
					{
						array_bites_number[k + _swap] = array_bites_number[k];
						k--;
					}
					i = 0;
					while (ch[i+1] != '&')
					{
						++i;
					}
					while (i>=0)
					{
						array_bites_number[min] = ch[i];
						--i;
						min++;
					}
					s1.clear();
				}
			}
		}
	else
	{
		if (s1.back() < s2.back() && s1.size() != s2.size())
		{
			k = s1.back() + 1;
			min = s2.front() - 1;
			k1 = s1.front(); k2 = s2.front();
			i = 0;
			while (!s1.empty())
			{
				if (!s2.empty())
				{

					bit = array_bites_number[k2];
					array_bites_number[k1] = bit;
					k2++;
					k1++;
					++i;
					s1.pop_back();
					s2.pop_back();
				}
				else
				{
					int _swap = s1.size();
					while (k <= min)
					{
						array_bites_number[k - _swap] = array_bites_number[k];
						k++;
					}
					i = 0;
					k = k2 - 1;
					while (ch[i] != '&')
					{
						array_bites_number[k] = ch[i];
						++i;
						k--;
					}
					s1.clear();
				}
			}
		}
	}
	number=assigning_bits_to_an_array(number, array_bites_number);
	output_bites_for_swap(number,bites_one_group,bites_two_group);
	gotoxy(90, 10);
	cout << fixed << setprecision(40) << number;
	gotoxy(10, 20);
	system("pause");
	return number;
}

template<class T>
T input_group_bit(T number, int number_system)
{
	ShowCursor(FALSE);
	bool bit;
	int i = 8*sizeof(T)-1, k = 0,lable = 0, x = 0, ch = 0,flag=0;
	types<T> u;
	u.d = number;
	setlocale(0, "");
	deque<int> s1 , s2 ;
	gotoxy(30, 10);
	while (k != 2)
	{
		gotoxy(140, 3);
		color(0, 15);
		cout << "����� �����";
		if (flag == 1) {
			gotoxy(160, 3);
			cout << "<==";
		}
		gotoxy(0, 3);
		cout << "������� TAB ��� ������ �����";
		gotoxy(0, 4);
		cout << "������� BACKSPACE ��� �������� �� ������ ����� � ������ �����";
		gotoxy(0, 2);
		color(0, 15);
		cout << "��� ��������� ���� ������� SPACE";
		gotoxy(x + 30, 10);
		if (ch == _right && x < i)
		{
			x++;
			gotoxy(x + 30, 10);
			lable = 1;
		}
		if (ch == _left && x > 0)
		{
			x--;
			gotoxy(x + 30, 10);
			lable = 0;
		}
		if (ch == _space)
		{
			gotoxy(x + 30, 10);
			if (k == 0)
			{
				if (s1.empty())
				{
					s1.push_back(i - x);
					output_bites_for_swap(number, s1);
				}
				else
				{
					if ((s1.back() == i - x + 1)  && s1.size() < i)
					{
						s1.push_back(i - x);
						output_bites_for_swap(number, s1);
					}
					else
					{
						if ((s1.front() == i - x - 1)  && s1.size() <= i)
						{
							s1.push_front(i - x);
							output_bites_for_swap(number, s1);
						}
						else
						{
							gotoxy(0, 5);
							cout << "����� �������� ������ ������ ������ ����";
							Sleep(3000);
							clear_screen(0, 40, 5, 5);
						}
					}
				}
				gotoxy(x + 30, 10);
			}
			if (k == 1)
			{
				if (s2.empty() && ((s1.front() < i - x ) || (s1.back() > i - x ) || (s1.front() < i - x && s1.back() > i - x )))
				{
					s2.push_back(i - x);
					output_bites_for_swap(number, s1, s2);
				}
				else
				{
					if (s2.size()>0 && (s2.back() == i - x + 1)  && (s1.size() + s2.size() <= i) && (s1.front() < i - x  || s1.back() > i - x || (s1.front() < i - x  && s1.back() > i - x )))
					{
						s2.push_back(i - x);
						output_bites_for_swap(number, s1, s2);
					}
					else
					{
						if ( s2.size()>0 && (s2.front() == i - x - 1)  && (s1.size() + s2.size() <= i) && (s1.front() < i - x  || s1.back() > i - x  || (s1.front() < i - x  && s1.back() > i - x )))
						{
							s2.push_front(i - x);
							gotoxy(x + 30, 10);
							output_bites_for_swap(number, s1, s2);
						}
						else
						{
							if (s1.front() >= i - x && s1.back() < i - x + 1)
							{
								gotoxy(0, 6);
								cout << "��� ���� ����������� 1 ������";
								Sleep(3000);
								clear_screen(0, 40, 6, 6);
							}
							else
							{
								gotoxy(0, 6);
								cout << "����� �������� ������ ������ ������ ����";
								Sleep(3000);
								clear_screen(0, 40, 6, 6);
							}
						}
					}
				}
				gotoxy(x + 30, 10);
			}
		}
		if (ch == _backspace)
		{
			int count = 0;
			if (k==0 && flag==0)
			{
				count =i - x;
				auto result = minmax_element(s1.begin(), s1.end());
				if (s1.size()>0 && (count == *result.first || count==*result.second))
				{
					s1.erase(remove(s1.begin(), s1.end(), count), s1.end());
				}
				else if(s1.size()>0)
				{
					gotoxy(0, 15);
					cout << "�� ������ ������� ������ ������� ����";
					Sleep(3000);
					clear_screen(0, 40, 15, 15);
				}
				else
				{
					gotoxy(0, 15);
					cout << "�������� ����!";
					Sleep(3000);
					clear_screen(0, 40, 15, 15);
				}
				if (s1.size() == 0)
				{
					output_bites_for_swap(number);
				}
				else 
				{
					output_bites_for_swap(number, s1);
				}
				gotoxy(30 + x, 10);
			}
			if (k == 1 && flag==0)
			{
				count = i - x;
				auto result = minmax_element(s2.begin(), s2.end());
				if (s2.size() > 0 && (count == *result.first || count == *result.second))
				{
					s2.erase(remove(s2.begin(), s2.end(), count), s2.end());
				}
				else if(s2.size()>0)
				{
					gotoxy(0, 15);
					cout << "�� ������ ������� ������ ������� ����";
					Sleep(3000);
					clear_screen(0, 40, 15, 15);
				}
				else
				{
					gotoxy(0, 15);
					cout << "�������� ����!";
					Sleep(3000);
					clear_screen(0, 40, 15, 15);
				}
				if (s2.size() == 0)
				{
					output_bites_for_swap(number, s1);
				}
				else 
					output_bites_for_swap(number, s1, s2);
				gotoxy(30 + x, 10);
			}
			if (flag == 1) {
				clear_screen(160, 160 + 3, 3, 3);
				flag = 0;
				gotoxy(30 + x, 10);
			}
		}
		if (ch ==_tab && flag ==0)
		{
			gotoxy(160, 3);
			cout << "<==";
			flag = 1;
		}
		else if(ch==_tab && flag==1)
		{
			gotoxy(160, 3);
			cout << "<==";
		}
		if (ch == _enter && flag==0)
		{
			if (s1.size() == 0 && k==0)
			{
				gotoxy(0, 5);
				cout << "����� ������� ���� �� ���� ���";
				Sleep(3000);
				clear_screen(0, 40, 5, 5);
			}
			else
				if (s1.size() > 0 && s2.size() == 0 && k == 1)
				{
					gotoxy(0, 5);
					cout << "����� ������� ���� �� ���� ���";
					Sleep(3000);
					clear_screen(0, 40, 5, 5);
				}
				else
					k++;
			if (k == 2)
			{
				gotoxy(0, 5);
				cout << "��� ����������� ������� ����� �������";
				clear_screen(0, 40, 5, 5);
			}
		}
		if (ch == _enter && flag == 1) {
			show_menu_for_color();
			system("cls");
			if(s1.size()>0 && s2.size()>0)
				output_bites_for_swap(number,s1,s2);
			else if(s1.size()>0 && s2.size()==0)
				output_bites_for_swap(number, s1);
			else if(s1.size()==0 && s2.size()==0)
				output_bites_for_swap(number);
		}
		ch = _getch();
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	number = swap_bites(number, s1, s2, number_system);
	return number;
}

void _bool(int number_system,int count)
{
	bool number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number=input_group_bit(number, number_system);
	chart(number);
}
void _char(int number_system, int count)
{
	char number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}
void short_int(int number_system,int count)
{
	short int number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}
void unsigned_short_int(int number_system,int count)
{
	unsigned short int number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}
void _int(int number_system,int count)
{
	int number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}
void unsigned_int(int number_system,int count)
{
	unsigned int number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);

}
void _float(int number_system,int count)
{
	float number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}
void _double(int number_system,int count)
{
	double number = 0;
	number = entering_number(number, number_system, count);
	dynamic_output(number);
	number = input_group_bit(number, number_system);
	chart(number);
}

template<class T>
T check_range(double ch,T number,int number_system,int count)
{
	switch (count)
	{
	case 0:
		if ((ch <= (255) && ch >= 0))
		{
			number = static_cast<T>(ch);
		}
		else
			number = false;
		break;
	case 1:
		if ((ch <= (255) && ch >= 0))
		{
			number = static_cast<T>(ch);
		}
		break;
	case 2:
		if ((ch <= (32767) && (ch >= -32768)))
		{
			number = static_cast<T>(ch);
		}
		break;
	case 3:
		if ((ch <= 65535) && ch >= 0)
		{
			number = static_cast<T>(ch);
		}
		break;
	case 4:
		if ((ch <= 2147483647) && (ch >= (-2147483647 - 1)))
		{
			number = static_cast<T>(ch);
		}
		break;
	case 5:
		if ((ch <= 4294967295) && ch >= 0)
		{
			number = static_cast<T>(ch);
		}
		break;
	case 6:
		if ((ch <= 2147483647.0) && (ch >= -2147483648.0))
		{
			number = static_cast<T>(ch);
		}
		else
			return -1;
		break;
	case 7:
		if ((ch >= -9223372036854775808.0) && (ch <= 9223372036854775807.0))
		{
			number = static_cast<T>(ch);
		}
		else
			return -1;
		break;
	}
	return number;
}

template<class T>
T check_number(T ch,int number_system)
{
	setlocale(0, "");
	int adress = 0; 
	adress = int(ch);
		if ((ch >= '0') && (ch <= '9') &&(adress-48)<number_system)
		{
			return (adress - 48);
		}
		if (ch >= 'A' && ch <= 'Z' && (adress - 55) < number_system)
		{
			return(adress - 55);
		}
		if (ch >= 'a' && ch <= 'z' && (adress - 61) < number_system)
		{
			return(adress - 61);
		}
		if (ch >= '�' && ch <= '�' && (adress + 128) < number_system)
		{
			return(adress + 128);
		}
		if (ch >= '�' && ch <= 'e' && (adress + 127) < number_system)
		{
			return(adress + 127);
		}
		if (ch == '�' && (adress + 173) < number_system)
		{
			return adress + 173;
		}
		if (ch >= '�' && ch <= '�' && (adress +126) < number_system)
		{
			return(adress+126);
		}
		if (ch == '�' && (adress + 156) < number_system)
		{
			return adress + 156;
		}
		return -1;
}

double transfer_number(string s,int number_system)
{
	double number = 0;
	int count = s.length()-1;
	int k = 0,i = 0,label=0;
	int counter = count;
	while (counter >= 0)
	{
		if (s[i] != '.')
			++i;
		else
			break;
		counter--;
	}
	k = i-1;
	i = 0;
	int number_ten = 0;
	while (count>=0)
	{
		if (s[i] != '.')
		{
			if (s[i] == '0' && label == 0)
			{
				count--;
				i++;
				k--;
				continue;
			}
			else
			{
				if(label==0)
					label = 1;
				number_ten = check_number(s[i], number_system);
				number = number + number_ten * pow(number_system, k);
				k--;
			}
		}
		count--;
		i++;
	}
	return number;
}

template<class T>
T entering_number(T number,int number_system,int count)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	stack<string> minus;
	string s,s2;
	double ten = 0;
	int k = 0, i = 0, number_ten= 0;
	char ch = 0;
	system("cls");
	gotoxy(0, 0);
	cout << "������� �����  ";
	map<int, string> m2;
	for (map<string, int>::iterator it = alphabet.begin(); it != alphabet.end(); ++it)
		m2[it->second] = it->first;
	for (int i = 0; i < number_system; ++i) {
		auto s= m2.find(i)->second;
		cout << s;
	}
	gotoxy(0, 1);
	while (k == 0)
	{
		ch = _getch();	
		number_ten = check_number(ch, number_system);
		if ((number_ten != -1|| ch=='.'||ch=='-')&& s.length()<=41)
		{
			if (count == 0 || count == 1 || count == 3 || count == 5)
			{
				if (ch != '.' && ch != '-')
					s = s + ch;
				else
				{
					gotoxy(0, 3);
					cout << "������.��� ����������� ������������� ���!";
					Sleep(3000);
				}
			}
			if (count == 2 || count == 4)
			{
				if (ch != '.')
				{
					if (ch != '-')
						s = s + ch;
					else
					{
						minus.push("-");
						cout << "-";
					}
				}
				else
					cout << "������.��� ������������� ���!";
			}
			if (count == 6 || count == 7)
			{
				if (ch != '.' && ch != '-')
					s = s + ch;
				else
					if (ch == '.' && s.length() > 0)
						s = s + ch;
					else
						if (ch == '-' && s.length() == 0)
						{
							minus.push("-");
							cout << "-";
						}
						else
							cout << "������";
			}
			system("cls");
			gotoxy(0, 0);
			cout << "������� �����  ";
			for (int i = 0; i < number_system; ++i) {
				auto s = m2.find(i)->second;
				cout << s;
			}
			cout<< endl;
			if (s.length() > 0)
			{
				gotoxy(0, 3);
				cout << "� " << number_system << " ������� ���������" << endl;
				gotoxy(0, 4);
				if (!minus.empty())
					cout << '-';
				cout << s;
			}
			if(s.length()>0)
				ten = transfer_number(s, number_system);
			if (check_range(ten, number, number_system, count) != number && count != 0 && count!=7 && count!=6)
			{
				number = static_cast<T>(ten);//�������������� � ����
				gotoxy(60, 3);
				cout << "� 10 ������� ���������";
				gotoxy(43, 4);
				if (!minus.empty())
					cout << '-';
				if (count < 6)
					cout << fixed << setprecision(0) << round(ten) << endl;
				else
					cout << fixed << setprecision(40)<< ten << endl;
				gotoxy(110, 3);
				cout << "� 2 ������� ���������";
				gotoxy(104, 4);
				output_bynary_system(number);
			}
			else
			{
				if (check_range(ten, number, number_system, count)!=-1 && (count==6||count==7))
				{
					number = static_cast<T>(ten);//�������������� � ����
					gotoxy(60, 3);
					cout << "� 10 ������� ���������";
					gotoxy(43, 4);
					if (!minus.empty())
						cout << '-';
					if (count < 6)
						cout << fixed << setprecision(0) << round(ten) << endl;
					else
						cout << fixed << setprecision(40) << ten << endl;
					gotoxy(110, 3);
					cout << "� 2 ������� ���������";
					gotoxy(104, 4);
					output_bynary_system(number);
				}
				else
				if (check_range(ten, number, number_system, count) && count == 0)
				{
					number = static_cast<T>(ten);//�������������� � ����
					gotoxy(60, 3);
					cout << "� 10 ������� ���������";
					gotoxy(43, 4);
					if (!minus.empty())
						cout << '-';
					if (count < 6)
						cout << fixed << setprecision(0) << round(ten) << endl;
					else
						cout << fixed << setprecision(40) << ten << endl;
					gotoxy(110, 3);
					cout << "� 2 ������� ���������";
					gotoxy(104, 4);
					output_bynary_system(number);
				}
				else
				{
				if (ch != '.' && ch!='-'&&ch!='0')
				{
					system("cls");
					cout << "������!����� �� ������ � �������� ��������" << endl;
					if (!minus.empty())
						cout << '-';
					if(count<6)
						cout << "� ��� ����������  " << fixed << setprecision(0) << round(ten) << " � 10 ��" << endl;
					else
						cout<< "� ��� ����������  " << fixed << setprecision(17)<<ten << " � 10 ��" << endl;
					Sleep(5000);
					if (s.length() > 1)
						s.resize(s.length() - 1);
					else
						s.resize(0);
					int j = 0,ch=0;
					ten = 0;
					string t;
					while (s[j] != '\0')
					{
						ch = check_number(s[j], number_system);
						t = t + s[j];
						ten = transfer_number(t,number_system);
						++j;
					}
					number = static_cast<T>(ten);
					system("cls");
					gotoxy(0, 0);
					cout << "������� �����  ";
					for (int i = 0; i < number_system; ++i) {
						auto s = m2.find(i)->second;
						cout << s;
					}
					cout << endl;
					gotoxy(0, 3);
					cout << "� " << number_system << " ������� ���������" << endl;
					gotoxy(0, 4);
					if (!minus.empty())
						cout << '-';
					cout << s;
					gotoxy(60, 3);
					cout << "� 10 ������� ���������";
					gotoxy(43, 4);
					if (!minus.empty())
						cout << '-';
					if (count < 6)
						cout << fixed << setprecision(0) << round(ten) << endl;
					else
						cout << fixed << setprecision(40)<< ten  << endl;
					gotoxy(110, 3);
					cout << "� 2 ������� ���������";
					gotoxy(104, 4);
					output_bynary_system(number);
				}
			}
		}
	}
		else
		{
			if (ch != _enter && ch != _backspace)
			{
				if (s.length() >= 20)
				{
					gotoxy(0, 10);
					cout << "�� ��������� ����� ������ ������ 40 ������ ";
				}
				else
				{
					gotoxy(0, 7);
					cout << "������ �������� ���� � ���� ������� ���������" << endl;
					Sleep(3000);
					system("cls");
					gotoxy(0, 0);
					cout << "������� �����  ";
					for (int i = 0; i < number_system; ++i) {
						auto s = m2.find(i)->second;
						cout << s;
					}
					cout << endl;
					gotoxy(0, 3);
					cout << "� " << number_system << " ������� ���������" << endl;
				}
				gotoxy(0, 4);
				if (!minus.empty())
					cout << '-';
				cout << s;
				gotoxy(60, 3);
				cout << "� 10 ������� ���������";
				gotoxy(43, 4);
				if (!minus.empty())
					cout << '-';
				if (count < 6)
					cout << fixed << setprecision(0) << round(ten)  << endl;
				else
					cout << fixed << setprecision(40) << ten<<endl;
				gotoxy(110, 3);
				cout << "� 2 ������� ���������";
				gotoxy(104, 4);
				output_bynary_system(number);
			}
		}
		if (ch == _backspace)
		{
			if (s.length() == 1 && !minus.empty())
				minus.pop();
			if (s.length() > 1)
				s.resize(s.length() - 1);
			else
			{
				s.resize(0);
			}
			int j = 0, ch = 0;
			ten = 0;
			string t;
			while (s[j] != '\0'&&s[0]!='0')
			{
				ch = check_number(s[j], number_system);
				t = t + s[j];
				ten = transfer_number(t,number_system);
				++j;
			}
			number = static_cast<T>(ten);
			system("cls");
			gotoxy(0, 0);
			cout << "������� �����  ";
			for (int i = 0; i < number_system; ++i) {
				auto s = m2.find(i)->second;
				cout << s;
			}
			cout << endl;
			gotoxy(0, 3);
			cout << "� " << number_system << " ������� ���������" << endl;
			gotoxy(0, 4);
			if (!minus.empty())
				cout << '-';
			cout << s;
			gotoxy(60, 3);
			cout << "� 10 ������� ���������";
			gotoxy(43, 4);
			if (!minus.empty())
				cout << '-';
			if (count < 6)
				cout << fixed << setprecision(0) << round(ten)  << endl;
			else
				cout << fixed << setprecision(40)<<ten << endl;
			gotoxy(110, 3);
			cout << "� 2 ������� ���������";
			gotoxy(104, 4);
			output_bynary_system(number);
		}
		if (ch == _enter )
		{
			system("cls");
			if (count != 0 && count != 1 && count != 3 && count != 5 && !minus.empty())
				number = number * (-1);
			return number;
		}
	}
}
// ���� ������������ �������
int entering_number_system()
{
	int k = 1, i = 0,x=0,y=0;
	int ch = 0;
	system("cls");
	gotoxy(0, 0);
	cout << "������� ������� ��������� �� 1 �� 128"<<endl;
	gotoxy(0, 1);
	while (true)
	{
		ch = _getch();
		if (ch >= '0' && ch <= '9')
		{
			//x = x*10  + (ch-'0');
			int c = ch - '0';
			_asm
			{
				mov eax,x
				mov ebx,10
				mul ebx 
				mov x,eax
				mov eax,x
				mov ebx,c
				add eax,ebx
				mov x,eax
			}
			if (x <= 128 && x >= 1)
			{
				y = x;
				gotoxy(0, 1);
				cout << y;
				++i;
			}
			else
			{
				gotoxy(0, 2);
				cout << "������!����� ������ ���� �� 1 �� 128" << endl;
				Sleep(3000);
				system("cls");
				cout << "������� ������� ��������� �� 1 �� 128" << endl;
				if(y)
					cout << y;
			}
		}
		else
		{
			if (ch != _enter && ch != _backspace && ch!=_esc)
			{
				gotoxy(0, 2);
				cout << "������� ������ �����!"<<endl;
				Sleep(3000);
				system("cls");
				cout << "������� ������� ��������� �� 1 �� 128" << endl;
				if(y)
					cout << y;
			}
		}
		if (ch == _backspace && y != 0)
		{
			y = y / 10;
			x = y;
			system("cls");
			gotoxy(0, 0);
			cout << "������� ������� ��������� �� 1 �� 128" << endl;
			gotoxy(0, 1);
			if(y)
				cout << y;
		}
		if (ch == _enter && y != 0)
		{	
			system("cls");
			return y;
		}
		if (ch == _right)
		{
			show_menu_for_color();
		}
	}
}

void change_type_data(int count)
{
	int number_system = 0;
	number_system = entering_number_system();
	switch (count)
	{
	case 0:
		_bool(number_system, count);
		break;
	case 1:
		_char(number_system, count);
		break;
	case 2:
		short_int(number_system, count);
		break;
	case 3:
		unsigned_short_int(number_system, count);
		break;
	case 4:
		_int(number_system, count);
		break;
	case 5:
		unsigned_int(number_system, count);
		break;
	case 6:
		_float(number_system, count);
		break;
	case 7:
		_double(number_system, count);
		break;
	}
}

void menu_main()
{
	gotoxy(0, 0);
	cout << "bool" << endl;
	cout << "char" << endl;
	cout << "short int" << endl;
	cout << "unsigned short int" << endl;
	cout << "int" << endl;
	cout << "unsigned int" << endl;
	cout << "float" << endl;
	cout << "double" << endl;
	gotoxy(140, 3);
	cout << "����� �����";
}
//������������ �������
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color F0");
	int ch=0, k = 1, x = 30, y = 0;
	setlocale(0, "");
	menu_main();
	gotoxy(x, y);
	cout << "<==";
	while (k==1)
	{
		if (ch == down && y <= 6 && x!=160)
		{
			clear_screen(x, x + 3, y, y);
			_asm
			{
				INC(y);
			}
			//y++;
			gotoxy(x, y);
			cout << "<==";
		}
		if (ch == up && y > 0 && x!=160)
		{
			clear_screen(x, x + 3, y, y);
			_asm
			{
				DEC(y);
			}
			//y--;
			gotoxy(x, y);
			cout << "<==";
		}
		if (ch == _enter)
		{
			if (x != 160)
				change_type_data(y);
			else
				show_menu_for_color();
			system("cls");
			clear_screen(x, x + 3, y, 6);
			menu_main();
			gotoxy(x, 3);
			cout << "<==";
		}
		if (ch == _right)
		{
			clear_screen(x, x + 3, y, y);
			x = 160;
			gotoxy(x, 3);
			cout << "<==";
		}
		if (ch == _left)
		{
			clear_screen(x, x + 3, 3, 3);
			x = 30;
			gotoxy(x, y);
			cout << "<==";
		}
		ch = _getch();
	}
	return 0;
}