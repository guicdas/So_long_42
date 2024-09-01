#include "includes/solong.h"

void	put_player_w(int x, int y)
{
	if (data()->level > 0.3f)
		put(data()->img.player_w, x, y);
	else if (data()->level > 0.6f)
		put(data()->img.player_w2, x, y);
	else
		put(data()->img.player_w3, x, y);
}

void	put_player_s(int x, int y)
{
	if (data()->level > 0.3f)
		put(data()->img.player_s, x, y);
	else if (data()->level > 0.6f)
		put(data()->img.player_s2, x, y);
	else
		put(data()->img.player_s3, x, y);
}

void	put_player_d(int x, int y)
{
	if (data()->level > 0.3f)
		put(data()->img.player_d, x, y);
	else if (data()->level > 0.6f)
		put(data()->img.player_d2, x, y);
	else
		put(data()->img.player_d3, x, y);
}

void	put_player_a(int x, int y)
{
	if (data()->level > 0.3f)
		put(data()->img.player_a, x, y);
	else if (data()->level > 0.6f)
		put(data()->img.player_a2, x, y);
	else
		put(data()->img.player_a3, x, y);
}
