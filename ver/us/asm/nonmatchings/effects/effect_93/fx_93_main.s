.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_93_main
/* 3B8BD0 E00BA000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B8BD4 E00BA004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B8BD8 E00BA008 4485A000 */  mtc1      $a1, $f20
/* 3B8BDC E00BA00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B8BE0 E00BA010 4486B000 */  mtc1      $a2, $f22
/* 3B8BE4 E00BA014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B8BE8 E00BA018 0080902D */  daddu     $s2, $a0, $zero
/* 3B8BEC E00BA01C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B8BF0 E00BA020 4487C000 */  mtc1      $a3, $f24
/* 3B8BF4 E00BA024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B8BF8 E00BA028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B8BFC E00BA02C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3B8C00 E00BA030 3C02E00C */  lui       $v0, %hi(func_E00BA16C)
/* 3B8C04 E00BA034 2442A16C */  addiu     $v0, $v0, %lo(func_E00BA16C)
/* 3B8C08 E00BA038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B8C0C E00BA03C 3C02E00C */  lui       $v0, %hi(func_E00BA174)
/* 3B8C10 E00BA040 2442A174 */  addiu     $v0, $v0, %lo(func_E00BA174)
/* 3B8C14 E00BA044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B8C18 E00BA048 3C02E00C */  lui       $v0, %hi(func_E00BA5DC)
/* 3B8C1C E00BA04C 2442A5DC */  addiu     $v0, $v0, %lo(func_E00BA5DC)
/* 3B8C20 E00BA050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B8C24 E00BA054 2402005D */  addiu     $v0, $zero, 0x5d
/* 3B8C28 E00BA058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B8C2C E00BA05C AFB00028 */  sw        $s0, 0x28($sp)
/* 3B8C30 E00BA060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B8C34 E00BA064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B8C38 E00BA068 0C080124 */  jal       shim_create_effect_instance
/* 3B8C3C E00BA06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B8C40 E00BA070 24040308 */  addiu     $a0, $zero, 0x308
/* 3B8C44 E00BA074 24030001 */  addiu     $v1, $zero, 1
/* 3B8C48 E00BA078 0040802D */  daddu     $s0, $v0, $zero
/* 3B8C4C E00BA07C 0C08012C */  jal       shim_general_heap_malloc
/* 3B8C50 E00BA080 AE030008 */   sw       $v1, 8($s0)
/* 3B8C54 E00BA084 0040302D */  daddu     $a2, $v0, $zero
/* 3B8C58 E00BA088 14C00003 */  bnez      $a2, .LE00BA098
/* 3B8C5C E00BA08C AE02000C */   sw       $v0, 0xc($s0)
.LE00BA090:
/* 3B8C60 E00BA090 0802E824 */  j         .LE00BA090
/* 3B8C64 E00BA094 00000000 */   nop
.LE00BA098:
/* 3B8C68 E00BA098 ACD20000 */  sw        $s2, ($a2)
/* 3B8C6C E00BA09C 1E200004 */  bgtz      $s1, .LE00BA0B0
/* 3B8C70 E00BA0A0 ACC00014 */   sw       $zero, 0x14($a2)
/* 3B8C74 E00BA0A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B8C78 E00BA0A8 0802E82D */  j         .LE00BA0B4
/* 3B8C7C E00BA0AC ACC20010 */   sw       $v0, 0x10($a2)
.LE00BA0B0:
/* 3B8C80 E00BA0B0 ACD10010 */  sw        $s1, 0x10($a2)
.LE00BA0B4:
/* 3B8C84 E00BA0B4 0000482D */  daddu     $t1, $zero, $zero
/* 3B8C88 E00BA0B8 0120402D */  daddu     $t0, $t1, $zero
/* 3B8C8C E00BA0BC 0120382D */  daddu     $a3, $t1, $zero
/* 3B8C90 E00BA0C0 A0C0001F */  sb        $zero, 0x1f($a2)
/* 3B8C94 E00BA0C4 E4D40004 */  swc1      $f20, 4($a2)
/* 3B8C98 E00BA0C8 E4D60008 */  swc1      $f22, 8($a2)
/* 3B8C9C E00BA0CC E4D8000C */  swc1      $f24, 0xc($a2)
/* 3B8CA0 E00BA0D0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3B8CA4 E00BA0D4 2402000A */  addiu     $v0, $zero, 0xa
/* 3B8CA8 E00BA0D8 A0C2001C */  sb        $v0, 0x1c($a2)
/* 3B8CAC E00BA0DC 2402006E */  addiu     $v0, $zero, 0x6e
/* 3B8CB0 E00BA0E0 240300FF */  addiu     $v1, $zero, 0xff
/* 3B8CB4 E00BA0E4 A0C2001D */  sb        $v0, 0x1d($a2)
/* 3B8CB8 E00BA0E8 240200BE */  addiu     $v0, $zero, 0xbe
/* 3B8CBC E00BA0EC A0C20020 */  sb        $v0, 0x20($a2)
/* 3B8CC0 E00BA0F0 240200DC */  addiu     $v0, $zero, 0xdc
/* 3B8CC4 E00BA0F4 A0C3001E */  sb        $v1, 0x1e($a2)
/* 3B8CC8 E00BA0F8 A0C20021 */  sb        $v0, 0x21($a2)
/* 3B8CCC E00BA0FC A0C30022 */  sb        $v1, 0x22($a2)
/* 3B8CD0 E00BA100 E4C00018 */  swc1      $f0, 0x18($a2)
.LE00BA104:
/* 3B8CD4 E00BA104 0000202D */  daddu     $a0, $zero, $zero
/* 3B8CD8 E00BA108 0100282D */  daddu     $a1, $t0, $zero
.LE00BA10C:
/* 3B8CDC E00BA10C 00C51021 */  addu      $v0, $a2, $a1
/* 3B8CE0 E00BA110 00871821 */  addu      $v1, $a0, $a3
/* 3B8CE4 E00BA114 24840001 */  addiu     $a0, $a0, 1
/* 3B8CE8 E00BA118 00C31821 */  addu      $v1, $a2, $v1
/* 3B8CEC E00BA11C A0600023 */  sb        $zero, 0x23($v1)
/* 3B8CF0 E00BA120 A440011A */  sh        $zero, 0x11a($v0)
/* 3B8CF4 E00BA124 2882000D */  slti      $v0, $a0, 0xd
/* 3B8CF8 E00BA128 1440FFF8 */  bnez      $v0, .LE00BA10C
/* 3B8CFC E00BA12C 24A50002 */   addiu    $a1, $a1, 2
/* 3B8D00 E00BA130 2508001A */  addiu     $t0, $t0, 0x1a
/* 3B8D04 E00BA134 25290001 */  addiu     $t1, $t1, 1
/* 3B8D08 E00BA138 29220013 */  slti      $v0, $t1, 0x13
/* 3B8D0C E00BA13C 1440FFF1 */  bnez      $v0, .LE00BA104
/* 3B8D10 E00BA140 24E7000D */   addiu    $a3, $a3, 0xd
/* 3B8D14 E00BA144 0200102D */  daddu     $v0, $s0, $zero
/* 3B8D18 E00BA148 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B8D1C E00BA14C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B8D20 E00BA150 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B8D24 E00BA154 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B8D28 E00BA158 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B8D2C E00BA15C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B8D30 E00BA160 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B8D34 E00BA164 03E00008 */  jr        $ra
/* 3B8D38 E00BA168 27BD0050 */   addiu    $sp, $sp, 0x50
