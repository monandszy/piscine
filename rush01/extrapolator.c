void extrapolate_four(void)
{
    int i = 0;
    int j = 0; 
    int column = -1;
    int row = -1;
    int is = 0;

    while (i < 4)
    {
        j = 0;
        is = 0;
        while (j < 4)
        {
            if (g_matrix[i][j] == 4)
                is = 1;
            j++;
        }
        if (is == 0) 
            column = i;
        i++;
    }
    i = 0;
    j = 0;
    while (j < 4)
    {
        i = 0;
        is = 0;
        while (i < 4)
        {
            if (g_matrix[j][i] == 4)
                is = 1;
            i++;
        }
        if (is == 0)
            row = j;
        j++;
    }
    printf("%d, %d", row, column);
    if (row != -1 && column != -1)
        g_matrix[row][column] = 4;
}

