<#
.SYNOPSIS
Opens and sets up a few helpful starter tabs in Windows Terminal using the default distro.

.DESCRIPTION
You can can set your default distro using: wsl --set-default <Distro>.

To register mips_to_c.py as a global command in your bash PATH:
sudo apt update
sudo apt install python3-pip
sudo git clone https://github.com/matt-kempster/mips_to_c.git /usr/local/bin/mips_to_c

Then add PATH="$PATH:/usr/local/bin/mips_to_c" to the end of your ~/.bashrc file.
Any editor should work to do this:
vim ~/.bashrc
joe ~/.bashrc
code ~/.bashrc
Apply the changes using: source ~/.bashrc.

You should be able to run mips_to_c.py now.

.LINK
https://docs.microsoft.com/en-us/windows/wsl/reference
https://github.com/matt-kempster/mips_to_c.git
#>

wt -d "../" `; split-pane -d "../" -V --title "diff.py" `; new-tab -d "../" --title "mips_to_c.py" `; focus-tab -t 0
