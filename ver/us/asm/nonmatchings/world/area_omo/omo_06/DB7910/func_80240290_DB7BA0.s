.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290_DB7BA0
/* DB7BA0 80240290 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DB7BA4 80240294 AFB10014 */  sw        $s1, 0x14($sp)
/* DB7BA8 80240298 0080882D */  daddu     $s1, $a0, $zero
/* DB7BAC 8024029C AFBF001C */  sw        $ra, 0x1c($sp)
/* DB7BB0 802402A0 AFB20018 */  sw        $s2, 0x18($sp)
/* DB7BB4 802402A4 AFB00010 */  sw        $s0, 0x10($sp)
/* DB7BB8 802402A8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* DB7BBC 802402AC F7B80030 */  sdc1      $f24, 0x30($sp)
/* DB7BC0 802402B0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DB7BC4 802402B4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DB7BC8 802402B8 8E30000C */  lw        $s0, 0xc($s1)
/* DB7BCC 802402BC 8E050000 */  lw        $a1, ($s0)
/* DB7BD0 802402C0 0C0B1EAF */  jal       evt_get_variable
/* DB7BD4 802402C4 26100004 */   addiu    $s0, $s0, 4
/* DB7BD8 802402C8 8E050000 */  lw        $a1, ($s0)
/* DB7BDC 802402CC 26100004 */  addiu     $s0, $s0, 4
/* DB7BE0 802402D0 0220202D */  daddu     $a0, $s1, $zero
/* DB7BE4 802402D4 0C0B210B */  jal       evt_get_float_variable
/* DB7BE8 802402D8 0040902D */   daddu    $s2, $v0, $zero
/* DB7BEC 802402DC 8E050000 */  lw        $a1, ($s0)
/* DB7BF0 802402E0 26100004 */  addiu     $s0, $s0, 4
/* DB7BF4 802402E4 0220202D */  daddu     $a0, $s1, $zero
/* DB7BF8 802402E8 0C0B210B */  jal       evt_get_float_variable
/* DB7BFC 802402EC 46000686 */   mov.s    $f26, $f0
/* DB7C00 802402F0 8E050000 */  lw        $a1, ($s0)
/* DB7C04 802402F4 26100004 */  addiu     $s0, $s0, 4
/* DB7C08 802402F8 0220202D */  daddu     $a0, $s1, $zero
/* DB7C0C 802402FC 0C0B210B */  jal       evt_get_float_variable
/* DB7C10 80240300 46000606 */   mov.s    $f24, $f0
/* DB7C14 80240304 0220202D */  daddu     $a0, $s1, $zero
/* DB7C18 80240308 8E050000 */  lw        $a1, ($s0)
/* DB7C1C 8024030C 0C0B210B */  jal       evt_get_float_variable
/* DB7C20 80240310 46000506 */   mov.s    $f20, $f0
/* DB7C24 80240314 0240202D */  daddu     $a0, $s2, $zero
/* DB7C28 80240318 0C00EAD2 */  jal       get_npc_safe
/* DB7C2C 8024031C 46000586 */   mov.s    $f22, $f0
/* DB7C30 80240320 0040202D */  daddu     $a0, $v0, $zero
/* DB7C34 80240324 E49A0038 */  swc1      $f26, 0x38($a0)
/* DB7C38 80240328 4600D006 */  mov.s     $f0, $f26
/* DB7C3C 8024032C E498003C */  swc1      $f24, 0x3c($a0)
/* DB7C40 80240330 4600C086 */  mov.s     $f2, $f24
/* DB7C44 80240334 E4940040 */  swc1      $f20, 0x40($a0)
/* DB7C48 80240338 4600A106 */  mov.s     $f4, $f20
/* DB7C4C 8024033C 8C830000 */  lw        $v1, ($a0)
/* DB7C50 80240340 3C050001 */  lui       $a1, 1
/* DB7C54 80240344 E496000C */  swc1      $f22, 0xc($a0)
/* DB7C58 80240348 E480006C */  swc1      $f0, 0x6c($a0)
/* DB7C5C 8024034C E4820070 */  swc1      $f2, 0x70($a0)
/* DB7C60 80240350 E4840074 */  swc1      $f4, 0x74($a0)
/* DB7C64 80240354 00651825 */  or        $v1, $v1, $a1
/* DB7C68 80240358 AC830000 */  sw        $v1, ($a0)
/* DB7C6C 8024035C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB7C70 80240360 8FB20018 */  lw        $s2, 0x18($sp)
/* DB7C74 80240364 8FB10014 */  lw        $s1, 0x14($sp)
/* DB7C78 80240368 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7C7C 8024036C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* DB7C80 80240370 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DB7C84 80240374 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DB7C88 80240378 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DB7C8C 8024037C 24020002 */  addiu     $v0, $zero, 2
/* DB7C90 80240380 03E00008 */  jr        $ra
/* DB7C94 80240384 27BD0040 */   addiu    $sp, $sp, 0x40
