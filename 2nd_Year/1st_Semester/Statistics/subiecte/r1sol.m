lambda = 1 / 4;
a = 1;
b = 3;

disp('a)')
fprintf('Probabilitatea teoretica este %f.\n', expcdf(3, 1 / lambda))

disp('b)')

N = 1000;
t1 = exprnd(1 / lambda, 1, N);
t2 = (t1 > 4) .* unifrnd(a, b, 1, N);

% smecheria asta transforma valorile mai mari ca 4 dintr-un vector in 4
s1 = (t1 > 4);
s1 = s1 .* 4;
s1 = (t1 <= 4) .* t1 + s1;

timpuri = [s1; t2];
valori = sum(timpuri);

fprintf('Valoarea medie este %f secunde.\n', mean(valori))

disp('c)')
fprintf('Probabilitea estimata este de %f.\n', sum((t1 <= 4)) / N)