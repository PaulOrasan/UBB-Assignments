N = 500;
x = rand(1, N);
x = (x <= 0.5) * -1 + (x > 0.5) * 4; % inlocuim cu -1 cele mai mici ca 0.5 si cu 4 cele mai mari

a = -1
b = 4
y = unifrnd(a, b, 1, 500);

u = x .^ 3 - y .^ 3;

frecv = hist(u, 20)
bar(frecv)
xlim([0 21])

fprintf('Probabilitatea P(U<0) estimata este %f\n', mean(u < 0))
fprintf('Valorea medie a lui U este %f\n', mean(u))
fprintf('Varianta lui U este %f\n', std(u))

fprintf('Valoarea medie teoretica a lui X^3 este %f.\n', -1 * 0.5 + 64 * 0.5)