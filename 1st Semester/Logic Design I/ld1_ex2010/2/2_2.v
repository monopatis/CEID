module myOR(A, B, C);
  input A, B;
  output C;

  or (C, A, B);
endmodule

module myand_test();
  reg X, Y;
  wire Z;

  initial
    begin
      #100 X = 0;	Y = 0;
	#100 X = 0;	Y = 1;
	#100 X = 1; Y = 1;
	#100 X = 1; Y = 0;
	#100 $stop;
    end

  myOR someOR (X, Y, Z);
endmodule
