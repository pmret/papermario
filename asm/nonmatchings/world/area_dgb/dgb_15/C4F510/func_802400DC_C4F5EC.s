.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400DC_C4F5EC
/* C4F5EC 802400DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C4F5F0 802400E0 AFB10034 */  sw        $s1, 0x34($sp)
/* C4F5F4 802400E4 0080882D */  daddu     $s1, $a0, $zero
/* C4F5F8 802400E8 AFBF0038 */  sw        $ra, 0x38($sp)
/* C4F5FC 802400EC AFB00030 */  sw        $s0, 0x30($sp)
/* C4F600 802400F0 8E300148 */  lw        $s0, 0x148($s1)
/* C4F604 802400F4 0C00EABB */  jal       get_npc_unsafe
/* C4F608 802400F8 86040008 */   lh       $a0, 8($s0)
/* C4F60C 802400FC 0040282D */  daddu     $a1, $v0, $zero
/* C4F610 80240100 94A2008E */  lhu       $v0, 0x8e($a1)
/* C4F614 80240104 2442FFFF */  addiu     $v0, $v0, -1
/* C4F618 80240108 A4A2008E */  sh        $v0, 0x8e($a1)
/* C4F61C 8024010C 00021400 */  sll       $v0, $v0, 0x10
/* C4F620 80240110 1C400023 */  bgtz      $v0, .L802401A0
/* C4F624 80240114 24020004 */   addiu    $v0, $zero, 4
/* C4F628 80240118 8E0300CC */  lw        $v1, 0xcc($s0)
/* C4F62C 8024011C AE02006C */  sw        $v0, 0x6c($s0)
/* C4F630 80240120 8C620000 */  lw        $v0, ($v1)
/* C4F634 80240124 ACA20028 */  sw        $v0, 0x28($a1)
/* C4F638 80240128 9602007A */  lhu       $v0, 0x7a($s0)
/* C4F63C 8024012C A4A2008E */  sh        $v0, 0x8e($a1)
/* C4F640 80240130 8E020078 */  lw        $v0, 0x78($s0)
/* C4F644 80240134 28420008 */  slti      $v0, $v0, 8
/* C4F648 80240138 14400018 */  bnez      $v0, .L8024019C
/* C4F64C 8024013C 24020021 */   addiu    $v0, $zero, 0x21
/* C4F650 80240140 24040003 */  addiu     $a0, $zero, 3
/* C4F654 80240144 27A30028 */  addiu     $v1, $sp, 0x28
/* C4F658 80240148 84A700A8 */  lh        $a3, 0xa8($a1)
/* C4F65C 8024014C 3C013F80 */  lui       $at, 0x3f80
/* C4F660 80240150 44810000 */  mtc1      $at, $f0
/* C4F664 80240154 3C014000 */  lui       $at, 0x4000
/* C4F668 80240158 44811000 */  mtc1      $at, $f2
/* C4F66C 8024015C 3C01C1A0 */  lui       $at, 0xc1a0
/* C4F670 80240160 44812000 */  mtc1      $at, $f4
/* C4F674 80240164 44873000 */  mtc1      $a3, $f6
/* C4F678 80240168 00000000 */  nop       
/* C4F67C 8024016C 468031A0 */  cvt.s.w   $f6, $f6
/* C4F680 80240170 E7A00010 */  swc1      $f0, 0x10($sp)
/* C4F684 80240174 E7A20014 */  swc1      $f2, 0x14($sp)
/* C4F688 80240178 E7A40018 */  swc1      $f4, 0x18($sp)
/* C4F68C 8024017C 8E020078 */  lw        $v0, 0x78($s0)
/* C4F690 80240180 44073000 */  mfc1      $a3, $f6
/* C4F694 80240184 0000302D */  daddu     $a2, $zero, $zero
/* C4F698 80240188 AFA30020 */  sw        $v1, 0x20($sp)
/* C4F69C 8024018C 2442FFFF */  addiu     $v0, $v0, -1
/* C4F6A0 80240190 0C01BFA4 */  jal       fx_emote
/* C4F6A4 80240194 AFA2001C */   sw       $v0, 0x1c($sp)
/* C4F6A8 80240198 24020021 */  addiu     $v0, $zero, 0x21
.L8024019C:
/* C4F6AC 8024019C AE220070 */  sw        $v0, 0x70($s1)
.L802401A0:
/* C4F6B0 802401A0 8FBF0038 */  lw        $ra, 0x38($sp)
/* C4F6B4 802401A4 8FB10034 */  lw        $s1, 0x34($sp)
/* C4F6B8 802401A8 8FB00030 */  lw        $s0, 0x30($sp)
/* C4F6BC 802401AC 03E00008 */  jr        $ra
/* C4F6C0 802401B0 27BD0040 */   addiu    $sp, $sp, 0x40
