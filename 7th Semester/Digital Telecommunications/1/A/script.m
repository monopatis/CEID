close all
clear

load source.mat
% s=(x(1:512))';
s=x;

%lpc and encoder-decoder parameters
lpclen=20;
% bitsize=input('bitsize=');
bitsize=8;
fprintf('\nPlease wait... data length is %i\n',length(s))

% DPCM with predictor
[Q,b, ai] = dpcm_encoder(s, lpclen, bitsize);
[st]=dpcm_deco_lpc(b, ai, bitsize);


figure
subplot(2,1,1),plot(s,'r');
ylabel('amplitude');
title('DPCM with predictor (red:input, green:decoder)');
subplot(2,1,2),plot(st,'g');
ylabel('amplitude');
% subplot(3,1,3),plot(Sa,'b');
% ylabel('amplitude');
xlabel('index, n');
grid
