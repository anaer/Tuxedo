#include "public.h"
int    GLogLevel=0; /*����־�ļ���. ����־�ļ�����:0,1,2�� 0�������*/
char GLogFile[100]= "../log/serv%s.log";

char *GetTimeChar()
{
    int    year = 0;
    static char tt[20] = "";
    struct tm t;
    time_t now;

    time(&now);
    t = *localtime(&now);
    year=t.tm_year;
        if (year<50)
                year+=2000;
        else
                year+=1900;
    sprintf(tt,"%04d-%02d-%02d %02d:%02d:%02d",year,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
    return tt;
}

/***************************************************************************
��������:WriteLog
��������:д��־�ļ�
�������:filename:�ļ�����format:����
�������:��
�� �� ֵ:0:��ȷ������:ʧ��
***************************************************************************/
int WriteLog(int LogLevel,char * format,...)
{
    FILE * fp;
    va_list args;
    char *ttime     = NULL;
    char ddate[9]="";
    char LogPath[50]="";
    
    ttime=GetTimeChar();
    strncpy(ddate,ttime,4);
    strncat(ddate,(ttime+5),2);
    strncat(ddate,(ttime+8),2);
    sprintf(LogPath,GLogFile,ddate);

    if (LogLevel<=GLogLevel)
    {
        if((fp=fopen(LogPath,"a+"))==NULL)
        {
            perror("Create or Open LogFile Error! GLogFile\n");
            return -1;
        }
        fprintf(fp,"[%s]",GetTimeChar());
        va_start(args,format);
        vfprintf(fp,format,args);
        va_end(args);
        va_start(args,format);
        vprintf(format,args);   
        va_end(args);
        fclose(fp);
    }
    return 0;
}
