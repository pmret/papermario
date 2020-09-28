.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dma_copy
/* 4B3C 8002973C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B40 80029740 AFB20018 */  sw        $s2, 0x18($sp)
/* 4B44 80029744 0080902D */  daddu     $s2, $a0, $zero
/* 4B48 80029748 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B4C 8002974C 00C0982D */  daddu     $s3, $a2, $zero
/* 4B50 80029750 0260202D */  daddu     $a0, $s3, $zero
/* 4B54 80029754 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B58 80029758 00B28823 */  subu      $s1, $a1, $s2
/* 4B5C 8002975C 0220282D */  daddu     $a1, $s1, $zero
/* 4B60 80029760 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B64 80029764 0C0185F4 */  jal       osInvalICache
/* 4B68 80029768 AFB00010 */   sw       $s0, 0x10($sp)
/* 4B6C 8002976C 24022000 */  addiu     $v0, $zero, 0x2000
/* 4B70 80029770 0051102B */  sltu      $v0, $v0, $s1
/* 4B74 80029774 1040000A */  beqz      $v0, .L800297A0
/* 4B78 80029778 0000802D */   daddu    $s0, $zero, $zero
/* 4B7C 8002977C 02502021 */  addu      $a0, $s2, $s0
.L80029780:
/* 4B80 80029780 02702821 */  addu      $a1, $s3, $s0
/* 4B84 80029784 0C017D24 */  jal       nuPiReadRom
/* 4B88 80029788 24062000 */   addiu    $a2, $zero, 0x2000
/* 4B8C 8002978C 26102000 */  addiu     $s0, $s0, 0x2000
/* 4B90 80029790 26022000 */  addiu     $v0, $s0, 0x2000
/* 4B94 80029794 0051102B */  sltu      $v0, $v0, $s1
/* 4B98 80029798 1440FFF9 */  bnez      $v0, .L80029780
/* 4B9C 8002979C 02502021 */   addu     $a0, $s2, $s0
.L800297A0:
/* 4BA0 800297A0 12110004 */  beq       $s0, $s1, .L800297B4
/* 4BA4 800297A4 02502021 */   addu     $a0, $s2, $s0
/* 4BA8 800297A8 02702821 */  addu      $a1, $s3, $s0
/* 4BAC 800297AC 0C017D24 */  jal       nuPiReadRom
/* 4BB0 800297B0 02303023 */   subu     $a2, $s1, $s0
.L800297B4:
/* 4BB4 800297B4 0220102D */  daddu     $v0, $s1, $zero
/* 4BB8 800297B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4BBC 800297BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4BC0 800297C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 4BC4 800297C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4BC8 800297C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4BCC 800297CC 03E00008 */  jr        $ra
/* 4BD0 800297D0 27BD0028 */   addiu    $sp, $sp, 0x28
