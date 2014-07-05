#include <stdio.h>
#include "atmi.h" /*����TUXEDOϵͳ��ͷ�ļ�"atmi.h", �Ա�����TUXEDO�ĺ����ͱ������塣*/
#include <sys/timeb.h>
#define ALLOClEN 80 /*��������ͷ��صĳ���*/ 


void check(char* sBuf)  // �ַ�������
{
	int len=0;
	int i=0;
	int sum = 0;
	char* temp = "1234567890";
	struct timeb time_acco_b;
	struct timeb time_acco_e;

	printf("%s\n", sBuf);
	len = strlen(sBuf);
	printf("�ַ�������:%d\n", len);
	printf("Size:%d\n", sizeof(sBuf));
	for(i=0; i<len-1; i++)
	{
		printf("%d:%c\t%c\n",i+1,sBuf[i], *(sBuf+i));
	}

	temp[5]='\0';
	printf("temp=%s", temp);

}


void test1(){                   // ָ��
	char *temp = "123";
	printf("test1:%c;%s\n",temp[0], temp);
	temp[1]='\0';
	printf("test1:%c;%s\n",temp[0], temp);
}


void test2(){                   // ����
	char temp[4] = "456";
	printf("test2:%c;%s\n",temp[0], temp);
	temp[1]='\0';
	printf("test2:%c;%s\n",temp[0], temp);
}


void test_time(){               // ���ڲ���
    struct timeb time_b;
    struct timeb time_e;
    ftime(&time_b);
    sleep(3);
    ftime(&time_e);
    printf("time1=%d\n", (time_e.time-time_b.time));
    printf("time2=%f\n", (time_e.millitm*1.0-time_b.millitm*1.0)/1000.0);
    printf("time3=%f\n", (time_e.time-time_b.time)+(time_e.millitm*1.0-time_b.millitm*1.0)/1000.0);
}

void test_sv(){
 char *inbuf=NULL;
    char *outbuf=NULL;
    long len=0;
    long outlen=0;
      /*�ͻ��˵���tpinit()����Ӧ��*/
    if  (tpinit((TPINIT * )NULL) == -1)
    {
        exit(1);
    }
    /*��tpalloc()����һ��STRING�������ݻ���*/
    if (NULL==(inbuf=tpalloc("STRING", NULL, ALLOClEN)))
    {
        tpterm();
        exit(2);
    }
    /*��tpalloc()����һ��STRING�������ݻ���*/
    if (NULL==(outbuf=tpalloc("STRING", NULL, ALLOClEN)))
    {
        tpterm();
        exit(-1);
    }
    /*��"hello world"����������*/
    strcpy(inbuf,  "abcdef");
    printf("\t������====>[%s]\n",inbuf);

    /*���������ݿ⣬����inbuf,outbuf,outlenû��ʲô����*/
    if ( tpcall("sv_connect", inbuf, 0, &outbuf, &outlen, 0)== -1)
    {
        fprintf(stderr, "sv_connect fail.\n");
        tpfree(inbuf);
        tpfree(outbuf);
        tpterm();
        exit(-1);
    }

    /*��tpcall()�������ݻ��壬����"TOUPPER"��һ��ͬ������*/
    if ( tpcall("sv_update", inbuf, 0, &outbuf, &outlen, 0)== -1)
    {
        fprintf(stderr, "service requst fail.\n");
        tpfree(inbuf);
        tpfree(outbuf);
        tpterm();
        exit(-1);
    }

    /*��ӡ���ı�����ݻ���*/
    printf("\n");
    printf("\t���ر���<======[%s]\n", outbuf);
    tpfree(inbuf);
    tpfree(outbuf);

    /*����tpterm()�ж���Ӧ�õ�����*/
    tpterm();
    exit(0);
}

int main(int argvc, char** agr)
{
   

    if(argvc>1){
      check(agr[1]);
    }

	test1();
	test2();

    test_sv();
    test_time();
}

