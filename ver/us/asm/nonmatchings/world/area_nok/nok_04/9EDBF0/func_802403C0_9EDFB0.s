.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C0_9EDFB0
/* 9EDFB0 802403C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9EDFB4 802403C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EDFB8 802403C8 0080882D */  daddu     $s1, $a0, $zero
/* 9EDFBC 802403CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9EDFC0 802403D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EDFC4 802403D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9EDFC8 802403D8 8E30000C */  lw        $s0, 0xc($s1)
/* 9EDFCC 802403DC 8E050000 */  lw        $a1, ($s0)
/* 9EDFD0 802403E0 0C0B1EAF */  jal       evt_get_variable
/* 9EDFD4 802403E4 26100004 */   addiu    $s0, $s0, 4
/* 9EDFD8 802403E8 8E050000 */  lw        $a1, ($s0)
/* 9EDFDC 802403EC 26100004 */  addiu     $s0, $s0, 4
/* 9EDFE0 802403F0 0220202D */  daddu     $a0, $s1, $zero
/* 9EDFE4 802403F4 0C0B1EAF */  jal       evt_get_variable
/* 9EDFE8 802403F8 0040902D */   daddu    $s2, $v0, $zero
/* 9EDFEC 802403FC 0220202D */  daddu     $a0, $s1, $zero
/* 9EDFF0 80240400 8E050000 */  lw        $a1, ($s0)
/* 9EDFF4 80240404 0C0B1EAF */  jal       evt_get_variable
/* 9EDFF8 80240408 0040802D */   daddu    $s0, $v0, $zero
/* 9EDFFC 8024040C 3C038024 */  lui       $v1, %hi(D_802413F8_9EEFE8)
/* 9EE000 80240410 246313F8 */  addiu     $v1, $v1, %lo(D_802413F8_9EEFE8)
/* 9EE004 80240414 06010002 */  bgez      $s0, .L80240420
/* 9EE008 80240418 0040202D */   daddu    $a0, $v0, $zero
/* 9EE00C 8024041C 2610000F */  addiu     $s0, $s0, 0xf
.L80240420:
/* 9EE010 80240420 00101103 */  sra       $v0, $s0, 4
/* 9EE014 80240424 44824000 */  mtc1      $v0, $f8
/* 9EE018 80240428 00000000 */  nop
/* 9EE01C 8024042C 46804220 */  cvt.s.w   $f8, $f8
/* 9EE020 80240430 3C013D80 */  lui       $at, 0x3d80
/* 9EE024 80240434 44811000 */  mtc1      $at, $f2
/* 9EE028 80240438 44920000 */  mtc1      $s2, $f0
/* 9EE02C 8024043C 00000000 */  nop
/* 9EE030 80240440 46800020 */  cvt.s.w   $f0, $f0
/* 9EE034 80240444 AC600034 */  sw        $zero, 0x34($v1)
/* 9EE038 80240448 46020182 */  mul.s     $f6, $f0, $f2
/* 9EE03C 8024044C 00000000 */  nop
/* 9EE040 80240450 C46A0034 */  lwc1      $f10, 0x34($v1)
/* 9EE044 80240454 44842000 */  mtc1      $a0, $f4
/* 9EE048 80240458 00000000 */  nop
/* 9EE04C 8024045C 46802120 */  cvt.s.w   $f4, $f4
/* 9EE050 80240460 E4680018 */  swc1      $f8, 0x18($v1)
/* 9EE054 80240464 E4640030 */  swc1      $f4, 0x30($v1)
/* 9EE058 80240468 4604503C */  c.lt.s    $f10, $f4
/* 9EE05C 8024046C 00000000 */  nop
/* 9EE060 80240470 45000009 */  bc1f      .L80240498
/* 9EE064 80240474 E466000C */   swc1     $f6, 0xc($v1)
/* 9EE068 80240478 C4600010 */  lwc1      $f0, 0x10($v1)
/* 9EE06C 8024047C 46003001 */  sub.s     $f0, $f6, $f0
/* 9EE070 80240480 C4620020 */  lwc1      $f2, 0x20($v1)
/* 9EE074 80240484 46024081 */  sub.s     $f2, $f8, $f2
/* 9EE078 80240488 46040003 */  div.s     $f0, $f0, $f4
/* 9EE07C 8024048C 46041083 */  div.s     $f2, $f2, $f4
/* 9EE080 80240490 E4600038 */  swc1      $f0, 0x38($v1)
/* 9EE084 80240494 E462003C */  swc1      $f2, 0x3c($v1)
.L80240498:
/* 9EE088 80240498 460A203C */  c.lt.s    $f4, $f10
/* 9EE08C 8024049C 00000000 */  nop
/* 9EE090 802404A0 45000004 */  bc1f      .L802404B4
/* 9EE094 802404A4 00000000 */   nop
/* 9EE098 802404A8 E4660010 */  swc1      $f6, 0x10($v1)
/* 9EE09C 802404AC E4680020 */  swc1      $f8, 0x20($v1)
/* 9EE0A0 802404B0 E46A0030 */  swc1      $f10, 0x30($v1)
.L802404B4:
/* 9EE0A4 802404B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9EE0A8 802404B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EE0AC 802404BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EE0B0 802404C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EE0B4 802404C4 24020002 */  addiu     $v0, $zero, 2
/* 9EE0B8 802404C8 03E00008 */  jr        $ra
/* 9EE0BC 802404CC 27BD0020 */   addiu    $sp, $sp, 0x20
