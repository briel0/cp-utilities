//Heron -> relaciona perimetro e area do triangulo
double s = (g + l + k) / 2;
double area = sqrt(s * (s - g) * (s - l) * (s - k));

//angulo do triangulo com teorema dos cossenos (sempre bom relembrar)
double alfa = acos((l*l + k*k - g*g) / (2*l*k));

//raio do circuncentro do triangulo
double raio = (g*l*k) / (4*area);

//formula geral area do poligono regular
double area = 0.5*n*raio*raio*sin(2*pi / n);
