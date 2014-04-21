#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int dayofweek(int day);
void showusage(void);

int main(int argc, char *argv[])
{
  if (argc != 4)
    {
      puts("Your input was wrong.");
      showusage();
      exit(1);
    }
  
  time_t now, termbegin_sec;
  int cal_diffdays, weeks; 		// cal_diffdays is not real diffdays.
  now = time(0);
  
  struct  tm termbegin = {0, 0, 0, atoi(argv[1]), atoi(argv[2])-1, atoi(argv[3])-1900, 0, 0, 0};
  termbegin_sec = mktime(&termbegin);
  termbegin = *localtime(&termbegin_sec);		// last two expressions add day of week to termbegin
 
  cal_diffdays = (int)((now - termbegin_sec)/(60*60*24)) + dayofweek(termbegin.tm_wday);		// cal_diffdays from first week's Monday.
  weeks = cal_diffdays/7 + ((cal_diffdays%7)?1:0);		// odd out of 7 is a week
  printf("Today is week %d from term beginning.\n", weeks);

  return 0;
}

int dayofweek(int day)
{
  if (day)
    return day;
  return 7;
}

void showusage(void)
{
  puts("\nUsage: ProgramName dd mm yyyy");
  puts("\nNotice: This date should be the date of the term's beginning");
}
