int		ft_atoi(char *str)
{
	unsigned int	i;
	int				signe;
	int				sortie;

	i = 0;
	sortie = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sortie = sortie * 10 + (str[i] - '0');
		i++;
	}
	return (signe * sortie);
}