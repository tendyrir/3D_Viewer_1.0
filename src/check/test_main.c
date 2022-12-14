#include <stdlib.h>

#include "./test.h"

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(NULL);

  /* ОТКРЫТИЕ ФАЙЛА */
  srunner_add_suite(sr, suite_open_file());
  // srunner_add_suite(sr, suite_count_data());
  






  // Должно быть обеспечено покрытие unit-тестами модулей, связанных с загрузкой моделей и аффинными преобразованиями

  // В один момент времени должна быть только одна модель на экране.

  // Программа должна корректно обрабатывать и позволять пользователю просматривать модели с деталями до 100, 1000, 10 000, 100 000, 1 000 000 вершин без зависания (зависание - это бездействие интерфейса более 0,5 секунды).

//   srunner_add_suite(sr, other_suite());
//   srunner_add_suite(sr, transform_suite());

  srunner_set_fork_status(sr, CK_NOFORK);
  // Используем данный блок для вывода подробно про каждый тест с разбиением по
  // блокам

  srunner_set_log(sr, "-");
  srunner_run_all(sr, CK_SILENT);

  // CK_SILENT || CK_MINIMAL || CK_NORMAL || CK_VERBOSE Либо данный блок вместо
  // предыдущего для вывода только ошибок и общего результата
  // srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);

  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}