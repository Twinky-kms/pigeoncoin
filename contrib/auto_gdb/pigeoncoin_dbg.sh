#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.pigeoncoincore/pigeoncoind.pid file instead
pigeoncoin_pid=$(<~/.pigeoncoincore/testnet3/pigeoncoind.pid)
sudo gdb -batch -ex "source debug.gdb" pigeoncoind ${pigeoncoin_pid}
