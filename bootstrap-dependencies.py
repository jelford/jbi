#! /usr/bin/env python3

from subprocess import call

def locate(file_name):
    return call(['locate', file_name]) == 0

def require_shared_library(name):
    if not locate('lib{name}.so'.format(name=name)):
        raise RuntimeError('Can\'t find required library "{name}" on your system - aborting')

if __name__ == '__main__':
    require_shared_library('boost_unit_test_framework')
