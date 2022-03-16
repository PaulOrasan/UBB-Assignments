function p = probabilitateaDinObservatii(N = 5000)
  count = 0;
  for i = 1:N
    v = extragere();
    if (verificaA(v))
      if (verificaB(v))
        count++;
      endif
    endif
  endfor
  p = count / N;
endfunction