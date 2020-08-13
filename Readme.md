# Paper Mario Decompilation

## Setup
### Requirements
You'll need Linux or Windows 10 (WSL) to work on this project.

### Dependencies
* *mips-linux-gnu binutils: You may be able to just download this via your package manager (`sudo apt install binutils-mips-linux-gnu`), or you'll have to build it yourself. (guide todo)


#### Ubuntu and co (easy mode):
For a quick and easy way to install all relevant decomp-related tools on Ubuntu and other similar distros, 
```
sudo apt install -y binutils-mips-linux-gnu build-essential pkg-config python3 python3-pip wget git clang-tidy clang-format nano vbindiff zlib1g-dev libyaml-dev libcapstone-dev
```

#### Building mips-linux-gnu
todo

### Fork and clone the repo
Click the "fork" button in the top right corner of the main repo's webpage (https://github.com/ethteck/papermario) to fork this repo to your own GitHub account. After this, clone the repo to your computer via the command below:

`git clone https://github.com/YOUR_GITHUB_USERNAME/papermario.git`

### The Rom
You'll need a US Paper Mario rom to work on this project. Copy it into the root directory of the repository with the name `baserom.z64`.

### Make setup
run `make setup` to set up tools and extract the rom

### Make
run `make` to rebuild the rom. Get `OK`? If so, you're all set! Otherwise, please feel free to reach out to us in the discord.
