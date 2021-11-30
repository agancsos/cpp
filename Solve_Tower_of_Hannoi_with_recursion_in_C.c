void recursive(int x, char from,char to,char aux)
{
        if(x==1)
        {
                printf(\"Move Disk %d From %c to %c\",x,from,to);
        }
        else
        {
                recursive(x-1,from,aux,to);
                printf(\"Move Disk %d From %c to %c\",x,from,to);
                recursive(x-1,aux,to,from);
        }
}

