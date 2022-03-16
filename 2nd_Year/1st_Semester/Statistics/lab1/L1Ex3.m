function out = L1Ex3(v)
  out = [];
  
  k = input("Numar de elemente pentru submultimi: ");
  
  aux = nchoosek(v, k)
  [linii, coloane] = size(v);
  for i = 1 : linii
    out = [out; perms(aux(i, :))];
  endfor
endfunction