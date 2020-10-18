#include <iostream>

using namespace std;
//-------------------------------------------------------------------
/*
  Спецификаторы доступа:
  private:
	  список свойств и методов для использования внутри класса
  public:
	  список методов доступных другим функциям и объектам программы
  protected:
	  список средств, доступных при наследовании
*/
//-------------------------------------------------------------------
class Darkness { // имя класса
protected:
	int x, y; // атрибуты
public: // спецификатор доступа
	Darkness() { // конструктор
		/*
		  метод класса, который предназначен для инициализации
		  элементов класса некоторыми начальными значениями
		*/
		cout << "Darkness()\n"; // отладочный вывод
		x = 0; // начальные значения
		y = 0;
	}
	Darkness(int x, int y) { // конструктор c параментрами
		cout << "Darkness(int x, int y)\n";
		// -> обращение к члену структуры
		this->x = x; // this - указатель на текущий объект данного класса
		this->y = y; // через this можно обращаться внутри класса к любым его членам
	}
	Darkness(const Darkness& here) { // копирующий конструктор
		// Переносит все свойства из объекта которое передали
		cout << "Darkness(const Darkness &here)\n";
		x = here.x;
		y = here.y;
	}
	~Darkness() { // деструктор
		/*
		  метод класса, служащий для
		  деинициализации объекта (освобождение памяти)
		*/
		cout << "~Darkness() " << x << " " << y << endl;
	}
	void move(int dx, int dy) { // метод класса
		x = dx + x;
		y = dy + y;
	}
	void reset();
};

void Darkness::reset() {
	x = 0;
	y = 0;
}

class ColoredDarkness : public Darkness { // класс - потомок наследуется от класса Darkness
protected:
	int color; // атрибуты
public: // спецификатор доступа
	ColoredDarkness() : Darkness() { // конструктор базового класса
		cout << "ColoredDarkness()\n";
		color = 0;
	}
	ColoredDarkness(int x, int y, int color) : Darkness(x, y) { // конструктор c параментрами с параметрами Darkness
		cout << "ColoredDarkness(int x, int y)\n";
		// -> обращение к члену структуры
		this->color = color; // this - указатель на текущий объект данного класса
	}
	ColoredDarkness(const ColoredDarkness& here) { // копирующий конструктор
		// Переносит все свойства из объекта которое передали
		cout << "ColoredDarkness(const ColoredDarkness &here)\n";
		color = here.color;
		x = here.x;
		y = here.y;
	}
	~ColoredDarkness() { // деструктор
		/*
		  метод класса, служащий для
		  деинициализации объекта (освобождение памяти)
		*/
		cout << "~ColoredDarkness() " << x << " " << y << " Color = " << color << endl;
	}
	void change_color(int new_color) { // метод класса
		color = new_color;
	}
};

int main() {

	ColoredDarkness *Ford = new ColoredDarkness(1, 2, 42);
	delete Ford;

	return 0;
}