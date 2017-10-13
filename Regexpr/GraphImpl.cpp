#include "GraphImpl.h"
#include <exception>
#include <algorithm>
#include <numeric>
#include <climits>



void wtf_graph::GraphImpl::add_edge(uint32_t from_, uint32_t to_)
{
	VIterator vi = adjs.find(to_);
	if (vi == adjs.end()) {
		return;
	}
	vi = adjs.find(from_);
	if (vi == adjs.end()) {
		return;
	}
	vi->second.insert(to_);
	return;
}

void wtf_graph::GraphImpl::rem_edge(uint32_t from_, uint32_t to_)
{
	VIterator vi = adjs.find(to_);
	if (vi == adjs.end())
		return;
	vi = adjs.find(from_);
	if (vi == adjs.end())
		return;
	vi->second.erase(to_);
	return;
}

uint32_t wtf_graph::GraphImpl::add_vertex()
{
	uint32_t v = adjs.size();
	while (adjs.find(v) != adjs.end() && v < INT32_MAX) {
		++v;
	}
	adjs[v] = std::set<uint32_t>();
	return v;
}

void wtf_graph::GraphImpl::rem_vertex(uint32_t v_)
{
	VIterator vi = adjs.find(v_);
	if (adjs.find == adjs.end()) {
		return;
	}
	adjs.erase(v_);
	return;
}
