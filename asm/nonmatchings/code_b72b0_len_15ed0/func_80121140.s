.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80121140
/* B7840 80121140 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B7844 80121144 AFB00010 */  sw        $s0, 0x10($sp)
/* B7848 80121148 AFBF0014 */  sw        $ra, 0x14($sp)
/* B784C 8012114C 0C019D28 */  jal       guMtxIdentF
/* B7850 80121150 0080802D */   daddu    $s0, $a0, $zero
/* B7854 80121154 3C013F80 */  lui       $at, 0x3f80
/* B7858 80121158 44810000 */  mtc1      $at, $f0
/* B785C 8012115C 3C01BF80 */  lui       $at, 0xbf80
/* B7860 80121160 44811000 */  mtc1      $at, $f2
/* B7864 80121164 E6000000 */  swc1      $f0, ($s0)
/* B7868 80121168 E6000014 */  swc1      $f0, 0x14($s0)
/* B786C 8012116C E6020028 */  swc1      $f2, 0x28($s0)
/* B7870 80121170 E600003C */  swc1      $f0, 0x3c($s0)
/* B7874 80121174 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7878 80121178 8FB00010 */  lw        $s0, 0x10($sp)
/* B787C 8012117C 03E00008 */  jr        $ra
/* B7880 80121180 27BD0018 */   addiu    $sp, $sp, 0x18
