def counter(f):
    global calls
    calls = 0
    def g(*args, **kwargs):
        global calls
        calls += 1
        return f(*args, **kwargs)
    return g

@counter
def roll_pitch_yaw():
    roll = 1.1
    pitch = 0.7
    yaw = 1.6

    print("number of calls: " + str(calls))

    return (roll, pitch, yaw)
    