function p = probabilitateaA(N = 5000)
  count = 0;
  for i = 1:N
    if verificaA(extragere())
      count++;
    endif
  endfor
  p = count / N;
endfunction