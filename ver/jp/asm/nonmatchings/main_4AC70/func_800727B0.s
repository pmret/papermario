.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800727B0
/* 4DBB0 800727B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DBB4 800727B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DBB8 800727B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DBBC 800727BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DBC0 800727C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DBC4 800727C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DBC8 800727C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DBCC 800727CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DBD0 800727D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DBD4 800727D4 0C016885 */  jal       func_8005A214
/* 4DBD8 800727D8 2404007E */   addiu    $a0, $zero, 0x7e
/* 4DBDC 800727DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DBE0 800727E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DBE4 800727E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DBE8 800727E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DBEC 800727EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DBF0 800727F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DBF4 800727F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DBF8 800727F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DBFC 800727FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DC00 80072800 3C018008 */  lui       $at, %hi(D_8007FDB0)
/* 4DC04 80072804 8C21FDB0 */  lw        $at, %lo(D_8007FDB0)($at)
/* 4DC08 80072808 00200008 */  jr        $at
/* 4DC0C 8007280C 00000000 */   nop
