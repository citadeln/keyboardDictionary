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
  ck_assert_int_eq(areAdjacent('q', '1'), false);
  ck_assert_int_eq(areAdjacent(' ', 'a'), false);
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

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
    printf("qqq");
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = keyboard_suite();
  sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("========= FAILED: %d =========\n", number_failed);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
