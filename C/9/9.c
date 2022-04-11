/*将整数转换为字符串*/
char* Int2String(int num,char *str)
{
    int i = 0;//指示填充str
    if(num<0)//如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    //转换
    do
    {
        str[i++] = num%10+48;//取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;//去掉最低位
    }while(num);//num不为0继续循环

    str[i] = '\0';

    //确定开始调整的位置
    int j = 0;
    if(str[0]=='-')//如果有负号，负号不用调整
    {
        j = 1;//从第二位开始调整
        ++i;//由于有负号，所以交换的对称轴也要后移1位
    }
    //对称交换
    for(;j<i/2;j++)
    {
        //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i-1-j];
        str[i-1-j] = str[j] - str[i-1-j];
        str[j] = str[j] - str[i-1-j];
    }

    return str;//返回转换后的值
}

/*比较对应位置是否相同，即测试是否符合回文数*/
int Compare(char *buf,int size)
{
    int i =0;
    for(;i<size/2;i++)
    {
        if(buf[i] != buf[size-i-1]) return -1;
    }
    return 0;
}
/*求非负整数的位数*/
int number(int num)
{
    int i=0;
    do
    {
        num=num/10;
        i++;
    }while(num!=0);
    return i;
}
/*主函数*/
bool isPalindrome(int x){
    if(x < 0) return false; //负数一定不为回文数
    int num = number(x);
    char string[num + 1];
I   nt2String(x,string);

    int length = strlen(string);
    int result = Compare(string,length);
    if(result==-1) return false;
    else return true;
}