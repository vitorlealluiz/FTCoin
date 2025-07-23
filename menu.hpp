#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>

using namespace std;

class Menu final /*não pode ser herdada por outras classes*/
	{
	private:
		vector<string> &itens; /*contém as opções passadas por referência*/

		string title;
		string message;

		string symbol; /*simbolo que decora o menu no terminal*/
		int width; /*largura do menu*/
		bool repeatList; /*controlar a reebição do menu*/
		bool zeroForLastOpt; /*se verdade a ultima opção é numerada como 0*/

		const bool isNotAValidChoice(unsigned long choice) const;
		const string replicate(string text, int times) const;
		const string makeDecorator();

	public:
		Menu(vector<string> &itens, string title = "Menu", string message = "Opcao: "); 
		virtual ~Menu();

		const int getChoice();
		void setDecorator(const string &decorator, int width);

		const string& getDecorator() const;
		const string& getMessage() const;
		const int getLength() const;
		void setMessage(const string &message);
		bool isRepeatList() const;
		void setRepeatList(bool repeatList = false);
		const string getSymbol() const;
		void setSymbol(const string &symbol = "-");
		const string& getTitle() const;
		void setTitle(const string &title);
		int getWidth() const;
		void setWidth(int width = 0);
		bool isZeroForLastOpt() const;
		void setZeroForLastOpt(bool zeroForLastOpt = true);
	};

#endif 