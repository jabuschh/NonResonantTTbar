#!/bin/bash

cd ../..;
scram b -j8;
make -j8;
cd NonResonantTTbar/;
scram b -j8;
make -j8;
cd config/;
