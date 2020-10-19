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

class Section { // имя класса
protected:
	Darkness *p1;
	Darkness *p2;
public: // спецификатор доступа
	Section() { // конструктор
		/*
		  метод класса, который предназначен для инициализации
		  элементов класса некоторыми начальными значениями
		*/
		cout << "Section()\n"; // отладочный вывод
		p1 = new Darkness;
		p2 = new Darkness;
	}
	Section(int x1, int y1, int x2, int y2) { // конструктор c параментрами
		cout << "Section(int x1, int y1, int x2, int y2)\n";
		p1 = new Darkness(x1, y1);
		p2 = new Darkness(x2, y2);
	}
	Section(const Section& s) { // копирующий конструктор
		// Переносит все свойства из объекта которое передали
		cout << "Section(const Section &here)\n";
		p1 = new Darkness(*(s.p1));
		p2 = new Darkness(*(s.p2));
	}
	~Section() { // деструктор
		/*
		  метод класса, служащий для
		  деинициализации объекта (освобождение памяти)
		*/
		//cout << "~Section() " << x << " " << y << endl;
		delete p1;
		delete p2;
	}
};

int main() {
	Section *Ford = new Section;         // работают одинаково, но
	Section* Ford1 = new Section(*Ford); // вызываются разные деструкторы
	delete Ford;                                    
	delete Ford1;
	return 0;
}