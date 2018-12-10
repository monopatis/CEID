module testHam;
  reg [1:8] original;
  wire [1:8] regenerated;
  wire [1:12] encoded, messedUp;
  integer seed;
  
  initial 
    begin
      seed = 1;
      forever 
        begin
          original = $random;
          #1 $display("original=%h, encoded=%h, messed=%h, regen=%h", original, encoded, messedUp, regenerated);
        end
    end
  hamEncode hIn (original, encoded);
  hamDecode hOut (messedUp, regenerated);
  assign messedUp = encoded ^ 12'b 0000_0010_0000;
endmodule



module hamEncode (input [1:8] vIn, output [1:12] valueOut);
  wire h1, h2, h4, h8;
  
  xor (h1, vIn[1], vIn[2], vIn[4], vIn[5], vIn[7]),
      (h2, vIn[1], vIn[3], vIn[4], vIn[6], vIn[7]),
      (h4, vIn[2], vIn[3], vIn[4], vIn[8]),
      (h8, vIn[5], vIn[6], vIn[7], vIn[8]);
  assign valueOut = {h1, h2, vIn[1], h4, vIn[2:4], h8, vIn[5:8]};
endmodule

module xor8 (output [1:8] xout, input [1:8] xin1,xin2);
  xor a[1:8] (xout, xin1, xin2);
endmodule




module hamDecode (input [1:12] vIn, output [1:8] valueOut);
  wire c1, c2, c4, c8;
  wire [1:8] bitFlippers;

  xor (c1, vIn[1], vIn[3], vIn[5], vIn[7], vIn[9], vIn[11]),
      (c2, vIn[2], vIn[3], vIn[6], vIn[7], vIn[10], vIn[11]),
      (c4, vIn[4], vIn[5], vIn[6], vIn[7], vIn[12]),
      (c8, vIn[8], vIn[9], vIn[10], vIn[11], vIn[12]);
  deMux mux1 (bitFlippers, c1, c2, c4, c8, 1'b1);
  xor8 x1 (valueOut, bitFlippers, {vIn[3], vIn[5], vIn[6], vIn[7], vIn[9],vIn[10],vIn[11],vIn[12]});
endmodule




module deMux (output [1:8] outVector, input A, B, C, D, enable);
  and v  (m12, D, C, ~B, ~A, enable),
      h  (m11, D, ~C, B, A, enable),
      d  (m10, D, ~C, B, ~A, enable),
      l  (m9, D, ~C, ~B, A, enable),
      s  (m7,~D,C,B, A, enable),
      u  (m6, ~D, C, B, ~A, enable),
      c  (m5, ~D, C, ~B, A, enable),
      ks (m3, ~D, ~C, B, A, enable);
  assign outVector = {m3, m5, m6, m7, m9, m10, m11, m12};
endmodule