function demoPowfit
% demoPowfit  Demonstrate curve fit to y = c(1)*x^c(2)

% -- Create synthetic data
x = 1:5:50;      %  Generate row vector:  1, 6, 11, .... 46
c1 = 0.25;       %  c1 and c2 are coefficients in the synthetic data
c2 = 1/3;
y = c1*x.^c2;    %  Create vector of y values y(i) = c1*x(i)^c2

% -- Compute curve fit to y = c(1)*x^c(2)
c = powfit(x,y);   %  c is a vector with two elements:  c(1) and c(2)

% -- Evaluate curve fit at many points on x interval of orginal data
xfit = linspace( min(x), max(x) );   %  xfit has 100 elements
yfit = c(1)*xfit.^c(2);              %  yfit has 100 elements.  Note the .^

plot(x,y,'bo',xfit,yfit,'r--')    %  plot data and fit on the same axes
legend('Data','Fit to y = c_1 x^{c_2}','Location','northwest')

% -- Repeat with noisy data
noise = 0.03*(randn(size(y)) - 0.5);  % Gaussian noise centered at 0
yn = y + noise;
cn = powfit(x,yn);
yfitn = cn(1)*xfit.^cn(2);
figure('Name','Noisey data');
plot(x,yn,'bo',xfit,yfitn,'r--');
legend('Data','Fit to y = c_1 x^{c_2}','Location','northwest');

% -- Print both sets of coefficients
fprintf('\nClean data:   c(1) = %9.7f,   c(2) = %9.7f\n',c);
fprintf('\nNoisey data:  cn(1) = %9.7f,  cn(2) = %9.7f\n',cn);

end