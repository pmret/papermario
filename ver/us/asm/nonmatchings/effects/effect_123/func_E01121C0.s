.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01121C0
/* 3FA010 E01121C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3FA014 E01121C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3FA018 E01121C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 3FA01C E01121CC 8C830000 */  lw        $v1, ($a0)
/* 3FA020 E01121D0 8C90000C */  lw        $s0, 0xc($a0)
/* 3FA024 E01121D4 30620010 */  andi      $v0, $v1, 0x10
/* 3FA028 E01121D8 10400005 */  beqz      $v0, .LE01121F0
/* 3FA02C E01121DC 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3FA030 E01121E0 00621024 */  and       $v0, $v1, $v0
/* 3FA034 E01121E4 AC820000 */  sw        $v0, ($a0)
/* 3FA038 E01121E8 24020010 */  addiu     $v0, $zero, 0x10
/* 3FA03C E01121EC AE020010 */  sw        $v0, 0x10($s0)
.LE01121F0:
/* 3FA040 E01121F0 8E030010 */  lw        $v1, 0x10($s0)
/* 3FA044 E01121F4 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3FA048 E01121F8 10400002 */  beqz      $v0, .LE0112204
/* 3FA04C E01121FC 2462FFFF */   addiu    $v0, $v1, -1
/* 3FA050 E0112200 AE020010 */  sw        $v0, 0x10($s0)
.LE0112204:
/* 3FA054 E0112204 8E020014 */  lw        $v0, 0x14($s0)
/* 3FA058 E0112208 8E030010 */  lw        $v1, 0x10($s0)
/* 3FA05C E011220C 24420001 */  addiu     $v0, $v0, 1
/* 3FA060 E0112210 0461000A */  bgez      $v1, .LE011223C
/* 3FA064 E0112214 AE020014 */   sw       $v0, 0x14($s0)
/* 3FA068 E0112218 0C080128 */  jal       shim_remove_effect
/* 3FA06C E011221C 00000000 */   nop
/* 3FA070 E0112220 8E03001C */  lw        $v1, 0x1c($s0)
/* 3FA074 E0112224 1060002C */  beqz      $v1, .LE01122D8
/* 3FA078 E0112228 00000000 */   nop
/* 3FA07C E011222C 8C620000 */  lw        $v0, ($v1)
/* 3FA080 E0112230 34420010 */  ori       $v0, $v0, 0x10
/* 3FA084 E0112234 080448B6 */  j         .LE01122D8
/* 3FA088 E0112238 AC620000 */   sw       $v0, ($v1)
.LE011223C:
/* 3FA08C E011223C 28620010 */  slti      $v0, $v1, 0x10
/* 3FA090 E0112240 14400025 */  bnez      $v0, .LE01122D8
/* 3FA094 E0112244 00000000 */   nop
/* 3FA098 E0112248 8E02001C */  lw        $v0, 0x1c($s0)
/* 3FA09C E011224C 10400022 */  beqz      $v0, .LE01122D8
/* 3FA0A0 E0112250 00000000 */   nop
/* 3FA0A4 E0112254 C6000018 */  lwc1      $f0, 0x18($s0)
/* 3FA0A8 E0112258 3C0141F0 */  lui       $at, 0x41f0
/* 3FA0AC E011225C 44812000 */  mtc1      $at, $f4
/* 3FA0B0 E0112260 00000000 */  nop
/* 3FA0B4 E0112264 46040002 */  mul.s     $f0, $f0, $f4
/* 3FA0B8 E0112268 00000000 */  nop
/* 3FA0BC E011226C 8C42000C */  lw        $v0, 0xc($v0)
/* 3FA0C0 E0112270 E4400010 */  swc1      $f0, 0x10($v0)
/* 3FA0C4 E0112274 C6020018 */  lwc1      $f2, 0x18($s0)
/* 3FA0C8 E0112278 3C014248 */  lui       $at, 0x4248
/* 3FA0CC E011227C 44810000 */  mtc1      $at, $f0
/* 3FA0D0 E0112280 00000000 */  nop
/* 3FA0D4 E0112284 46001082 */  mul.s     $f2, $f2, $f0
/* 3FA0D8 E0112288 00000000 */  nop
/* 3FA0DC E011228C 8E02001C */  lw        $v0, 0x1c($s0)
/* 3FA0E0 E0112290 8C42000C */  lw        $v0, 0xc($v0)
/* 3FA0E4 E0112294 E4420014 */  swc1      $f2, 0x14($v0)
/* 3FA0E8 E0112298 8E02001C */  lw        $v0, 0x1c($s0)
/* 3FA0EC E011229C C6000004 */  lwc1      $f0, 4($s0)
/* 3FA0F0 E01122A0 8C42000C */  lw        $v0, 0xc($v0)
/* 3FA0F4 E01122A4 E4400004 */  swc1      $f0, 4($v0)
/* 3FA0F8 E01122A8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 3FA0FC E01122AC 46040002 */  mul.s     $f0, $f0, $f4
/* 3FA100 E01122B0 00000000 */  nop
/* 3FA104 E01122B4 C6020008 */  lwc1      $f2, 8($s0)
/* 3FA108 E01122B8 8E02001C */  lw        $v0, 0x1c($s0)
/* 3FA10C E01122BC 46001081 */  sub.s     $f2, $f2, $f0
/* 3FA110 E01122C0 8C42000C */  lw        $v0, 0xc($v0)
/* 3FA114 E01122C4 E4420008 */  swc1      $f2, 8($v0)
/* 3FA118 E01122C8 8E02001C */  lw        $v0, 0x1c($s0)
/* 3FA11C E01122CC C600000C */  lwc1      $f0, 0xc($s0)
/* 3FA120 E01122D0 8C42000C */  lw        $v0, 0xc($v0)
/* 3FA124 E01122D4 E440000C */  swc1      $f0, 0xc($v0)
.LE01122D8:
/* 3FA128 E01122D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3FA12C E01122DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3FA130 E01122E0 03E00008 */  jr        $ra
/* 3FA134 E01122E4 27BD0018 */   addiu    $sp, $sp, 0x18
