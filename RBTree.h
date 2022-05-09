#pragma once
#include <memory>
#include <iostream>
#define RED 1
#define BLACK 0
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
		typedef node<T>* branch;
		RB_TREE() 
		{
			_TNULL = new node<T>;
			_TNULL->_color = BLACK;
			_TNULL->_left = nullptr;
			_TNULL->_right = nullptr;
			_root = _TNULL;
		}
		branch getRoot() const { return _root; }
		branch minimum(branch _node) {
			while (_node->_left != TNULL) {
				_node = _node->_left;
			}
			return _node;
		}

		branch maximum(branch _node) {
			while (_node->_right != TNULL) {
				_node = _node->_right;
			}
			return node;
		}
		void deleteNode(T _data) {
			deleteHelper(this->_root, _data);
		}
		branch search(T key) {
			return searchTreeHelper(this->_root,key)
		}
		void insert(const T& _val) {
			branch _new_node = new node<T>;
			_new_node->_parent = nullptr;
			_new_node->_data = _val;
			_new_node->_left = _TNULL;
			_new_node->_right = _TNULL;
			_new_node->_color = RED;
			branch y = nullptr;
			branch x = this->_root;
			while (x != _TNULL) {
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
				_new_node->_color = BLACK;
				return;
			}
			if (_new_node->_parent->_parent == nullptr) {
				return;
			}
			fixInsert(_new_node);
		}
		void LRotate(branch node) {
			branch tmp = node->_right;
			node->_right = tmp->_left;
			if (tmp->_left != _TNULL) {
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
			if (tmp->_right != _TNULL) {
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
			node->_color = BLACK; // black
		}
		void rbTransplant(branch u, branch v) {
			if (u->_parent == nullptr) {
				_root = = v;
			}
			else if (u == u->_parent->_left) {
				u->_parent->_left = v;
			}
			else {
				u->_parent->_right = v;
			}
			v->_parent = u->_parent;
		}

		branch searchTreeHelper(branch _node, T key) {
			if (_node == TNULL || key==_node->_data) {
				return _node;
			}
			if (key < _node->_data) {
				return searchTreeHelper(_node->_left, key);
			}
			return searchTreeHelper(_node->_right, key);
		}

		void deleteHelper(branch _node, T _data) {
			branch z = TNULL;
			branch x;
			branch y;
			while (_node != TNULL) {
				if (_node->_data == _data) {
					z = _node;
				}
				if (_node->_data <= key) {
					_node = _node->_right;
				}
				else {
					_node = _node->_left;
				}
			}
			if (z == TNULL) {
				std::cout << "No such key in the tree" << std::endl;
				return;
			}
			// need to finish
		}
		void fixInsert(branch _b) {
			// need to implement
			branch _tmp;
			while (_b != _root && _b->_color == BLACK) {
				if (_b == _b->_parent->_left) {
					_tmp = _b->_parent->_right;
					if (_tmp->_color == RED) {
						_tmp->_color = BLACK;
						_b->_parent->_color = RED;
						LRotate(_b->_parent);
						_tmp = _b->_parent->_right;
					}
					if (_tmp->_left->_color == BLACK && _tmp->_right->_color == BLACK) {
						_tmp->_color = 1;
						_b = _b->_parent;
					}
					else {
						if (_tmp->_right->_color == BLACK) {
							_tmp->_left->_color = BLACK;
							_tmp->_color = RED;
							RRotate(_tmp);
							_tmp = _b->_parent->_right;
						}
						_tmp->_color = _b->_parent->_color;
						_b->_parent->_color = BLACK;
						_tmp->_right->_color = 0;
						LRotate(_b->_parent);
						_b = _root;
					}
				}
				else {
					_tmp = _b->_parent->_left;
					if (_tmp->_color == RED) {
						_tmp->_color = BLACK;
						_b->_parent->_color = RED;
						RRotate(_b->_parent);
						_tmp = _b->_parent->_left;
					}
					if (_tmp->_right->_color == BLACK && _tmp->_right->_color == 0) {
						_tmp->_color = 1;
						_b = _b->_parent;
					}
					else {
						if (_tmp->_left->_color == BLACK) {
							_tmp->_right->_color = BLACK;
							_tmp->_color = RED;
							LRotate(_tmp);
							_tmp = _b->_parent->_left;
						}
						_tmp->_color = _b->_parent->_color;
						_b->_parent->_color = BLACK;
						_tmp->_left->_color = 0;
						RRotate(_b->_parent);
						_b = _root;
					}
				}
			}
			_b->_color = BLACK;
		}
	};
}