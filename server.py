from multiprocessing import Process
from time import sleep
import matplotlib.pyplot as plt
import random
import os
import struct
import stat
import sys
import numpy as np

FIFO_START = '/tmp/exam_3_start'
FIFO_DATA = '/tmp/exam_3_data_'
NUM_PIPES = 0

def init_pipes():
    try:
        if stat.S_ISFIFO(os.stat(FIFO_START).st_mode):
            os.remove(FIFO_START)
        else:
            os.remove(FIFO_START)
    except:
        pass
    os.mkfifo(FIFO_START)
    for i in range(NUM_PIPES):
        try:
            if stat.S_ISFIFO(os.stat(f'{FIFO_DATA}{i}').st_mode):
                os.remove(f'{FIFO_DATA}{i}')
            else:
                os.remove(f'{FIFO_DATA}{i}')
        except:
            pass
        os.mkfifo(f'{FIFO_DATA}{i}')

def send_start_info(num_pipes):
    print(f'Abriendo fifo {FIFO_START}')
    fifo_start = open(FIFO_START, 'wb')
    xb = num_pipes.to_bytes(4, 'little')
    fifo_start.write(xb)    
    fifo_start.close()

def get_sample(i, sensor_type, par1, par2):
    if sensor_type==1:
        x = np.sin(i/par1[0]) * par2[0] 
        y = np.sin(i/par1[1]) * par2[1]
        z = np.sin(i/par1[2]) * par2[2]
    elif sensor_type==2:
        x = ( (i%par1[0])/par1[0] ) * par2[0]
        y = ( (i%par1[1])/par1[1] ) * par2[1]
        z = ( (i%par1[2])/par1[2] ) * par2[2]
    elif sensor_type==3:
        x = np.random.uniform(-1.0, 1.0)
        y = np.random.uniform(-1.0, 1.0)
        z = np.random.uniform(-1.0, 1.0)
    return x, y, z

def main_process(num_pipe):
    print(f'Arrancando hilo de tubería {FIFO_DATA}{num_pipe}')
    i = 0
    time_delay = np.random.uniform(0.1, 0.5)
    sensor_type = random.randint(1, 3)
    if sensor_type==1:
        par1 = np.random.uniform(3.0, 10.0, 3)
        par2 = np.random.uniform(0.3, 1.5, 3)
    elif sensor_type==2:
        par1 = np.random.randint(20, 100, 3)
        par2 = np.random.uniform(0.3, 1.5, 3)
    elif sensor_type==3:
        par1 = None
        par2 = None
    while(True):
        x, y, z = get_sample(i, sensor_type, par1, par2)
        fifo_data = open(f'{FIFO_DATA}{num_pipe}', 'wb')
        print(f'X:{x}Y:{y}Z:{z}')
        fifo_data.write( bytearray(struct.pack("d", x)) )
        fifo_data.write( bytearray(struct.pack("d", y)) )
        fifo_data.write( bytearray(struct.pack("d", z)) )
        fifo_data.close()
        sleep(time_delay)
        i += 1
        

if __name__ == "__main__":

    if len(sys.argv)<2:
        print('Ingrese la cantidad de sensores a crear como argumento')
        exit()

    NUM_PIPES = int(sys.argv[1])

    init_pipes()
    send_start_info(NUM_PIPES)

    p = []

    for i in range(NUM_PIPES):
        p.append(Process(target=main_process, args=(i,)))
        p[-1].start()

    while True:
        pass




