#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

void
graph_init(graph_t g)
{
	assert (g != NULL);

	memset(g, 0, sizeof(struct graph));
}

void
graph_insert_vertex(graph_t g, vertex_t v)
{
	assert (g != NULL);
	assert (v != NULL);

	if (g->v == NULL) {
		/* Insert vertex into empty graph */
		g->v = v;
		return;
	}
	/* Insert at the front of the double linked list */
	g->v->prev = v;
	v->next = g->v;
	g->v = v;
}

vertex_t
graph_find_vertex_by_id(graph_t g, vertexid_t id)
{
	vertex_t v;

	assert (g != NULL);

	for (v = g->v; v != NULL; v = v->next)
		if (v->id == id)
			return v;

	return NULL;
}

void
graph_insert_edge(graph_t g, edge_t e)
{
	if (g->e == NULL) {
		/* Insert edge into empty graph edge set */
		g->e = e;
		return;
	}
	/* Insert at the front of the double linked list */
	g->e->prev = e;
	e->next = g->e;
	g->e = e;

}

void
graph_print(graph_t g)
{
	vertex_t v;
	edge_t e;

	assert (g != NULL);

	/* Vertices */
	for (v = g->v; v != NULL; v = v->next) {
		vertex_print(v);
		printf("\n");
	}
	/* Edges */
	for (e = g->e; e != NULL; e = e->next) {
		edge_print(e);
		printf("\n");
	}
}
