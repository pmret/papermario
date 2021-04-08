.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029794
/* 4B94 80029794 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B98 80029798 AFB20018 */  sw        $s2, 0x18($sp)
/* 4B9C 8002979C 0080902D */  daddu     $s2, $a0, $zero
/* 4BA0 800297A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4BA4 800297A4 0000802D */  daddu     $s0, $zero, $zero
/* 4BA8 800297A8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4BAC 800297AC 00C0982D */  daddu     $s3, $a2, $zero
/* 4BB0 800297B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 4BB4 800297B4 00B28823 */  subu      $s1, $a1, $s2
/* 4BB8 800297B8 24022000 */  addiu     $v0, $zero, 0x2000
/* 4BBC 800297BC 0051102B */  sltu      $v0, $v0, $s1
/* 4BC0 800297C0 1040000A */  beqz      $v0, .L800297EC
/* 4BC4 800297C4 AFBF0020 */   sw       $ra, 0x20($sp)
/* 4BC8 800297C8 02502021 */  addu      $a0, $s2, $s0
.L800297CC:
/* 4BCC 800297CC 02702821 */  addu      $a1, $s3, $s0
/* 4BD0 800297D0 0C00A608 */  jal       func_80029820
/* 4BD4 800297D4 24062000 */   addiu    $a2, $zero, 0x2000
/* 4BD8 800297D8 26102000 */  addiu     $s0, $s0, 0x2000
/* 4BDC 800297DC 26022000 */  addiu     $v0, $s0, 0x2000
/* 4BE0 800297E0 0051102B */  sltu      $v0, $v0, $s1
/* 4BE4 800297E4 1440FFF9 */  bnez      $v0, .L800297CC
/* 4BE8 800297E8 02502021 */   addu     $a0, $s2, $s0
.L800297EC:
/* 4BEC 800297EC 12110004 */  beq       $s0, $s1, .L80029800
/* 4BF0 800297F0 02502021 */   addu     $a0, $s2, $s0
/* 4BF4 800297F4 02702821 */  addu      $a1, $s3, $s0
/* 4BF8 800297F8 0C00A608 */  jal       func_80029820
/* 4BFC 800297FC 02303023 */   subu     $a2, $s1, $s0
.L80029800:
/* 4C00 80029800 0220102D */  daddu     $v0, $s1, $zero
/* 4C04 80029804 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4C08 80029808 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4C0C 8002980C 8FB20018 */  lw        $s2, 0x18($sp)
/* 4C10 80029810 8FB10014 */  lw        $s1, 0x14($sp)
/* 4C14 80029814 8FB00010 */  lw        $s0, 0x10($sp)
/* 4C18 80029818 03E00008 */  jr        $ra
/* 4C1C 8002981C 27BD0028 */   addiu    $sp, $sp, 0x28
