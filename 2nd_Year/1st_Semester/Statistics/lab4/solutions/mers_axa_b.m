m = 100;
k = 100;
pozitii = [];
for i = 1:m
  pozitii = [pozitii mers_axa_a()(end);];
endfor
disp(pozitii);

h = histc(pozitii, -k : k)
disp(find(h == max(h)) - k - 1)