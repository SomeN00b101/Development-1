#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iterator>

class Model{
protected:
  Model(int in, int out) : num_input(in), num_output(out){
    num_hidden = std::min(5, std::max(1, std::floor((std::log2(input)) + 0.5)));
  }

  void train_forward_start(vector<double> input_data){

    //input layer
    for (int i(0); i < num_input; i++)
      model.ntwork.at(i)->node_input = input_data.at(i);

    //hidden layers
    double lin_sum;
    vector<*Node> prevLayer = model.ntwork, currLayer = model.ntwork.at(0)->neighbors;
    for (int h(0); h < num_hidden + 1; h++){
      for (int i(0); i < currLayer.size(); i++){
	lin_sum = currLayer.at(i)->bias;
	for (int j(0); j < prevLayer.size(); j++){
	  lin_sum += prevLayer.at(j)->weights.at(i) * prevLayer.at(j)->node_input;
	}
	currLayer.at(i)->node_input = h == num_hidden ? lin_sum : activation_relu(lin_sum); 
      }
      prevLayer = currLayer;
      currLayer = currLayer.at(0)->neighbors;
    }

    train_forward_final(prevLayer);
  }

  virtual void train_forward_final(vector<*Node> output_layer) = 0;

  double activation_relu(double val){
    if (val >= 0) return val; return 0;
  }

  double activation_relu_derivative(){
    if (val > 0) return 1; return 0;
  }

protected:
  Network model(num_input, num_output, num_hidden);
  int num_input;
  int num_output;
  int num_hidden;
  
  class Network{
  protected:
    std::vector<*Node> ntwork;

    Network(int input, int output, int hidden){
      
      //intialize input layer
      for(int i(0); i < currNum; i++){
	Node n;
	ntwork.push_back(&n);
      }

      //connects hidden layers & output layer
      vector<*Node> currLayer = ntwork;
      int currNum = input;
      for (int h(0); h < hidden + 1; h++){
	nextNum = input * std::pow(static_cast<double>(output)/input, 1.0/(h + 2));
	for (int i(0); i < nextNum; i++){
	  Node n;
	  for (int j(0); j < currNum; j++){
	    currLayer.at(j).neighbors.push_back(&n);
	    currLayer.at(j).weights.push_back(static_cast<double>(rand())/RAND_MAX/100);
	  }
	  
	}
	currLayer = currLayer.at(0).neighbors;
	currNum = nextNum;
      }
    }
    
    class Node{
    protected:
      double node_input;
      double bias;
      std::vector<*Node> neighbors;
      std::vector<double> weights;
      
      Node() : bias(0){}
    };
  };
};
