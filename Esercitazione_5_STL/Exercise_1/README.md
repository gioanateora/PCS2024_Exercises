# Triangular mesh

Triangular meshes are largely used in many graphic softwares and for simulating mathematical-model.

## Requirements

Build a C++ program which exploits STL utilities to memorize and manage efficiently the main properties of a triangular mesh.

The program should memorize and test imported properties of a triangular mesh read from files.

In particular a triangular mesh is composed by

1. Cell0D, which we read from a space-separated Cell0Ds.csv file of format

```text
Id	Marker	X	Y
0	1	0.0000000000000000e+00	0.0000000000000000e+00
... (many rows)
```

2. Cell1D, which we read from a space-separated Cell1Ds.csv file of format

```text
Id	Marker	Origin	End
0	0	41	43
... (many rows)
```

3. Cell2D, which we read from a space-separated Cell2Ds.csv file of format

```text
Id	Vertices	Edges				
0	41	43	15	0	1	2
... (many rows)
```


