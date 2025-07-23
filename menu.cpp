#include <math.h>
#include "menu.hpp"

Menu::Menu(vector<string> &itens, string title, string message) :
		itens(itens), title(title), message(message)
	{
	this->setWidth();
	this->setSymbol();
	this->setZeroForLastOpt();
	this->setRepeatList();
	}

void Menu::setDecorator(const string &symbol, int width)
	{
	this->symbol = symbol;
	this->width = width;
	}

const int Menu::getChoice()
	{
	unsigned long choice;
	bool firstTime = true;
	string decorator = makeDecorator();

	do
		{
		if (repeatList || firstTime)
			{
			unsigned long index = 0;
			cout << decorator << endl;
			cout << title << endl;
			cout << decorator << endl;

			for (index = 0; index < ((itens.size() - (zeroForLastOpt ? 1 : 0))); index++)
				{
				cout << (index + (zeroForLastOpt ? 1 : 00)) << " - " << itens.at(index) << endl;
				}
			cout << decorator << endl;

			if (zeroForLastOpt)
				{
				cout << 0 << " - " << itens.at(index) << endl;
				cout << decorator << endl;
				}

			firstTime = false;
			}
		cout << message << endl;
		cin >> choice;
		}
	while (isNotAValidChoice(choice));
	cin.ignore();

	return (choice);
	}

const string Menu::makeDecorator()
	{
	if (!width)
		{
		width = max(title.length(), message.length());

		for (string item : itens)
			{
			width = ((unsigned long int) width >= item.length()) ? width : item.length();
			}
		width += 4 + (log10(itens.size()));
		width = (width / symbol.length()) + ((width % symbol.length()) ? 1 : 0);
		}
	return (replicate(symbol, width));
	}

const bool Menu::isNotAValidChoice(unsigned long choice) const
	{
	return ((choice < 0) || (choice > (itens.size() - 1)));
	}

const string Menu::replicate(string text, int times) const
	{
	string buffer;
	for (int count = 0; count < times; count++)
		{
		buffer += text;
		}
	return (buffer);
	}

const int Menu::getLength() const
	{
	return (itens.size());
	}

const string& Menu::getMessage() const
	{
	return message;
	}

void Menu::setMessage(const string &message)
	{
	this->message = message;
	}

bool Menu::isRepeatList() const
	{
	return repeatList;
	}

void Menu::setRepeatList(bool repeatList)
	{
	this->repeatList = repeatList;
	}

const string Menu::getSymbol() const
	{
	return symbol;
	}

void Menu::setSymbol(const string &symbol)
	{
	this->symbol = symbol;
	}

const string& Menu::getTitle() const
	{
	return title;
	}

void Menu::setTitle(const string &title)
	{
	this->title = title;
	}

int Menu::getWidth() const
	{
	return width;
	}

void Menu::setWidth(int width)
	{
	this->width = width;
	}

bool Menu::isZeroForLastOpt() const
	{
	return zeroForLastOpt;
	}

void Menu::setZeroForLastOpt(bool zeroForLastOpt)
	{
	this->zeroForLastOpt = zeroForLastOpt;
	}

Menu::~Menu(){
	}

