#!/bin/bash
# pip3 install https://github.com/alexforencich/cocotbext-i2c/archive/master.zip


# First, type:  docker exec -it MY-CIS5710 /bin/bash
# type: cd /MYSTUFF
# then: ./run.sh

pytest -xs testbench.py

# use GTKWave to view waveforms. To upload waveforms into GTKWave,
# go to file -> open new window -> dump.fst
# (dump.fst can be found in SystemVerilogStudy -> sim_build)