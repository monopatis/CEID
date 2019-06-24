function Sa=lpf(tap, cf, Sn)
%LPF lowpass filter
%function Sa=lpf(tap,cf,Sn)
%
%tap: filter order.
%cf: cut-off frequency.
%Quantized reconstructed signal.
%Sa: decoder output.

% __SG 7-30-98

b=fir1(tap,cf);
Sa = conv2(Sn,b,'same');
