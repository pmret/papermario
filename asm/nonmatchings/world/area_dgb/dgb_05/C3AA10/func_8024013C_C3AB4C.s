.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024013C_C3AB4C
/* C3AB4C 8024013C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C3AB50 80240140 AFB10034 */  sw        $s1, 0x34($sp)
/* C3AB54 80240144 0080882D */  daddu     $s1, $a0, $zero
/* C3AB58 80240148 AFBF0038 */  sw        $ra, 0x38($sp)
/* C3AB5C 8024014C AFB00030 */  sw        $s0, 0x30($sp)
/* C3AB60 80240150 8E300148 */  lw        $s0, 0x148($s1)
/* C3AB64 80240154 0C00EABB */  jal       get_npc_unsafe
/* C3AB68 80240158 86040008 */   lh       $a0, 8($s0)
/* C3AB6C 8024015C 0040282D */  daddu     $a1, $v0, $zero
/* C3AB70 80240160 94A2008E */  lhu       $v0, 0x8e($a1)
/* C3AB74 80240164 2442FFFF */  addiu     $v0, $v0, -1
/* C3AB78 80240168 A4A2008E */  sh        $v0, 0x8e($a1)
/* C3AB7C 8024016C 00021400 */  sll       $v0, $v0, 0x10
/* C3AB80 80240170 1C400023 */  bgtz      $v0, .L80240200
/* C3AB84 80240174 24020004 */   addiu    $v0, $zero, 4
/* C3AB88 80240178 8E0300CC */  lw        $v1, 0xcc($s0)
/* C3AB8C 8024017C AE02006C */  sw        $v0, 0x6c($s0)
/* C3AB90 80240180 8C620000 */  lw        $v0, ($v1)
/* C3AB94 80240184 ACA20028 */  sw        $v0, 0x28($a1)
/* C3AB98 80240188 9602007A */  lhu       $v0, 0x7a($s0)
/* C3AB9C 8024018C A4A2008E */  sh        $v0, 0x8e($a1)
/* C3ABA0 80240190 8E020078 */  lw        $v0, 0x78($s0)
/* C3ABA4 80240194 28420008 */  slti      $v0, $v0, 8
/* C3ABA8 80240198 14400018 */  bnez      $v0, .L802401FC
/* C3ABAC 8024019C 24020021 */   addiu    $v0, $zero, 0x21
/* C3ABB0 802401A0 24040003 */  addiu     $a0, $zero, 3
/* C3ABB4 802401A4 27A30028 */  addiu     $v1, $sp, 0x28
/* C3ABB8 802401A8 84A700A8 */  lh        $a3, 0xa8($a1)
/* C3ABBC 802401AC 3C013F80 */  lui       $at, 0x3f80
/* C3ABC0 802401B0 44810000 */  mtc1      $at, $f0
/* C3ABC4 802401B4 3C014000 */  lui       $at, 0x4000
/* C3ABC8 802401B8 44811000 */  mtc1      $at, $f2
/* C3ABCC 802401BC 3C01C1A0 */  lui       $at, 0xc1a0
/* C3ABD0 802401C0 44812000 */  mtc1      $at, $f4
/* C3ABD4 802401C4 44873000 */  mtc1      $a3, $f6
/* C3ABD8 802401C8 00000000 */  nop       
/* C3ABDC 802401CC 468031A0 */  cvt.s.w   $f6, $f6
/* C3ABE0 802401D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C3ABE4 802401D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3ABE8 802401D8 E7A40018 */  swc1      $f4, 0x18($sp)
/* C3ABEC 802401DC 8E020078 */  lw        $v0, 0x78($s0)
/* C3ABF0 802401E0 44073000 */  mfc1      $a3, $f6
/* C3ABF4 802401E4 0000302D */  daddu     $a2, $zero, $zero
/* C3ABF8 802401E8 AFA30020 */  sw        $v1, 0x20($sp)
/* C3ABFC 802401EC 2442FFFF */  addiu     $v0, $v0, -1
/* C3AC00 802401F0 0C01BFA4 */  jal       fx_emote
/* C3AC04 802401F4 AFA2001C */   sw       $v0, 0x1c($sp)
/* C3AC08 802401F8 24020021 */  addiu     $v0, $zero, 0x21
.L802401FC:
/* C3AC0C 802401FC AE220070 */  sw        $v0, 0x70($s1)
.L80240200:
/* C3AC10 80240200 8FBF0038 */  lw        $ra, 0x38($sp)
/* C3AC14 80240204 8FB10034 */  lw        $s1, 0x34($sp)
/* C3AC18 80240208 8FB00030 */  lw        $s0, 0x30($sp)
/* C3AC1C 8024020C 03E00008 */  jr        $ra
/* C3AC20 80240210 27BD0040 */   addiu    $sp, $sp, 0x40
