> **Note**: This quickstart is written with N64 ROMs in mind, and the assumption that you are using Ubuntu 20.04 either natively, via WSL2 or via Docker.

For the purposes of this quickstart, we will assume that we are going to split a game called `mygame` and we have the ROM in `.z64` format named `baserom.z64`.

Create a directory for `~/mygame` and `cd` into it:

```sh
mkdir -p ${HOME}/mygame && cd ${HOME}/mygame
```

Copy the `baserom.z64` file into the `mygame` directory inside your home directory.

### System packages

#### Python 3.8

Ensure you are have **Python 3.8** or higher installed:

```sh
$ python3 --version
Python 3.8.10
```

If you get `bash: python3: command not found` install it with the following command:

```sh
sudo apt-get update && sudo apt-get install -y python3 python3-pip
```

#### Git

Ensure you have **git**:

```sh
$ git --version
```

If you get `bash: git: command not found`, install it with the following command:

```sh
sudo apt-get update && sudo apt-get install -y git
```

## Checkout the repository

We will clone **splat** into a `tools` directory to keep things organised:

```sh
git clone https://github.com/ethteck/splat.git tools/splat
```

## Python packages

Run the following to install the prerequisite Python packages:

```sh
python3 -m pip install -r ./tools/splat/requirements.txt
```

## Create a config file for your baserom

**splat** has a script that will generate a `yaml` file for your ROM.

```sh
python3 tools/splat/create_config.py baserom.z64
```

The `yaml` file generated will be named based upon the name of the ROM (taken from its header). The example below is for Super Mario 64:

```yaml
$ cat supermario64.yaml
name: Super Mario 64 (North America)
sha1: 9bef1128717f958171a4afac3ed78ee2bb4e86ce
options:
  basename: supermario64
  target_path: baserom.z64
  base_path: .
  compiler: IDO
  find_file_boundaries: True
  # platform: n64
  # undefined_funcs_auto_path: undefined_funcs_auto.txt
  # undefined_syms_auto_path: undefined_syms_auto.txt
  # symbol_addrs_path: symbol_addrs.txt
  # undefined_syms_path: undefined_syms.txt
  # asm_path: asm
  # src_path: src
  # build_path: build
  # extensions_path: tools/splat_ext
  # auto_all_sections: True
segments:
  - name: header
    type: header
    start: 0x0
  - name: boot
    type: bin
    start: 0x40
  - name: main
    type: code
    start: 0x1000
    vram: 0x80246000
    subsegments:
      - [0x1000, asm]
  - type: bin
    start: 0xE6430
  - [0x800000]
```

This is a bare-bones configuration and there is a lot of work required to map out the different sections of the ROM.

## Run splat with your configuration

```sh
python3 tools/splat/split.py supermario64.yaml
```

The output will look something like this:
```
splat 0.7.10.1
Loading and processing symbols
Starting scan
..Segment 1000, function at vram 80246DF8 ends with extra nops, indicating a likely file split.
File split suggestions for this segment will follow in config yaml format:
      - [0x1E70, asm]
      - [0x3C40, asm]
      - [0x45E0, asm]
      - [0x6FF0, asm]
#     < -- snip -->
      - [0xE6060, asm]
      - [0xE61F0, asm]
      - [0xE6200, asm]
      - [0xE6260, asm]
..
Starting split
....
Split 943 KB (11.24%) in defined segments
              header:     64 B (0.00%) 1 split, 0 cached
                 bin:     4 KB (0.05%) 1 split, 0 cached
                code:   939 KB (11.19%) 1 split, 0 cached
             unknown:     7 MB (88.76%) from unknown bin files
```

Notice that **splat** has found some potential file splits (function start/end with 16 byte alignment padded with nops).

It's up to you to figure out the layout of the ROM.


## Next Steps

The reassembly of the ROM is currently out of scope of this quickstart, as is switching out the `asm` segments for `c`.

You can find a general workflow for using `splat` at [General Workflow](https://github.com/ethteck/splat/wiki/General-Workflow)

Please feel free to improve this guide!
