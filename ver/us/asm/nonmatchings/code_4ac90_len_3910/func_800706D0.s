.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800706D0
/* 4BAD0 800706D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BAD4 800706D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BAD8 800706D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BADC 800706DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BAE0 800706E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BAE4 800706E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BAE8 800706E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BAEC 800706EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BAF0 800706F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BAF4 800706F4 0C016959 */  jal       load_effect
/* 4BAF8 800706F8 24040026 */   addiu    $a0, $zero, 0x26
/* 4BAFC 800706FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BB00 80070700 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BB04 80070704 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BB08 80070708 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BB0C 8007070C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BB10 80070710 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BB14 80070714 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BB18 80070718 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BB1C 8007071C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BB20 80070720 3C018008 */  lui       $at, %hi(gEffectTable+0x390)
/* 4BB24 80070724 8C21F5A0 */  lw        $at, %lo(gEffectTable+0x390)($at)
/* 4BB28 80070728 00200008 */  jr        $at
/* 4BB2C 8007072C 00000000 */   nop
