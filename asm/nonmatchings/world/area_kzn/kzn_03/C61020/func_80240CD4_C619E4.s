.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD4_C619E4
/* C619E4 80240CD4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C619E8 80240CD8 AFB10034 */  sw        $s1, 0x34($sp)
/* C619EC 80240CDC 0080882D */  daddu     $s1, $a0, $zero
/* C619F0 80240CE0 AFBF0038 */  sw        $ra, 0x38($sp)
/* C619F4 80240CE4 AFB00030 */  sw        $s0, 0x30($sp)
/* C619F8 80240CE8 8E300148 */  lw        $s0, 0x148($s1)
/* C619FC 80240CEC 0C00EABB */  jal       get_npc_unsafe
/* C61A00 80240CF0 86040008 */   lh       $a0, 8($s0)
/* C61A04 80240CF4 0040282D */  daddu     $a1, $v0, $zero
/* C61A08 80240CF8 94A2008E */  lhu       $v0, 0x8e($a1)
/* C61A0C 80240CFC 2442FFFF */  addiu     $v0, $v0, -1
/* C61A10 80240D00 A4A2008E */  sh        $v0, 0x8e($a1)
/* C61A14 80240D04 00021400 */  sll       $v0, $v0, 0x10
/* C61A18 80240D08 1C400023 */  bgtz      $v0, .L80240D98
/* C61A1C 80240D0C 24020004 */   addiu    $v0, $zero, 4
/* C61A20 80240D10 8E0300CC */  lw        $v1, 0xcc($s0)
/* C61A24 80240D14 AE02006C */  sw        $v0, 0x6c($s0)
/* C61A28 80240D18 8C620000 */  lw        $v0, ($v1)
/* C61A2C 80240D1C ACA20028 */  sw        $v0, 0x28($a1)
/* C61A30 80240D20 9602007A */  lhu       $v0, 0x7a($s0)
/* C61A34 80240D24 A4A2008E */  sh        $v0, 0x8e($a1)
/* C61A38 80240D28 8E020078 */  lw        $v0, 0x78($s0)
/* C61A3C 80240D2C 28420008 */  slti      $v0, $v0, 8
/* C61A40 80240D30 14400018 */  bnez      $v0, .L80240D94
/* C61A44 80240D34 24020021 */   addiu    $v0, $zero, 0x21
/* C61A48 80240D38 24040003 */  addiu     $a0, $zero, 3
/* C61A4C 80240D3C 27A30028 */  addiu     $v1, $sp, 0x28
/* C61A50 80240D40 84A700A8 */  lh        $a3, 0xa8($a1)
/* C61A54 80240D44 3C013F80 */  lui       $at, 0x3f80
/* C61A58 80240D48 44810000 */  mtc1      $at, $f0
/* C61A5C 80240D4C 3C014000 */  lui       $at, 0x4000
/* C61A60 80240D50 44811000 */  mtc1      $at, $f2
/* C61A64 80240D54 3C01C1A0 */  lui       $at, 0xc1a0
/* C61A68 80240D58 44812000 */  mtc1      $at, $f4
/* C61A6C 80240D5C 44873000 */  mtc1      $a3, $f6
/* C61A70 80240D60 00000000 */  nop       
/* C61A74 80240D64 468031A0 */  cvt.s.w   $f6, $f6
/* C61A78 80240D68 E7A00010 */  swc1      $f0, 0x10($sp)
/* C61A7C 80240D6C E7A20014 */  swc1      $f2, 0x14($sp)
/* C61A80 80240D70 E7A40018 */  swc1      $f4, 0x18($sp)
/* C61A84 80240D74 8E020078 */  lw        $v0, 0x78($s0)
/* C61A88 80240D78 44073000 */  mfc1      $a3, $f6
/* C61A8C 80240D7C 0000302D */  daddu     $a2, $zero, $zero
/* C61A90 80240D80 AFA30020 */  sw        $v1, 0x20($sp)
/* C61A94 80240D84 2442FFFF */  addiu     $v0, $v0, -1
/* C61A98 80240D88 0C01BFA4 */  jal       fx_emote
/* C61A9C 80240D8C AFA2001C */   sw       $v0, 0x1c($sp)
/* C61AA0 80240D90 24020021 */  addiu     $v0, $zero, 0x21
.L80240D94:
/* C61AA4 80240D94 AE220070 */  sw        $v0, 0x70($s1)
.L80240D98:
/* C61AA8 80240D98 8FBF0038 */  lw        $ra, 0x38($sp)
/* C61AAC 80240D9C 8FB10034 */  lw        $s1, 0x34($sp)
/* C61AB0 80240DA0 8FB00030 */  lw        $s0, 0x30($sp)
/* C61AB4 80240DA4 03E00008 */  jr        $ra
/* C61AB8 80240DA8 27BD0040 */   addiu    $sp, $sp, 0x40
