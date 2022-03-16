function conf = extragere(v = [zeros(1, 10) ones(1, 5) 2 2 2 2 2])
  conf = randsample(v, 3, false);
endfunction