.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004ADD0
/* 261D0 8004ADD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 261D4 8004ADD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 261D8 8004ADD8 0080802D */  daddu     $s0, $a0, $zero
/* 261DC 8004ADDC AFBF0014 */  sw        $ra, 0x14($sp)
/* 261E0 8004ADE0 0C018250 */  jal       osSetIntMask
/* 261E4 8004ADE4 24040001 */   addiu    $a0, $zero, 1
/* 261E8 8004ADE8 3C018008 */  lui       $at, 0x8008
/* 261EC 8004ADEC AC308174 */  sw        $s0, -0x7e8c($at)
/* 261F0 8004ADF0 0C018250 */  jal       osSetIntMask
/* 261F4 8004ADF4 0040202D */   daddu    $a0, $v0, $zero
/* 261F8 8004ADF8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 261FC 8004ADFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 26200 8004AE00 03E00008 */  jr        $ra
/* 26204 8004AE04 27BD0018 */   addiu    $sp, $sp, 0x18
