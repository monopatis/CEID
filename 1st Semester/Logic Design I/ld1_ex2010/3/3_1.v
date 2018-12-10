module circuit3_1(A, B, C, Z);
	input A, B, C;
	output Z;
	
	wire K, L;

	and AND1(K, A, B);
	and AND2(L, B, C);
	or OR1(Z, K, L);

endmodule


module circuit3_1_test();
	reg A, B, C;
	wire Z;

	circuit3_1 kyklwma3_1(A, B, C, Z);

	initial
	begin
	#100;
	A = 0;
	B = 0;
	C = 0;
	
	#100;
	A = 0;
	B = 0;
	C = 1;

	#100;
	A = 0;
	B = 1;
	C = 0;

	#100;
	A = 0;
	B = 1;
	C = 1;

	#100;
	A = 1;
	B = 0;
	C = 0;
	
	#100;
	A = 1;
	B = 0;
	C = 1;

	#100;
	A = 1;
	B = 1;
	C = 0;

	#100;
	A = 1;
	B = 1;
	C = 1;

	#100;
	$stop;
	end

endmodule