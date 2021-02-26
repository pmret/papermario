.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800375F8
/* 129F8 800375F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 129FC 800375FC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 12A00 80037600 AFBF0010 */  sw        $ra, 0x10($sp)
/* 12A04 80037604 0C00DD89 */  jal       func_80037624
/* 12A08 80037608 46007506 */   mov.s    $f20, $f14
/* 12A0C 8003760C 0C00DEAB */  jal       func_80037AAC
/* 12A10 80037610 4600A306 */   mov.s    $f12, $f20
/* 12A14 80037614 8FBF0010 */  lw        $ra, 0x10($sp)
/* 12A18 80037618 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 12A1C 8003761C 03E00008 */  jr        $ra
/* 12A20 80037620 27BD0020 */   addiu    $sp, $sp, 0x20
