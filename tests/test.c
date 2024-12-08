#include "test.h"

START_TEST(test_areAdjacent_same_keys) {
    ck_assert_int_eq(areAdjacent('a', 'a'), true);
}

START_TEST(test_areAdjacent_adjacent_keys) {
    ck_assert_int_eq(areAdjacent('a', 's'), true);
    ck_assert_int_eq(areAdjacent('s', 'd'), true);
    ck_assert_int_eq(areAdjacent('q', 'w'), true);
    ck_assert_int_eq(areAdjacent('u', 'i'), true);
}

START_TEST(test_areAdjacent_non_adjacent_keys) {
    ck_assert_int_eq(areAdjacent('a', 'd'), false);
    ck_assert_int_eq(areAdjacent('q', 'e'), false);
    ck_assert_int_eq(areAdjacent('z', 'x'), true);
    ck_assert_int_eq(areAdjacent('m', 'n'), false);
}

START_TEST(test_areAdjacent_edge_cases) {
    ck_assert_int_eq(areAdjacent('q', '1'), false); // Не допустимый символ
    ck_assert_int_eq(areAdjacent(' ', 'a'), false); // Не допустимый символ
}

START_TEST(test_isValidChar_valid_chars) {
    ck_assert_int_eq(isValidChar('a'), true);
    ck_assert_int_eq(isValidChar('Z'), true);
    ck_assert_int_eq(isValidChar('-'), true);
    ck_assert_int_eq(isValidChar('\''), true);
}

START_TEST(test_isValidChar_invalid_chars) {
    ck_assert_int_eq(isValidChar('1'), false);
    ck_assert_int_eq(isValidChar('#'), false);
    ck_assert_int_eq(isValidChar(' '), false);
}

// Тесты для функции main (проверка на количество валидных слов)
START_TEST(test_main_valid_words_count) {
    // Здесь вы можете создать временный файл с тестовыми данными,
    // запустить main и проверить количество валидных слов.
    
    // Пример:
    FILE *file = fopen("test_file.txt", "w");
    fprintf(file, "hello\nworld\nqwerty\n");
    fclose(file);

    int result = system("./your_program_name test_file.txt"); // Запуск вашей программы с файлом
    // Здесь необходимо обработать результат и проверить, что он соответствует ожидаемому количеству слов

    // Удаление временного файла
    remove("test_file.txt");
}

START_TEST(test_main_invalid_words_count) {
    // Создание файла с невалидными словами
    FILE *file = fopen("invalid_test_file.txt", "w");
    fprintf(file, "hello1\nworld#\nqw@rty\n");
    fclose(file);

    int result = system("./your_program_name invalid_test_file.txt"); // Запуск вашей программы с файлом
    // Обработка результата

    remove("invalid_test_file.txt");
}

// Функция для создания тестового набора
Suite *keyboard_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Keyboard");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_areAdjacent_same_keys);
    tcase_add_test(tc_core, test_areAdjacent_adjacent_keys);
    tcase_add_test(tc_core, test_areAdjacent_non_adjacent_keys);
    tcase_add_test(tc_core, test_areAdjacent_edge_cases);

    tcase_add_test(tc_core, test_isValidChar_valid_chars);
    tcase_add_test(tc_core, test_isValidChar_invalid_chars);

    tcase_add_test(tc_core, test_main_valid_words_count);
    tcase_add_test(tc_core, test_main_invalid_words_count);

    suite_add_tcase(s, tc_core);

    return s;
}

// Основная функция для запуска тестов
int main(void) {
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = keyboard_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);

   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
