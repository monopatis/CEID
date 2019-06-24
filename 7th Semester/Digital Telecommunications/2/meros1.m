function output = meros1(input,SNR,channel)
% mikos: Μήκος αρχικού σήματος
% input: αρχικό σήμα
% yperdeigm: yperdeigmatolhpthmeno shma
% filtro: filtro
% output: eksodos
% SNR: isxys shmatos/isxys thoryvou
% isx_simat: isxys shmatos
% diasp_thor: tetragono diasporas 8oryboy
% yperd_sima: yperdeigmatolipsia kanaliou
% sima_kanal: sima pou eiserxetai sto kanali
% signal_power: isxys simatos
% sima_lipsis: sima meta tin prosthiki thoribou
% sima_eksodou: sima pou eiserxetai sti diataksi apofasis
% BER: Bit error rate
mikos = length(input);
yperdeigm = [];
output = [];
sima_kanal = [];
% yperdeigmatolhpsia kata 4
for i = 1:mikos,
    yperdeigm = [yperdeigm, [input(i), 0, 0, 0]];
end
% filtro pompou
filtro = rcosfir(0.3, 3, 4, 1, 'sqrt');
yperd_sima = conv(filtro, yperdeigm);
%mi idaniko kanali
if channel==1,
    h=[0.04 -0.05 0.07 -0.21 -0.5 0.72 0.36 0 0.21 0.03 0.07];
    for i = 1:length(h),
        sima_kanal = [sima_kanal, [h(i), 0, 0, 0]];
    end
    yperd_sima = conv(yperd_sima,sima_kanal);
end
% pros8hkh 8oryboy
signal_power = sum(yperd_sima.*yperd_sima)/length(yperd_sima);
diasp_thor = signal_power/(10^(SNR/10));
noise = sqrt(diasp_thor) * randn(1, length(yperd_sima));
yperd_sima = yperd_sima + noise;
yperd_sima_len = length(yperd_sima);
sima_lipsis = conv(filtro, yperd_sima);
% ypodeigmatolipsia kata 4
if channel==1,
    delay = 2*floor(length(filtro)/2) +floor(length(sima_kanal)/2);
else
    delay = 2*floor(length(filtro)/2);
end
sima_eksodou = sima_lipsis(delay+1:4:length(sima_lipsis));
% diataksi apofashs
for i = 1:mikos,
    if sima_eksodou(i)>0,
        output(i)=1;
    else
        output(i)=-1;
    end
end
