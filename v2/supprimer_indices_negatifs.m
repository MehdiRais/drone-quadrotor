function aux_matrix_final = supprimer_indices_negatifs(Omega_square, matrix)
    index = [];
    aux_matrix_final = matrix
    for i=1:length(Omega_square)
        if Omega_square(i) < 0 
            index = [index i];
        end
    end
    if length(index) ~= 0 
        aux_matrix_final(:,index) = []
    end
end