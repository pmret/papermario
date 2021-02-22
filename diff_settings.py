#!/usr/bin/env python3

def apply(config, args):
    ver_dir = 'ver/current/'
    config['baseimg'] = f'{ver_dir}baserom.z64'
    config['myimg'] = f'{ver_dir}build/papermario.z64'
    config['mapfile'] = f'{ver_dir}build/papermario.map'
    config['source_directories'] = ['src', f'{ver_dir}asm', 'include', f'{ver_dir}assets']
    config['make_command'] = ['ninja']
