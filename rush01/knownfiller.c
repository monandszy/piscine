extern int  g_top[4];
extern int  g_btm[4];
extern int  g_rig[4];
extern int  g_lft[4];
extern int	g_matrix[4][4];

void fill3and2(void)
{
    int i = 0;

    while (i < 4)
    {
        if (g_top[i] == 3 && g_btm[i] == 2)
        {
            g_matrix[2][i] = 4;
        }
        else if (g_top[i] == 3 && g_btm[i] == 2)
        {
            g_matrix[1][i] = 4;
        }
        if (g_lft[i] == 3 && g_rig[i] == 2)
        {
            g_matrix[i][2] = 4;
        }
        else if (g_lft[i] == 2 && g_rig[i] == 3)
        {
            g_matrix[i][1] = 4;
        }
        i++;
    }
}


void fill3and1(void)
{
    int i = 0;

    while (i < 4)
    {
        if (g_btm[i] == 1)
        {
            g_matrix[3][i] = 4;
        }
        else if (g_top[i] == 1)
        {
            g_matrix[0][i] = 4;
        }
        if (g_rig[i] == 1)
        {
            g_matrix[i][3] = 4;
        }
        else if (g_lft[i] == 1)
        {
            g_matrix[i][0] = 4;
        }
        i++;
    }
}


void fill2and1(void)
{
    int i = 0;

    while (i < 4)
    {
        if (g_top[i] == 2 && g_btm[i] == 1)
        {
            g_matrix[0][i] = 3;
            g_matrix[3][i] = 4;
        }
        else if (g_top[i] == 1 && g_btm[i] == 2)
        {
            g_matrix[0][i] = 4;
            g_matrix[3][i] = 3;
        }
        if (g_lft[i] == 2 && g_rig[i] == 1)
        {
            g_matrix[i][0] = 3;
            g_matrix[i][3] = 4;
        }
        else if (g_lft[i] == 1 && g_rig[i] == 2)
        {
            g_matrix[i][0] = 4;
            g_matrix[i][3] = 3;
        }
        i++;
    }
}


void fill4and1(void)
{
    int i = 0;

    while (i < 4)
    {
        if (g_top[i] == 4 && g_btm[i] == 1)
        {
            g_matrix[0][i] = 1;
            g_matrix[1][i] = 2;
            g_matrix[2][i] = 3;
            g_matrix[3][i] = 4;
        }
        else if (g_top[i] == 1 && g_btm[i] == 4)
        {
            g_matrix[0][i] = 4;
            g_matrix[1][i] = 3;
            g_matrix[2][i] = 2;
            g_matrix[3][i] = 1;
        }
        if (g_lft[i] == 4 && g_rig[i] == 1)
        {
            g_matrix[i][0] = 1;
            g_matrix[i][1] = 2;
            g_matrix[i][2] = 3;
            g_matrix[i][3] = 4;
        }
        else if (g_lft[i] == 1 && g_rig[i] == 4)
        {
            g_matrix[i][0] = 4;
            g_matrix[i][1] = 3;
            g_matrix[i][2] = 2;
            g_matrix[i][3] = 1;
        }
        i++;
    }
}

