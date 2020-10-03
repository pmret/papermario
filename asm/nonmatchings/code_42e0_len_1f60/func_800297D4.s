.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800297D4
/* 4BD4 800297D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4BD8 800297D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 4BDC 800297DC 0080902D */  daddu     $s2, $a0, $zero
/* 4BE0 800297E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4BE4 800297E4 0000802D */  daddu     $s0, $zero, $zero
/* 4BE8 800297E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4BEC 800297EC 00C0982D */  daddu     $s3, $a2, $zero
/* 4BF0 800297F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 4BF4 800297F4 00B28823 */  subu      $s1, $a1, $s2
/* 4BF8 800297F8 24022000 */  addiu     $v0, $zero, 0x2000
/* 4BFC 800297FC 0051102B */  sltu      $v0, $v0, $s1
/* 4C00 80029800 1040000A */  beqz      $v0, .L8002982C
/* 4C04 80029804 AFBF0020 */   sw       $ra, 0x20($sp)
/* 4C08 80029808 02502021 */  addu      $a0, $s2, $s0
.L8002980C:
/* 4C0C 8002980C 02702821 */  addu      $a1, $s3, $s0
/* 4C10 80029810 0C00A618 */  jal       func_80029860
/* 4C14 80029814 24062000 */   addiu    $a2, $zero, 0x2000
/* 4C18 80029818 26102000 */  addiu     $s0, $s0, 0x2000
/* 4C1C 8002981C 26022000 */  addiu     $v0, $s0, 0x2000
/* 4C20 80029820 0051102B */  sltu      $v0, $v0, $s1
/* 4C24 80029824 1440FFF9 */  bnez      $v0, .L8002980C
/* 4C28 80029828 02502021 */   addu     $a0, $s2, $s0
.L8002982C:
/* 4C2C 8002982C 12110004 */  beq       $s0, $s1, .L80029840
/* 4C30 80029830 02502021 */   addu     $a0, $s2, $s0
/* 4C34 80029834 02702821 */  addu      $a1, $s3, $s0
/* 4C38 80029838 0C00A618 */  jal       func_80029860
/* 4C3C 8002983C 02303023 */   subu     $a2, $s1, $s0
.L80029840:
/* 4C40 80029840 0220102D */  daddu     $v0, $s1, $zero
/* 4C44 80029844 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4C48 80029848 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4C4C 8002984C 8FB20018 */  lw        $s2, 0x18($sp)
/* 4C50 80029850 8FB10014 */  lw        $s1, 0x14($sp)
/* 4C54 80029854 8FB00010 */  lw        $s0, 0x10($sp)
/* 4C58 80029858 03E00008 */  jr        $ra
/* 4C5C 8002985C 27BD0028 */   addiu    $sp, $sp, 0x28
