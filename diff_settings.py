#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'papermario.z64'
    config['mapfile'] = 'build/papermario.map'
    config['source_directories'] = ['.']
