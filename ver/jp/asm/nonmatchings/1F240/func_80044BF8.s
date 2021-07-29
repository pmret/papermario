.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044BF8
/* 1FFF8 80044BF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1FFFC 80044BFC AFBF001C */  sw        $ra, 0x1c($sp)
/* 20000 80044C00 AFB20018 */  sw        $s2, 0x18($sp)
/* 20004 80044C04 AFB10014 */  sw        $s1, 0x14($sp)
/* 20008 80044C08 AFB00010 */  sw        $s0, 0x10($sp)
/* 2000C 80044C0C 8C82000C */  lw        $v0, 0xc($a0)
/* 20010 80044C10 8C450000 */  lw        $a1, ($v0)
/* 20014 80044C14 0C0B1EAF */  jal       func_802C7ABC
/* 20018 80044C18 8C900148 */   lw       $s0, 0x148($a0)
/* 2001C 80044C1C 0040902D */  daddu     $s2, $v0, $zero
/* 20020 80044C20 2402FFFF */  addiu     $v0, $zero, -1
/* 20024 80044C24 16420002 */  bne       $s2, $v0, .L80044C30
/* 20028 80044C28 00000000 */   nop
/* 2002C 80044C2C 86120008 */  lh        $s2, 8($s0)
.L80044C30:
/* 20030 80044C30 0C00FA6A */  jal       func_8003E9A8
/* 20034 80044C34 0240202D */   daddu    $a0, $s2, $zero
/* 20038 80044C38 0040802D */  daddu     $s0, $v0, $zero
/* 2003C 80044C3C 8E020000 */  lw        $v0, ($s0)
/* 20040 80044C40 30420001 */  andi      $v0, $v0, 1
/* 20044 80044C44 10400002 */  beqz      $v0, .L80044C50
/* 20048 80044C48 2411000B */   addiu    $s1, $zero, 0xb
/* 2004C 80044C4C 2411000A */  addiu     $s1, $zero, 0xa
.L80044C50:
/* 20050 80044C50 8E020044 */  lw        $v0, 0x44($s0)
/* 20054 80044C54 10400005 */  beqz      $v0, .L80044C6C
/* 20058 80044C58 2405000A */   addiu    $a1, $zero, 0xa
/* 2005C 80044C5C 8E04005C */  lw        $a0, 0x5c($s0)
/* 20060 80044C60 0C0B102B */  jal       func_802C40AC
/* 20064 80044C64 90510004 */   lbu      $s1, 4($v0)
/* 20068 80044C68 2405000A */  addiu     $a1, $zero, 0xa
.L80044C6C:
/* 2006C 80044C6C 8E04002C */  lw        $a0, 0x2c($s0)
/* 20070 80044C70 0C0B0CF8 */  jal       func_802C33E0
/* 20074 80044C74 0000302D */   daddu    $a2, $zero, $zero
/* 20078 80044C78 0040182D */  daddu     $v1, $v0, $zero
/* 2007C 80044C7C AE030044 */  sw        $v1, 0x44($s0)
/* 20080 80044C80 8C640144 */  lw        $a0, 0x144($v1)
/* 20084 80044C84 AE04005C */  sw        $a0, 0x5c($s0)
/* 20088 80044C88 AC700148 */  sw        $s0, 0x148($v1)
/* 2008C 80044C8C AC72014C */  sw        $s2, 0x14c($v1)
/* 20090 80044C90 A0710004 */  sb        $s1, 4($v1)
/* 20094 80044C94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 20098 80044C98 8FB20018 */  lw        $s2, 0x18($sp)
/* 2009C 80044C9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 200A0 80044CA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 200A4 80044CA4 24020002 */  addiu     $v0, $zero, 2
/* 200A8 80044CA8 03E00008 */  jr        $ra
/* 200AC 80044CAC 27BD0020 */   addiu    $sp, $sp, 0x20
