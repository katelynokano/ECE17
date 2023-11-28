//
// Created by katie on 11/27/2023.
//

#include "BinarySearchTree.h"

BinarySearchTree::Node::Node(int _val, Node* _left, Node* _right){
    val = _val;
    left = _left;
    right = _right;
}

void BinarySearchTree::insert(BinarySearchTree::Node *&aNodePtr, BinarySearchTree::Node *&aNewNodePtr) {
    if(aNodePtr == nullptr){
        aNodePtr = aNewNodePtr;
    }
    else if (aNewNodePtr->val < aNodePtr->val){
        insert(aNodePtr->left, aNewNodePtr);
    }
    else{
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinarySearchTree::deleteNode(int aVal, BinarySearchTree::Node *&aNodePtr) {
    if(aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if(aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else{ //if the value is found
        makeDeletion(aNodePtr);
    }
}

void BinarySearchTree::makeDeletion(BinarySearchTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;
    if (aNodePtr == nullptr){
        std::cout << "Cannot remove empty Node" << std::endl;
    }
    else if (aNodePtr->right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr =  aNodePtr->left;
        delete tempNodePtr;
    }
    else if (aNodePtr->left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr =  aNodePtr->right;
        delete tempNodePtr;
    }
    else{
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = aNodePtr->left;

        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

bool BinarySearchTree::searchNode(int aVal) {
    Node* currentNode= root;

    while(currentNode){
        if(currentNode->val == aVal){
            return true;
        }
        else if (aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else{
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinarySearchTree::remove(int aVal) {
    deleteNode(aVal, root);
}
