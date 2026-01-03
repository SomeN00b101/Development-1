#include "model.h"

class Regression : public Model{
 private:
 Regression(int in, int out) : Model(in, out){}

  void train_forward_final(vector<*Node>& output_layer){
    return;
  }
};

class Classification : public Model{
 private:
 Regression(int in, int out) : Model(in, out){}

  void train_forward_final(vector<*Node> output_layer){
    if (out > 1){
      double softmax_sum = 0, softmax_val;
      for (int i(0); i < out; i++){
	sum += std::exp(*(output_layer.at(i)));
      }

      for (std::vector<*Node>::iterator itr = output_layer.begin();
	   itr != output_layer.end(); itr++){
	softmax_val = (*itr)->node_input/softmax_sum;
	(*itr)->node_input = sigmoid_val; 
      }
    }
    else{
      double sigmoid_val = 1/(1 + std::exp(-1 * output_layer.at(0)->node_input));
      output_layer.at(0)->node_input = sigmoid_val;
    }
  }
};
