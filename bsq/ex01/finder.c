#include "fts.h"

extern char	**g_matrix;

int calculate_size(int col_size, int row_size, int x, int y)
{
    int size;
    int a_y;
    int a_x;
    int tmp_y;
    int tmp_x;
    int tmp_s;

    size = 0;
    tmp_x = x;
    tmp_y = y;
    while (x < col_size && y < row_size)
    {
        a_x = tmp_x;
        a_y = tmp_y;
        tmp_s = size + 1;
        while (tmp_s > 0)
        {
            if (g_matrix[x][a_y] == 'o' || g_matrix[a_x][y] == 'o')
                return (size);
            a_y++;
            a_x++;
            tmp_s--;
        }
        x++;
        y++;
        size++;
    }
    return (size);
}


int find_max(int col_size, int row_size, int *m_x, int *m_y) 
{ 
    int x; 
    int y; 
    int size; 
    int max; 
 
    x = 0; 
    max = 0; 
    while (x < col_size) 
    { 
        y = 0; 
        while (y < row_size) 
        { 
            if (g_matrix[x][y] != 'o') 
            { 
                size = calculate_size(col_size, row_size, x, y); 
                if (size > max) 
                { 
                    *m_x = x; 
                    *m_y = y; 
                    max = size; 
                } 
            } 
            y++; 
        } 
        x++; 
    } 
    return (max); 
}


void fill_max(int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            g_matrix[x + i][y + j] = '!';
            j++;
        }
        i++;
    }
}

int handle_max(int col_size, int row_size)
{
    int m_x;
    int m_y;
    int m_size;

    m_size = find_max(col_size, row_size, &m_x, &m_y);
    fill_max(m_x, m_y, m_size);
    if (m_size == 0)
        return (1);
    return (0);
}

