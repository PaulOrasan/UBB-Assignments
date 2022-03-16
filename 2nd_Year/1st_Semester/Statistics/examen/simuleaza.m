function simuleaza(urna, extragere, N = 5000)
  countA = 0;
  countB = 0;
  countC = 0;
  for i = 1:N
    e = extragere(urna);
    if (conditieA(e))
      countA++;
    endif
    if (conditieB(e))
      countB++;
    endif
    if (conditieC(e))
      countC++;
    endif
  endfor
  fprintf('Probabilitatea estimata pentru conditia A este %f.\n', countA / N)
  fprintf('Probabilitatea estimata pentru conditia B este %f.\n', countB / N)
  fprintf('Probabilitatea estimata pentru conditia C este %f.\n', countC / N)
endfunction