.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240114_7E74B4
/* 7E74B4 80240114 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E74B8 80240118 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E74BC 8024011C 0080802D */  daddu     $s0, $a0, $zero
/* 7E74C0 80240120 10A00009 */  beqz      $a1, .L80240148
/* 7E74C4 80240124 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7E74C8 80240128 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 7E74CC 8024012C 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 7E74D0 80240130 AE000070 */  sw        $zero, 0x70($s0)
/* 7E74D4 80240134 8C430000 */  lw        $v1, ($v0)
/* 7E74D8 80240138 240400FF */  addiu     $a0, $zero, 0xff
/* 7E74DC 8024013C AE040074 */  sw        $a0, 0x74($s0)
/* 7E74E0 80240140 34630010 */  ori       $v1, $v1, 0x10
/* 7E74E4 80240144 AC430000 */  sw        $v1, ($v0)
.L80240148:
/* 7E74E8 80240148 C6000074 */  lwc1      $f0, 0x74($s0)
/* 7E74EC 8024014C 46800020 */  cvt.s.w   $f0, $f0
/* 7E74F0 80240150 44050000 */  mfc1      $a1, $f0
/* 7E74F4 80240154 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 7E74F8 80240158 0000202D */   daddu    $a0, $zero, $zero
/* 7E74FC 8024015C 8E020074 */  lw        $v0, 0x74($s0)
/* 7E7500 80240160 14400009 */  bnez      $v0, .L80240188
/* 7E7504 80240164 2442FFF6 */   addiu    $v0, $v0, -0xa
/* 7E7508 80240168 24020002 */  addiu     $v0, $zero, 2
/* 7E750C 8024016C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 7E7510 80240170 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 7E7514 80240174 8C640000 */  lw        $a0, ($v1)
/* 7E7518 80240178 2405FFEF */  addiu     $a1, $zero, -0x11
/* 7E751C 8024017C 00852024 */  and       $a0, $a0, $a1
/* 7E7520 80240180 08090066 */  j         .L80240198
/* 7E7524 80240184 AC640000 */   sw       $a0, ($v1)
.L80240188:
/* 7E7528 80240188 04410002 */  bgez      $v0, .L80240194
/* 7E752C 8024018C AE020074 */   sw       $v0, 0x74($s0)
/* 7E7530 80240190 AE000074 */  sw        $zero, 0x74($s0)
.L80240194:
/* 7E7534 80240194 0000102D */  daddu     $v0, $zero, $zero
.L80240198:
/* 7E7538 80240198 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E753C 8024019C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E7540 802401A0 03E00008 */  jr        $ra
/* 7E7544 802401A4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 7E7548 802401A8 00000000 */  nop
/* 7E754C 802401AC 00000000 */  nop
