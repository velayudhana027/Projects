import numpy as np

def calculate_A_i(dh, q_i):
    """
    Function to calculate the i-th transformation between frame i and i-1
    from modified DH convention
    """
    a = dh[0]
    d = dh[1]
    alpha = dh[2]
    theta = q_i
    
    #TODO: Create S_i and Q_i as np.array() and calculate A_i by multiplying
    # the two matrices with a proper numpy function
    S_i = np.array([[...], ...])
    Q_i = ...
    A_i = ...
    return A_i


if __name__ == '__main__':
    # Table of Denavit-Hartenberg parameters of the Franka-Emika robot
    #TODO: fill the table with the DH parameters of the Franka-Emika robot
    dh_table = np.array([[0, 0.333, 0], 
                         [0, 0, -np.pi/2], 
                         ...
                         ])
    
    # Given joint angles for testing
    q = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]) # last element: always 0.0 (distance to flange)
    
    # Number of frames and single transformations
    N = len(dh_table)
    
    # Predefine transformation matrix
    A_b_EE = np.eye(4)
    
    # Transformations from base to endeffector frame
    #TODO: Compute the the 4x4 transformation matrix 'A_b_EE' from the base to
    # the end effector (flange) with the kinematic chain
    # Hint: A[i] = calculate_A_i(dh_table[i], q[i])
    ...
        
    print(np.round(A_b_EE, 4))
