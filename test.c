#include <stdio.h>
int get_x_value();

int main()
{
//    FILE *fp;
//   fp=fopen("configration.txt","w+");
//    fputc('a',fp);
//    fclose(fp);
//   if(fp=fopen("config.txt","r"))
 /*   {
        char ch;
        do{
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        fputchar(ch);
        }while(1);
    }
    //fputchar('8');
    */
   int i=0;
   char value[20];
   char *p_value=value;
   get_x_value("class","config.txt",p_value);
   do
   {
      fputchar(value[i]);
      i++; 
   } while (value[i]!='\0'&&i<=19);
   
   //printf("读取到的class的值是%s\n",p_value);
}

int get_x_value(char *x,char *objFile,char *valueBox)
{
    char *x_temp=x;
    FILE *fp;
    char temp;
    if(fp=fopen("config.txt","r"))
    {
        //文件打开成功,开始查找x
        do
        {
            temp=fgetc(fp);
            if(*x_temp==temp)
            {
                x_temp++;
            }
            else x_temp=x;
            if(temp==EOF) 
            {
                printf("未查找到相应变量\n");
                return 2;
            }
        } while (*x_temp!='\0');
        if(fgetc(fp)=='=')    
        {
            do
            {
                temp=fgetc(fp);
                *valueBox=temp;
                valueBox++;
            } while (temp!=(char)(32));
            *(valueBox-1)='\0';
            printf("获取参数成功\n");
            return 0;
        }
    }
    else 
    {
        printf("文件打开失败\n");
        return 1;
    }
}