# Keyboard Dictionary

Программа, анализирует словарь английских слов и определяет, сколько из них могут быть набраны на QWERTY-клавиатуре с английским языком, передвигаясь только по смежным клавишам.

При этом можно нажимать одну и ту же клавишу дважды подряд.

#### Запуск программы ####
Чтобы запустить программу, укажите путь к файлу со списком английских слов, которые нужно проверить в <b>keyboardDictionary.h</b>, например:

``` #define FILE_NAME "tests/dictionary.txt" ```

Затем введите в командную строку:

```make```

```./start```
 

#### Условия: ####

* Входные данные: файл со списком английских слов (одно слово на строку).

* Раскладка клавиатуры: стандартная английская QWERTY.

* Клавиши считаются смежными, если они находятся горизонтально или вертикально рядом друг с другом.
Диагональное расположение также считается смежным, но только для клавиш, имеющих общие грани. Так, 's' и 'w', а также 's' и 'z' считаются смежными, но 's' и 'q' - не считаются смежными.

* Каждую клавишу можно нажимать дважды подряд.

 
Задача – посчитать и вывести количество английских слов, которые можно набрать, используя только смежные клавиши на QWERTY-клавиатуре.
 

Файл со словами можно взять любой из открытых источников, регистр букв значения не имеет.

![keypad](img/keypad.png)
