#pragma once
#include<math.h>
#include<vector>
#include<stdlib.h>

using namespace std;

struct neuron
{
	vector<float> m_weights;
	float m_threshold;

	neuron(int numInputs, float threshold);
	float getOutput(vector<float> inputs);
};

struct net
{
	vector<vector<neuron*>> layers;

	net(vector<int> sizes);
	void setData();
	void dump();
	vector<float> run(vector<float> inputs);
};