#include <iostream>
using namespace std;
int n, i = 0, stop = 0, start = 0, szefo = 0, point = 0, sub = 0, _left = 0, _max = 0, possible = 0;
int szef[1000001];
int wyplata[1000001];
int pracownik[1000001];
int pracownicy[1000001];
int _ranga[1000001];
int flag[1000001];
int buffor[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> szef[i] >> wyplata[i];
		if (szef[i] == i)
		{
			wyplata[i] = n;
		}
		else if (wyplata[i])
		{
			szef[i] = n + 1;
		}
	}
	n++;
	for (int i = 1; i <= n; i++)
	{
		_ranga[szef[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (_ranga[i] == 0)
		{
			buffor[stop++] = i;
		}
	}
	while (start < stop)
	{
		point = buffor[start++];
		szefo = szef[point];
		if (wyplata[point] == 0)
		{
			_ranga[szefo]--;
			if (_ranga[szefo] == 0)
			{
				buffor[stop++] = szefo;
			}
			pracownicy[szefo] += pracownicy[point] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (wyplata[i])
		{
			flag[wyplata[i]] = i;
		}
		else if(pracownik[szef[i]]==0)
		{
			pracownik[szef[i]] = i;
		}
		else
		{
			pracownik[szef[i]] = -1;
		}
	}
	while (i < n - 1)
	{
		
		while (i < n - 1 && flag[i + 1] != 0)
		{
			i++;
			sub = flag[i];
			_left -= pracownicy[sub];
			_max = i;
			if (_left == 0)
			{
				while (possible-- && pracownik[sub] > 0)
				{
					while (flag[_max])
					{
						_max--;
					}
					sub = pracownik[sub];
					wyplata[sub] = _max;
					flag[_max] = sub;
				}
				possible = 0;
			}
			if (pracownicy[sub] != 0)
			{
				possible = 0;
			}
		}
		while (i < n - 1 && flag[i + 1] == 0)
		{
			i++;
			_left++;
			possible++;
		}
	}
	for (int i = 1; i < n; i++)
	{
		cout << wyplata[i] << "\n";
	}
}