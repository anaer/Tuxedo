#ifndef __PUBLIC_H__
#define __PUBLIC_H__
#include "ctype.h"
#include <stdio.h>
#include <stdlib.h>    
#include <sqlca.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <assert.h>    
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
char *GetTimeChar();
int WriteLog(int LogLevel,char * format,...);
#endif  /* __PUBLIC.H__*/ 
