#include <iostream>
#include <queue>
#include <cmath>

template <typename T> class node {
public:
  T data;
  node *right = nullptr;
  node *left = nullptr;
  node *parent;
  bool status = false;

  bool isroot() { return this->parent == nullptr; }
  bool isexternal() { return this == nullptr; }

  int max_nodes(){
    int max_number_of_nodes = 0;
    for(int i{this->tree_hight()} ; i >= 0 ; i--) max_number_of_nodes += pow(2, i);
    return max_number_of_nodes;
  }

  node* convert_to_array(){
    node *arr = new node[this->max_nodes()+1];
    arr[1] = *this;
    for(int i{1} ; i <= this->max_nodes() ; i++){
      if(arr[i].status && arr[i].left) arr[2*i] = *arr[i].left;
      if(arr[i].status && arr[i].right) arr[2*i +1] = *arr[i].right;
    }
    return arr;
  }

  void postorder_traverse() {
    if (!this->isexternal()) {
      this->left->postorder_traverse();
      this->right->postorder_traverse();
      std::cout << this->data << "\t";
    }
  }

  void preorder_traverse() {
    if (!this->isexternal()) {
      std::cout << this->data << '\t';
      this->left->preorder_traverse();
      this->right->preorder_traverse();
    }
  }

  void inorder() {
    if (!this->isexternal()) {
      this->left->inorder();
      std::cout << this->data << '\t';
      this->right->inorder();
    }
  }

  void level_treaversal(){
    std::queue<node*> q;
    q.push(this);
    for(int i{0} ; i <= this->max_nodes() - pow(2, this->tree_hight()); i++) {
      if(!q.empty()){
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        std::cout<<q.front()->data<<'\t';
        q.pop();
        }
    }
  }

  int tree_hight() {
    if (!this->isexternal()) {
      int right_hight = this->right->tree_hight();
      int left_hight = this->left->tree_hight();
      return right_hight > left_hight ? right_hight + 1 : left_hight + 1;
    } else {
      return -1;
    }
  }

  int node_depth() {
    if (this->isroot())
      return 0;
    return 1 + this->parent->node_depth();
  }

  void tree_viewer(){
    int lines_num = 2*this->tree_hight()-1;
    for(int i{0} ; i < lines_num ; i++){
      for(int j{i} ; j < 5 ; j++) std::cout<<'\t';
      for(int k{i+1} ; k > 0 ; k--) std::cout<<'\t'<<'\t'<<'h';
      std::cout<<std::endl;
    } 
  }
};

template <typename T2> node<T2> test_create_tree() {
  node<double> *root = new node<double>;
  root->data = 1;
  root->status = true;
  root->right = new node<double>;
  root->right->parent = root;
  root->right->data = 2;
  root->right->status = true;
  root->right->right = new node<double>;
  root->right->right->parent = root->right;
  root->right->right->data = 3;
  root->right->right->status = true;
  root->right->right->right = new node<double>;
  root->right->right->right->parent = root->right->right;
  root->right->right->right->data = 100;
  root->right->right->right->status = true;
  root->right->left = new node<double>;
  root->right->left->parent = root->right;
  root->right->left->data = 4;
  root->right->left->status = true;
  root->left = new node<double>;
  root->left->parent = root;
  root->left->data = 5;
  root->left->status = true;
  root->left->right = new node<double>;
  root->left->right->parent = root->left;
  root->left->right->data = 6;
  root->left->right->status = true;
  root->left->left = new node<double>;
  root->left->left->parent = root->left;
  root->left->left->data = 7;
  root->left->left->status = true;
  return *root;
}

void test_postorder() {
  node<double> root = test_create_tree<double>();
  root.postorder_traverse();
  std::cout << std::endl;
}

void test_preorder() {
  node<double> root = test_create_tree<double>();
  root.preorder_traverse();
  std::cout << std::endl;
}

void test_inorder() {
  node<double> root = test_create_tree<double>();
  root.inorder();
  std::cout << std::endl;
}

void test_hight() {
  node<double> root = test_create_tree<double>();
  std::cout << root.tree_hight() << std::endl;
}

void test_node_depth() {
  node<double> root = test_create_tree<double>();
  std::cout << root.right->node_depth() << std::endl;
}

void test_tree_viewer() {
  node<double> root = test_create_tree<double>();
  root.tree_viewer();
}

void test_tree_level_traverse(){
  node<double> root = test_create_tree<double>();
  root.level_treaversal();
}

void test_convert_to_array(){
  node<double> root = test_create_tree<double>();
  node<double> *arr = root.convert_to_array();
  for(int i{0} ; i <= root.max_nodes() ; i++){
    if(arr[i].status) std::cout<<arr[i].data<<'\t';
    else
     std::cout<<"e"<<'\t';
  }
}

int main() {
  // test_postorder();
  // test_preorder();
  test_inorder();
  // test_hight();
  // test_node_depth();
  // test_tree_viewer();
  // test_tree_level_traverse();
  test_convert_to_array();
}
