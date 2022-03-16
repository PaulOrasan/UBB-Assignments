m = 1;
sigma = 1;
lambda = 1 / 2;

disp('a)')

fprintf('Probabilitatea teoretica este %f.\n', normcdf(1.5, m, sigma))

disp('b)')

N = 2000;
s1 = normrnd(m, sigma, 1, N);
s1 = arrayfun(@abs, s1);
s2 = exprnd(1 / lambda, 1, N) .* (s1 > 2);  % s2 generat doar daca s1 nu se incadreaza in 2 secunde

s1 = ((s1 > 2) .* 2) + ((s1 <= 2) .* s1);   % cream un vector care are valoarea 0 daca s1 <= 2 si 2 daca s1 > 2
                                            % si taiem din s1 valorile > 2 inlocuindu-le cu 2
matrice = [s1; s2];

timpi = sum(matrice);

fprintf('Valoarea medie a timpului de asteptare este %f.\n', mean(timpi))

disp('c)')

fprintf('Probabilitatea estimata sa fie procesat in cel mult 4 secunde este %f.\n', mean(timpi <= 4))
