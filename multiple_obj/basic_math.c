#include "basic.h"

double	smallest_positive(double x, double y)
{
	double	smallest;
	double	largest;

	smallest = fmin(x, y);
	if (smallest >= 0)
		return (smallest);
	largest = fmax(x, y);
	return (largest);
}
