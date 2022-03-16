function out = verificaCerc(pct, latura)
  out = pdist([pct; [latura / 2, latura / 2]]) <= latura / 2;
endfunction