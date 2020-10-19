.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D30_844900
/* 844900 80241D30 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 844904 80241D34 3C04800A */  lui       $a0, 0x800a
/* 844908 80241D38 8484A634 */  lh        $a0, -0x59cc($a0)
/* 84490C 80241D3C 27A20030 */  addiu     $v0, $sp, 0x30
/* 844910 80241D40 AFA20010 */  sw        $v0, 0x10($sp)
/* 844914 80241D44 27A20034 */  addiu     $v0, $sp, 0x34
/* 844918 80241D48 AFA20014 */  sw        $v0, 0x14($sp)
/* 84491C 80241D4C 27A20038 */  addiu     $v0, $sp, 0x38
/* 844920 80241D50 AFB00040 */  sw        $s0, 0x40($sp)
/* 844924 80241D54 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 844928 80241D58 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 84492C 80241D5C AFBF0044 */  sw        $ra, 0x44($sp)
/* 844930 80241D60 AFA20018 */  sw        $v0, 0x18($sp)
/* 844934 80241D64 8E050028 */  lw        $a1, 0x28($s0)
/* 844938 80241D68 8E06002C */  lw        $a2, 0x2c($s0)
/* 84493C 80241D6C 0C00B94E */  jal       get_screen_coords
/* 844940 80241D70 8E070030 */   lw       $a3, 0x30($s0)
/* 844944 80241D74 27A40020 */  addiu     $a0, $sp, 0x20
/* 844948 80241D78 AFB00028 */  sw        $s0, 0x28($sp)
/* 84494C 80241D7C 820300BE */  lb        $v1, 0xbe($s0)
/* 844950 80241D80 8FA50038 */  lw        $a1, 0x38($sp)
/* 844954 80241D84 3C028024 */  lui       $v0, 0x8024
/* 844958 80241D88 24421DAC */  addiu     $v0, $v0, 0x1dac
/* 84495C 80241D8C AFA2002C */  sw        $v0, 0x2c($sp)
/* 844960 80241D90 AFA30020 */  sw        $v1, 0x20($sp)
/* 844964 80241D94 0C047644 */  jal       queue_render_task
/* 844968 80241D98 AFA50024 */   sw       $a1, 0x24($sp)
/* 84496C 80241D9C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 844970 80241DA0 8FB00040 */  lw        $s0, 0x40($sp)
/* 844974 80241DA4 03E00008 */  jr        $ra
/* 844978 80241DA8 27BD0048 */   addiu    $sp, $sp, 0x48
