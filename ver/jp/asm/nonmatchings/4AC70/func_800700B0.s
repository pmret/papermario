.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800700B0
/* 4B4B0 800700B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B4B4 800700B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B4B8 800700B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B4BC 800700BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B4C0 800700C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B4C4 800700C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B4C8 800700C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B4CC 800700CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B4D0 800700D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B4D4 800700D4 0C016885 */  jal       func_8005A214
/* 4B4D8 800700D8 24040016 */   addiu    $a0, $zero, 0x16
/* 4B4DC 800700DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B4E0 800700E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B4E4 800700E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B4E8 800700E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B4EC 800700EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B4F0 800700F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B4F4 800700F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B4F8 800700F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B4FC 800700FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B500 80070100 3C018008 */  lui       $at, %hi(D_8007F3F0)
/* 4B504 80070104 8C21F3F0 */  lw        $at, %lo(D_8007F3F0)($at)
/* 4B508 80070108 00200008 */  jr        $at
/* 4B50C 8007010C 00000000 */   nop
