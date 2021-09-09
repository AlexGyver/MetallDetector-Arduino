[![AlexGyver YouTube](http://alexgyver.ru/git_banner.jpg)](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
# Металлоискатель на Arduino
* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Материалы и компоненты](#chapter-3)
* [Настройка и использование](#chapter-4)
* [FAQ](#chapter-5)
* [Полезная информация](#chapter-6)
* [Мой сайт](http://alexgyver.ru/)
* [Основной YouTube канал](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
* [YouTube канал про Arduino](https://www.youtube.com/channel/UC4axiS76D784-ofoTdo5zOA?sub_confirmation=1)

<a id="chapter-0"></a>
## Описание проекта
- Принцип работы: колебательный контур, частота которого зависит от индуктивности катушки. Arduino следит за изменениями частоты
- Статический режим: по нажатию на кнопку запоминается текущая частота, пищит когда есть отклонение
- Динамический режим: частота постоянно стремится к текущей, реагирует только на резкое появление металла
- Подробности в видео: https://youtu.be/ax87lBtabpQ

<a id="chapter-1"></a>
## Папки
- **metall_detector** - прошивка для Arduino, файл в папке открыть в Arduino IDE (читай [FAQ](#chapter-5))
- **schemes** - схемы к проекту

<a id="chapter-2"></a>
## Схема генератора
![СХЕМА](https://github.com/AlexGyver/MetallDetector-Arduino/blob/master/schemes/generator2.png)

## Макет генератора
![СХЕМА](https://github.com/AlexGyver/MetallDetector-Arduino/blob/master/schemes/maket.jpg)

## Схема блока электроники
![СХЕМА](https://github.com/AlexGyver/MetallDetector-Arduino/blob/master/schemes/scheme2.jpg)

## Компоновка
![СХЕМА](https://github.com/AlexGyver/MetallDetector-Arduino/blob/master/schemes/comp.jpg)

<a id="chapter-3"></a>
## Материалы и компоненты
Если товар закончился, то почти всё указанное ниже можно найти здесь http://alexgyver.ru/arduino_shop/ или здесь http://alexgyver.ru/electronics/

Блок электроники:
* Arduino NANO 328p – искать
* https://ali.ski/Xlrkkl
* https://ali.ski/mbu6K
* https://ali.ski/TkMuh
* https://ali.ski/SGi6ZD
* Потенциометр 10к https://ali.ski/Iny6Cm
* Усилитель
* https://ali.ski/4vIcj-
* https://ali.ski/5xO_UP
* Динамик https://ali.ski/rEb7l
* Аудио гнездо https://ali.ski/AsYper
* Тумблеры https://ali.ski/PtJ6F
* Адаптер на Крону https://ali.ski/cXhZXv
* Рассыпуха:
* Кондеры: 100n – 2шт
* 22n – 2шт
* Транзистор BC547
* Резисторы:
* 1.2k – 1шт
* 10k – 2шт
* Кнопки можно найти тут https://www.chipdip.ru/catalog/switches-buttons

Рассыпуха:  
* Кондеры: 
100n - 2шт  
22n - 2шт  
* Транзистор BC547
* Резисторы:  
1.2k - 1шт  
10k - 2шт  
* Кнопки можно найти тут https://www.chipdip.ru/catalog/switches-buttons

## Вам скорее всего пригодится
* [Всё для пайки (паяльники и примочки)](http://alexgyver.ru/all-for-soldering/)
* [Недорогие инструменты](http://alexgyver.ru/my_instruments/)
* [Все существующие модули и сенсоры Arduino](http://alexgyver.ru/arduino_shop/)
* [Электронные компоненты](http://alexgyver.ru/electronics/)
* [Аккумуляторы и зарядные модули](http://alexgyver.ru/18650/)

<a id="chapter-4"></a>
## Настройка и использование
* [Загрузка прошивки](http://alexgyver.ru/arduino-first/) - ультра подробная статья по началу работы с Ардуино

## Настройки в коде
    sound 1                // 0 - в стиле счётчика гейгера, 1 - пищалка верещалка
    default_mode 1         // если нет переключателя режимов, то по умолчанию стоит: 1 - статический, 0 - динамический
    sens_change 1          // 0 - нет регулировки чувствительности, 1 - есть
    SENSITIVITY = 1000.0;  // ручная установка чувствительности


<a id="chapter-5"></a>
## FAQ
### Основные вопросы
В: Как скачать с этого грёбаного сайта?  
О: На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**

В: Скачался какой то файл .zip, куда его теперь?
О: Это архив. Можно открыть стандартными средствами Windows, но думаю у всех на компьютере установлен WinRAR, архив нужно правой кнопкой и извлечь.

В: Я совсем новичок! Что мне делать с Ардуиной, где взять все программы?  
О: Читай и смотри видос http://alexgyver.ru/arduino-first/

В: Компьютер никак не реагирует на подключение Ардуины!  
О: Возможно у тебя зарядный USB кабель, а нужен именно data-кабель, по которому можно данные передавать

В: Ошибка! Скетч не компилируется!  
О: Путь к скетчу не должен содержать кириллицу. Положи его в корень диска.

В: Сколько стоит?  
О: Ничего не продаю.

### Вопросы по этому проекту
<a id="chapter-6"></a>
## Полезная информация
* [Мои видеоуроки по пайке](https://www.youtube.com/playlist?list=PLOT_HeyBraBuMIwfSYu7kCKXxQGsUKcqR)
* [Мои видеоуроки по Arduino](http://alexgyver.ru/arduino_lessons/)