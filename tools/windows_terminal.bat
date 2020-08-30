:: replace with your distro 
set distro="Ubuntu-18.04"
wt -p %distro% -d "../" ; ^
split-pane -p %distro% -d "../" -V --title "diff.py" ; ^
new-tab -p %distro% -d . --title "mips_to_c.py" ; ^
focus-tab -t 0
