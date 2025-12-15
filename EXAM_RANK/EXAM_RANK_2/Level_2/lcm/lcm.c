unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	lcm = (a < b) ? a : b;
	while (a > 0 && b > 0)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm += (a < b) ? a : b;
	}
	return (0);
}
