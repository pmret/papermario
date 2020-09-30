.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055760
/* 30B60 80055760 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30B64 80055764 AFB20018 */  sw        $s2, 0x18($sp)
/* 30B68 80055768 0080902D */  daddu     $s2, $a0, $zero
/* 30B6C 8005576C AFB10014 */  sw        $s1, 0x14($sp)
/* 30B70 80055770 24110004 */  addiu     $s1, $zero, 4
/* 30B74 80055774 240200FF */  addiu     $v0, $zero, 0xff
/* 30B78 80055778 AFB00010 */  sw        $s0, 0x10($sp)
/* 30B7C 8005577C 0000802D */  daddu     $s0, $zero, $zero
/* 30B80 80055780 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30B84 80055784 3C018008 */  lui       $at, 0x8008
/* 30B88 80055788 A4228DB6 */  sh        $v0, -0x724a($at)
/* 30B8C 8005578C 0200202D */  daddu     $a0, $s0, $zero
.L80055790:
/* 30B90 80055790 0C015519 */  jal       func_80055464
/* 30B94 80055794 0000282D */   daddu    $a1, $zero, $zero
/* 30B98 80055798 14400006 */  bnez      $v0, .L800557B4
/* 30B9C 8005579C 26100001 */   addiu    $s0, $s0, 1
/* 30BA0 800557A0 0211102B */  sltu      $v0, $s0, $s1
/* 30BA4 800557A4 1440FFFA */  bnez      $v0, .L80055790
/* 30BA8 800557A8 0200202D */   daddu    $a0, $s0, $zero
/* 30BAC 800557AC 0C015612 */  jal       func_80055848
/* 30BB0 800557B0 0240202D */   daddu    $a0, $s2, $zero
.L800557B4:
/* 30BB4 800557B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30BB8 800557B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 30BBC 800557BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 30BC0 800557C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 30BC4 800557C4 03E00008 */  jr        $ra
/* 30BC8 800557C8 27BD0020 */   addiu    $sp, $sp, 0x20
