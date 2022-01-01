function constants = initial_constants()

% Constants
Ix = 0.0034; %kg?m^2
Iy = 0.0034; %kg?m^2
Iz = 0.006; %kg?m^2
m = 0.698; %kg
g = 9.81; %m/ s ^2
Jtp =1.302*(10E-6); %N?m? s^2=kg?m^2

constants = { Ix Iy Iz m g Jtp };

end