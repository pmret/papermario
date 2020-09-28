.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AC08
/* E1308 8014AC08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E130C 8014AC0C 0000202D */  daddu     $a0, $zero, $zero
/* E1310 8014AC10 2405FFFF */  addiu     $a1, $zero, -1
/* E1314 8014AC14 0080302D */  daddu     $a2, $a0, $zero
/* E1318 8014AC18 240700FA */  addiu     $a3, $zero, 0xfa
/* E131C 8014AC1C AFB00018 */  sw        $s0, 0x18($sp)
/* E1320 8014AC20 24100008 */  addiu     $s0, $zero, 8
/* E1324 8014AC24 AFBF001C */  sw        $ra, 0x1c($sp)
/* E1328 8014AC28 0C052A46 */  jal       set_music_track
/* E132C 8014AC2C AFB00010 */   sw       $s0, 0x10($sp)
/* E1330 8014AC30 24040001 */  addiu     $a0, $zero, 1
/* E1334 8014AC34 2405FFFF */  addiu     $a1, $zero, -1
/* E1338 8014AC38 0000302D */  daddu     $a2, $zero, $zero
/* E133C 8014AC3C 240700FA */  addiu     $a3, $zero, 0xfa
/* E1340 8014AC40 0C052A46 */  jal       set_music_track
/* E1344 8014AC44 AFB00010 */   sw       $s0, 0x10($sp)
/* E1348 8014AC48 8FBF001C */  lw        $ra, 0x1c($sp)
/* E134C 8014AC4C 8FB00018 */  lw        $s0, 0x18($sp)
/* E1350 8014AC50 24020001 */  addiu     $v0, $zero, 1
/* E1354 8014AC54 03E00008 */  jr        $ra
/* E1358 8014AC58 27BD0020 */   addiu    $sp, $sp, 0x20
