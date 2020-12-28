.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BB0_557F90
/* 557F90 80218BB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 557F94 80218BB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 557F98 80218BB8 0080882D */  daddu     $s1, $a0, $zero
/* 557F9C 80218BBC AFBF0020 */  sw        $ra, 0x20($sp)
/* 557FA0 80218BC0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 557FA4 80218BC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 557FA8 80218BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 557FAC 80218BCC 8E30000C */  lw        $s0, 0xc($s1)
/* 557FB0 80218BD0 8E050000 */  lw        $a1, ($s0)
/* 557FB4 80218BD4 0C0B1EAF */  jal       get_variable
/* 557FB8 80218BD8 26100004 */   addiu    $s0, $s0, 4
/* 557FBC 80218BDC 8E050000 */  lw        $a1, ($s0)
/* 557FC0 80218BE0 26100004 */  addiu     $s0, $s0, 4
/* 557FC4 80218BE4 0220202D */  daddu     $a0, $s1, $zero
/* 557FC8 80218BE8 0C0B1EAF */  jal       get_variable
/* 557FCC 80218BEC 0040982D */   daddu    $s3, $v0, $zero
/* 557FD0 80218BF0 8E050000 */  lw        $a1, ($s0)
/* 557FD4 80218BF4 26100004 */  addiu     $s0, $s0, 4
/* 557FD8 80218BF8 0220202D */  daddu     $a0, $s1, $zero
/* 557FDC 80218BFC 0C0B1EAF */  jal       get_variable
/* 557FE0 80218C00 0040902D */   daddu    $s2, $v0, $zero
/* 557FE4 80218C04 0220202D */  daddu     $a0, $s1, $zero
/* 557FE8 80218C08 8E050000 */  lw        $a1, ($s0)
/* 557FEC 80218C0C 0C0B1EAF */  jal       get_variable
/* 557FF0 80218C10 0040802D */   daddu    $s0, $v0, $zero
/* 557FF4 80218C14 8E240148 */  lw        $a0, 0x148($s1)
/* 557FF8 80218C18 0C09A75B */  jal       get_actor
/* 557FFC 80218C1C 0040882D */   daddu    $s1, $v0, $zero
/* 558000 80218C20 0040182D */  daddu     $v1, $v0, $zero
/* 558004 80218C24 8C620008 */  lw        $v0, 8($v1)
/* 558008 80218C28 90420024 */  lbu       $v0, 0x24($v0)
/* 55800C 80218C2C 8C640008 */  lw        $a0, 8($v1)
/* 558010 80218C30 02629823 */  subu      $s3, $s3, $v0
/* 558014 80218C34 A0730194 */  sb        $s3, 0x194($v1)
/* 558018 80218C38 90820025 */  lbu       $v0, 0x25($a0)
/* 55801C 80218C3C 02429023 */  subu      $s2, $s2, $v0
/* 558020 80218C40 A0720195 */  sb        $s2, 0x195($v1)
/* 558024 80218C44 90820026 */  lbu       $v0, 0x26($a0)
/* 558028 80218C48 02028023 */  subu      $s0, $s0, $v0
/* 55802C 80218C4C A0700196 */  sb        $s0, 0x196($v1)
/* 558030 80218C50 90840027 */  lbu       $a0, 0x27($a0)
/* 558034 80218C54 02248823 */  subu      $s1, $s1, $a0
/* 558038 80218C58 A0710197 */  sb        $s1, 0x197($v1)
/* 55803C 80218C5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 558040 80218C60 8FB3001C */  lw        $s3, 0x1c($sp)
/* 558044 80218C64 8FB20018 */  lw        $s2, 0x18($sp)
/* 558048 80218C68 8FB10014 */  lw        $s1, 0x14($sp)
/* 55804C 80218C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 558050 80218C70 24020002 */  addiu     $v0, $zero, 2
/* 558054 80218C74 03E00008 */  jr        $ra
/* 558058 80218C78 27BD0028 */   addiu    $sp, $sp, 0x28
