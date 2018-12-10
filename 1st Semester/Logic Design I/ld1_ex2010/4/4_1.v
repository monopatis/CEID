module myxorgate1 (A, B, F);
  input  A, B;
  output F;

  xor i0 (F, A, B);
endmodule



module myxorgate2 (A, B, F);
  input  A, B;
  output F;

  assign F = A ^ B;
endmodule



module myxorgate3 (A, B, F);
  input  A, B;
  output F;
  wire   S1, S2;

  assign S1 = A & ~B; 
  assign S2 = ~A & B;
  assign F = S1 | S2;
endmodule



module myxorgate4 (A, B, F);
  input  A, B;
  output F;

  assign S1 = A & ~B; 
  assign S2 = ~A & B;
  assign F = S1 | S2;
endmodule



module myxorgate5 (A, B, F);
  input  A, B;
  output F;

  not i1 (notB, B);
  not i2 (notA, A);
  assign S1 = A & notB; 
  assign S2 = notA & B;
  or o1 (F, S1, S2);   
endmodule



module myxorgate6 (A, B, F);
  input  A, B;
  output F;
  wire SUM;

  assign SUM = (A + B) % 2;
  assign F = (SUM==1)? 1 : 0;
endmodule



module myxorgate7 (A, B, F);
  input  A, B;
  output F;
  wire [1:0] AB;

  assign AB = {A, B};
  assign F = (AB == 0)? 0 : 
             (AB == 3)? 0 : 1;
endmodule



module myxorgate8 (A, B, F);
  input  A, B;
  output F;
  reg F;

  always @(A or B)
    case ({A,B})
      0 : F=0;
      1 : F=1;
      2 : F=1;
      3 : F=0;
    endcase
endmodule



module test_all_xor ();
  reg I1, I2;
  wire F1, F2, F3, F4, F5, F6, F7, F8;

  myxorgate1 i1 (I1, I2, F1);
  myxorgate2 i2 (I1, I2, F2);
  myxorgate3 i3 (I1, I2, F3);
  myxorgate4 i4 (I1, I2, F4);
  myxorgate5 i5 (I1, I2, F5);
  myxorgate6 i6 (I1, I2, F6);
  myxorgate7 i7 (I1, I2, F7);
  myxorgate8 i8 (I1, I2, F8);

  initial begin I1=0; I2=0; end
  initial 
    begin 
      #100 I1 = 1;
      #100 I2 = 1;
      #100 I1 = 0;
    end
endmodule