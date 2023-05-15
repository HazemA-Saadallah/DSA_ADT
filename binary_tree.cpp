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
};

template <typename T2> node<T2> test_create_tree() {
  node<double> *root = new node<double>(1);
  root->right = new node<double>(2);
  root->right->parent = root;
  root->right->right = new node<double>(3);
  root->right->right->parent = root->right;
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

int main() {
  test_postorder();
  test_preorder();
  test_inorder();
}
