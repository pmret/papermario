.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0084000
/* 3889D0 E0084000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3889D4 E0084004 8FA20038 */  lw        $v0, 0x38($sp)
/* 3889D8 E0084008 8FA3003C */  lw        $v1, 0x3c($sp)
/* 3889DC E008400C 8FA80040 */  lw        $t0, 0x40($sp)
/* 3889E0 E0084010 AFA20010 */  sw        $v0, 0x10($sp)
/* 3889E4 E0084014 3C02E008 */  lui       $v0, 0xe008
/* 3889E8 E0084018 8C424E34 */  lw        $v0, 0x4e34($v0)
/* 3889EC E008401C 3084FFFF */  andi      $a0, $a0, 0xffff
/* 3889F0 E0084020 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3889F4 E0084024 AFA30014 */  sw        $v1, 0x14($sp)
/* 3889F8 E0084028 0040F809 */  jalr      $v0
/* 3889FC E008402C AFA80018 */   sw       $t0, 0x18($sp)
/* 388A00 E0084030 8FBF0020 */  lw        $ra, 0x20($sp)
/* 388A04 E0084034 03E00008 */  jr        $ra
/* 388A08 E0084038 27BD0028 */   addiu    $sp, $sp, 0x28
