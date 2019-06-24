function [symbols] = foratis(r, m)
% symbols = foratis(r1, r2)
% The foratis function takes the r argument and calculates the
% binary (or gray) symbols that was to be send

[r_lines, r_columns] = size(r);

    % calculates each possible received symbol
    for i = 1: m
        s(i, 1) = cos( 2 * pi * i / m );
        s(i, 2) = sin( 2 * pi * i / m );
    end

    % calculates the symbol which presents the greatest propability to
    % be the sent symbol
    for j =1: r_lines
        for i = 1: m
            temp(i, 1) = norm([r(j,1), r(j,2)] - s(i,:));
        end
        [min_diff, symbols(j, 1)] = min(temp);
    end

% the mth symbol is actually the 0th symbol
symbols = mod(symbols,m);
end
