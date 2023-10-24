#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

//gerenciador gr�fico baseado no tutorial do Matheus Burda!

//ps:o nome da classe de cada gerenciador se da pela sua fun�ao
//sua chamada por namespace ja nos diz que se trata de um gerenciador

typedef std::map <const char*, sf::Texture*> MapaTextura;

namespace Gerenciadores
{
	class Grafico
	{
	private:
		MapaTextura CharactersTextures;
		MapaTextura FontTextures;
		sf::RenderWindow janelaPrincipal;
		sf::View cameraJogo;

		//Padr�o de Projeto Singleton:
		Grafico();
		static Gerenciadores::Grafico* instancia_pGG;

	public:
		~Grafico();
		static Grafico* getGerenciador_Grafico();

		//render
		void renderCharacter(sf::RectangleShape* corpo);
		void renderText(sf::Text* texto);

		//janela e camera
		bool isWindowOpen();
		void clearWindow();
		void displayWindow();
		void centralizarCamera();
		void setWindowTitle(std::string titulo);
	};
}
