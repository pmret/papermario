.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070530
/* 4B930 80070530 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B934 80070534 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B938 80070538 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B93C 8007053C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B940 80070540 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B944 80070544 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B948 80070548 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B94C 8007054C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B950 80070550 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B954 80070554 0C016885 */  jal       func_8005A214
/* 4B958 80070558 24040022 */   addiu    $a0, $zero, 0x22
/* 4B95C 8007055C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B960 80070560 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B964 80070564 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B968 80070568 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B96C 8007056C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B970 80070570 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B974 80070574 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B978 80070578 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B97C 8007057C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B980 80070580 3C018008 */  lui       $at, %hi(D_8007F510)
/* 4B984 80070584 8C21F510 */  lw        $at, %lo(D_8007F510)($at)
/* 4B988 80070588 00200008 */  jr        $at
/* 4B98C 8007058C 00000000 */   nop
