.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B44_A40284
/* A40284 80240B44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A40288 80240B48 AFB10014 */  sw        $s1, 0x14($sp)
/* A4028C 80240B4C 0080882D */  daddu     $s1, $a0, $zero
/* A40290 80240B50 AFBF0018 */  sw        $ra, 0x18($sp)
/* A40294 80240B54 AFB00010 */  sw        $s0, 0x10($sp)
/* A40298 80240B58 8E30000C */  lw        $s0, 0xc($s1)
/* A4029C 80240B5C 8E050000 */  lw        $a1, ($s0)
/* A402A0 80240B60 0C0B1EAF */  jal       get_variable
/* A402A4 80240B64 26100004 */   addiu    $s0, $s0, 4
/* A402A8 80240B68 0220202D */  daddu     $a0, $s1, $zero
/* A402AC 80240B6C 8E050000 */  lw        $a1, ($s0)
/* A402B0 80240B70 0C0B210B */  jal       get_float_variable
/* A402B4 80240B74 0040802D */   daddu    $s0, $v0, $zero
/* A402B8 80240B78 8E03000C */  lw        $v1, 0xc($s0)
/* A402BC 80240B7C E4600010 */  swc1      $f0, 0x10($v1)
/* A402C0 80240B80 8FBF0018 */  lw        $ra, 0x18($sp)
/* A402C4 80240B84 8FB10014 */  lw        $s1, 0x14($sp)
/* A402C8 80240B88 8FB00010 */  lw        $s0, 0x10($sp)
/* A402CC 80240B8C 24020002 */  addiu     $v0, $zero, 2
/* A402D0 80240B90 03E00008 */  jr        $ra
/* A402D4 80240B94 27BD0020 */   addiu    $sp, $sp, 0x20
