module four_bit_comp (X, Y, G, L);
  input  [3:0] X, Y;
  output G, L;

 assign G = (X > Y) ? 1 : 0;
 assign L = (Y > X) ? 1 : 0; 
endmodule



module fbc_serial (X, Y, g, l);
  input  [3:0] X, Y;
  output       g, l;

  wire [3:0] G, L;
  
  assign g = G[3];
  assign l = L[3];

  assign G[3:0] = (X[3:0] & ~Y[3:0]) | (X[3:0] & {G[2:0], X[0]} & ~{L[2:0], Y[0]}) | (~Y[3:0] & {G[2:0], X[0]} & ~{L[2:0], Y[0]});
  assign L[3:0] = (~X[3:0] & Y[3:0]) | (~X[3:0] & ~{G[2:0], X[0]} & {L[2:0], Y[0]}) | (Y[3:0] & ~{G[2:0], X[0]} & {L[2:0], Y[0]});
endmodule



module testfbc ();
  reg [3:0] X, Y;
  wire      G1, L1, G2, L2;

four_bit_comp i0 (X, Y, G1, L1);
fbc_serial     i1 (X, Y, G2, L2);

initial begin X=$random; Y=$random; end
always #40 begin X=$random; Y=$random; end
endmodule


