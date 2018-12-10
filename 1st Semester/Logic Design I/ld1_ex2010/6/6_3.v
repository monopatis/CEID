module two_bit_comp(Xi, Yi, G_i_1, L_i_1, Gi, Li);
  input  Xi, Yi, G_i_1, L_i_1;
  output Gi, Li;

  not #10 inv0 (notXi,    Xi);
  not #10 inv1 (notYi,    Yi);
  not #10 inv2 (notG_i_1, G_i_1);
  not #10 inv3 (notL_i_1, L_i_1);

  and #20 and2_0 (Gi_0, Xi, notYi);
  and #20 and2_1 (Li_0, notXi, Yi);
  
  and #30 and3_0 (Gi_1,    Xi, G_i_1, notL_i_1);
  and #30 and3_1 (Gi_2, notYi, G_i_1, notL_i_1);
  and #30 and3_2 (Li_1, notXi, L_i_1, notG_i_1);
  and #30 and3_3 (Li_2,    Yi, L_i_1, notG_i_1);

  or  #30 or3_0 (Gi, Gi_0, Gi_1, Gi_2);
  or  #30 or3_1 (Li, Li_0, Li_1, Li_2);
endmodule



module eight_bit_serial (X, Y, G, L);
  input  [7:0] X, Y;
  output G, L;
 
  two_bit_comp i0 (X[1], Y[1], X[0], Y[0], G1, L1);
  two_bit_comp i1 (X[2], Y[2],   G1,   L1, G2, L2);
  two_bit_comp i2 (X[3], Y[3],   G2,   L2, G3, L3);
  two_bit_comp i3 (X[4], Y[4],   G3,   L3, G4, L4);
  two_bit_comp i4 (X[5], Y[5],   G4,   L4, G5, L5);
  two_bit_comp i5 (X[6], Y[6],   G5,   L5, G6, L6);
  two_bit_comp i6 (X[7], Y[7],   G6,   L6,  G,  L);
endmodule



module eight_bit_parallel (X, Y, G, L);
  input  [7:0] X, Y;
  output G, L;

  two_bit_comp i0 (X[1], Y[1], X[0], Y[0], G1, L1);
  two_bit_comp i1 (X[3], Y[3], X[2], Y[2], G3, L3);
  two_bit_comp i2 (X[5], Y[5], X[4], Y[4], G5, L5);
  two_bit_comp i3 (X[7], Y[7], X[6], Y[6], G7, L7);
  two_bit_comp i4 (G7, L7, G5, L5, G7_4, L7_4);
  two_bit_comp i5 (G3, L3, G1, L1, G3_0, L3_0);
  two_bit_comp i6 (G7_4, L7_4, G3_0, L3_0, G,  L);
endmodule



module randomtestdelay();
  reg  [7:0] X, Y;
  
  eight_bit_serial   i0 (X, Y, GS, LS);
  eight_bit_parallel i1 (X, Y, GP, LP);

  initial begin X=0; Y=0; end
  always #1000 begin X=$random; Y=$random; end
endmodule



