#include "stdafx.h"
#include "ann.h"

#include <stdio.h>

int main()
{
	neuron n(3, 0.1);

	n.m_weights[0] = 1;
	n.m_weights[1] = -0.5;
	

	printf("%f\n", n.getOutput({ 1, 2, 3 }));
}