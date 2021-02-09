.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_sleep_bubble
/* 4BBF0 800707F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BBF4 800707F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BBF8 800707F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BBFC 800707FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BC00 80070800 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BC04 80070804 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BC08 80070808 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BC0C 8007080C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BC10 80070810 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BC14 80070814 0C016959 */  jal       load_effect
/* 4BC18 80070818 24040029 */   addiu    $a0, $zero, 0x29
/* 4BC1C 8007081C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BC20 80070820 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BC24 80070824 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BC28 80070828 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BC2C 8007082C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BC30 80070830 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BC34 80070834 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BC38 80070838 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BC3C 8007083C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BC40 80070840 3C018008 */  lui       $at, %hi(D_8007F5E8)
/* 4BC44 80070844 8C21F5E8 */  lw        $at, %lo(D_8007F5E8)($at)
/* 4BC48 80070848 00200008 */  jr        $at
/* 4BC4C 8007084C 00000000 */   nop
