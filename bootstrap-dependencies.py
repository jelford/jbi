#! /usr/bin/env python3

from subprocess import Popen, PIPE
from os import path
import shutil

lib_directory = 'lib'

def copy(source, target_directory):
    shutil.copy(source, target_directory)

def lib_present(name):
    for extension in ('.a', '.so'):
        if path.isfile(path.join(lib_directory, 'lib{name}{extension}'.format(**locals()))):
            return True
    return False

def locate(file_name):
    p = Popen(['locate', file_name], stdout=PIPE, stdin=PIPE)
    out, err = p.communicate()
    if p.returncode == 0 and out:
        return out.decode()
    else:
        return False
        

def require_installed_shared_library(name):
    library_name = 'lib{name}.so'.format(name=name)
    if not locate(library_name):
        raise RuntimeError(
            'Can\'t find required library "{name}" on your system - aborting'.format(name=name))

def require_local_shared_library(name):
    if lib_present(name):
        return

    raise RuntimeError(
            'Can\'t find required library "{name}" in "{lib_directory}". You\'ll need to get a copy.'
                .format(name=name, lib_directory=lib_directory))

if __name__ == '__main__':
    require_installed_shared_library('boost_unit_test_framework')
    require_local_shared_library('gmock')
    require_local_shared_library('gtest')
