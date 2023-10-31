//classe template para substituir sf::Vector e desacoplar SFML
//baseada na classe de Vetores do próprio SFML e na engine GoDot

#include <iostream>
#include <cmath>

namespace Math {

	template <typename T>

	class Vector2D
	{
	//para evitar ter que chamar os gets de x e y os atributos sao publicos
	public:
		T x;
		T y;

	public:
		Vector2D();
		~Vector2D();
		Vector2D(T coord_x, T coord_y);

		//operacao com vetores
		void operator+= (Vector2D<T> other_v);
		void operator-= (Vector2D<T> other_v);
		void operator= (Vector2D<T> other_v);
		//operacao com escalar
		void operator/= (T escalar);
		void operator*= (T escalar);
		void operator= (T escalar);

		//operacao aritmetica com vetores
		Vector2D<T> operator+(Vector2D<T> other_v);
		Vector2D<T> operator-(Vector2D<T> other_v);
		T operator/(Vector2D<T> other_v);
		T operator*(Vector2D<T> other_v);
		///operacao aritmetica com escalar
		Vector2D<T> operator/(T escalar);
		Vector2D<T> operator*(T escalar);

		//operacoes no proprio vetor
		Vector2D<T> operator-() const;
		Vector2D<T> normalize(Vector2D<T> unnormalized_v);
	};

	typedef Vector2D<int> Vector2Di;
	typedef Vector2D<float> Vector2Df;
	typedef Vector2D<double> Vector2Dd;

	template<typename T>
	Vector2D<T>::Vector2D()
	{
		this->x = 0;
		this->y = 0;
	}

	template<typename T>
	Vector2D<T>::~Vector2D(){}

	template<typename T>
	Vector2D<T>::Vector2D(T coord_x, T coord_y): x (coord_x), y(coord_y){}

	template<typename T>
	void Vector2D<T>::operator+=(Vector2D<T> other_v)
	{
		this->x += other_v.x;
		this->y += other_v.y;
	}

	template<typename T>
	void Vector2D<T>::operator-=(Vector2D<T> other_v)
	{
		this->x -= other_v.x;
		this->y -= other_v.y;
	}

	template<typename T>
	void Vector2D<T>::operator=(Vector2D<T> other_v)
	{
		this->x = other_v.x;
		this->y = other_v.y;
	}

	template<typename T>
	void Vector2D<T>::operator/=(T escalar)
	{
		if (escalar == 0)
		{
			std::cout << "Erro ao tentar dividir por zero" << std::endl;
			getchar();
			exit(1);
		}
		this->x /= escalar;
		this->y /= escalar;
	}

	template<typename T>
	void Vector2D<T>::operator*=(T escalar)
	{
		this->x *= escalar;
		this->y *= escalar;
	}

	template<typename T>
	void Vector2D<T>::operator=(T escalar)
	{
		this->x = escalar;
		this->y = escalar;
	}

	template<typename T>
	Vector2D<T> Vector2D<T>::operator+(Vector2D<T> other_v)
	{
		Vector2D<T> vetor;

		vetor.x = (this->x) + (other_v.x);
		vetor.y = (this->y) + (other_v.y);

		return vetor;
	}

	template<typename T>
	Vector2D<T> Vector2D<T>::operator-(Vector2D<T> other_v)
	{
		Vector2D<T> vetor;

		vetor.x = (this->x) - (other_v.x);
		vetor.y = (this->y) - (other_v.y);

		return vetor;
	}

	template<typename T>
	T Vector2D<T>::operator/(Vector2D<T> other_v)
	{
		T produto_interno = 0;

		produto_interno = ((this->x) / (other_v.x));
		produto_interno += ((this->y) / (other_v.y));

		return produto_interno;
	}

	template<typename T>
	T Vector2D<T>::operator*(Vector2D<T> other_v)
	{
		T produto_interno = 0;

		produto_interno = ((this->x) / (other_v.x));
		produto_interno += ((this->y) / (other_v.y));

		return produto_interno;
	}

	template<typename T>
	Vector2D<T> Vector2D<T>::operator/(T escalar)
	{
		Vector2D<T> vetor;

		vetor.x = (this->x) * escalar;
		vetor.y = (this->y) * escalar;

		return vetor;
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator*(T escalar)
	{
		Vector2D<T> vetor;

		vetor.x = (this->x) / escalar;
		vetor.y = (this->y) / escalar;

		return vetor;
	}

	template<typename T>
	Vector2D<T> Vector2D<T>::operator-() const
	{
		Vector2D<T> vetor;

		vetor.x = (this->x) * -1;
		vetor.y = (this->y) * -1;

		return vetor;
	}

	//retorna a direcao, mas evitar a chamada dessa funcao por conta do custo
	template<typename T>
	Vector2D<T> Vector2D<T>::normalize(Vector2D<T> unnormalized_v)
	{
		Vector2D<T> vetor_normalizado;

		T modulo = sqrt((unnormalized_v.x * unnormalized_v.x)
		+ (unnormalized_v.y * unnormalized_v.y));
		
		vetor_normalizado.x = unnormalized_v.x / modulo;
		vetor_normalizado.y = unnormalized_v.y / modulo;

		return vetor_normalizado;
	}

}