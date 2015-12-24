#include <stdio.h>

void read_word(char *s, int *i, char *w)//чтение слова
{
    int j;
    while (s[*i] <= ' ')
        (*i)++;
    j = 0;
    while (s[*i] != '\0' && s[*i] != ' ')
    {
        w[j] = s[*i];
        j++;
        (*i)++;
    }
    w[j] = '\0';
}
void strings()
{
    FILE *f,*g;
    char s[2000], w[2000], ws[2000], pred[2000], pred1[2000];
    s[0] = '\0';
    ws[0] = '\0';
    w[0] = '\0';
    int vsp=1;
    int sl = 0;
    int str;
    int j = 0;
    f = fopen("2.txt", "r");
    if (!f)
           {
            puts("cannot open the file");
            return;
}
    while (!feof(f))
    {
        fgets(s, 2000, f);

        int i = 0;
        str = 0;
        ws[0] = '\0';
        if (vsp)
        while (s[i] != '\0')
        {
            if (s[i] == '$')
            {
                w[j] = '\n';
                j++;
                w[j] = ' ';
                j++;
                w[j] = ' ';
                j++;
                w[j] = '\0';
                i++;
            }
            else
            {
                if (s[i] == '#')
                    read_word(s, &i, ws);
                else
                {
                    if (s[i] == '@')
                    {
                        while (s[i + 1] != '.'&&s[i + 1] != '!'&&s[i + 1] != '?'&&s[i + 1] != '\0')
                            i++;
                        i++;
                        if (s[i] == '\0')
                            vsp = 0;
                    }
                    else
                    {
                        w[j] = s[i];
                        i++;
                        j++;
                        w[j] = '\0';
                    }
                }
            }
        }
        else
        {
            while (s[i + 1] != '.'&&s[i + 1] != '!'&&s[i + 1] != '?'&&s[i + 1] != '\0')
                i++;
            i++;
            if (s[i] != '\0')
                vsp = 1;
        }

    }
    printf("text:\n");
    puts(w);
    fclose(f);
    remove("2.txt");
    g = fopen("2.txt", "w");
    fputs(w, g);
    fclose(g);
    getchar();
    getchar();
}
