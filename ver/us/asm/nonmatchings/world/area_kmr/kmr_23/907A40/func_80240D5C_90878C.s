.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D5C_90878C
/* 90878C 80240D5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 908790 80240D60 3C05FD05 */  lui       $a1, 0xfd05
/* 908794 80240D64 34A50F80 */  ori       $a1, $a1, 0xf80
/* 908798 80240D68 AFBF0010 */  sw        $ra, 0x10($sp)
/* 90879C 80240D6C 0C0B1EAF */  jal       evt_get_variable
/* 9087A0 80240D70 0000202D */   daddu    $a0, $zero, $zero
/* 9087A4 80240D74 3C05FFEF */  lui       $a1, 0xffef
/* 9087A8 80240D78 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 9087AC 80240D7C 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* 9087B0 80240D80 A440001E */  sh        $zero, 0x1e($v0)
/* 9087B4 80240D84 8C830000 */  lw        $v1, ($a0)
/* 9087B8 80240D88 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 9087BC 80240D8C 00651824 */  and       $v1, $v1, $a1
/* 9087C0 80240D90 AC830000 */  sw        $v1, ($a0)
/* 9087C4 80240D94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9087C8 80240D98 24020002 */  addiu     $v0, $zero, 2
/* 9087CC 80240D9C 03E00008 */  jr        $ra
/* 9087D0 80240DA0 27BD0018 */   addiu    $sp, $sp, 0x18
