#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"

# define BUFFER_SIZE 42

typedef	struct	s_map
{
	char	**tab;
	char	**mapcopy;
	int	size_y;
	int	size_x;
	int	P;
	int	C;
	int	E;
}		t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*img_player_h;
	void	*img_player_b;
	void	*img_player_g;
	void	*img_player_d;
	void	*img_wall;
	void	*img_floor;
	void	*collectible;
	void	*img_exit;
}	t_game;
 //		SO_LONG			//

//	PARSING
void	parsing(t_map *map, int ac, char **av);
void	load_map(char *file, t_map *map);
int     count_line(char *file);
//	CHECK_MAP
void	check_map(t_map *map, char **tab);
void    check_line(t_map *map, char *line, int border);
void	check_tiles(t_map *map);
void	increment_tiles(char c, t_map *map);
//	FLOOD_FILL
void     flood_fill(t_map *map);
void     verif_access(char **mapcopy, t_map *map);
void    flood(t_map *map, char  **mapcpy, int P_y, int P_x);
void    find_P(char **mapcopy, int *player_y, int *player_x);
char    **ft_tabcpy(char **tab);
//	GET_NEXT_LINE
char	*get_next_line(int fd);
char	*extract_line(char **stored);

//	MLX
void    init_mlx(t_game *game);


//	UTILS
int	ft_strlen_tab(char **tab);
char    *ft_strnstr(const char *str, const char *to_find, size_t n);
void	ft_putstr(char *str);

//	FREE
void    error();
# endif
