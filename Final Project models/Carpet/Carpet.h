// "Carpet.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Carpet.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Carpet_version_
const char Carpet_version[4] = { '0','1','9','d' };
#define _Carpet_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Carpet_vertexcount_
const unsigned Carpet_vertexcount = 242;
#define _Carpet_vertexcount_
#endif
#ifndef _Carpet_indexcount_
const unsigned Carpet_indexcount = 474;
#define _Carpet_indexcount_
#endif
#ifndef _Carpet_materialcount_
const unsigned Carpet_materialcount = 2; // can be used for batched draws
#define _Carpet_materialcount_
#endif
#ifndef _Carpet_meshcount_
const unsigned Carpet_meshcount = 2;
#define _Carpet_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Carpet_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Carpet_vertices[242] =
{
	{	{ 0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.622717f, 0.141124f, 1.999662f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, -2.320911f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, -2.629710f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.622717f, 0.141124f, -2.320911f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, 2.308461f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.141124f, 2.308461f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.326900f, 0.820900f, 0.468200f }	},
	{	{ -0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.326900f, 0.820900f, 0.468200f }	},
	{	{ -0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.326900f, 0.820900f, 0.468200f }	},
	{	{ 0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.372300f, 0.784600f, -0.495800f }	},
	{	{ 0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.372300f, 0.784600f, -0.495800f }	},
	{	{ 0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.372300f, 0.784600f, -0.495700f }	},
	{	{ 0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.141124f, -2.629710f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.372300f, 0.784600f, -0.495800f }	},
	{	{ -0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.372300f, 0.784600f, -0.495800f }	},
	{	{ -0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.372300f, 0.784600f, -0.495700f }	},
	{	{ -0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.411200f, 0.664300f, -0.624100f }	},
	{	{ -0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.411200f, 0.664400f, -0.624100f }	},
	{	{ -0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.411200f, 0.664400f, -0.624100f }	},
	{	{ 0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.326900f, 0.820900f, 0.468200f }	},
	{	{ 0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.326900f, 0.820900f, 0.468200f }	},
	{	{ 0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.326900f, 0.820900f, 0.468200f }	},
	{	{ -0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.405300f, 0.655400f, 0.637300f }	},
	{	{ -0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.405300f, 0.655400f, 0.637300f }	},
	{	{ -0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.405300f, 0.655400f, 0.637400f }	},
	{	{ 0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.411200f, 0.664300f, -0.624100f }	},
	{	{ 0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.411200f, 0.664400f, -0.624100f }	},
	{	{ 0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.411200f, 0.664400f, -0.624100f }	},
	{	{ -0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.405300f, 0.655400f, 0.637300f }	},
	{	{ 0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.405300f, 0.655400f, 0.637300f }	},
	{	{ 0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.405300f, 0.655400f, 0.637400f }	},
	{	{ -0.863317f, 0.256028f, 1.222101f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.374100f, 0.637400f, 0.673600f }	},
	{	{ -0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.374100f, 0.637400f, 0.673600f }	},
	{	{ -0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.364600f, 0.609200f, -0.704200f }	},
	{	{ 0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.364600f, 0.609200f, -0.704200f }	},
	{	{ 0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.364600f, 0.609200f, -0.704200f }	},
	{	{ -0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, 1.999662f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.256028f, 1.222102f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.364600f, 0.609200f, -0.704200f }	},
	{	{ -0.863317f, 0.256028f, 1.222101f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.364600f, 0.609200f, -0.704200f }	},
	{	{ -0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.364700f, 0.609200f, -0.704200f }	},
	{	{ -0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.326900f, 0.820900f, 0.468200f }	},
	{	{ 0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.372300f, 0.784600f, -0.495800f }	},
	{	{ 0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.372300f, 0.784600f, -0.495800f }	},
	{	{ -0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.411200f, 0.664400f, -0.624100f }	},
	{	{ 0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.326900f, 0.820900f, 0.468200f }	},
	{	{ -0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.405300f, 0.655400f, 0.637300f }	},
	{	{ 0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.411200f, 0.664400f, -0.624100f }	},
	{	{ -0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.405300f, 0.655400f, 0.637300f }	},
	{	{ -0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.863317f, 0.256028f, 1.222102f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.364600f, 0.609200f, -0.704200f }	},
	{	{ -0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.374100f, 0.637400f, 0.673600f }	},
	{	{ 0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.364600f, 0.609200f, -0.704200f }	},
	{	{ -1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 1.054611f, 0.141124f, -2.629714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, -2.629714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.054611f, 0.141124f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, 1.484486f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.502329f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.113700f, 0.853000f, -0.509300f }	},
	{	{ 0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.113600f, 0.852900f, -0.509500f }	},
	{	{ 0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.113500f, 0.852900f, -0.509600f }	},
	{	{ 0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.834400f, -0.551200f }	},
	{	{ 0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.834400f, -0.551200f }	},
	{	{ -0.622717f, 0.141124f, -1.356308f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.834400f, -0.551200f }	},
	{	{ -1.054611f, 0.141124f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.264900f, 0.851400f, 0.452700f }	},
	{	{ -0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.264900f, 0.851300f, 0.452800f }	},
	{	{ -0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.264900f, 0.851300f, 0.452900f }	},
	{	{ -1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.867400f, 0.497600f }	},
	{	{ -1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.867400f, 0.497600f }	},
	{	{ 1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.867400f, 0.497600f }	},
	{	{ 1.054611f, 0.228621f, -1.353833f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.189324f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.228621f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.820700f, -0.483600f }	},
	{	{ -0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.820700f, -0.483600f }	},
	{	{ -0.863317f, 0.141124f, -1.542997f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.820700f, -0.483600f }	},
	{	{ 1.054611f, 0.141124f, -1.502329f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.201847f, -1.120009f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.201847f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.341800f, 0.706900f, -0.619300f }	},
	{	{ -0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.341800f, 0.706900f, -0.619200f }	},
	{	{ -0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.341800f, 0.706900f, -0.619200f }	},
	{	{ 1.054611f, 0.228621f, -1.353833f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.115700f, 0.874400f, 0.471200f }	},
	{	{ 0.863317f, 0.228621f, -1.398509f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.115600f, 0.874300f, 0.471400f }	},
	{	{ 0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.115600f, 0.874400f, 0.471300f }	},
	{	{ 0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.858900f, 0.512100f }	},
	{	{ 0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.858900f, 0.512100f }	},
	{	{ -0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.858900f, 0.512100f }	},
	{	{ -1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.888000f, -0.459900f }	},
	{	{ -1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.888000f, -0.459900f }	},
	{	{ 1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.888000f, -0.459900f }	},
	{	{ -1.054611f, 0.141124f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.228621f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.337000f, 0.697400f, 0.632500f }	},
	{	{ -0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.337000f, 0.697500f, 0.632400f }	},
	{	{ -0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.337000f, 0.697500f, 0.632500f }	},
	{	{ 1.054611f, 0.141124f, -1.053047f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.189324f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.171200f, 0.736700f, -0.654200f }	},
	{	{ 0.863317f, 0.141124f, -1.238439f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.171200f, 0.736700f, -0.654200f }	},
	{	{ 0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.171200f, 0.736700f, -0.654200f }	},
	{	{ 0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.713500f, -0.700700f }	},
	{	{ 0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.713500f, -0.700700f }	},
	{	{ -0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.713500f, -0.700700f }	},
	{	{ -1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.760800f, 0.649000f }	},
	{	{ -1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.760800f, 0.649000f }	},
	{	{ 1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.760800f, 0.649000f }	},
	{	{ -1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, 1.261297f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.201847f, -1.120009f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.180600f, 0.724100f, 0.665600f }	},
	{	{ 0.863317f, 0.201847f, -1.170995f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.180500f, 0.724100f, 0.665700f }	},
	{	{ 0.863317f, 0.141124f, -1.105840f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.180600f, 0.724100f, 0.665600f }	},
	{	{ 0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.701300f, 0.712900f }	},
	{	{ 0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.701300f, 0.712900f }	},
	{	{ -0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.701300f, 0.712900f }	},
	{	{ -1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.749600f, -0.661900f }	},
	{	{ -1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.749600f, -0.661900f }	},
	{	{ 1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.749600f, -0.661900f }	},
	{	{ -1.054611f, 0.141124f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.201847f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.256028f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.310500f, 0.677100f, 0.667200f }	},
	{	{ -1.054611f, 0.141124f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.310500f, 0.677100f, 0.667200f }	},
	{	{ -0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.310500f, 0.677100f, 0.667200f }	},
	{	{ 1.054611f, 0.141124f, 1.484486f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, 1.261297f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.486400f, 0.589800f, -0.644600f }	},
	{	{ 0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.486400f, 0.589900f, -0.644600f }	},
	{	{ 0.863317f, 0.256028f, 1.222102f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.486400f, 0.589900f, -0.644600f }	},
	{	{ 0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.637500f, -0.770500f }	},
	{	{ 0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.637500f, -0.770500f }	},
	{	{ -0.622717f, 0.141124f, 0.998132f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.637500f, -0.770500f }	},
	{	{ -1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.689700f, 0.724000f }	},
	{	{ -1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.689700f, 0.724000f }	},
	{	{ 1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.689700f, 0.724000f }	},
	{	{ -1.054611f, 0.141124f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, 0.141124f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.256028f, 1.367882f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.478100f, 0.621400f, 0.620700f }	},
	{	{ 0.863317f, 0.256028f, 1.222102f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.478100f, 0.621400f, 0.620700f }	},
	{	{ 0.863317f, 0.141124f, 1.335559f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.478100f, 0.621400f, 0.620800f }	},
	{	{ 0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.671100f, 0.741400f }	},
	{	{ 0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.671100f, 0.741400f }	},
	{	{ -0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.671100f, 0.741400f }	},
	{	{ -1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.721600f, -0.692400f }	},
	{	{ -1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.721600f, -0.692400f }	},
	{	{ 1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.721600f, -0.692400f }	},
	{	{ -1.054611f, 0.256028f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.053047f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.054611f, 0.141124f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.303100f, 0.648100f, -0.698600f }	},
	{	{ -1.054611f, 0.256028f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.303100f, 0.648100f, -0.698700f }	},
	{	{ -0.863317f, 0.256028f, 1.222101f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.303100f, 0.648100f, -0.698700f }	},
	{	{ 1.054611f, 0.256028f, 1.367882f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 1.054611f, 0.141124f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -1.054611f, -0.001622f, -2.835411f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 1.054611f, -0.001623f, 2.514162f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.228621f, -1.353833f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.113700f, 0.853000f, -0.509400f }	},
	{	{ -0.622717f, 0.228621f, -1.223851f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.834400f, -0.551200f }	},
	{	{ -1.054611f, 0.228621f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.264900f, 0.851400f, 0.452800f }	},
	{	{ 1.054611f, 0.085874f, -1.514853f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.867400f, 0.497600f }	},
	{	{ 1.054611f, -0.001623f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.502329f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.054611f, 0.141124f, -1.667356f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.820700f, -0.483600f }	},
	{	{ -1.054611f, 0.141124f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.341800f, 0.706900f, -0.619300f }	},
	{	{ 1.054611f, 0.141124f, -1.189324f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.115600f, 0.874300f, 0.471400f }	},
	{	{ -0.622717f, 0.141124f, -1.077111f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.858900f, 0.512100f }	},
	{	{ 1.054611f, -0.001623f, -1.345905f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.888000f, -0.459900f }	},
	{	{ -1.054611f, 0.201847f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.337000f, 0.697500f, 0.632400f }	},
	{	{ 1.054611f, 0.201847f, -1.120009f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.171200f, 0.736700f, -0.654200f }	},
	{	{ -0.622717f, 0.201847f, -1.015283f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.713500f, -0.700700f }	},
	{	{ 1.054611f, 0.059100f, -1.274719f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.760800f, 0.649000f }	},
	{	{ -1.054611f, 0.141124f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 1.054611f, 0.141124f, -1.053047f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.180600f, 0.724100f, 0.665600f }	},
	{	{ -0.622717f, 0.141124f, -0.955553f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.701300f, 0.712900f }	},
	{	{ 1.054611f, -0.001623f, -1.205950f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.749600f, -0.661900f }	},
	{	{ -0.863317f, 0.256028f, 1.222101f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.310500f, 0.677100f, 0.667200f }	},
	{	{ 1.054611f, 0.256028f, 1.367882f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.486400f, 0.589900f, -0.644600f }	},
	{	{ -0.622717f, 0.256028f, 1.093204f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.637500f, -0.770500f }	},
	{	{ 1.054611f, 0.113281f, 1.307963f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.689700f, 0.724000f }	},
	{	{ 1.054611f, 0.141124f, 1.484486f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.478100f, 0.621400f, 0.620700f }	},
	{	{ -0.622717f, 0.141124f, 1.197214f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.671100f, 0.741400f }	},
	{	{ 1.054611f, -0.001623f, 1.427714f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.721600f, -0.692400f }	},
	{	{ 1.054611f, -0.001623f, 1.198503f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 1.054611f, 0.141124f, 1.261297f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.863317f, 0.141124f, 1.118393f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.303100f, 0.648100f, -0.698700f }	},
};
#define _Carpet_vertices_
#endif
#ifndef _Carpet_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Carpet_indices[474] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 5, 7,
	 8, 9, 2,
	 10, 11, 12,
	 13, 14, 15,
	 16, 17, 7,
	 18, 19, 20,
	 21, 22, 23,
	 24, 25, 26,
	 27, 28, 29,
	 30, 31, 32,
	 33, 34, 35,
	 36, 37, 38,
	 39, 40, 41,
	 42, 43, 44,
	 45, 8, 46,
	 47, 48, 49,
	 50, 51, 52,
	 53, 54, 55,
	 0, 2, 9,
	 3, 5, 6,
	 6, 7, 17,
	 8, 2, 46,
	 10, 12, 56,
	 13, 15, 57,
	 16, 7, 58,
	 18, 20, 59,
	 21, 23, 60,
	 24, 26, 61,
	 27, 29, 62,
	 30, 32, 63,
	 33, 35, 64,
	 36, 38, 65,
	 39, 41, 66,
	 42, 44, 67,
	 45, 46, 68,
	 47, 49, 69,
	 50, 52, 70,
	 53, 55, 71,
	 72, 73, 74,
	 75, 76, 77,
	 78, 79, 80,
	 81, 82, 83,
	 84, 85, 86,
	 87, 88, 9,
	 89, 17, 90,
	 91, 3, 6,
	 89, 92, 6,
	 2, 1, 68,
	 93, 0, 9,
	 94, 95, 96,
	 97, 98, 99,
	 100, 101, 102,
	 103, 104, 105,
	 106, 107, 108,
	 109, 110, 111,
	 109, 112, 113,
	 114, 115, 116,
	 58, 7, 5,
	 90, 17, 16,
	 117, 118, 119,
	 120, 106, 121,
	 107, 122, 123,
	 124, 125, 126,
	 127, 128, 129,
	 130, 131, 132,
	 133, 134, 135,
	 136, 137, 111,
	 138, 139, 140,
	 122, 141, 142,
	 143, 144, 145,
	 146, 147, 148,
	 149, 150, 151,
	 136, 152, 153,
	 141, 154, 155,
	 156, 33, 64,
	 157, 158, 159,
	 160, 161, 162,
	 163, 164, 165,
	 166, 167, 153,
	 168, 169, 170,
	 171, 172, 173,
	 174, 175, 176,
	 177, 178, 179,
	 180, 181, 182,
	 183, 184, 185,
	 171, 186, 187,
	 188, 87, 8,
	 189, 190, 191,
	 192, 193, 194,
	 195, 196, 197,
	 73, 198, 185,
	 183, 166, 199,
	 200, 201, 202,
	 70, 52, 35,
	 203, 51, 50,
	 204, 205, 206,
	 154, 207, 173,
	 72, 74, 208,
	 75, 77, 209,
	 79, 78, 120,
	 78, 80, 210,
	 81, 83, 211,
	 84, 86, 212,
	 87, 9, 8,
	 91, 6, 92,
	 89, 6, 17,
	 2, 68, 46,
	 93, 9, 88,
	 94, 96, 213,
	 97, 99, 214,
	 100, 102, 215,
	 103, 105, 216,
	 106, 108, 121,
	 109, 111, 137,
	 109, 113, 110,
	 114, 116, 217,
	 58, 5, 4,
	 90, 16, 218,
	 117, 119, 219,
	 120, 121, 79,
	 107, 123, 108,
	 124, 126, 220,
	 127, 129, 221,
	 130, 132, 222,
	 133, 135, 223,
	 136, 111, 152,
	 138, 140, 224,
	 122, 142, 123,
	 143, 145, 225,
	 146, 148, 226,
	 149, 151, 227,
	 136, 153, 167,
	 141, 155, 142,
	 156, 64, 228,
	 157, 159, 229,
	 160, 162, 230,
	 163, 165, 231,
	 166, 153, 199,
	 168, 170, 232,
	 171, 173, 207,
	 174, 176, 233,
	 177, 179, 234,
	 180, 182, 235,
	 183, 185, 198,
	 171, 187, 172,
	 188, 8, 45,
	 189, 191, 236,
	 192, 194, 237,
	 195, 197, 238,
	 73, 185, 74,
	 183, 199, 184,
	 200, 202, 239,
	 70, 35, 34,
	 203, 50, 240,
	 204, 206, 241,
	 154, 173, 155,
};
#define _Carpet_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Carpet_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Carpet_materials[2] =
{
	{
		{{ 0.800003f, 0.382697f, 0.064921f },
		0.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078423f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		9},
		"Gold",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
	{
		{{ 0.800002f, 0.067156f, 0.051991f },
		0.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078423f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		9},
		"Red",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Carpet_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Carpet_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Carpet_batches[2][2] =
{
	{ 120, 0 },
	{ 354, 120 },
};
#define _Carpet_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Carpet_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Carpet_meshes[2] =
{
	{
		"default",
		120,
		0,
		0,
	},
	{
		"default",
		354,
		120,
		1,
	},
};
#define _Carpet_meshes_
#endif
