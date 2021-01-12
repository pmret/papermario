.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_EFEE40
/* EFEE40 80240340 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EFEE44 80240344 AFB20018 */  sw        $s2, 0x18($sp)
/* EFEE48 80240348 0080902D */  daddu     $s2, $a0, $zero
/* EFEE4C 8024034C AFBF0028 */  sw        $ra, 0x28($sp)
/* EFEE50 80240350 AFB50024 */  sw        $s5, 0x24($sp)
/* EFEE54 80240354 AFB40020 */  sw        $s4, 0x20($sp)
/* EFEE58 80240358 AFB3001C */  sw        $s3, 0x1c($sp)
/* EFEE5C 8024035C AFB10014 */  sw        $s1, 0x14($sp)
/* EFEE60 80240360 AFB00010 */  sw        $s0, 0x10($sp)
/* EFEE64 80240364 F7B80040 */  sdc1      $f24, 0x40($sp)
/* EFEE68 80240368 F7B60038 */  sdc1      $f22, 0x38($sp)
/* EFEE6C 8024036C F7B40030 */  sdc1      $f20, 0x30($sp)
/* EFEE70 80240370 8E50000C */  lw        $s0, 0xc($s2)
/* EFEE74 80240374 8E140000 */  lw        $s4, ($s0)
/* EFEE78 80240378 26100004 */  addiu     $s0, $s0, 4
/* EFEE7C 8024037C 0C0B53A3 */  jal       func_802D4E8C
/* EFEE80 80240380 0280282D */   daddu    $a1, $s4, $zero
/* EFEE84 80240384 0040982D */  daddu     $s3, $v0, $zero
/* EFEE88 80240388 8E150000 */  lw        $s5, ($s0)
/* EFEE8C 8024038C 26100004 */  addiu     $s0, $s0, 4
/* EFEE90 80240390 8E050000 */  lw        $a1, ($s0)
/* EFEE94 80240394 26100004 */  addiu     $s0, $s0, 4
/* EFEE98 80240398 0C0B55FF */  jal       func_802D57FC
/* EFEE9C 8024039C 0240202D */   daddu    $a0, $s2, $zero
/* EFEEA0 802403A0 8E050000 */  lw        $a1, ($s0)
/* EFEEA4 802403A4 26100004 */  addiu     $s0, $s0, 4
/* EFEEA8 802403A8 0240202D */  daddu     $a0, $s2, $zero
/* EFEEAC 802403AC 0C0B55FF */  jal       func_802D57FC
/* EFEEB0 802403B0 46000606 */   mov.s    $f24, $f0
/* EFEEB4 802403B4 8E050000 */  lw        $a1, ($s0)
/* EFEEB8 802403B8 26100004 */  addiu     $s0, $s0, 4
/* EFEEBC 802403BC 0240202D */  daddu     $a0, $s2, $zero
/* EFEEC0 802403C0 0C0B53A3 */  jal       func_802D4E8C
/* EFEEC4 802403C4 46000506 */   mov.s    $f20, $f0
/* EFEEC8 802403C8 8E050000 */  lw        $a1, ($s0)
/* EFEECC 802403CC 26100004 */  addiu     $s0, $s0, 4
/* EFEED0 802403D0 0240202D */  daddu     $a0, $s2, $zero
/* EFEED4 802403D4 0C0B53A3 */  jal       func_802D4E8C
/* EFEED8 802403D8 0040882D */   daddu    $s1, $v0, $zero
/* EFEEDC 802403DC 0240202D */  daddu     $a0, $s2, $zero
/* EFEEE0 802403E0 8E050000 */  lw        $a1, ($s0)
/* EFEEE4 802403E4 0C0B55FF */  jal       func_802D57FC
/* EFEEE8 802403E8 0040802D */   daddu    $s0, $v0, $zero
/* EFEEEC 802403EC 3C014334 */  lui       $at, 0x4334
/* EFEEF0 802403F0 44811000 */  mtc1      $at, $f2
/* EFEEF4 802403F4 3C014049 */  lui       $at, 0x4049
/* EFEEF8 802403F8 34210FD8 */  ori       $at, $at, 0xfd8
/* EFEEFC 802403FC 44812000 */  mtc1      $at, $f4
/* EFEF00 80240400 46020003 */  div.s     $f0, $f0, $f2
/* EFEF04 80240404 46040582 */  mul.s     $f22, $f0, $f4
/* EFEF08 80240408 00000000 */  nop       
/* EFEF0C 8024040C 4618A501 */  sub.s     $f20, $f20, $f24
/* EFEF10 80240410 3C013F00 */  lui       $at, 0x3f00
/* EFEF14 80240414 44810000 */  mtc1      $at, $f0
/* EFEF18 80240418 4600A505 */  abs.s     $f20, $f20
/* EFEF1C 8024041C 4600A502 */  mul.s     $f20, $f20, $f0
/* EFEF20 80240420 00000000 */  nop       
/* EFEF24 80240424 12000007 */  beqz      $s0, .L80240444
/* EFEF28 80240428 0233102A */   slt      $v0, $s1, $s3
/* EFEF2C 8024042C 10400005 */  beqz      $v0, .L80240444
/* EFEF30 80240430 0240202D */   daddu    $a0, $s2, $zero
/* EFEF34 80240434 0220982D */  daddu     $s3, $s1, $zero
/* EFEF38 80240438 0280282D */  daddu     $a1, $s4, $zero
/* EFEF3C 8024043C 0C0B551A */  jal       func_802D5468
/* EFEF40 80240440 0220302D */   daddu    $a2, $s1, $zero
.L80240444:
/* EFEF44 80240444 3C014049 */  lui       $at, 0x4049
/* EFEF48 80240448 34210FD8 */  ori       $at, $at, 0xfd8
/* EFEF4C 8024044C 44810000 */  mtc1      $at, $f0
/* EFEF50 80240450 44936000 */  mtc1      $s3, $f12
/* EFEF54 80240454 00000000 */  nop       
/* EFEF58 80240458 46806320 */  cvt.s.w   $f12, $f12
/* EFEF5C 8024045C 46006302 */  mul.s     $f12, $f12, $f0
/* EFEF60 80240460 00000000 */  nop       
/* EFEF64 80240464 44910000 */  mtc1      $s1, $f0
/* EFEF68 80240468 00000000 */  nop       
/* EFEF6C 8024046C 46800020 */  cvt.s.w   $f0, $f0
/* EFEF70 80240470 46006303 */  div.s     $f12, $f12, $f0
/* EFEF74 80240474 0C00AD30 */  jal       func_8002B4C0
/* EFEF78 80240478 46166300 */   add.s    $f12, $f12, $f22
/* EFEF7C 8024047C 4600A002 */  mul.s     $f0, $f20, $f0
/* EFEF80 80240480 00000000 */  nop       
/* EFEF84 80240484 4614C080 */  add.s     $f2, $f24, $f20
/* EFEF88 80240488 46001081 */  sub.s     $f2, $f2, $f0
/* EFEF8C 8024048C 0240202D */  daddu     $a0, $s2, $zero
/* EFEF90 80240490 44061000 */  mfc1      $a2, $f2
/* EFEF94 80240494 0C0B5684 */  jal       func_802D5A10
/* EFEF98 80240498 02A0282D */   daddu    $a1, $s5, $zero
/* EFEF9C 8024049C 8FBF0028 */  lw        $ra, 0x28($sp)
/* EFEFA0 802404A0 8FB50024 */  lw        $s5, 0x24($sp)
/* EFEFA4 802404A4 8FB40020 */  lw        $s4, 0x20($sp)
/* EFEFA8 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* EFEFAC 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* EFEFB0 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* EFEFB4 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* EFEFB8 802404B8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* EFEFBC 802404BC D7B60038 */  ldc1      $f22, 0x38($sp)
/* EFEFC0 802404C0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* EFEFC4 802404C4 24020002 */  addiu     $v0, $zero, 2
/* EFEFC8 802404C8 03E00008 */  jr        $ra
/* EFEFCC 802404CC 27BD0048 */   addiu    $sp, $sp, 0x48
