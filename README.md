# AccountInfo

Dana jest klasa account_info zawierająca numer konta bankowego, nazwisko właściciela i stan konta. Napisz program, który tworzy, inicjalizuje i drukuje tablicę kont (obiektów typu account_info) a następnie sprawdza stan kolejnych kont. Jeżeli stan konta jest ujemny, to generowany jest wyjątek negative_balance_exception (podklasy std::out_of_range). Obsługa wyjątku powinna polegać na wydrukowaniu nazwy wyjątku i wielkości deficytu na koncie, który spowodował wygenerowanie wyjątku (wykorzystaj nadpisaną w klasie wyjątku funkcję what()).

Przykładowy wynik działania programu:

![image](https://user-images.githubusercontent.com/51761120/172724001-09e75c1c-f3e0-4ff3-9394-d0e2585288c3.png)
