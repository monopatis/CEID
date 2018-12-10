module myand(A, B, C);
  input A, B;
  output C;

  and (C, A, B);
endmodule

module myand_test();
  reg X, Y;
  wire Z;

  initial
    begin
      #100 X = 0;	Y = 0;
	#100 X = 0;	Y = 1;
	#100 X = 1; Y = 1;
	#100;
	#100 $stop;
    end

  myand inst1 (X, Y, Z);
endmodule
