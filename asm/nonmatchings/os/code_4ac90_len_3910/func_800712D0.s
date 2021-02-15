.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800712D0
/* 4C6D0 800712D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C6D4 800712D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C6D8 800712D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C6DC 800712DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C6E0 800712E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C6E4 800712E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C6E8 800712E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C6EC 800712EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C6F0 800712F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C6F4 800712F4 0C016959 */  jal       load_effect
/* 4C6F8 800712F8 24040046 */   addiu    $a0, $zero, 0x46
/* 4C6FC 800712FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C700 80071300 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C704 80071304 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C708 80071308 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C70C 8007130C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C710 80071310 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C714 80071314 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C718 80071318 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C71C 8007131C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C720 80071320 3C018008 */  lui       $at, %hi(D_8007F8A0)
/* 4C724 80071324 8C21F8A0 */  lw        $at, %lo(D_8007F8A0)($at)
/* 4C728 80071328 00200008 */  jr        $at
/* 4C72C 8007132C 00000000 */   nop
