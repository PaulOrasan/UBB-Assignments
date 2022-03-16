clear all;
close all;
figure;
title('Functia de densitate')
hold on;
lambda = 2;
interval = [-2:1:5];
plot(interval, exppdf(interval, 1 / lambda)) 

figure;
title('Functia de repartitie')
hold on;
plot(interval, expcdf(interval, 1 / lambda)) 

N = 2000;
valori = exprnd(1 / lambda, 1, N);
fprintf('Valoarea medie este %f.\n', mean(valori))
fprintf('Deviatia standard este %f.\n', std(valori))
fprintf('Probabilitatea P(X > 0.7) estimata este %f.\n', mean(valori > 0.7))
fprintf('Probabilitatea P(X > 0.7) teoretica este %f.\n', 1 - expcdf(0.7, 1 / lambda))