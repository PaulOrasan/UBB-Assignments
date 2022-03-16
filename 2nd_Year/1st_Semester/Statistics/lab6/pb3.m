N = 1000;
y = exprnd(5, 1, N) .* (r <= 0.4) + unifrnd(4, 6, 1, N) .* (r > 0.4);
mean(y)
std(y)

r = rand(1, N);
T = exprnd(1,1,N).*(r <= 0.1) + exprnd(2,1,N).*(r > 0.1 & r <= 0.3) + exprnd(3,1,N).*(r > 0.3 & r <= 0.6) + exprnd(4,1,N).*(r > 0.6);

% b)
mean(y > 5)

% c)
count1 = 0; count2 = 0;
for i = 1 : N
  r = rand;
  if r <= 0.4
    I = 1;
    T = exprnd(5);
  else
    I = 2;
    T = unifrnd(4,6);
  end
  if T > 5
    count1++;
    
    if I == 2
      count2++;
    endif
    
  endif
endfor
count2 / count1
