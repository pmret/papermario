.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400DC_C3DCCC
/* C3DCCC 802400DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C3DCD0 802400E0 AFB10034 */  sw        $s1, 0x34($sp)
/* C3DCD4 802400E4 0080882D */  daddu     $s1, $a0, $zero
/* C3DCD8 802400E8 AFBF0038 */  sw        $ra, 0x38($sp)
/* C3DCDC 802400EC AFB00030 */  sw        $s0, 0x30($sp)
/* C3DCE0 802400F0 8E300148 */  lw        $s0, 0x148($s1)
/* C3DCE4 802400F4 0C00EABB */  jal       get_npc_unsafe
/* C3DCE8 802400F8 86040008 */   lh       $a0, 8($s0)
/* C3DCEC 802400FC 0040282D */  daddu     $a1, $v0, $zero
/* C3DCF0 80240100 94A2008E */  lhu       $v0, 0x8e($a1)
/* C3DCF4 80240104 2442FFFF */  addiu     $v0, $v0, -1
/* C3DCF8 80240108 A4A2008E */  sh        $v0, 0x8e($a1)
/* C3DCFC 8024010C 00021400 */  sll       $v0, $v0, 0x10
/* C3DD00 80240110 1C400023 */  bgtz      $v0, .L802401A0
/* C3DD04 80240114 24020004 */   addiu    $v0, $zero, 4
/* C3DD08 80240118 8E0300CC */  lw        $v1, 0xcc($s0)
/* C3DD0C 8024011C AE02006C */  sw        $v0, 0x6c($s0)
/* C3DD10 80240120 8C620000 */  lw        $v0, ($v1)
/* C3DD14 80240124 ACA20028 */  sw        $v0, 0x28($a1)
/* C3DD18 80240128 9602007A */  lhu       $v0, 0x7a($s0)
/* C3DD1C 8024012C A4A2008E */  sh        $v0, 0x8e($a1)
/* C3DD20 80240130 8E020078 */  lw        $v0, 0x78($s0)
/* C3DD24 80240134 28420008 */  slti      $v0, $v0, 8
/* C3DD28 80240138 14400018 */  bnez      $v0, .L8024019C
/* C3DD2C 8024013C 24020021 */   addiu    $v0, $zero, 0x21
/* C3DD30 80240140 24040003 */  addiu     $a0, $zero, 3
/* C3DD34 80240144 27A30028 */  addiu     $v1, $sp, 0x28
/* C3DD38 80240148 84A700A8 */  lh        $a3, 0xa8($a1)
/* C3DD3C 8024014C 3C013F80 */  lui       $at, 0x3f80
/* C3DD40 80240150 44810000 */  mtc1      $at, $f0
/* C3DD44 80240154 3C014000 */  lui       $at, 0x4000
/* C3DD48 80240158 44811000 */  mtc1      $at, $f2
/* C3DD4C 8024015C 3C01C1A0 */  lui       $at, 0xc1a0
/* C3DD50 80240160 44812000 */  mtc1      $at, $f4
/* C3DD54 80240164 44873000 */  mtc1      $a3, $f6
/* C3DD58 80240168 00000000 */  nop       
/* C3DD5C 8024016C 468031A0 */  cvt.s.w   $f6, $f6
/* C3DD60 80240170 E7A00010 */  swc1      $f0, 0x10($sp)
/* C3DD64 80240174 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3DD68 80240178 E7A40018 */  swc1      $f4, 0x18($sp)
/* C3DD6C 8024017C 8E020078 */  lw        $v0, 0x78($s0)
/* C3DD70 80240180 44073000 */  mfc1      $a3, $f6
/* C3DD74 80240184 0000302D */  daddu     $a2, $zero, $zero
/* C3DD78 80240188 AFA30020 */  sw        $v1, 0x20($sp)
/* C3DD7C 8024018C 2442FFFF */  addiu     $v0, $v0, -1
/* C3DD80 80240190 0C01BFA4 */  jal       fx_emote
/* C3DD84 80240194 AFA2001C */   sw       $v0, 0x1c($sp)
/* C3DD88 80240198 24020021 */  addiu     $v0, $zero, 0x21
.L8024019C:
/* C3DD8C 8024019C AE220070 */  sw        $v0, 0x70($s1)
.L802401A0:
/* C3DD90 802401A0 8FBF0038 */  lw        $ra, 0x38($sp)
/* C3DD94 802401A4 8FB10034 */  lw        $s1, 0x34($sp)
/* C3DD98 802401A8 8FB00030 */  lw        $s0, 0x30($sp)
/* C3DD9C 802401AC 03E00008 */  jr        $ra
/* C3DDA0 802401B0 27BD0040 */   addiu    $sp, $sp, 0x40
