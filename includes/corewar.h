#ifndef VM_H
# define VM_H

# include "../libft/includes/libft.h"
# include <inttypes.h>
# include <errno.h>
# include "op.h"

# define USAGE          -1
# define DUMP           FT_BIT(0)
# define NUM            FT_BIT(1)
# define VIS            FT_BIT(2)
# define EXT            ".core"

/*
** struct arena
*/

typedef struct      s_cursor
{
    /* data */
}                   t_cursor;

typedef struct      s_player
{
    char            name[PROG_NAME_LENGTH + 1];
    char            comment[COMMENT_LENGTH + 1];
    uint8_t         instr[CHAMP_MAX_SIZE];
    int             isntr_size;
    int             id;
    struct s_player *next;
}                   t_player;

typedef struct      s_vm
{
    uint8_t         arena[MEM_SIZE];
    t_player        *players[MAX_PLAYERS];
    int             players_num;
    int             flags;
    int             dump_num;
    int             id;

}                   t_vm;


/*
** Initialization functions
*/

void        init_vm(t_vm *vm);
t_player    *creat_champion(int id);
void        init_arena(t_vm *vm);

/*
** Parse functions
*/

void        ft_parse_champion(t_vm *vm, char *file, int id);
void        add_champion(t_vm *vm, t_player *player);
void        ft_parse_args(t_vm *vm, char **argv);
void        ft_parse_dump(t_vm *vm, char ***av);
int         ft_parse_num(t_vm *vm, char *av);
int         is_number(char *str);


/*
** Error processing & print functions
*/

int			print_usage();
void		ft_error(t_vm *vm, int code);

#endif