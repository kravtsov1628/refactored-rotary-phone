# Практическая работа №7

Проект содержит 3 независимые части тестирования по требованиям лабораторной:

- `assert_project` — задание 1, тестирование через `assert`
- `ctest_project` — задание 2, тестирование через `ctest` (3 отдельных теста)
- `gtest_project` — задания 3-8, тестирование через `GoogleTest` (все тесты в одном файле)

## Требования

- CMake (версия 3.16+)
- Компилятор C++ с поддержкой C++17
- Доступ в интернет при первой конфигурации (для загрузки GoogleTest через `FetchContent`)

## Сборка и запуск (только из корня проекта)

Все команды выполняются из папки `Practise7`.

### 1) Конфигурация

```powershell
cmake --preset one
```

### 2) Сборка

```powershell
cmake --build --preset one-build
```

### 3) Запуск всех тестов

```powershell
ctest --preset one-test
```

Эта команда запускает:

- `assert`-тесты из `assert_project`
- `ctest`-тесты из `ctest_project`
- `gtest`-тесты из `gtest_project`

## Полезные команды

Запуск с подробным выводом при падении тестов:

```powershell
ctest --preset one-test --output-on-failure
```

Пересборка после изменений:

```powershell
cmake --build --preset one-build
ctest --preset one-test
```
