#include <iostream>
#include <fstream>
#include <string>

enum State
{
    S0,
    S1,
    S2,
    S3,
    ERROR
};

State changeState(State currentState, char symbol)
{
    switch (currentState)
    {
    case S0:
        if (symbol == '1')
        {
            std::cout << "S0 -> S1\n";
            return S1;
        }
        else if (symbol == '2')
        {
			std::cout << "S0 -> S2\n";
			return S2;
        }
		else if (symbol == '3')
		{
			std::cout << "S0 -> S3\n";
			return S3;
		}
        std::cout << "Ошибка в S0\n";
        return ERROR;
    case S1:
        if (symbol == '1')
        {
            std::cout << "S1 -> S1\n";
            return S1;
        }
        else if (symbol == '2')
        {
            std::cout << "S1 -> S2\n";
            return S2;
        }
        else if (symbol == '3')
        {
            std::cout << "S1 -> S3\n";
            return S3;
        }
        std::cout << "Ошибка в S1\n";
        return ERROR;
    case S2:
        if (symbol == '2')
        {
            std::cout << "S2 -> S2\n";
            return S2;
        }
        if (symbol == '3')
        {
            std::cout << "S2 -> S3\n";
            return S3;
        }
        std::cout << "Ошибка в S2\n";
        return ERROR;
    case S3:
        if (symbol == '3')
        {
            std::cout << "S3 -> S3\n";
            return S3;
        }
        std::cout << "Ошибка в S3\n";
        return ERROR;
    default:
        std::cout << "Неизвестное состояние\n";
        return ERROR;
    }
}

bool checkStates(const std::string& line)
{
    State currentState = S0;
    for (char symbol : line)
    {
        currentState = changeState(currentState, symbol);
        if (currentState == ERROR)
        {
            return false;
        }
    }
    return currentState == S1 || currentState == S2 || currentState == S3;
}

int main()
{
    std::ifstream test_file("test.txt");
    std::string line;

    while (std::getline(test_file, line))
    {
        if (checkStates(line))
        {
            std::cout << "Строка " << line << " правильная\n\n";
        }
        else
        {
            std::cout << "Строка " << line << " неправильная\n\n";
        }
    }
    test_file.close();
}
