#include "../../includes/corewar.h"

int is_number(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
    }
    return (1);
}

int     is_extension(char *av, char *ext)
{
    char *tmp;

    tmp = ft_strchr(av, '\0');
    if (!ft_strcmp(tmp - 4, ext))
        return (1);
    return (0);
}