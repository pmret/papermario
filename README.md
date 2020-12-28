# Paper Mario

This is a WIP decompilation of Paper Mario (USA). It builds the following ROM:

* papermario.z64 `md5: a722f8161ff489943191330bf8416496`

Discord: [Paper Mario Modding](https://discord.gg/urUm3VG)

## Setup

You'll need Linux, a Linux VM, or [Windows 10 (WSL2)](#wsl) to work on this project.

#### Clone the repository
```sh
$ git clone https://github.com/ethteck/papermario.git
$ cd papermario
```

#### Install build dependencies

```sh
$ ./install.sh
```

Our install script does not yet support distros other than Ubuntu, Arch, and their derivatives. Please consider contributing to the script if you use another distro!

##### Docker

A Docker image containing all dependencies can be built and ran as follows:
```sh
# build image
$ docker build . -t pm
# spin up container, mounting current directory inside
$ docker run --rm -ti -v $(pwd):/papermario pm
```

#### Base ROM

You'll need a Paper Mario (USA) ROM to work on this project. Copy it into the root directory of the repository with the name `baserom.z64`.

#### Install tools and extract ROM

```sh
$ make setup
```

### Compile the game

```sh
$ make
```

If you get `OK`, you're all set! Otherwise, please feel free to reach out to us in [our Discord channel](https://discord.gg/urUm3VG).

## Star Rod GUI

You can open [our modified version of Star Rod](https://github.com/nanaian/star-rod-for-decomp) with `make editor`.

## Contributing
Please see [CONTRIBUTING.md](CONTRIBUTING.md) for information on how to contribute to the project. Any and all help is welcome!

## Troubleshooting

* If you are using Windows, you may encounter the following when you run `make`:
```
sha1sum -c checksum.sha1
sha1sum: 'papermario.z64'$'\r': No such file or directory
: FAILED open or read
sha1sum: WARNING: 1 listed file could not be read
Makefile:118: recipe for target 'verify' failed
make: *** [verify] Error 1
```
> 💡 Solution

> Run `git checkout checksum.sha1` and retry building. Windows has different line endings than Linux, causing some of our tools to break.
