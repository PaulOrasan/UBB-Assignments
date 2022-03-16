v = [0 0 0 1 2];
valori = [];
for i = 1 : 5000
  e = randsample(v, 2);
  valori = [valori (length(unique(e)) == 1 && e(1) == 0)];
endfor
disp(mean(valori))
disp(nchoosek(3, 2) / nchoosek(5, 2))
disp(nchoosek(3, 2) * factorial(2) / (nchoosek(5, 2) * factorial(2)))