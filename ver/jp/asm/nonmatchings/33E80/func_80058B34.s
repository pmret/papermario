.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058B34
/* 33F34 80058B34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 33F38 80058B38 AFB3001C */  sw        $s3, 0x1c($sp)
/* 33F3C 80058B3C 0080982D */  daddu     $s3, $a0, $zero
/* 33F40 80058B40 AFB20018 */  sw        $s2, 0x18($sp)
/* 33F44 80058B44 00C0902D */  daddu     $s2, $a2, $zero
/* 33F48 80058B48 0240202D */  daddu     $a0, $s2, $zero
/* 33F4C 80058B4C AFB40020 */  sw        $s4, 0x20($sp)
/* 33F50 80058B50 00A0A02D */  daddu     $s4, $a1, $zero
/* 33F54 80058B54 24050004 */  addiu     $a1, $zero, 4
/* 33F58 80058B58 24060030 */  addiu     $a2, $zero, 0x30
/* 33F5C 80058B5C AFBF0024 */  sw        $ra, 0x24($sp)
/* 33F60 80058B60 AFB10014 */  sw        $s1, 0x14($sp)
/* 33F64 80058B64 0C015F10 */  jal       func_80057C40
/* 33F68 80058B68 AFB00010 */   sw       $s0, 0x10($sp)
/* 33F6C 80058B6C 0240202D */  daddu     $a0, $s2, $zero
/* 33F70 80058B70 24050A10 */  addiu     $a1, $zero, 0xa10
/* 33F74 80058B74 24060002 */  addiu     $a2, $zero, 2
/* 33F78 80058B78 0C015F10 */  jal       func_80057C40
/* 33F7C 80058B7C AE62000C */   sw       $v0, 0xc($s3)
/* 33F80 80058B80 0000882D */  daddu     $s1, $zero, $zero
/* 33F84 80058B84 AE620000 */  sw        $v0, ($s3)
/* 33F88 80058B88 0240202D */  daddu     $a0, $s2, $zero
.L80058B8C:
/* 33F8C 80058B8C 24050001 */  addiu     $a1, $zero, 1
/* 33F90 80058B90 24060010 */  addiu     $a2, $zero, 0x10
/* 33F94 80058B94 3223FFFF */  andi      $v1, $s1, 0xffff
/* 33F98 80058B98 00A31004 */  sllv      $v0, $v1, $a1
/* 33F9C 80058B9C 00431021 */  addu      $v0, $v0, $v1
/* 33FA0 80058BA0 8E70000C */  lw        $s0, 0xc($s3)
/* 33FA4 80058BA4 00021100 */  sll       $v0, $v0, 4
/* 33FA8 80058BA8 0C015F10 */  jal       func_80057C40
/* 33FAC 80058BAC 02028021 */   addu     $s0, $s0, $v0
/* 33FB0 80058BB0 0240202D */  daddu     $a0, $s2, $zero
/* 33FB4 80058BB4 24050001 */  addiu     $a1, $zero, 1
/* 33FB8 80058BB8 24060020 */  addiu     $a2, $zero, 0x20
/* 33FBC 80058BBC 0C015F10 */  jal       func_80057C40
/* 33FC0 80058BC0 AE02002C */   sw       $v0, 0x2c($s0)
/* 33FC4 80058BC4 0240202D */  daddu     $a0, $s2, $zero
/* 33FC8 80058BC8 24050001 */  addiu     $a1, $zero, 1
/* 33FCC 80058BCC 8E03002C */  lw        $v1, 0x2c($s0)
/* 33FD0 80058BD0 24060030 */  addiu     $a2, $zero, 0x30
/* 33FD4 80058BD4 0C015F10 */  jal       func_80057C40
/* 33FD8 80058BD8 AC620000 */   sw       $v0, ($v1)
/* 33FDC 80058BDC 0240202D */  daddu     $a0, $s2, $zero
/* 33FE0 80058BE0 24050001 */  addiu     $a1, $zero, 1
/* 33FE4 80058BE4 24060008 */  addiu     $a2, $zero, 8
/* 33FE8 80058BE8 0C015F10 */  jal       func_80057C40
/* 33FEC 80058BEC AE020024 */   sw       $v0, 0x24($s0)
/* 33FF0 80058BF0 8E030024 */  lw        $v1, 0x24($s0)
/* 33FF4 80058BF4 26310001 */  addiu     $s1, $s1, 1
/* 33FF8 80058BF8 AC620028 */  sw        $v0, 0x28($v1)
/* 33FFC 80058BFC 3222FFFF */  andi      $v0, $s1, 0xffff
/* 34000 80058C00 2C420004 */  sltiu     $v0, $v0, 4
/* 34004 80058C04 1440FFE1 */  bnez      $v0, .L80058B8C
/* 34008 80058C08 0240202D */   daddu    $a0, $s2, $zero
/* 3400C 80058C0C 0260202D */  daddu     $a0, $s3, $zero
/* 34010 80058C10 0C01633F */  jal       func_80058CFC
/* 34014 80058C14 328500FF */   andi     $a1, $s4, 0xff
/* 34018 80058C18 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3401C 80058C1C 8FB40020 */  lw        $s4, 0x20($sp)
/* 34020 80058C20 8FB3001C */  lw        $s3, 0x1c($sp)
/* 34024 80058C24 8FB20018 */  lw        $s2, 0x18($sp)
/* 34028 80058C28 8FB10014 */  lw        $s1, 0x14($sp)
/* 3402C 80058C2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 34030 80058C30 03E00008 */  jr        $ra
/* 34034 80058C34 27BD0028 */   addiu    $sp, $sp, 0x28
