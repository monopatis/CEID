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

module testdelay();
  reg  Xi, Yi, G_i_1, L_i_1;
  wire Gi, Li;

two_bit_comp i0 (Xi, Yi, G_i_1, L_i_1, Gi, Li);
initial 
  begin 
         Xi=1; Yi=1; G_i_1=1; L_i_1=1; 
    #100 G_i_1=0; 
  end
endmodule
