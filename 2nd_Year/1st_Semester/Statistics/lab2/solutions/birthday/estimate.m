function out = estimate(n = 23, N = 1000)
  p = 0;
  favorabil = 0;
  for i = 1 : N
    if check(generate(n))
      favorabil++;
    endif
  endfor
  out = favorabil / N;
endfunction