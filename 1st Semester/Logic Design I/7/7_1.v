module ex7 (W, X, Y, Z, G);
	input W, X, Y, Z;
	output G;
	wire A, B, C;
	assign A=~((~W) &(~X));
	assign B=~((~Y)&(~Z));
	assign C=~((~Y)&(~X));
	assign G=~(A&B&C);
endmodule

module test_ex7 ();
	reg	K, L, M, N;
	wire	O;
	
ex7 i0 (K, L, M, N, O);

	initial begin K=$random; L=$random; M=$random; N=$random; end
	    always #100 begin K=$random; L=$random; M=$random; N=$random; end
	endmodule