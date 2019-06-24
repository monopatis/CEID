bits = 10^5;

i = 1;
x = (0: 2: 16);

for SNR = 0: 2: 16
    A = binary_input(bits);
    B = mapper(A, 4, 1);
    C = modulator(B, 4);
    D = noise(C,SNR, 4);
    r = demodulator(D, 4);
    E = foratis(r, 4);
    F = demapper(E', 4, 1);
    BER_psk4_gray(i, 1) = ber(A,F,4);

    A = binary_input(bits);
    B = mapper(A, 4, 0);
    C = modulator(B, 4);
    D = noise(C,SNR, 4);
    r = demodulator(D, 4);
    E = foratis(r, 4);
    F = demapper(E', 4, 0);
    BER_psk4_without_gray(i, 1) = ber(A,F,4);

    A = binary_input(bits);
    B = mapper(A, 8, 1);
    C = modulator(B, 8);
    D = noise(C,SNR,8);
    r = demodulator(D, 8);
    E = foratis(r, 8);
    F = demapper(E', 8, 1);
    BER_psk8_gray(i, 1) = ber(A,F,8);

    A = binary_input(bits);
    B = mapper(A, 8, 0);
    C = modulator(B, 8);
    D = noise(C,SNR,8);
    r = demodulator(D, 8);
    E = foratis(r, 8);
    F = demapper(E', 8, 0);
    BER_psk8_without_gray(i, 1) = ber(A,F,8);
    
    i = i + 1;
end

semilogy(x', BER_psk4_gray, '.-');
hold on;
semilogy(x', BER_psk4_without_gray, 'r.-');
semilogy(x', BER_psk8_gray, 'b.-');
semilogy(x', BER_psk8_without_gray, 'g.-');
legend('4-PSK with Gray','4-PSK without Gray','8-PSK with Gray','8-PSK without Gray');
title('Bit Rate Error');
xlabel('SNR/bit, dB');
ylabel('BER');
hold;

figure;