#pragma once
#include <cinttypes>
#include <vector>
#include <map>
#include <set>

namespace wtf_graph {
	using std::vector;
	using std::map;
	using std::set;
	class GraphImpl {
		typedef map<uint32_t, set<uint32_t>>::iterator VIterator;
		typedef set<uint32_t>::iterator EIterator;
	public:
		GraphImpl() : adjs() {}
		GraphImpl(uint32_t sz_) {
			for (uint32_t i = 0; i < sz_; ++i) {
				adjs[i] = set<uint32_t>();
			}
		}
		GraphImpl(const GraphImpl&) = delete;
		GraphImpl operator=(const GraphImpl&) = delete;
	public:
		void add_edge(uint32_t from_, uint32_t to_);
		void rem_edge(uint32_t from_, uint32_t to_);
		uint32_t add_vertex();
		void rem_vertex(uint32_t v_);
	public:

	private:
		map<uint32_t, set<uint32_t>> adjs;
	};
}
