.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FD50
/* 3B150 8005FD50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B154 8005FD54 24040304 */  addiu     $a0, $zero, 0x304
/* 3B158 8005FD58 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B15C 8005FD5C 0C0180B2 */  jal       func_800602C8
/* 3B160 8005FD60 0000282D */   daddu    $a1, $zero, $zero
/* 3B164 8005FD64 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B168 8005FD68 03E00008 */  jr        $ra
/* 3B16C 8005FD6C 27BD0018 */   addiu    $sp, $sp, 0x18
