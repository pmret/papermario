.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004AA80
/* 25E80 8004AA80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 25E84 8004AA84 AFB00010 */  sw        $s0, 0x10($sp)
/* 25E88 8004AA88 0080802D */  daddu     $s0, $a0, $zero
/* 25E8C 8004AA8C AFBF0014 */  sw        $ra, 0x14($sp)
/* 25E90 8004AA90 0C018244 */  jal       func_80060910
/* 25E94 8004AA94 24040001 */   addiu    $a0, $zero, 1
/* 25E98 8004AA98 3C018008 */  lui       $at, %hi(D_80078144)
/* 25E9C 8004AA9C AC308144 */  sw        $s0, %lo(D_80078144)($at)
/* 25EA0 8004AAA0 0C018244 */  jal       func_80060910
/* 25EA4 8004AAA4 0040202D */   daddu    $a0, $v0, $zero
/* 25EA8 8004AAA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 25EAC 8004AAAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 25EB0 8004AAB0 03E00008 */  jr        $ra
/* 25EB4 8004AAB4 27BD0018 */   addiu    $sp, $sp, 0x18
