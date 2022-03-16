nr_sim = 1000;
x1 = rndexp(nr_sim, 1 / 12); % 1 / lambda
x2 = exprnd(12, 1, nr_sim); % lambda
[mean(x1), mean(x2)]
[std(x1, 1), std(x2, 1)]