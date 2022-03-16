function p = probabilitateaAsiB(N = 5000)
  count = 0;
  for i = 1:N
    v = extragere();
    if (verificaA(v) && verificaB(v))
      count++;
    endif
  endfor
  p = count / N;
endfunction
