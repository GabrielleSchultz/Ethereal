#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class Ente;

//gerenciador gráfico baseado no tutorial do Matheus Burda!

//ps:o nome da classe de cada gerenciador se da pela sua funçao
//sua chamada por namespace ja nos diz que se trata de um gerenciador

typedef std::map <const char*, sf::Texture*> MapaTextura;

namespace Gerenciadores
{
	class Grafico
	{
	private:
		MapaTextura CharactersTextures;
		MapaTextura FontTextures;
		sf::RenderWindow* janelaPrincipal;
		sf::View cameraJogo;

		//Padrão de Projeto Singleton:
		Grafico();
		static Gerenciadores::Grafico* instancia_pGG;

	public:
		~Grafico();
		static Grafico* getGerenciador_Grafico();

		//janela e camera
		bool isWindowOpen();
		void clearWindow();
		void displayWindow();
		void centralizarCamera();
		void setWindowTitle(std::string titulo);
		void closeWindow();
		void zoomOut();
		void zoomIn();
		sf::RenderWindow* getWindow();

		//geracao de mundo
		void criarMapa(std::string file_path);

		//render
		void desenharEnte(sf::RectangleShape body);
		void desenharEnte(Ente* pEnte);
		void desenharTexto(sf::Text* texto);

	};
}
