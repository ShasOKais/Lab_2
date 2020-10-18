#include <iostream>

using namespace std;
//-------------------------------------------------------------------
/*
  ������������� �������:
  private:
	  ������ ������� � ������� ��� ������������� ������ ������
  public:
	  ������ ������� ��������� ������ �������� � �������� ���������
  protected:
	  ������ �������, ��������� ��� ������������
*/
//-------------------------------------------------------------------
class Darkness { // ��� ������
protected:
	int x, y; // ��������
public: // ������������ �������
	Darkness() { // �����������
		/*
		  ����� ������, ������� ������������ ��� �������������
		  ��������� ������ ���������� ���������� ����������
		*/
		cout << "Darkness()\n"; // ���������� �����
		x = 0; // ��������� ��������
		y = 0;
	}
	Darkness(int x, int y) { // ����������� c ������������
		cout << "Darkness(int x, int y)\n";
		// -> ��������� � ����� ���������
		this->x = x; // this - ��������� �� ������� ������ ������� ������
		this->y = y; // ����� this ����� ���������� ������ ������ � ����� ��� ������
	}
	Darkness(const Darkness& here) { // ���������� �����������
		// ��������� ��� �������� �� ������� ������� ��������
		cout << "Darkness(const Darkness &here)\n";
		x = here.x;
		y = here.y;
	}
	~Darkness() { // ����������
		/*
		  ����� ������, �������� ���
		  ��������������� ������� (������������ ������)
		*/
		cout << "~Darkness() " << x << " " << y << endl;
	}
	void move(int dx, int dy) { // ����� ������
		x = dx + x;
		y = dy + y;
	}
	void reset();
};

void Darkness::reset() {
	x = 0;
	y = 0;
}

class ColoredDarkness : public Darkness { // ����� - ������� ����������� �� ������ Darkness
protected:
	int color; // ��������
public: // ������������ �������
	ColoredDarkness() : Darkness() { // ����������� �������� ������
		cout << "ColoredDarkness()\n";
		color = 0;
	}
	ColoredDarkness(int x, int y, int color) : Darkness(x, y) { // ����������� c ������������ � ����������� Darkness
		cout << "ColoredDarkness(int x, int y)\n";
		// -> ��������� � ����� ���������
		this->color = color; // this - ��������� �� ������� ������ ������� ������
	}
	ColoredDarkness(const ColoredDarkness& here) { // ���������� �����������
		// ��������� ��� �������� �� ������� ������� ��������
		cout << "ColoredDarkness(const ColoredDarkness &here)\n";
		color = here.color;
		x = here.x;
		y = here.y;
	}
	~ColoredDarkness() { // ����������
		/*
		  ����� ������, �������� ���
		  ��������������� ������� (������������ ������)
		*/
		cout << "~ColoredDarkness() " << x << " " << y << " Color = " << color << endl;
	}
	void change_color(int new_color) { // ����� ������
		color = new_color;
	}
};

int main() {

	ColoredDarkness *Ford = new ColoredDarkness(1, 2, 42);
	delete Ford;

	return 0;
}