/*** includes ***/

// если в вводимый поток попадеться character - Ctrl-S or Ctrl-
// Ctrl-Q восстанавливает поток 


//iscntrl - проверяет вводимое значение является ли оно котрольным символом
#include <ctype.h>
#include <errno.h>
//perror()
#include <stdio.h>
// atexit()
#include <stdlib.h>
//struct termios, tcgetattr(), tcsetattr(), ECHO, and TCSAFLUSH, ICANON, IEXTEN
#include <termios.h>
#include <unistd.h>

/*** data ***/

struct termios orig_termios;

/*** terminal ***/

void die(const char *s) {
  perror(s);
  exit(1);
}

// отключает сырой мод 
void disableRawMode() {
	// tcsetattr() устанавливает аттрибуты терминала такими, какими мы их нашли
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("tcsetattr");
}

void enableRawMode() {
	// tcgetattr() берет аттрибуты терминала
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
  atexit(disableRawMode);

  struct termios raw = orig_termios;

  // IXON - (Ctrl-S -> 19) останавливает передачу данных на терминал до тех пор, пока вы не нажмете (Ctrl-Q -> 17) || software flow control (xONN | xOFF) || 
  // ICRNL - (Ctrl-M -> 13) перевод коретки в начало строки и на новую строку ('\r\n')
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  // Функция ECHO заставляет каждую введенную вами клавишу печатать на терминал, чтобы вы могли видеть, что вы печатаете
  //ECHO представлен как 00000000000000000000000000001000
  // ~(ECHO) betwise оператор переводит его в это - 11111111111111111111111111110111 
  // будет казаться, будто мы вводим пароль и ничего не видно
  // Это полезно в каноническом режиме, но на самом деле мешает нам, когда мы пытаемся тщательно отобразить пользовательский интерфейс в сыром режиме

  // ISIG - Ctrl-C(terminate -> 3), Ctrl-Z(suspend -> 26) превращает
  // IEXTEN - При сочитании клавиш (Ctrl-V -> 22) ожидает, что вы напечатаете еще одну букву и только потом отправит данные, (Ctrl-O -> 15)
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  //начение VMIN устанавливает минимальное количество байтов ввода, необходимое до возврата функции read ().
  raw.c_cc[VMIN] = 0;

  // Значение VTIME устанавливает максимальное время ожидания перед возвратом функции read (). value /10
  raw.c_cc[VTIME] = 1;


  // Аргумент TCSAFLUSH указывает, когда применять изменение: в этом случае он ожидает, что все ожидающие вывода будут записаны на терминал, а также отбросит любой вход, который не был прочитан.
  // АААА!!! когда мы только начали, выводились оставшиеся буквы после q, а это штука их не показывает ))
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

/*** init ***/

int main() {
  enableRawMode();

  while (1) {
    char c = '\0';
    /* мы просим read() считывать по одному байту и записать в переменную "c",
       каждый раз возвращая количество байтов и вернет 0, если подошли к концу файла
       Однако, мы находимся в куки мод, и данные сохраняются на Enter*/
    		// (STDIN_FILENO) == поток ввода
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d ('%c')\r\n", c, c);
    }

    // выйдет из цикла, если вводимый символ равен = 'q';
    if (c == 'q') break;
  }

  return 0;
}
