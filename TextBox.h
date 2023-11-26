#pragma once
#include "Controller.h"

//baseado fortemente no código do monitor Matheus Burda

namespace Controle
{
	namespace ControleUI
	{
		class TextBox : public Controller
		{
		private:
			std::string texto;

		public:
			TextBox();
			~TextBox();
			void notifyKeyPressed(std::string key);
			void notifyKeyReleased(std::string key){}
			std::string getTexto() const;
			void resetarTexto();

		};

	}
}
