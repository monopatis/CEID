function PAM = meros2()
% BERideal: BER se idaniko kanali
% BERnoised: BER se kanali me thoribo
% l: Arithmos sfalmatwn
BERideal = [];
BERnoised = [];
input = randsrc(1, 10000, [-1 1]);
len = length(input);
for SNR = 5:5:20,
    %idaniko kanali
    output = meros1(input,SNR,0);
    %ipologismos BER
    l=0;
    for i = 1:len,
        if input(i) ~= output(i),
            l = l+1;
        end
    end
    BER = l/len;
    BERideal = [BERideal,BER];
    output = meros1(input,SNR,1);
    %ipologismos BER
    l=0;
    for i = 1:len,
        if input(i) ~= output(i),
            l = l+1;
        end
    end
    BER = l/len;
    BERnoised = [BERnoised,BER];
end
plot ((5:5:20),BERideal,'g',(5:5:20),BERnoised,'r')
