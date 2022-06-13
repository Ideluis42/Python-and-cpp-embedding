import py # import module

returns = py.mod() # get the values from c++ by calling the method

#print("returned: " + str(returns)) # print the returns as a check

# set new roll, pitch, and yaw based on new values
def set_roll_pitch_yaw():
    #print("in set_roll_pitch_yaw")
    roll = returns[0] + 1
    pitch = returns[1] + .5
    yaw = returns[2] + .25

    return (roll, pitch, yaw)
