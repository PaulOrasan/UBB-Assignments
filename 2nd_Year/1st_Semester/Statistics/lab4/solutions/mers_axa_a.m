function v = simulare(p = 0.62, k = 100)
  nod = 0;
  v = [nod];
  for i = 1:k
    if rand() < p
      nod++;
    else
      nod--;
    endif
    v = [v nod];
  endfor
endfunction
    
