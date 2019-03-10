# Generate the .bin files by splitting the rom
Place "Paper Mario (U) [!].z64" in the root directory with a build of `n64split` and run:
```
./splitrom.sh
```

## To rebuild n64split every time
```
rm -rf ./n64splitter/bin/ && ./splitrom.sh
```
