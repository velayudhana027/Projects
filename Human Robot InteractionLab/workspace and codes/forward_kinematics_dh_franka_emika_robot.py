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
    S_i = np.array([[1,0,0,a],[0,np.cos(alpha),-1*np.sin(alpha),0],[0,np.sin(alpha),np.cos(alpha),0],[0,0,0,1]])
    Q_i = np.array([[np.cos(theta),-1*np.sin(theta),0,0],[np.sin(theta),np.cos(theta),0,0],[0,0,1,d],[0,0,0,1]])
    A_i = S_i @ Q_i
    return A_i


if __name__ == '__main__':
    # Table of Denavit-Hartenberg parameters of the Franka-Emika robot
    #TODO: fill the table with the DH parameters of the Franka-Emika robot
    dh_table = np.array([[0, 0.333, 0], 
                         [0, 0, -np.pi/2], 
                         [0, 0.316, np.pi/2],
                         [0.0825, 0, np.pi/2],
                         [-0.0825, 0.384, -np.pi/2],
                         [0, 0, np.pi/2],
                         [0.088, 0, np.pi/2],
                         [0, 0.107, 0],
                         ])
    
    # Given joint angles for testing
    #q1, q = np.array([0.019235233998089504, -0.7923776416149696, -0.20422321128849782, -2.2628194952513043, 0.03060367239923808, 2.2371299488503813, 0.7993941150075777, 0.0]) # last element: always 0.0 (distance to flange)
    #q,q2 = np.array([-0.8204829062662625, 0.28642457318817194, -0.050539825154577694, -1.596728804069792, -0.01043816279537148, 1.8973373835075273, -0.10994413763615819,  0.0]) # last element: always 0.0 (distance to flange)
    q = np.array([0.30700487279881034, -1.0351293052204869, -1.5220864513978467, -1.7237004241334015, -0.3194815674364632, 1.7751590567822317, -0.6607242964174908, 0.0]) # last element: always 0.0 (distance to flange)
    
    # Number of frames and single transformations
    N = len(dh_table)
    
    # Predefine transformation matrix
    A_b_EE = np.eye(4)
    
    # Transformations from base to endeffector frame
    #TODO: Compute the the 4x4 transformation matrix 'A_b_EE' from the base to
    # the end effector (flange) with the kinematic chain
    # Hint: A[i] = calculate_A_i(dh_table[i], q[i])
    for i in range(N):
        A_i=calculate_A_i(dh_table[i],q[i])
        A_b_EE= A_b_EE @ A_i
        
    print(np.round(A_b_EE, 4))
