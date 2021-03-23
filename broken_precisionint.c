
char    precision_int(char *dir,va_list args2)
{
    int start;
    static int real;
    int x;
    int print;
    int width;
    int position;
    int arglen  = ft_arglen(dir);

    position += 1;
    print = va_arg(args2, int);
    start = ft_intstrchr_flag(dir, '%', position);
    real = (ft_intstrchr(dir, '.', start));
    width = find_width(dir, start);
    x = ft_atoi(&dir[real + 1]);
    int len = ft_intlen_bonus(print);
    if (real == -1 && width == 0)
    {
        print = 0;
        position = 0;
        return(0);
    }
    if ((x == 0 && ft_isalpha(dir[real])) || real == -1)
        return(0);
    while(arglen >= 0)
    {
        if (ft_intlen_bonus(print) < x)
        {
            printf("imhere\n");
            if (width >= 0)
            {
                if (print >= 0)
                {
                print_x_times(width - x, ' ');
                print_x_times(x - ft_intlen_bonus(print), '0');
                ft_putnbr(print);
        
                arglen--;
                }
                if (print < 0)
                {
                print_x_times(width - (x + 1), ' ');
                ft_putc('-');
                print_x_times(x - ft_intlen_bonus(print), '0');
                ft_putnbr(print * -1);
                }
                debug_number(arglen, "args");
                arglen--;
            return(0);
            }
            else
            {
                width *= -1;
                print_x_times(x - ft_intlen_bonus(print), '0');
                ft_putnbr(print);
                print_x_times(width - x, ' ');
            }
            debug_number(arglen, "args");
            arglen--;
            return(0);
        }
        if (ft_intlen_bonus(print) >= x)
        {    
            if (width >= 0)
            {
                if (print >= 0)
                {
                    print_x_times(width - x, ' ');
                    print_x_times(x - ft_intlen_bonus(print), '0');
                    ft_putnbr(print);
                }
                 if (print < 0)
                {
                    ft_putc('-');
                    print_x_times(width - x, ' ');
                    print_x_times(x - ft_intlen_bonus(print), '0');
                    ft_putnbr(print * -1);
                }
            return(0);
            }
            else
            {
                width *= -1;
                print_x_times(x - ft_intlen_bonus(print), '0');
                ft_putnbr(print);
                print_x_times(width - x, ' ');
            }
        return(0);
        }

       position += real;
       return(arglen);
    }   
    return(0);
}