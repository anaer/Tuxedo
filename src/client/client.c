#include <stdio.h>
#include "atmi.h" /*包含TUXEDO系统的头文件"atmi.h", 以便引用TUXEDO的函数和变量定义。*/
#include <sys/timeb.h>
#define ALLOClEN 80 /*定义输入和返回的长度*/ 


void check(char* sBuf)  // 字符串测试
{
	int len=0;
	int i=0;
	int sum = 0;
	char* temp = "1234567890";
	struct timeb time_acco_b;
	struct timeb time_acco_e;

	printf("%s\n", sBuf);
	len = strlen(sBuf);
	printf("字符串长度:%d\n", len);
	printf("Size:%d\n", sizeof(sBuf));
	for(i=0; i<len-1; i++)
	{
		printf("%d:%c\t%c\n",i+1,sBuf[i], *(sBuf+i));
	}

	temp[5]='\0';
	printf("temp=%s", temp);

}


void test1(){                   // 指针
	char *temp = "123";
	printf("test1:%c;%s\n",temp[0], temp);
	temp[1]='\0';
	printf("test1:%c;%s\n",temp[0], temp);
}


void test2(){                   // 数组
	char temp[4] = "456";
	printf("test2:%c;%s\n",temp[0], temp);
	temp[1]='\0';
	printf("test2:%c;%s\n",temp[0], temp);
}


void test_time(){               // 日期测试
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
      /*客户端调用tpinit()连接应用*/
    if  (tpinit((TPINIT * )NULL) == -1)
    {
        exit(1);
    }
    /*用tpalloc()分配一个STRING类型数据缓冲*/
    if (NULL==(inbuf=tpalloc("STRING", NULL, ALLOClEN)))
    {
        tpterm();
        exit(2);
    }
    /*用tpalloc()分配一个STRING类型数据缓冲*/
    if (NULL==(outbuf=tpalloc("STRING", NULL, ALLOClEN)))
    {
        tpterm();
        exit(-1);
    }
    /*将"hello world"拷贝进缓冲*/
    strcpy(inbuf,  "abcdef");
    printf("\t请求报文====>[%s]\n",inbuf);

    /*先连上数据库，这里inbuf,outbuf,outlen没有什么作用*/
    if ( tpcall("sv_connect", inbuf, 0, &outbuf, &outlen, 0)== -1)
    {
        fprintf(stderr, "sv_connect fail.\n");
        tpfree(inbuf);
        tpfree(outbuf);
        tpterm();
        exit(-1);
    }

    /*用tpcall()包含数据缓冲，向交易"TOUPPER"发一个同步请求*/
    if ( tpcall("sv_update", inbuf, 0, &outbuf, &outlen, 0)== -1)
    {
        fprintf(stderr, "service requst fail.\n");
        tpfree(inbuf);
        tpfree(outbuf);
        tpterm();
        exit(-1);
    }

    /*打印出改变的数据缓冲*/
    printf("\n");
    printf("\t返回报文<======[%s]\n", outbuf);
    tpfree(inbuf);
    tpfree(outbuf);

    /*调用tpterm()切断与应用的连接*/
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

