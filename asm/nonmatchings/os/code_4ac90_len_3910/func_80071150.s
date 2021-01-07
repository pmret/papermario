.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071150
/* 4C550 80071150 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C554 80071154 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C558 80071158 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C55C 8007115C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C560 80071160 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C564 80071164 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C568 80071168 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C56C 8007116C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C570 80071170 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C574 80071174 0C016959 */  jal       play_effect
/* 4C578 80071178 24040042 */   addiu    $a0, $zero, 0x42
/* 4C57C 8007117C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C580 80071180 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C584 80071184 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C588 80071188 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C58C 8007118C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C590 80071190 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C594 80071194 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C598 80071198 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C59C 8007119C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C5A0 800711A0 3C018008 */  lui       $at, %hi(D_8007F840)
/* 4C5A4 800711A4 8C21F840 */  lw        $at, %lo(D_8007F840)($at)
/* 4C5A8 800711A8 00200008 */  jr        $at
/* 4C5AC 800711AC 00000000 */   nop      
