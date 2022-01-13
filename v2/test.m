function [Omega, u1, u2, u3, u4] = fcn(u)

    function y = list_nb_negatif(X)
       y = [];
       for i=1: length(X)
          if X(i) < 0
              y = [y i]
          end
       end
    end
constant = initial_constants();
cT = constant{7};
cQ = constant{8};
l  = constant{9};

Omegas_square = [0, 0, 0, 0];

fin = 0;
while fin == 0
    u1C = u(1)/cT;
    u2C = u(2)/(cT*l);
    u3C = u(3)/(cT*l);
    u4C = u(4)/cQ;

    omega4P2 = (u1C + 2*u2C + u4C)/4;
    omega3P2 = (-u4C + 2*omega4P2 - u2C + u3C)/2;
    omega2P2 = omega4P2 - u2C;
    omega1P2 = omega3P2 - u3C;

    Omegas_square = [omega1P2, omega2P2, omega3P2, omega4P2];
    liste = list_nb_negatif(Omegas_square)
    if length(liste) == 0
        fin = 1;
    else
        for k=1:length(liste)
            u(1) = u(1) + 1*sign(u(liste(k)));
        end     
        u
        pause(1)
    end
    
end


Omegas = sqrt((Omegas_square));
Omegas(Omegas > 14800) = 14800; % max vitesse rotation d'un moteur 1000 kV alimenté par lipo 4S

Omega = -Omegas(1) + Omegas(2) - Omegas(3) + Omegas(4);
u_aux = [cT*(Omegas(1)^2 + Omegas(2)^2 + Omegas(3)^2 + Omegas(4)^2),
         cT*l*(Omegas(4)^2 - Omegas(2)^2),
         cT*l*(Omegas(3)^2 - Omegas(1)^2),
         cQ*(-Omegas(1)^2 + Omegas(2)^2 - Omegas(3)^2 + Omegas(4)^2)];
u1 = u_aux(1)
u2 = u_aux(2)   
u3 = u_aux(3)
u4 = u_aux(4)

end