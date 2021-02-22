.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A10_BB0350
/* BB0350 80242A10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BB0354 80242A14 AFB10014 */  sw        $s1, 0x14($sp)
/* BB0358 80242A18 0080882D */  daddu     $s1, $a0, $zero
/* BB035C 80242A1C AFBF0018 */  sw        $ra, 0x18($sp)
/* BB0360 80242A20 AFB00010 */  sw        $s0, 0x10($sp)
/* BB0364 80242A24 8E300148 */  lw        $s0, 0x148($s1)
/* BB0368 80242A28 0C00EABB */  jal       get_npc_unsafe
/* BB036C 80242A2C 86040008 */   lh       $a0, 8($s0)
/* BB0370 80242A30 0040202D */  daddu     $a0, $v0, $zero
/* BB0374 80242A34 9482008E */  lhu       $v0, 0x8e($a0)
/* BB0378 80242A38 2442FFFF */  addiu     $v0, $v0, -1
/* BB037C 80242A3C A482008E */  sh        $v0, 0x8e($a0)
/* BB0380 80242A40 00021400 */  sll       $v0, $v0, 0x10
/* BB0384 80242A44 8E030098 */  lw        $v1, 0x98($s0)
/* BB0388 80242A48 00021403 */  sra       $v0, $v0, 0x10
/* BB038C 80242A4C 0062182A */  slt       $v1, $v1, $v0
/* BB0390 80242A50 14600005 */  bnez      $v1, .L80242A68
/* BB0394 80242A54 3C03E0EF */   lui      $v1, 0xe0ef
/* BB0398 80242A58 8E020000 */  lw        $v0, ($s0)
/* BB039C 80242A5C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BB03A0 80242A60 00431024 */  and       $v0, $v0, $v1
/* BB03A4 80242A64 AE020000 */  sw        $v0, ($s0)
.L80242A68:
/* BB03A8 80242A68 8482008E */  lh        $v0, 0x8e($a0)
/* BB03AC 80242A6C 14400007 */  bnez      $v0, .L80242A8C
/* BB03B0 80242A70 00000000 */   nop
/* BB03B4 80242A74 8E0200CC */  lw        $v0, 0xcc($s0)
/* BB03B8 80242A78 8C420028 */  lw        $v0, 0x28($v0)
/* BB03BC 80242A7C A480008E */  sh        $zero, 0x8e($a0)
/* BB03C0 80242A80 AC820028 */  sw        $v0, 0x28($a0)
/* BB03C4 80242A84 2402000C */  addiu     $v0, $zero, 0xc
/* BB03C8 80242A88 AE220070 */  sw        $v0, 0x70($s1)
.L80242A8C:
/* BB03CC 80242A8C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BB03D0 80242A90 8FB10014 */  lw        $s1, 0x14($sp)
/* BB03D4 80242A94 8FB00010 */  lw        $s0, 0x10($sp)
/* BB03D8 80242A98 03E00008 */  jr        $ra
/* BB03DC 80242A9C 27BD0020 */   addiu    $sp, $sp, 0x20
