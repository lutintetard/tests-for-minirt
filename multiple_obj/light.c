# include "basic.h"

unsigned int	modify_light(unsigned int color, t_light light, double distance)
{
	int	i;
	double	calculate;
	unsigned int	result;
	double		intensity_added;

	i = 0;
	printf("~~~~~~~~~~light modifications~~~~~~~~~~\n");
	//distance = distance / 10;
	//intensity_added = light.bright_ratio / (distance * distance + 0.01);
	intensity_added = light.bright_ratio / (1 + distance / 10);
	printf("distance : %f intensity factor: %f\n", distance, intensity_added);
	result = 0;
	while (i < 3)
	{
//		calculate = (color << (24 - i * 8)) / (int)pow((24), 2);
//		printf("%d : %d", i, calculate);
//		calculate += (double)(1 + intensity_added) * ((light.color << (24 - i * 8)) % (int)pow(2, (24 - i * 8)));
//		if (calculate > 256)
//			calculate = 256;
//		result += calculate * pow((24 - i * 8), 2);
//		printf(" : %d\t", calculate);
//		i++;
		switch (i)
		{
			case 0:
				printf("RED\n");
				break;
			case 1:
				printf("GREEN\n");
				break;
			case 2:
				printf("BLUE\n");
				break;
		}
		calculate = (double)((color >> ((2 - i) * 8)) % 256);
		printf("Object color %f\n",  calculate);
		//debug = ((light.color >> ((2 - i) * 8)) % 256);
		double multiplication_factor;
		multiplication_factor = (double)((intensity_added) * (((light.color >> ((2 - i) * 8)) % 256) / (double)256));
		printf("multiplicaton factor : %f \n", multiplication_factor);
		calculate *= 1 + multiplication_factor;
		printf("new val : %f \t", calculate);
		if (calculate > 255)
			calculate = 255;
		result += (unsigned int)calculate * pow(2, ((2 - i) * 8));
		printf("current result: %d\n", result);
		i++;
	}
	printf("\n");
	return (result);
}

unsigned int	make_light_nice(unsigned int color, t_light light, double distance)
//la dissipation de la lumiere est egale a Ifin = Iinit / Distance^2
{
	unsigned int	nice_light;

	nice_light = modify_light(color, light, distance);
	return (nice_light);
}
