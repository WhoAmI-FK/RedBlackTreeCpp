#pragma once
#include <memory>
#include <iostream>
namespace RBTREE {
	namespace {
		template<typename T, typename _Alloc = std::allocator<T>>
		struct node {
			typedef node* _node;
			typedef std::string colorPlaceholder;
			T _data;
			_node _left;
			_node _right;
			_node _parent;
			colorPlaceholder _color;
//			int color; // 1 -> Red, 0 -> Black
//			node(const T& data, )
		};
	};

	template<typename T,typename _Alloc=std::allocator<T>>
	class RB_TREE {
	public:
		typedef node* branch;
		RB_TREE() 
		{
			TNULL = new node<T>;
			TNULL->_color = "BLACK";
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
			_new_node->_color = "RED";
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
			// fixInsert(_new_node);
		}

	private:
		branch _root;
		branch _TNULL;
		void fixDelete(branch _b) {

		}
		void fixInsert(branch _b) {

		}
	};
}