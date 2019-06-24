function [ symbols_array ]= mapper(binary_sequence, m, gray)
% symbols_array = mapper(binary_sequence, encoding, gray):
%
% The mapper_modulator is a function that take as argument a binary
% sequence and transforms the elements of this array into symbols
% m is 4 for 4-PSK or 8 for 8-PSK
% The gray argument denotes if is to be used gray (1) encoding or not (0)
% OUTPUT
% symbols_array: the elements of the transformation into symbols

% the length of input
size_of_binary_sequence = length(binary_sequence);

% we group the bits into groups of log2(m)
% the remainder of the sequence is separately converted into one symbol at
% the end
temp = mod(size_of_binary_sequence, log2(m));

% the sequence which is dividable by log2(m)
new_bin_seq = binary_sequence(1 : (size_of_binary_sequence - temp), :);

% grouping of that sequence
reshaped_sequence = reshape(new_bin_seq, log2(m), (size_of_binary_sequence - temp) / log2(m));

% tranform the sequence into binary code for every group of 3 bits
for i = 1: (size_of_binary_sequence - temp) / log2(m)
    symbols_array(i) = bin2dec(num2str(reshaped_sequence(:, i)'));
end

% the rest of the bits are separately tranformed into a symbol in binary
% code
if temp ~= 0
    symbols_array(i + 1) = bin2dec(num2str(binary_sequence(size_of_binary_sequence - temp + 1 :size_of_binary_sequence, 1)'));
end

% if we use gray encoding in order to achieve smaller distance among two
% symbols which are adjacent, we encode the symbols into Gray by using the
% following function bin2gray
if gray == 1
    symbols_array = bin2gray(symbols_array, 'psk', m);
end

end
