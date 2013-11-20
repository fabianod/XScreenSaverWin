#include "gllist.h"
static const float data[]={
	0.998257,-0.059011,0,-0.18331,-0.276766,0.209005,
	0.998257,-0.059011,0,-0.196507,-0.5,0.123502,
	0.998257,-0.059011,0,-0.196507,-0.5,-0.235113,
	0.99951,0.002941,-0.031177,-0.18331,0,0.235113,
	0.99951,0.002941,-0.031177,-0.18331,-0.276766,0.209005,
	0.99951,0.002941,-0.031177,-0.196507,-0.5,-0.235113,
	0,1,0,-0.059418,-0.5,0.123502,
	0,1,0,-0.058641,-0.5,-0.235113,
	0,1,0,-0.196507,-0.5,-0.235113,
	0,1,0,-0.059418,-0.5,0.123502,
	0,1,0,-0.196507,-0.5,-0.235113,
	0,1,0,-0.196507,-0.5,0.123502,
	0.998257,0.059011,0,-0.196507,0.5,0.123502,
	0.998257,0.059011,0,-0.18331,0.276766,0.209005,
	0.998257,0.059011,0,-0.196507,0.5,-0.235113,
	0.99951,-0.002941,-0.031177,-0.196507,0.5,-0.235113,
	0.99951,-0.002941,-0.031177,-0.18331,0.276766,0.209005,
	0.99951,-0.002941,-0.031177,-0.18331,0,0.235113,
	0,-1,0,-0.196507,0.5,0.123502,
	0,-1,0,-0.196507,0.5,-0.235113,
	0,-1,0,-0.059418,0.5,0.123502,
	0.999606,0,-0.028053,-0.196507,0.5,-0.235113,
	0.999606,0,-0.028053,-0.18331,0,0.235113,
	0.999606,0,-0.028053,-0.196507,-0.5,-0.235113,
	-0.99999,-0.003119,-0.003317,-0.058641,0.5,-0.235113,
	-0.99999,-0.003119,-0.003317,-0.058641,0,0.235113,
	-0.99999,-0.003119,-0.003317,-0.059418,0.276766,0.209005,
	-0.999997,0.00083,-0.002166,-0.059418,-0.276766,0.209005,
	-0.999997,0.00083,-0.002166,-0.058641,-0.5,-0.235113,
	-0.999997,0.00083,-0.002166,-0.059418,-0.5,0.123502,
	-0.99999,0.003119,-0.003317,-0.058641,0,0.235113,
	-0.99999,0.003119,-0.003317,-0.058641,-0.5,-0.235113,
	-0.99999,0.003119,-0.003317,-0.059418,-0.276766,0.209005,
	-1,0,0,-0.058641,0.5,-0.235113,
	-1,0,0,-0.058641,-0.5,-0.235113,
	-1,0,0,-0.058641,0,0.235113,
	0,-0,1,-0.058641,-0.5,-0.235113,
	0,-0,1,-0.058641,0.5,-0.235113,
	0,-0,1,-0.196507,0.5,-0.235113,
	0,0,1,-0.058641,-0.5,-0.235113,
	0,0,1,-0.196507,0.5,-0.235113,
	0,0,1,-0.196507,-0.5,-0.235113,
	0,-1,-0,-0.059418,0.5,0.123502,
	0,-1,-0,-0.196507,0.5,-0.235113,
	0,-1,-0,-0.058641,0.5,-0.235113,
	-0.999997,-0.00083,-0.002166,-0.058641,0.5,-0.235113,
	-0.999997,-0.00083,-0.002166,-0.059418,0.276766,0.209005,
	-0.999997,-0.00083,-0.002166,-0.059418,0.5,0.123502,
	1,0,0,0.058641,0.5,-0.235113,
	1,0,0,0.058641,0,0.235113,
	1,0,0,0.058641,-0.5,-0.235113,
	0.999997,0.00083,-0.002166,0.059418,-0.276766,0.209005,
	0.999997,0.00083,-0.002166,0.059418,-0.5,0.123502,
	0.999997,0.00083,-0.002166,0.058641,-0.5,-0.235113,
	0.99999,-0.003119,-0.003317,0.058641,0.5,-0.235113,
	0.99999,-0.003119,-0.003317,0.059418,0.276766,0.209005,
	0.99999,-0.003119,-0.003317,0.058641,0,0.235113,
	0.99999,0.003119,-0.003317,0.058641,0,0.235113,
	0.99999,0.003119,-0.003317,0.059418,-0.276766,0.209005,
	0.99999,0.003119,-0.003317,0.058641,-0.5,-0.235113,
	-0.998257,0.059011,0,0.196507,0.5,-0.235113,
	-0.998257,0.059011,0,0.18331,0.276766,0.209005,
	-0.998257,0.059011,0,0.196507,0.5,0.123502,
	-0.99951,0.002941,-0.031177,0.18331,0,0.235113,
	-0.99951,0.002941,-0.031177,0.196507,-0.5,-0.235113,
	-0.99951,0.002941,-0.031177,0.18331,-0.276766,0.209005,
	0,1,0,0.059418,-0.5,0.123502,
	0,1,0,0.196507,-0.5,-0.235113,
	0,1,0,0.058641,-0.5,-0.235113,
	-0.998257,-0.059011,0,0.18331,-0.276766,0.209005,
	-0.998257,-0.059011,0,0.196507,-0.5,-0.235113,
	-0.998257,-0.059011,0,0.196507,-0.5,0.123502,
	0,-1,0,0.059418,0.5,0.123502,
	0,-1,0,0.196507,0.5,-0.235113,
	0,-1,0,0.196507,0.5,0.123502,
	0,1,0,0.196507,-0.5,0.123502,
	0,1,0,0.196507,-0.5,-0.235113,
	0,1,0,0.059418,-0.5,0.123502,
	-0.99951,-0.002941,-0.031177,0.196507,0.5,-0.235113,
	-0.99951,-0.002941,-0.031177,0.18331,0,0.235113,
	-0.99951,-0.002941,-0.031177,0.18331,0.276766,0.209005,
	-0.999606,-0,-0.028053,0.196507,0.5,-0.235113,
	-0.999606,-0,-0.028053,0.196507,-0.5,-0.235113,
	-0.999606,-0,-0.028053,0.18331,0,0.235113,
	0,0,1,0.196507,0.5,-0.235113,
	0,0,1,0.058641,-0.5,-0.235113,
	0,0,1,0.196507,-0.5,-0.235113,
	0,0,1,0.196507,0.5,-0.235113,
	0,0,1,0.058641,0.5,-0.235113,
	0,0,1,0.058641,-0.5,-0.235113,
	0.999997,-0.00083,-0.002166,0.059418,0.5,0.123502,
	0.999997,-0.00083,-0.002166,0.059418,0.276766,0.209005,
	0.999997,-0.00083,-0.002166,0.058641,0.5,-0.235113,
	0,-1,-0,0.059418,0.5,0.123502,
	0,-1,-0,0.058641,0.5,-0.235113,
	0,-1,-0,0.196507,0.5,-0.235113
};
static const struct gllist frame={GL_N3F_V3F,GL_TRIANGLES,96,data,NULL};
const struct gllist *toaster_slots=&frame;
