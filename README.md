# Sonar
Projekt napisano w okresie: 2016_01

Programowanie z wykorzystaniem strumieni do operacji na plikach BMP

Napisz program, który do obrazu dodaje kolorowe logo Katedry Systemów Elektroniki Morskiej, pozbawione białego tła. 
Logo powinno znaleźć się w pracym górnym rogu obrazka, 20 pikseli od prawego brzegu i 15 pikseli od górnej krawędzi.
Obraz wynikowy powinien mieć format 24-bitowej bitmapy (taki sam format mają pliki wejściowe).

Kopiowanie pikseli loga należy zrealizować niezależnie dla każdej składowej RGB.
W celu rozpoznania, czy dany piksel reprezentuje kolor biały, wystarczy sprawdzić, czy wszystkie jego składowe RGB są równe bądź bliskie wartości 255 (np. większe niż 250).
Pamiętaj, że kolejne wiersze obrazu zapisane są w bitmapie w odwrotnej kolejności, niż są wyświetlane.
