#include "../../includes/corewar.h"

static int  bytecode_to_int(uint8_t *buffer, int size)
{
    int result;
    int i;

    i = 0;
    result = 0;
    while (i < size)
        result = result * 256 + buffer[i++];
    return (result);
}

static void parse_instr(t_vm *vm, uint8_t *dst, int fd, int size)
{
    int     ret;
    uint8_t byte;

    if ((ret = read(fd, dst, size)) == -1)
        ft_error(vm, errno);
    if (ret < size)
        ft_error(vm, 1);
    else if (read(fd, &byte, 1) != 0)
        ft_error(vm, 1);
}

static void parse_string(t_vm *vm, char *dst, int fd, int size)
{
    int ret;

    if ((ret = read(fd, dst, size) == -1))
        ft_error(vm, errno);
    if (ret < size)
        ft_error(vm, 1);
    dst[ret] = '\0';
}

static int  parse_4byte(t_vm *vm, int fd)
{
    uint8_t buffer[4];
    int     ret;

    if ((ret = read(fd, buffer, 4)) == -1)
        ft_error(vm, errno);
    if (ret < 4)
        ft_error(vm, 1);
    return (bytecode_to_int(buffer, 4));
}

void        ft_parse_champion(t_vm *vm, char *file, int id)
{
    t_player    *player;
    int         fd;

    if (!(player = creat_champion(id)))
        ft_error(vm, 0);
    add_champion(vm, player);
    if ((fd = open(file, O_RDONLY)) == -1)
        ft_error(vm, 0);
    if (parse_4byte(vm, fd) != COREWAR_EXEC_MAGIC)
        ft_error(vm, 1);
    parse_string(vm, player->name, fd, PROG_NAME_LENGTH);
    if (parse_4byte(vm, fd) != 0)
        ft_error(vm, 2);
    player->isntr_size = parse_4byte(vm, fd);
    if (player->isntr_size < 0 || player->isntr_size > CHAMP_MAX_SIZE)
        ft_error(vm, 3);
    parse_string(vm, player->comment, fd, COMMENT_LENGTH);
    if (parse_4byte(vm, fd) != 0)
        ft_error(vm, 2);
    parse_instr(vm, player->instr, fd, CHAMP_MAX_SIZE);
}