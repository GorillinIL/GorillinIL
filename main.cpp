#include <iostream>
#include <string>
#include <ctime>
#include <clocale>
#include <cstdlib>
using namespace std;

int main()
{
	//Добавление русской локали на вывод
	setlocale(LC_ALL, "Russian");
	//Посев генератора случайных чисел
	srand(time(0));
	//Переменные:
	//Символ активации игры
	char symbolStart = 'E';
	//Кнопка действия за Джона
	char startJhon = 'J';
	//Кнопка действия за Дэвида
	char startDevid = 'D';
	//ХП "героя игрока"
	int hpHeroPlayer = 100;
	//Нанесенный урон "героем игрока"
	int damageHeroPlayer;
	//ХП "героя ПК"
	int hpHerroPC = 100;
	//Нанесенный урон "героя ПК"
	int damageHeroPc;
	//Результат урона Джона
	int resultDamageJhon = 0;
	//Результат урона Дэвида
	int resulDamagetDevid = 0;
	//Имя "гладиатора игрока" (Джон)
	string gladiatorPL = "Джон";
	//Имя "гладиатора ПК" (Дэвид)
	string gladiatorPC = "Дэвид";
	//Уклонение - бьет Джон (Дэвид)
	int ddeadsingPl = 0;
	//Уклонение - бьет Дэвид (Джон)
	int ddeadsingPc = 0;
	//Флаг появления принцесссы
	bool princess = true;
	//Флаг зелья лечения
	bool potionHealth = false;
	//Кол-во ед. лечения от зелья
	int potionGame = 7;
	//Флаг использования зелья
	bool potionUsed = false;
	//Выбор героя
	int enterHero;
	//Ввод пользователя
	bool enterPlayerHero;
	
	//Основная информация (главное меню)
	cout << "\n\t\t\t\t            ### Добро пожаловать в игру: ### \n\n\t\t\t\t                   --- ГЛАДИАТОРЫ ---\n\n \n\t\t     /// Здесь вы сможете наблюдать со стороны за боем двух гладиаторов на арене /// \n\n\t\t     /// Кто победит угадать невозможно, система все расчитывает случайным образом ///" << endl;
	cout << "\nВыберите героя, который по вашему мнению должен победить: " << endl;
	cout << "\nВведите цифру героя, за которого будете болеть: \n1: Джон. \n2: Дэвид." << endl;
	//Выбор героя игроком
	cin >> enterHero;
	
	//Цикл с проверкой ввода игрока на выбор героя
	while (true)
	{

		if (enterHero == 1)
		{
			cout << "Вы считаете, что Джон сможет победить в этом бою." << endl;
			break;
		}
		else if (enterHero == 2)
		{
			cout << "Вы считаете, что Дэвид сможет победить в этом бою." << endl;
			break;
		}
		else if (enterHero != 1 && enterHero != 2)
		{
			cout << "Неверное значение, попробуйте еще. Введите 1 - Джон или 2 - Дэвид." << endl;
			cin >> enterHero;
		}
	}

	//Основной игровой цикл
	do
	{

		cout << "\n\n\t\t\t\t\t Введите символ 'J' \n\n\t\t\t\t### Чтобы сделать ход за Джона ### - " << endl;
		//Ход за Джона
		cin >> startJhon;

		//Провека в цикле на неверный ввод
		do
		{
			if (startJhon != 'J')
			{
				cout << "\n::: Неверный символ, попробуйте снова :::\n" << endl;
				cin >> startJhon;
			}
		} while (startJhon != 'J');

		//Рандом на уклонение Дэвида (Удар Джона)
		bool deadsingPl = rand() % 2 == 0;

		//Проверка срабатывания уклонения и дальнейший урон с учетом уклонения + вывод информации боя
		if (deadsingPl == true)
		{
			ddeadsingPc = damageHeroPlayer = rand() % 12 + 6;
			cout << "\n*** Потенциальный урон *** = " << ddeadsingPc << " ед." << endl;
			cout << "\n*** Уклонение! Урон режется вдвое! ***" << endl;
			ddeadsingPc = ddeadsingPc/2;
			resultDamageJhon += ddeadsingPc;
			hpHerroPC -= ddeadsingPc;
			cout << "\n***** Теперь Джон нанесет всего лишь ***** " << ddeadsingPc<< " ед. урона" << endl;
			cout << "\n\v\v<<< Джон наносит удар и... " << gladiatorPC << " увернулся! >>> \n\n||| Джон нанес: " << ddeadsingPc << " ед. урона по Дэвиду |||" << endl;
			cout << "\n||| Здоровья остается у - " << gladiatorPC << " - в количестве: " << hpHerroPC << " ед. |||" << endl;
		}
		else
		{
			resultDamageJhon += damageHeroPlayer = rand() % 12 + 6;
			hpHerroPC -= damageHeroPlayer;
			cout << "\n<<< Удар наносит " << gladiatorPL << " и его урон равен >>> " << damageHeroPlayer << " ед." << endl;
			cout << "\n||| Здоровья остается у игрока - " << gladiatorPC << " - в количестве: " << hpHerroPC << " ед. |||" << endl;
		}

		//Проверка на уровень ХП игроков (Выход из цикла при 0)
		if (hpHeroPlayer <= 0 || hpHerroPC <= 0)
			break;

			cout << "\n\n\t\t\t\t\t Введите символ 'D' \n\n\t\t\t\t ### Чтобы сделать ход за Дэвида ### - " << endl;
			//Ход за Дэвида
			cin >> startDevid;

			//Проверка на неверный ввод символа от пользователя
			do
			{
				if (startDevid != 'D')
				{
					cout << "\n::: Неверный символ, попробуйте снова :::\n" << endl;
					cin >> startDevid;
				}
			} while (startDevid != 'D');

			//Переменная с рандомным значение true или false для уклонения Джона
		bool deadsingPC = rand() % 2 == 0;

		//Проверка уклонения с последующем уроном и выводом информации по бою
		if (deadsingPC == true)
		{
			ddeadsingPl = damageHeroPc = rand() % 12 + 6;
			cout << "\n*** Потенциальный урон *** = " << ddeadsingPl << " ед." << endl;
			cout << "\n*** Уклонение! Урон режется вдвое ***" << endl;
			ddeadsingPl = ddeadsingPl/2;
			resulDamagetDevid += ddeadsingPl;
			hpHeroPlayer -= ddeadsingPl;
			cout << "\n***** Теперь Дэвид наносит всего ***** " << ddeadsingPl << " ед. урона" << endl;
			cout << "\n\v\v<<< Удар наносит " << gladiatorPC << ", НО ДЖОН СМОГ УВЕРНУТЬСЯ! >>> \n\n||| Дэвид нанес: " << ddeadsingPl << " ед. урона по противнику |||" << endl;
			cout << "\n||| Здоровья остается у игрока " << gladiatorPL << " в количестве: " << hpHeroPlayer << " ед. |||" << endl;
		}
		else
		{
			resulDamagetDevid += damageHeroPc = rand() % 12 + 6;
			hpHeroPlayer -= damageHeroPc;
			cout << "\n<<< Удар наносит " << gladiatorPC << " ого, он  смог нанести >>> " << damageHeroPc << " ед. урона противнику" << endl;
			cout << "\n||| Здоровья остается у игрока " << gladiatorPL << " в количестве: " << hpHeroPlayer << " ед. |||\n" << endl;
		}

		//Появление принцессы с зельем (Есть принцесса и зелье не активировано)
		if (princess && !potionUsed)
		{
			//Вручение зелья рандомному игроку
			potionHealth = rand() % 2 == 0;
			cout << "\n\t\t\t\t\t\t\t\t\t       ***** Появилась принцесса! *****\n\n\t\t\t\t\t\t\t\t       <<< У нее в руках зелье исцеления на: " << potionGame << " ед. >>>" << "\n\n\t\t\t\t\t\t\t\t\t         <<< Кому она его отдаст? >>>\n" << endl;
			princess = false;

			//Проверка на рандом зелья (Кто из игроков получает зелье?)
			if (potionHealth == false)
			{
				hpHeroPlayer += potionGame;
				cout << "\n\v<<< Зелье получает " << gladiatorPL << " >>> \n||| Теперь его здоровье - " << hpHeroPlayer << " ед. |||" << endl;
			}
			else
			{
				hpHerroPC += potionGame;
				cout << "\n\v<<< Зелье получает " << gladiatorPC << " >>> \n||| Теперь его здоровье = " << hpHerroPC << " ед. |||" << endl;
			}
			//Два флага для принцессы и зелья (Принцесса больше не появится, зелье было активировано)
			potionUsed = true;
			princess = false;
		}
		
		//Ветвление (проверка) на критический урон
		//Если ХП менее 40ед. то урон у игрока повышается с учетом рандома
		if (hpHeroPlayer < 40)
		{
			damageHeroPlayer = rand() % 18 + 9;
		}
		else
		{
			damageHeroPlayer= rand() % 12 + 6;
		}

		if (hpHerroPC < 40)
		{
			damageHeroPc = rand() % 18 + 9;
		}
		else
		{
			damageHeroPc = rand() % 12 + 6;
		}

		if (hpHeroPlayer < 40 && hpHerroPC < 40)
		{
			damageHeroPlayer= rand() % 18 + 9;
			damageHeroPc = rand() % 18 + 9;
		}
		
	
	} while (hpHeroPlayer>0&&hpHerroPC>0);

	//Проверка результата боя и вывода основной информации по игре
	if (hpHeroPlayer <= 0)
	{
		cout << "\n\v\v\v<<<<< В этом бою побеждает: " << gladiatorPC << " >>>>> \n##### Он нанес: " << resulDamagetDevid << " ед. урона #####" << "\n||||| Здоровья у Дэвида осталось: " << hpHerroPC << " ед. |||||\n\v\v\v" << endl;
		enterPlayerHero = false;
	}
	else if (hpHerroPC <= 0)
	{
		cout << "\n\v\v\v<<<<< В этом бою побеждает: " << gladiatorPL << " >>>>> \n##### Он смог нанести: " << resultDamageJhon << " ед. урона #####" << "\n||||| Здоровья же у Джона осталось: " << hpHeroPlayer << " ед. |||||\n\v\v\v" << endl;
		enterPlayerHero = true;
	}

	//Проверка на прогноз игрока по бою
	if (enterPlayerHero == true && enterHero == 1)
	{
		cout << "Вы победили! Ваш прогноз оказался верным!\nПобедил Джон!" << endl;
	}
	else if (enterPlayerHero == false && enterHero == 2)
	{
		cout << "Вы победили! Ваш прогноз оказался верным!\nПобедил Дэвид!" << endl;
	}
	else
	{
		cout << "Вы проиграли! Ваш прогноз оказался неверным." << endl;
	}

	return 0;

}
