# Лабораторная работа № 2. «Объекты и Классы»
Тип приложения: консольное; язык: C++.

Определение и реализация тестовых классов, и написание программы, иллюстрирующей их использование (код, делающий нечто, и при этом обязательный отладочный вывод в консоль, для контроля того, какие методы вызываются – особенно важен отладочный вывод во всех конструкторах и деструкторах).

Лабораторная работа может включать несколько программ, не стоит пытаться писать все сразу в одну программу и строго последовательно. Например, сначала стоит написать определение и реализацию простого объекта, создать его статически и динамически, проверить вызов атрибутов и методов. Затем определить конструкторы и деструкторы и проверить их работу. Затем научиться определять классы-наследники. Затем научиться перекрывать методы и создавать виртуальные методы и проверить их использование, и так далее. Настоятельно не рекомендуется в качестве методов использовать переопределяемые операции (++, <<, >> и т.д.).

Рекомендуемые объекты для манипуляций: геометрические фигуры (точки, линии, квадраты, круги, эллипсы), математические объекты (вектора, матрицы) и т.д.
Нерекомендуемые объекты для манипуляций (преподаватель плохо разбирается в этой предметной области, да и надоело): Warrior, Weapon, HP, Damage, и т.д.

*	Определения
    +	классов
    +	атрибутов, методов
    +	классов-наследников
    +	конструкторов (обязательно несколько: без параметров, с параметрами, с параметром-объектом того же класса), деструкторов
    +	доступности атрибутов и методов (показать, как влияют модификаторы private, protected, public)
*	Реализация
    +	методов объектов
    +	реализация методов сразу в определении или после определения
    +	конструкторов, деструкторов
*	Создание и использование (обращение к атрибутам, вызов методов)
    +	статически создаваемых объектов («MyClass obj;»)
    +	динамически создаваемых объектов («MyClass *obj = new MyClass();»)
    +	объектов с помощью различных конструкторов (у каждого создаваемого объекта должны быть: конструктор без параметров, с параметрами, с параметром-объектом того же класса –         конструктор копирования)
    +	помещение объектов в переменные различных типов (объяснять, чем отличается MyBase * obj = new MyBase() от MyBase * obj = new MyDeriv())
    +	объектов классов-наследников (проверить и продемонстрировать, какие конструкторы классов при этом вызываются)
    +	композиция объектов: атрибутом одного объекта класса A является указатель на другой объект класса B, создаваемый в конструкторе класса A и уничтожаемый в деструкторе             класса A; композируемые классы должны определяться отдельно (не один в другом).
*	Уничтожение
    +	статически созданных объектов
    +	динамически созданных объектов
    +	объектов классов-наследников (проверить и продемонстрировать, какие деструкторы классов при этом вызываются)

 Лабораторная работа требует уверенного понимания и работы с указателями. Студенты должны четко понимать всё, что происходит при выполнении строки MyBase * obj = new MyDeriv() (создается переменная-указатель, создается объект в памяти и возвращается его адрес, этот адрес записывается в созданную переменную-указатель).