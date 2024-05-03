# Compute polygonal area

Data in input una lista di poligoni convessi privi di lati allineati che giacciono sul piano xy. Si richiede di:

- calcolare l'area partendo da una sua triangolazione;

- creare la documentazione UML che modellizzi la struttura definita dal codice C++;

- testare tutti i metodi e le funzioni implementate tramite i GoogleTest;

- esportare i poligoni tramite paraview.

La lista di poligoni verrà fornita in input da file

\tiny

```test
# Num Points
22
# Coordinates
2.8497189605540285e-01 -1.3877787807814457e-17 0.0000000000000000e+00
6.6483884502196300e-01 -1.3877787807814457e-17 0.0000000000000000e+00
....
# NumPolygons
10
# PolygonId NumVertices
0 5
# Vertices 
1 3 2 4 0
# PolygonId NumVertices
1 5
# Vertices 
5 7 6 3 1
# PolygonId NumVertices
...
```
