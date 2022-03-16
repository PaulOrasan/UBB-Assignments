function mat = simulare(N = 1000)
  count = zeros(1, 24);
  for i = 1:N
    count(sum(aruncaZaruri()))++;
  endfor
  mat = []
  for i = 1:24
    if (count(i) > 0)
      mat = [mat; [i count(i)]];
    endif
  endfor
endfunction