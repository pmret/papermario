.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E8264
/* 3E18F4 E00E8264 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3E18F8 E00E8268 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3E18FC E00E826C 8C850000 */  lw        $a1, ($a0)
/* 3E1900 E00E8270 8C83000C */  lw        $v1, 0xc($a0)
/* 3E1904 E00E8274 30A20010 */  andi      $v0, $a1, 0x10
/* 3E1908 E00E8278 8C670000 */  lw        $a3, ($v1)
/* 3E190C E00E827C 10400005 */  beqz      $v0, .LE00E8294
/* 3E1910 E00E8280 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3E1914 E00E8284 00A21024 */  and       $v0, $a1, $v0
/* 3E1918 E00E8288 AC820000 */  sw        $v0, ($a0)
/* 3E191C E00E828C 24020010 */  addiu     $v0, $zero, 0x10
/* 3E1920 E00E8290 AC62001C */  sw        $v0, 0x1c($v1)
.LE00E8294:
/* 3E1924 E00E8294 8C65001C */  lw        $a1, 0x1c($v1)
/* 3E1928 E00E8298 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3E192C E00E829C 10400002 */  beqz      $v0, .LE00E82A8
/* 3E1930 E00E82A0 24A2FFFF */   addiu    $v0, $a1, -1
/* 3E1934 E00E82A4 AC62001C */  sw        $v0, 0x1c($v1)
.LE00E82A8:
/* 3E1938 E00E82A8 8C620020 */  lw        $v0, 0x20($v1)
/* 3E193C E00E82AC 8C66001C */  lw        $a2, 0x1c($v1)
/* 3E1940 E00E82B0 24450001 */  addiu     $a1, $v0, 1
/* 3E1944 E00E82B4 04C10005 */  bgez      $a2, .LE00E82CC
/* 3E1948 E00E82B8 AC650020 */   sw       $a1, 0x20($v1)
/* 3E194C E00E82BC 0C080128 */  jal       func_E02004A0
/* 3E1950 E00E82C0 00000000 */   nop      
/* 3E1954 E00E82C4 0803A0DA */  j         .LE00E8368
/* 3E1958 E00E82C8 00000000 */   nop      
.LE00E82CC:
/* 3E195C E00E82CC 10E00004 */  beqz      $a3, .LE00E82E0
/* 3E1960 E00E82D0 00C0202D */   daddu    $a0, $a2, $zero
/* 3E1964 E00E82D4 24020002 */  addiu     $v0, $zero, 2
/* 3E1968 E00E82D8 14E2000D */  bne       $a3, $v0, .LE00E8310
/* 3E196C E00E82DC 28A20004 */   slti     $v0, $a1, 4
.LE00E82E0:
/* 3E1970 E00E82E0 28A20010 */  slti      $v0, $a1, 0x10
/* 3E1974 E00E82E4 10400003 */  beqz      $v0, .LE00E82F4
/* 3E1978 E00E82E8 00051100 */   sll      $v0, $a1, 4
/* 3E197C E00E82EC 0803A0BE */  j         .LE00E82F8
/* 3E1980 E00E82F0 2442000F */   addiu    $v0, $v0, 0xf
.LE00E82F4:
/* 3E1984 E00E82F4 240200FF */  addiu     $v0, $zero, 0xff
.LE00E82F8:
/* 3E1988 E00E82F8 AC620030 */  sw        $v0, 0x30($v1)
/* 3E198C E00E82FC 28820010 */  slti      $v0, $a0, 0x10
/* 3E1990 E00E8300 1040000D */  beqz      $v0, .LE00E8338
/* 3E1994 E00E8304 00041100 */   sll      $v0, $a0, 4
/* 3E1998 E00E8308 0803A0CE */  j         .LE00E8338
/* 3E199C E00E830C AC620030 */   sw       $v0, 0x30($v1)
.LE00E8310:
/* 3E19A0 E00E8310 10400003 */  beqz      $v0, .LE00E8320
/* 3E19A4 E00E8314 00051180 */   sll      $v0, $a1, 6
/* 3E19A8 E00E8318 0803A0C9 */  j         .LE00E8324
/* 3E19AC E00E831C 2442003F */   addiu    $v0, $v0, 0x3f
.LE00E8320:
/* 3E19B0 E00E8320 240200FF */  addiu     $v0, $zero, 0xff
.LE00E8324:
/* 3E19B4 E00E8324 AC620030 */  sw        $v0, 0x30($v1)
/* 3E19B8 E00E8328 28820004 */  slti      $v0, $a0, 4
/* 3E19BC E00E832C 10400002 */  beqz      $v0, .LE00E8338
/* 3E19C0 E00E8330 00041180 */   sll      $v0, $a0, 6
/* 3E19C4 E00E8334 AC620030 */  sw        $v0, 0x30($v1)
.LE00E8338:
/* 3E19C8 E00E8338 C4660004 */  lwc1      $f6, 4($v1)
/* 3E19CC E00E833C C4600010 */  lwc1      $f0, 0x10($v1)
/* 3E19D0 E00E8340 C4640008 */  lwc1      $f4, 8($v1)
/* 3E19D4 E00E8344 46003180 */  add.s     $f6, $f6, $f0
/* 3E19D8 E00E8348 C4600014 */  lwc1      $f0, 0x14($v1)
/* 3E19DC E00E834C C462000C */  lwc1      $f2, 0xc($v1)
/* 3E19E0 E00E8350 46002100 */  add.s     $f4, $f4, $f0
/* 3E19E4 E00E8354 C4600018 */  lwc1      $f0, 0x18($v1)
/* 3E19E8 E00E8358 46001080 */  add.s     $f2, $f2, $f0
/* 3E19EC E00E835C E4660004 */  swc1      $f6, 4($v1)
/* 3E19F0 E00E8360 E4640008 */  swc1      $f4, 8($v1)
/* 3E19F4 E00E8364 E462000C */  swc1      $f2, 0xc($v1)
.LE00E8368:
/* 3E19F8 E00E8368 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3E19FC E00E836C 03E00008 */  jr        $ra
/* 3E1A00 E00E8370 27BD0018 */   addiu    $sp, $sp, 0x18
