.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800707D0
/* 4BBD0 800707D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BBD4 800707D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BBD8 800707D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BBDC 800707DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BBE0 800707E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BBE4 800707E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BBE8 800707E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BBEC 800707EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BBF0 800707F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BBF4 800707F4 0C016885 */  jal       func_8005A214
/* 4BBF8 800707F8 24040029 */   addiu    $a0, $zero, 0x29
/* 4BBFC 800707FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BC00 80070800 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BC04 80070804 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BC08 80070808 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BC0C 8007080C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BC10 80070810 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BC14 80070814 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BC18 80070818 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BC1C 8007081C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BC20 80070820 3C018008 */  lui       $at, %hi(D_8007F5B8)
/* 4BC24 80070824 8C21F5B8 */  lw        $at, %lo(D_8007F5B8)($at)
/* 4BC28 80070828 00200008 */  jr        $at
/* 4BC2C 8007082C 00000000 */   nop
