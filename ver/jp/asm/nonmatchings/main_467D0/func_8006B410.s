.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B410
/* 46810 8006B410 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 46814 8006B414 AFB00010 */  sw        $s0, 0x10($sp)
/* 46818 8006B418 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4681C 8006B41C 0C01ACD0 */  jal       func_8006B340
/* 46820 8006B420 00808021 */   addu     $s0, $a0, $zero
/* 46824 8006B424 3C038009 */  lui       $v1, %hi(D_80095890)
/* 46828 8006B428 8C635890 */  lw        $v1, %lo(D_80095890)($v1)
/* 4682C 8006B42C 00108027 */  nor       $s0, $zero, $s0
/* 46830 8006B430 36100401 */  ori       $s0, $s0, 0x401
/* 46834 8006B434 00701824 */  and       $v1, $v1, $s0
/* 46838 8006B438 3C018009 */  lui       $at, %hi(D_80095890)
/* 4683C 8006B43C AC235890 */  sw        $v1, %lo(D_80095890)($at)
/* 46840 8006B440 0C01ACEC */  jal       func_8006B3B0
/* 46844 8006B444 00402021 */   addu     $a0, $v0, $zero
/* 46848 8006B448 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4684C 8006B44C 8FB00010 */  lw        $s0, 0x10($sp)
/* 46850 8006B450 03E00008 */  jr        $ra
/* 46854 8006B454 27BD0018 */   addiu    $sp, $sp, 0x18
/* 46858 8006B458 00000000 */  nop
/* 4685C 8006B45C 00000000 */  nop
