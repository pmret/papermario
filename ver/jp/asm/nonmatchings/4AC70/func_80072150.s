.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072150
/* 4D550 80072150 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D554 80072154 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D558 80072158 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D55C 8007215C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D560 80072160 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D564 80072164 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D568 80072168 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D56C 8007216C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D570 80072170 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D574 80072174 0C016885 */  jal       func_8005A214
/* 4D578 80072178 2404006D */   addiu    $a0, $zero, 0x6d
/* 4D57C 8007217C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D580 80072180 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D584 80072184 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D588 80072188 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D58C 8007218C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D590 80072190 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D594 80072194 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D598 80072198 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D59C 8007219C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D5A0 800721A0 3C018008 */  lui       $at, %hi(D_8007FC18)
/* 4D5A4 800721A4 8C21FC18 */  lw        $at, %lo(D_8007FC18)($at)
/* 4D5A8 800721A8 00200008 */  jr        $at
/* 4D5AC 800721AC 00000000 */   nop
