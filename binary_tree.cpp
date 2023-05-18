#include <iostream>

template <typename T> class node {
public:
  T data;
  node *right = nullptr;
  node *left = nullptr;
  node *parent;
  node(T data) { this->data = data; }

  bool isroot() { return this->parent == nullptr; }
  bool isexternal() { return this == nullptr; }

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
  node<double> *root = new node<double>(1);
  root->right = new node<double>(2);
  root->right->parent = root;
  root->right->right = new node<double>(3);
  root->right->right->parent = root->right;
  root->right->right->right = new node<double>(100);
  root->right->right->right->parent = root->right->right;
  root->right->left = new node<double>(4);
  root->right->left->parent = root->right;
  root->left = new node<double>(5);
  root->left->parent = root;
  root->left->right = new node<double>(6);
  root->left->right->parent = root->left;
  root->left->left = new node<double>(7);
  root->left->left->parent = root->left;
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

int main() {
  // test_postorder();
  // test_preorder();
  // test_inorder();
  // test_hight();
  // test_node_depth();
  // test_tree_viewer();
}
