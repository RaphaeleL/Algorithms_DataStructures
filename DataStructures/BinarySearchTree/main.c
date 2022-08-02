#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} node;

node *newNode(int data) {
  node *tmp = (node *)malloc(sizeof(node));

  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;

  return tmp;
}

node *insert(node *root, int data) {
  if (root == NULL) {
    root = newNode(data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  }
  return root;
}

node *getMax(node *root) {
  if (root->right != NULL) {
    return getMax(root->right);
  }
  return root;
}

node *delete (node *root, int data) {
  if (root == NULL) {
    return root;
  } else if (data > root->data) {
    root->right = delete (root->right, data);
  } else if (data < root->data) {
    root->left = delete (root->left, data);
  } else if (data == root->data) {
    if ((root->left == NULL) && (root->right == NULL)) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      node *tmp = root;
      root = root->right;
      free(tmp);
      return root;
    } else if (root->right == NULL) {
      node *tmp = root;
      root = root->left;
      free(tmp);
      return root;
    } else {
      node *tmp = getMax(root->left);
      root->data = tmp->data;
      root->left = delete (root->left, tmp->data);
    }
  }
  return root;
}
int find(node *root, int data) {
  if (root == NULL) {
    return 0;
  } else if (data > root->data) {
    return find(root->right, data);
  } else if (data < root->data) {
    return find(root->left, data);
  } else if (data == root->data) {
    return 1;
  } else {
    return 0;
  }
}

int height(node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int right_h = height(root->right);
    int left_h = height(root->left);
    if (right_h > left_h) {
      return (right_h + 1);
    } else {
      return (left_h + 1);
    }
  }
}

void purge(node *root) {
  if (root != NULL) {
    if (root->left != NULL) {
      purge(root->left);
    }
    if (root->right != NULL) {
      purge(root->right);
    }
    free(root);
    root = NULL;
  }
}

void print(node *root) {
  if (root != NULL) {
    print(root->left);
    printf("\t[ %d ]\t", root->data);
    print(root->right);
  }
}

int main() {
  node *root = NULL;
  int opt = -1;
  int data = 0;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);

  print(root);
  printf("\n");

  if (find(root, 4)) {
    printf("The value is in the tree.\n");
  } else {
    printf("The value is not in the tree.\n");
  }
  printf("Current height of the tree is: %d\n", height(root));

  root = delete (root, 4);

  print(root);
  printf("\n");

  if (find(root, 4)) {
    printf("The value is in the tree.\n");
  } else {
    printf("The value is not in the tree.\n");
  }
  printf("Current height of the tree is: %d\n", height(root));

  return 0;
}
