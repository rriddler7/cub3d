#include "../inc/Cube3d.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	char	a[] = "qwerty";

	int i = ft_strlen(a);
	i--;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	mlx_win--;
}
