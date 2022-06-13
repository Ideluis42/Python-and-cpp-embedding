from py_receiver import set_roll_pitch_yaw # import the function with the new roll, pitch, yaw values

# set new roll pitch yaw values
new_values = set_roll_pitch_yaw()

roll = new_values[0]
pitch = new_values[1]
yaw = new_values[2]

# return roll pitch yaw
def roll_pitch_yaw():
    print(f"roll: {roll}, pitch: {pitch}, yaw: {yaw}")
    return (roll, pitch, yaw)
  