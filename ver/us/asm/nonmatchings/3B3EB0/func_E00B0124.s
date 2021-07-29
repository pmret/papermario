.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B0124
/* 3B3FD4 E00B0124 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B3FD8 E00B0128 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B3FDC E00B012C 8C850000 */  lw        $a1, ($a0)
/* 3B3FE0 E00B0130 8C83000C */  lw        $v1, 0xc($a0)
/* 3B3FE4 E00B0134 30A20010 */  andi      $v0, $a1, 0x10
/* 3B3FE8 E00B0138 10400005 */  beqz      $v0, .LE00B0150
/* 3B3FEC E00B013C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B3FF0 E00B0140 00A21024 */  and       $v0, $a1, $v0
/* 3B3FF4 E00B0144 AC820000 */  sw        $v0, ($a0)
/* 3B3FF8 E00B0148 24020010 */  addiu     $v0, $zero, 0x10
/* 3B3FFC E00B014C AC620010 */  sw        $v0, 0x10($v1)
.LE00B0150:
/* 3B4000 E00B0150 8C650010 */  lw        $a1, 0x10($v1)
/* 3B4004 E00B0154 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3B4008 E00B0158 10400002 */  beqz      $v0, .LE00B0164
/* 3B400C E00B015C 24A2FFFF */   addiu    $v0, $a1, -1
/* 3B4010 E00B0160 AC620010 */  sw        $v0, 0x10($v1)
.LE00B0164:
/* 3B4014 E00B0164 8C620014 */  lw        $v0, 0x14($v1)
/* 3B4018 E00B0168 8C660010 */  lw        $a2, 0x10($v1)
/* 3B401C E00B016C 24450001 */  addiu     $a1, $v0, 1
/* 3B4020 E00B0170 04C10005 */  bgez      $a2, .LE00B0188
/* 3B4024 E00B0174 AC650014 */   sw       $a1, 0x14($v1)
/* 3B4028 E00B0178 0C080128 */  jal       func_E02004A0
/* 3B402C E00B017C 00000000 */   nop
/* 3B4030 E00B0180 0802C07B */  j         .LE00B01EC
/* 3B4034 E00B0184 00000000 */   nop
.LE00B0188:
/* 3B4038 E00B0188 28C40008 */  slti      $a0, $a2, 8
/* 3B403C E00B018C 1080000E */  beqz      $a0, .LE00B01C8
/* 3B4040 E00B0190 24020008 */   addiu    $v0, $zero, 8
/* 3B4044 E00B0194 00461023 */  subu      $v0, $v0, $a2
/* 3B4048 E00B0198 3C01E00B */  lui       $at, %hi(D_E00B07E0)
/* 3B404C E00B019C D42007E0 */  ldc1      $f0, %lo(D_E00B07E0)($at)
/* 3B4050 E00B01A0 44821000 */  mtc1      $v0, $f2
/* 3B4054 E00B01A4 00000000 */  nop
/* 3B4058 E00B01A8 468010A1 */  cvt.d.w   $f2, $f2
/* 3B405C E00B01AC 46201082 */  mul.d     $f2, $f2, $f0
/* 3B4060 E00B01B0 00000000 */  nop
/* 3B4064 E00B01B4 C460002C */  lwc1      $f0, 0x2c($v1)
/* 3B4068 E00B01B8 46000021 */  cvt.d.s   $f0, $f0
/* 3B406C E00B01BC 46220000 */  add.d     $f0, $f0, $f2
/* 3B4070 E00B01C0 46200020 */  cvt.s.d   $f0, $f0
/* 3B4074 E00B01C4 E460002C */  swc1      $f0, 0x2c($v1)
.LE00B01C8:
/* 3B4078 E00B01C8 28A20010 */  slti      $v0, $a1, 0x10
/* 3B407C E00B01CC 10400003 */  beqz      $v0, .LE00B01DC
/* 3B4080 E00B01D0 00051100 */   sll      $v0, $a1, 4
/* 3B4084 E00B01D4 2442000F */  addiu     $v0, $v0, 0xf
/* 3B4088 E00B01D8 AC620024 */  sw        $v0, 0x24($v1)
.LE00B01DC:
/* 3B408C E00B01DC 10800003 */  beqz      $a0, .LE00B01EC
/* 3B4090 E00B01E0 00061140 */   sll      $v0, $a2, 5
/* 3B4094 E00B01E4 2442001F */  addiu     $v0, $v0, 0x1f
/* 3B4098 E00B01E8 AC620024 */  sw        $v0, 0x24($v1)
.LE00B01EC:
/* 3B409C E00B01EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B40A0 E00B01F0 03E00008 */  jr        $ra
/* 3B40A4 E00B01F4 27BD0018 */   addiu    $sp, $sp, 0x18
