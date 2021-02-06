.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072350
/* 4D750 80072350 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D754 80072354 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D758 80072358 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D75C 8007235C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D760 80072360 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D764 80072364 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D768 80072368 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D76C 8007236C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D770 80072370 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D774 80072374 0C016959 */  jal       load_effect
/* 4D778 80072378 24040072 */   addiu    $a0, $zero, 0x72
/* 4D77C 8007237C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D780 80072380 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D784 80072384 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D788 80072388 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D78C 8007238C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D790 80072390 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D794 80072394 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D798 80072398 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D79C 8007239C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D7A0 800723A0 3C018008 */  lui       $at, %hi(D_8007FCC0)
/* 4D7A4 800723A4 8C21FCC0 */  lw        $at, %lo(D_8007FCC0)($at)
/* 4D7A8 800723A8 00200008 */  jr        $at
/* 4D7AC 800723AC 00000000 */   nop
