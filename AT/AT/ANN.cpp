#include "stdafx.h"
#include "ann.h"
#include <math.h>


neuron::neuron(int numInputs, float threshold)
	: m_threshold(threshold)
{
	m_weights.resize(numInputs);
}

float neuron::getOutput(vector<float> inputs)
{
	float x = 0;
	for (int i = 0; i < m_weights.size(); ++i)
	{
		x += m_weights[i] * inputs[i];
	}

	printf("x: %f\n", x);

	return tanh(3.141592653 * x * m_threshold);
}

net::net(vector<int> sizes)
{
	layers.resize(sizes.size());
	for (int i = 0; i < layers.size(); ++i)
	{
		layers[i].resize(sizes[i]);
		for (int j = 0; j < layers[i].size(); ++j)
		{
			layers[i][j] = new neuron(i == 0 ? 1 : layers[i - 1].size(), 0);
		}
	}
}

void net::setData()
{
	for (int i = 0; i < layers.size(); ++i)
	{
		for (int j = 0; j < layers[i].size(); ++j)
		{
			layers[i][j]->m_threshold = (rand() % 1000) / 1000000.0f;
			for (int k = 0; k < layers[i][j]->m_weights.size(); ++k)
			{
				layers[i][j]->m_weights[k] = (rand() % 1000) / 1000000.0f;
			}
		}
	}
}

void net::dump()
{
	for (auto& l : layers)
	{
		printf("Layer: ");
		for (auto& n : l)
		{
			printf("%0.2f ", n->m_threshold);
		}
		printf("\n");
	}
}

vector<float> net::run(vector<float> inputs)
{
	vector<float> prevOutputs = inputs;
	for (int i = 0; i < layers.size(); ++i)
	{
		vector<float> outputs;
		outputs.resize(i == layers.size() - 1 ? layers[i].size() : layers[i + 1].size());

		for (int j = 0; j < layers[i].size(); ++j)
		{
			outputs[i] = layers[i][j]->getOutput(prevOutputs);
		}

		prevOutputs = outputs;
	}

	return prevOutputs;
}
