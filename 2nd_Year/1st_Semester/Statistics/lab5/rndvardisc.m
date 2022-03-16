function X = rndvardisc(x = [1 : 4], p = [0.46, 0.4, 0.1, 0.04], N = 10)
  q = cumsum(p) % suma cumulativa
  X = zeros(1, N);
  for i = 1 : N
    U = rand;
    j = 1;
    while U > q(j)
      j++;
    endwhile
    X(i) = x(j);
  endfor
endfunction