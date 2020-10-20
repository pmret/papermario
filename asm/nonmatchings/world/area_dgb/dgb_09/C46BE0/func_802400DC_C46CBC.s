.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400DC_C46CBC
/* C46CBC 802400DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C46CC0 802400E0 AFB10034 */  sw        $s1, 0x34($sp)
/* C46CC4 802400E4 0080882D */  daddu     $s1, $a0, $zero
/* C46CC8 802400E8 AFBF0038 */  sw        $ra, 0x38($sp)
/* C46CCC 802400EC AFB00030 */  sw        $s0, 0x30($sp)
/* C46CD0 802400F0 8E300148 */  lw        $s0, 0x148($s1)
/* C46CD4 802400F4 0C00EABB */  jal       get_npc_unsafe
/* C46CD8 802400F8 86040008 */   lh       $a0, 8($s0)
/* C46CDC 802400FC 0040282D */  daddu     $a1, $v0, $zero
/* C46CE0 80240100 94A2008E */  lhu       $v0, 0x8e($a1)
/* C46CE4 80240104 2442FFFF */  addiu     $v0, $v0, -1
/* C46CE8 80240108 A4A2008E */  sh        $v0, 0x8e($a1)
/* C46CEC 8024010C 00021400 */  sll       $v0, $v0, 0x10
/* C46CF0 80240110 1C400023 */  bgtz      $v0, .L802401A0
/* C46CF4 80240114 24020004 */   addiu    $v0, $zero, 4
/* C46CF8 80240118 8E0300CC */  lw        $v1, 0xcc($s0)
/* C46CFC 8024011C AE02006C */  sw        $v0, 0x6c($s0)
/* C46D00 80240120 8C620000 */  lw        $v0, ($v1)
/* C46D04 80240124 ACA20028 */  sw        $v0, 0x28($a1)
/* C46D08 80240128 9602007A */  lhu       $v0, 0x7a($s0)
/* C46D0C 8024012C A4A2008E */  sh        $v0, 0x8e($a1)
/* C46D10 80240130 8E020078 */  lw        $v0, 0x78($s0)
/* C46D14 80240134 28420008 */  slti      $v0, $v0, 8
/* C46D18 80240138 14400018 */  bnez      $v0, .L8024019C
/* C46D1C 8024013C 24020021 */   addiu    $v0, $zero, 0x21
/* C46D20 80240140 24040003 */  addiu     $a0, $zero, 3
/* C46D24 80240144 27A30028 */  addiu     $v1, $sp, 0x28
/* C46D28 80240148 84A700A8 */  lh        $a3, 0xa8($a1)
/* C46D2C 8024014C 3C013F80 */  lui       $at, 0x3f80
/* C46D30 80240150 44810000 */  mtc1      $at, $f0
/* C46D34 80240154 3C014000 */  lui       $at, 0x4000
/* C46D38 80240158 44811000 */  mtc1      $at, $f2
/* C46D3C 8024015C 3C01C1A0 */  lui       $at, 0xc1a0
/* C46D40 80240160 44812000 */  mtc1      $at, $f4
/* C46D44 80240164 44873000 */  mtc1      $a3, $f6
/* C46D48 80240168 00000000 */  nop       
/* C46D4C 8024016C 468031A0 */  cvt.s.w   $f6, $f6
/* C46D50 80240170 E7A00010 */  swc1      $f0, 0x10($sp)
/* C46D54 80240174 E7A20014 */  swc1      $f2, 0x14($sp)
/* C46D58 80240178 E7A40018 */  swc1      $f4, 0x18($sp)
/* C46D5C 8024017C 8E020078 */  lw        $v0, 0x78($s0)
/* C46D60 80240180 44073000 */  mfc1      $a3, $f6
/* C46D64 80240184 0000302D */  daddu     $a2, $zero, $zero
/* C46D68 80240188 AFA30020 */  sw        $v1, 0x20($sp)
/* C46D6C 8024018C 2442FFFF */  addiu     $v0, $v0, -1
/* C46D70 80240190 0C01BFA4 */  jal       fx_emote
/* C46D74 80240194 AFA2001C */   sw       $v0, 0x1c($sp)
/* C46D78 80240198 24020021 */  addiu     $v0, $zero, 0x21
.L8024019C:
/* C46D7C 8024019C AE220070 */  sw        $v0, 0x70($s1)
.L802401A0:
/* C46D80 802401A0 8FBF0038 */  lw        $ra, 0x38($sp)
/* C46D84 802401A4 8FB10034 */  lw        $s1, 0x34($sp)
/* C46D88 802401A8 8FB00030 */  lw        $s0, 0x30($sp)
/* C46D8C 802401AC 03E00008 */  jr        $ra
/* C46D90 802401B0 27BD0040 */   addiu    $sp, $sp, 0x40
