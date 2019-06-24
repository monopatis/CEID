function [BER] = ber(input, output, m)
% BER = ber(input, output)
% calculate the bit error rate

% find the length of input array
length_of_input = length(input);

% see if it can be divided by log2(m)
modular = mod(length_of_input, log2(m));

% if not, that means that we send more bits than the length of input
if modular ~= 0
    % calculate the reduntant bits of the output
    further_elements_to_add = log2(m) - modular;

    % we concatenate at the end of the transmitted string the reduntant
    % bits in order to compare the same ammount of bits at both ends
    input(length_of_input + further_elements_to_add) = input(length_of_input);
    input(length_of_input) = 0;

end

% calculate the bit error rate
BER = sum(input ~= output)/length(output);
end
