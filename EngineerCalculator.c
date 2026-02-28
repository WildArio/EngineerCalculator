#include <stdio.h>
#include <windows.h>
#include "motor_data.h"

void search_by_power_menu(void);
void search_by_current_menu(void);

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (1) {

        printf("Добро пожаловать!\n");
        printf("Выберите пункт:\n");
        printf("1) Поиск ЭД по мощности.\n");
        printf("2) Поиск ЭД по току.\n");
        printf("3) Выход.\n");
        printf("Введите цирфу необходимого пункта...\n");

        int user_input = 0;

        scanf("%d", &user_input);

        switch (user_input)
        {
        case 1:
            search_by_power_menu();
            break;

        case 2:
            search_by_current_menu();
            break;

        case 3:
            return 0;

        default:
            break;
        }
    }
}

void search_by_power_menu(void) {
    float user_input = 0;

    printf("Чтобы получить характеристики двигателя - введите мощность\n");
    printf("Доступные ступени мощности (кВт):\n");
    printf("----------------------------------------\n");
    printf("0.37   0.55   0.75   1.1    1.5    2.2\n");
    printf("3.0    4.0    5.5    7.5    11.0   15.0\n");
    printf("18.5   22.0   30.0   37.0   45.0   55.0\n");
    printf("75.0   90.0   110.0  132.0  160.0  200.0\n");
    printf("250.0\n");

    scanf("%f", &user_input);
    
    const Motor* new_motor = motor_get_by_power(user_input);

    printf("Параметры полученного электродвигателя:");
    printf("\n-- Мощность: ");
    printf("%.2f", new_motor->power_kw);
    printf("\n-- Напряжение: ");
    printf("%.2f", new_motor->voltage_380v);
    printf("\n-- Номинальный ток: ");
    printf("%.2f", new_motor->nominal_current_a);
    printf("\n-- Коэффициент мощности: ");
    printf("%.2f", new_motor->cos_phi);
    printf("\n-- КПД: ");
    printf("%.2f", new_motor->efficiency_percent);
    printf("\n-- Кратность пускового тока: ");
    printf("%.2f", new_motor->start_current_ratio);

    printf("\n");

    printf("Нажмите Enter чтобы продолжить...");
    getchar();
    getchar();
}

void search_by_current_menu(void) {
    float user_input = 0;

    printf("Чтобы получить характеристики двигателя - введите ток\n");

    scanf("%f", &user_input);
    
    const Motor* new_motor = motor_get_by_current(user_input);

    printf("Параметры полученного электродвигателя:");
    printf("\n-- Мощность: ");
    printf("%.2f", new_motor->power_kw);
    printf("\n-- Напряжение: ");
    printf("%.2f", new_motor->voltage_380v);
    printf("\n-- Номинальный ток: ");
    printf("%.2f", new_motor->nominal_current_a);
    printf("\n-- Коэффициент мощности: ");
    printf("%.2f", new_motor->cos_phi);
    printf("\n-- КПД: ");
    printf("%.2f", new_motor->efficiency_percent);
    printf("\n-- Кратность пускового тока: ");
    printf("%.2f", new_motor->start_current_ratio);

    printf("\n");

    printf("Нажмите Enter чтобы продолжить...");
    getchar();
    getchar();
}