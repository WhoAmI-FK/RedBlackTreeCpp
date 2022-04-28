#pragma once
#include <memory>
#include <iostream>
namespace RBTREE {
	namespace {
		template<typename T, typename _Alloc = std::allocator<T>>
		struct node {
			typedef node* _node;
			typedef int colorPlaceholder;
			T _data;
			_node _left;
			_node _right;
			_node _parent;
			colorPlaceholder _color;
//			int color; // 1 -> Red, 0 -> Black
//			node(const T& data, )
			bool isBlack() const {
				return _color == 0;
			}
			bool isRed() const {
				return _color == 1;
			}
		};
	};

	template<typename T,typename _Alloc=std::allocator<T>>
	class RB_TREE {
	public:
		typedef node* branch;
		RB_TREE() 
		{
			TNULL = new node<T>;
			TNULL->_color = 0;
			TNULL->_left = nullptr;
			TNULL->_right = nullptr;
			root = TNULL;
		}
		branch getRoot() const { return root; }
		
		void leftRotate(branch _b) {

		}
		void rightRotate(branch _b) {

		}
		void insert(const T& _val) {
			branch _new_node = new node<T>;
			_new_node->_parent = nullptr;
			_new_node->_data = key;
			_new_node->_left = TNULL;
			_new_node->_right = TNULL;
			_new_node->_color = 1;
			branch y = nullptr;
			branch x = this->_root;
			while (x != TNULL) {
				y = x;
				if (_new_node->_data < x->_data) {
					x = x->_left;
				}
				else {
					x = x->_right;
				}
			}
			_new_node->_parent = y;
			if (y == nullptr) {
				_root = _new_node;
			}
			else if (_new_node->_data < y->_data) {
				y->_left = _new_node;
			}
			else {
				y->_right = _new_node;
			}
			if (_new_node->_parent == nullptr) {
				_new_node->_color = 0;
				return;
			}
			if (_new_node->_parent == nullptr) {
				return;
			}
			fixInsert(_new_node);
		}
		void LRotate(branch node) {
			branch tmp = node->_right;
			node->_right = tmp->_left;
			if (tmp->_left != TNULL) {
				tmp->_left->_parent = node;
			}
			tmp->_parent = node->_parent;
			if (node->_parent == nullptr) {
				_root = tmp;
			}
			else if (node == node->_parent->_left) {
				node->_parent->_left = tmp;
			}
			else {
				node->_parent->_right = tmp;
			}
			tmp->_left = node;
			node->_parent = tmp;
		}
		void RRotate(branch node) {
			branch tmp = node->_left;
			node->_left = tmp->_right;
			if (tmp->_right != TNULL) {
				tmp->_right->_parent = node;
			}
			tmp->_parent = node->_parent;
			if (node->_parent == nullptr) {
				_root = tmp;
			}
			else if (node == node->_parent->_right) {
				node->_parent->_right = tmp;
			}
			else {
				node->_parent->_left = tmp;
			}
			tmp->_right = node;
			node->_parent = tmp;
		}
	private:
		branch _root;
		branch _TNULL;
		void initNULLNode(branch node, branch parent) {
			node->_data = 0;
			node->_parent = parent;
			node->_left = nullptr;
			node->_right = nullptr;
			node->_color = 0; // black
		}
		void fixDelete(branch _b) {

		}
		void fixInsert(branch _b) {

		}
	};
}