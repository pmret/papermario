.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D758
/* 28B58 8004D758 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28B5C 8004D75C AFBF0010 */  sw        $ra, 0x10($sp)
/* 28B60 8004D760 90820221 */  lbu       $v0, 0x221($a0)
/* 28B64 8004D764 10400007 */  beqz      $v0, .L8004D784
/* 28B68 8004D768 24020004 */   addiu    $v0, $zero, 4
/* 28B6C 8004D76C A0820221 */  sb        $v0, 0x221($a0)
/* 28B70 8004D770 24020001 */  addiu     $v0, $zero, 1
/* 28B74 8004D774 AC820010 */  sw        $v0, 0x10($a0)
/* 28B78 8004D778 AC820008 */  sw        $v0, 8($a0)
/* 28B7C 8004D77C 0C014DB2 */  jal       func_800536C8
/* 28B80 8004D780 2484002C */   addiu    $a0, $a0, 0x2c
.L8004D784:
/* 28B84 8004D784 8FBF0010 */  lw        $ra, 0x10($sp)
/* 28B88 8004D788 03E00008 */  jr        $ra
/* 28B8C 8004D78C 27BD0018 */   addiu    $sp, $sp, 0x18
