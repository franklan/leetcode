#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node 
{
	int key;
	string data;
	Node* prev, *next;
};

class LRU
{
public:
	LRU(size_t size) 
	{
		for(int i = 0; i < size; ++i)
		{
			Node* entry = new Node();
			free_.push_back(entry);
		}
		head_ = new Node();
		tail_ = new Node();
		head_->prev = nullptr;
		head_->next = tail_;
		tail_->next = nullptr;
		tail_->prev = head_;
	}

	~LRU() 
	{
		delete head_;
		delete tail_;
		for (auto & it : free_)
		{
			delete it;
			it = NULL;
		}
	}
public:
	void put(int k, string v)
	{
		Node* node = m_[k];
		if (node)
		{
			detach(node);
			node->data = v;
			attach(node);
		}
		else
		{
			if (free_.empty())
			{
				node = tail_->prev;
				detach(node);
				m_.erase(node->key);
			}
			else
			{
				node = free_.back();
				free_.pop_back();
			}
			node->key = k;
			node->data = v;
			m_[k] = node;
			attach(node);
		}
	}
	string Get(int k)
	{
		if (m_.find(k) == m_.end()) return "";
		
		Node* node = m_[k];
		detach(node);
		attach(node);
		return node->data;
	}
private:
	void detach(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	// always attach it on HEAD
	void attach(Node* node)
	{
		node->prev = head_;
		node->next = head_->next;
		head_->next = node;
		node->next->prev = node;
	}
private:
	unordered_map<int, Node*> m_;
	Node* head_;
	Node* tail_;
	vector<Node*> free_;
};
