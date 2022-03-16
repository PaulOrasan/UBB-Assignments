disp('i)')

p = 0;  % sansa de a nimeri un bilet castigator
for i = 3:6       % castiga daca nimereste 3, 4, 5, 6 numere castigatoare
  p += hygepdf(i, 49, 6, 6); % sansa de a nimeri i bile albe dintr-o urna cu 49 de bile unde 6 bile sunt albe si se fac 6 extrageri
endfor
disp(p)
v = [];
N = 1000
for i = 1:N
  v = [v geornd(p)];
endfor
disp(v)
disp('ii)')
p2 = 0;
for i = 0:9
  p2 += geopdf(i, p);
endfor
disp(sum(v >= 10) / N)
disp(1-p2)