function out = submultimi(v)
  out = []
  k = input("Lungimea submultimilor: ")
  aux = nchoosek(v, k)
  [linii, coloane] = size(v)
  for i = 1 : linii
    out = [out; perms(aux(i, :))]
  endfor
endfunction