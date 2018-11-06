// Bosco Lo - Fall 2018 - 11:51 PM 05 Nov 2018 - C programming for fun - All rights reserved
#include <stdio.h>
#include <time.h>

void seconds_from_start_of_month(time_t now);
void show_GMT_and_EDT_time(time_t rawtime);

int main() {

time_t now, rawtime;
seconds_from_start_of_month(now);
show_GMT_and_EDT_time(rawtime);
  
}

void seconds_from_start_of_month(time_t now) {
  now = time(&now);
  struct tm beginning_month = *localtime(&now);
  beginning_month.tm_hour = 0;
  beginning_month.tm_min = 0;
  beginning_month.tm_sec = 0;
  beginning_month.tm_mday = 0;
 
  double seconds = difftime(now, mktime(&beginning_month));
  printf("%.0f seconds from first day of the month.\n\n", seconds-18000);
}

void show_GMT_and_EDT_time(time_t rawtime) {
  char text[90];
  rawtime = time(NULL); // time_t now = time(NULL);
  time(&rawtime); // not necessary on this comment option
  struct tm *current_time = localtime(&rawtime); // struct tm *current_time = localtime(&now);

  int h = ((rawtime - 18000) / 3600) % 24;
  int m = (rawtime / 60) % 60;
  int s = rawtime % 60;

  strftime(text, sizeof(text), "%a, %d %b %Y at %H:%M:%S %Z", current_time);
  printf("Current Date & Time: %s or %02d:%02d:%02d EDT", text, h, m, s);
}
