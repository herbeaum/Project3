% Open file

fd = fopen('domain.bin');

% Read the size of an integer and the size of a floating point

sizeOfInt = fread(fd, 1, 'int8');
sizeOfFloat = fread(fd, 1, 'int8');

% Define int and double precision strings depending on sizeOfInt and
% sizeOfFloat

switch sizeOfInt
    case 1
        intPrec = 'int8';
    case 2
        intPrec = 'int16';
    case 4
        intPrec = 'int32';
    case 8
        intPrec = 'int64';
    otherwise
        error('int size (in byte) must be 1, 2, 4 or 8!')
end

switch sizeOfFloat
    case 4
        floatPrec = 'float32';
    case 8
        floatPrec = 'float64';
    otherwise
        error('int size (in byte) must be 1, 2, 4 or 8!')
end

% Read m and n (width and height of the matrix respectively)

m = fread(fd, 1, intPrec);
n = fread(fd, 1, intPrec);

% Read the x and y coordinates as vectors

X = fread(fd, m * n, floatPrec);
Y = fread(fd, m * n, floatPrec);

% Close file and clean unnecessary variables

fclose(fd);
clear fd m n sizeOfInt sizeOfFloat intPrec floatPrec

% Plot domain

scatter(X, Y, 'filled')
clear ans
