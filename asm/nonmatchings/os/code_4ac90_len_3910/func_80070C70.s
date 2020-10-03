.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070C70
/* 4C070 80070C70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C074 80070C74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C078 80070C78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C07C 80070C7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C080 80070C80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C084 80070C84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C088 80070C88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C08C 80070C8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C090 80070C90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C094 80070C94 0C016959 */  jal       play_effect
/* 4C098 80070C98 24040035 */   addiu    $a0, $zero, 0x35
/* 4C09C 80070C9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C0A0 80070CA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C0A4 80070CA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C0A8 80070CA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C0AC 80070CAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C0B0 80070CB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C0B4 80070CB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C0B8 80070CB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C0BC 80070CBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C0C0 80070CC0 3C018008 */  lui       $at, 0x8008
/* 4C0C4 80070CC4 8C21F708 */  lw        $at, -0x8f8($at)
/* 4C0C8 80070CC8 00200008 */  jr        $at
/* 4C0CC 80070CCC 00000000 */   nop      
