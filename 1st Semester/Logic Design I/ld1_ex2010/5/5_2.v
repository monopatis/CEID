module decoder2_2_4 (S1, S0, O0, O1, O2, O3);
  input S1, S0;
  output O0, O1, O2, O3;

  assign O0 = ~S1 & ~S0;
  assign O1 = ~S1 & S0;
  assign O2 = S1 & ~S0;
  assign O3 = S1 & S0;
endmodule



module mux4_2_1_decoder_based (A, B, C, D, S, T, O);
  input A, B, C, D, S, T;
  output O;
  wire D0, D1, D2, D3;

  decoder2_2_4 i0 (S, T, D0, D1, D2, D3);
  and          i1 (P1, D0, A);
  and          i2 (P2, D1, B);
  and          i3 (P3, D2, C);
  and          i4 (P4, D3, D);
  or           i5 (O, P1, P2, P3, P4);
endmodule



module testhier ();
  reg A, B, C, D;
  reg S, T;
  wire O1;

  mux4_2_1_decoder_based i0 (A, B, C, D, S, T, O1);

  initial begin A=0; B=0; C=0; D=0; S=0; T=0; end

  always #  20 A=~A;
  always #  40 B=~B;
  always #  80 C=~C;
  always # 160 D=~D;
  
  always #1000 T=~T;
  always #2000 S=~S;
endmodule

