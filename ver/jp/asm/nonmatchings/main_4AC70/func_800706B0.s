.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800706B0
/* 4BAB0 800706B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BAB4 800706B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BAB8 800706B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BABC 800706BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BAC0 800706C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BAC4 800706C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BAC8 800706C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BACC 800706CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BAD0 800706D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BAD4 800706D4 0C016885 */  jal       func_8005A214
/* 4BAD8 800706D8 24040026 */   addiu    $a0, $zero, 0x26
/* 4BADC 800706DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BAE0 800706E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BAE4 800706E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BAE8 800706E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BAEC 800706EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BAF0 800706F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BAF4 800706F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BAF8 800706F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BAFC 800706FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BB00 80070700 3C018008 */  lui       $at, %hi(D_8007F570)
/* 4BB04 80070704 8C21F570 */  lw        $at, %lo(D_8007F570)($at)
/* 4BB08 80070708 00200008 */  jr        $at
/* 4BB0C 8007070C 00000000 */   nop
