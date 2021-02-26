.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029DE0
/* 51E0 80029DE0 44806000 */  mtc1      $zero, $f12
/* 51E4 80029DE4 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 51E8 80029DE8 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 51EC 80029DEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 51F0 80029DF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 51F4 80029DF4 8C460128 */  lw        $a2, 0x128($v0)
/* 51F8 80029DF8 8C470130 */  lw        $a3, 0x130($v0)
/* 51FC 80029DFC 0C00A710 */  jal       func_80029C40
/* 5200 80029E00 46006386 */   mov.s    $f14, $f12
/* 5204 80029E04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5208 80029E08 03E00008 */  jr        $ra
/* 520C 80029E0C 27BD0018 */   addiu    $sp, $sp, 0x18
