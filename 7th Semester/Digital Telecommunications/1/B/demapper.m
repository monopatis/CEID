function [received_bits] = demapper(symbols, m, gray)
% received_bits = demapper(symbols)
% The demapper function converts the received symbols to bits
% The encoding could be with gray encoding (1) or not (0)

% if there has been used Gray encoding in the transmitted signal
if gray == 1
    symbols = gray2bin(symbols, 'psk', m);
end

received_bits = dec2bin(symbols);

% lines: number of lines of the received bits matrix
% columns: number of columns of the received bits matrix
[lines, columns] = size(received_bits);

% reshape the matrix with the received bits to an array
received_bits = reshape(received_bits', lines*columns, 1);

% convert to double every character
% in orde to recover the value that this character represents in ASCII code
% we substruct 30(hex) = 48(dec)
% we have assumed that we deal only with character wich represents digits
% that is a valid hypothesis because we deal only with zero and one
received_bits = double(received_bits) - 48;
end
