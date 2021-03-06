.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800296FC
/* 4AFC 800296FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B00 80029700 AFB20018 */  sw        $s2, 0x18($sp)
/* 4B04 80029704 0080902D */  daddu     $s2, $a0, $zero
/* 4B08 80029708 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B0C 8002970C 00C0982D */  daddu     $s3, $a2, $zero
/* 4B10 80029710 0260202D */  daddu     $a0, $s3, $zero
/* 4B14 80029714 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B18 80029718 00B28823 */  subu      $s1, $a1, $s2
/* 4B1C 8002971C 0220282D */  daddu     $a1, $s1, $zero
/* 4B20 80029720 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B24 80029724 0C0185E8 */  jal       func_800617A0
/* 4B28 80029728 AFB00010 */   sw       $s0, 0x10($sp)
/* 4B2C 8002972C 24022000 */  addiu     $v0, $zero, 0x2000
/* 4B30 80029730 0051102B */  sltu      $v0, $v0, $s1
/* 4B34 80029734 1040000A */  beqz      $v0, .L80029760
/* 4B38 80029738 0000802D */   daddu    $s0, $zero, $zero
/* 4B3C 8002973C 02502021 */  addu      $a0, $s2, $s0
.L80029740:
/* 4B40 80029740 02702821 */  addu      $a1, $s3, $s0
/* 4B44 80029744 0C017C50 */  jal       func_8005F140
/* 4B48 80029748 24062000 */   addiu    $a2, $zero, 0x2000
/* 4B4C 8002974C 26102000 */  addiu     $s0, $s0, 0x2000
/* 4B50 80029750 26022000 */  addiu     $v0, $s0, 0x2000
/* 4B54 80029754 0051102B */  sltu      $v0, $v0, $s1
/* 4B58 80029758 1440FFF9 */  bnez      $v0, .L80029740
/* 4B5C 8002975C 02502021 */   addu     $a0, $s2, $s0
.L80029760:
/* 4B60 80029760 12110004 */  beq       $s0, $s1, .L80029774
/* 4B64 80029764 02502021 */   addu     $a0, $s2, $s0
/* 4B68 80029768 02702821 */  addu      $a1, $s3, $s0
/* 4B6C 8002976C 0C017C50 */  jal       func_8005F140
/* 4B70 80029770 02303023 */   subu     $a2, $s1, $s0
.L80029774:
/* 4B74 80029774 0220102D */  daddu     $v0, $s1, $zero
/* 4B78 80029778 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4B7C 8002977C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4B80 80029780 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B84 80029784 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B88 80029788 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B8C 8002978C 03E00008 */  jr        $ra
/* 4B90 80029790 27BD0028 */   addiu    $sp, $sp, 0x28
