.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FD70
/* 3B170 8005FD70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B174 8005FD74 24040305 */  addiu     $a0, $zero, 0x305
/* 3B178 8005FD78 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B17C 8005FD7C 0C0180B2 */  jal       func_800602C8
/* 3B180 8005FD80 0000282D */   daddu    $a1, $zero, $zero
/* 3B184 8005FD84 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B188 8005FD88 03E00008 */  jr        $ra
/* 3B18C 8005FD8C 27BD0018 */   addiu    $sp, $sp, 0x18
