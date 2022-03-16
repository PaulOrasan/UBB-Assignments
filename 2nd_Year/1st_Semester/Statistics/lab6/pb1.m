function pb1(n = 2000)
  close all;
  x = normrnd(165, 10, 1, n);
  % i)
  figure(1)
  hist(x, 10);
  % ii)
  figure(2)
  [x1, xx] = hist(x, 10)
  hist(x, xx, 10 / (max(x) - min(x))); % ultimul parametru este folosit pentru normalizare;
  hold on;
  t = linspace(min(x), max(x), 1000);
  plot(t, normpdf(t, 165, 10), '-r', 'LineWidth', 3);
  %iii)
  mean(x)
  165
  std(x)
  10
  mean((x >= 160) & (x <= 170))
  normcdf(170, 165, 10) - normcdf(160, 165, 10)
endfunction