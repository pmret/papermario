.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_D7F170
/* D7F170 80240410 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7F174 80240414 AFB00010 */  sw        $s0, 0x10($sp)
/* D7F178 80240418 0080802D */  daddu     $s0, $a0, $zero
/* D7F17C 8024041C AFBF0014 */  sw        $ra, 0x14($sp)
/* D7F180 80240420 0C00EAD2 */  jal       get_npc_safe
/* D7F184 80240424 8E04014C */   lw       $a0, 0x14c($s0)
/* D7F188 80240428 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* D7F18C 8024042C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* D7F190 80240430 C44C0038 */  lwc1      $f12, 0x38($v0)
/* D7F194 80240434 C44E0040 */  lwc1      $f14, 0x40($v0)
/* D7F198 80240438 8C660028 */  lw        $a2, 0x28($v1)
/* D7F19C 8024043C 0C00A720 */  jal       atan2
/* D7F1A0 80240440 8C670030 */   lw       $a3, 0x30($v1)
/* D7F1A4 80240444 0C00A6C9 */  jal       clamp_angle
/* D7F1A8 80240448 46000306 */   mov.s    $f12, $f0
/* D7F1AC 8024044C 4600008D */  trunc.w.s $f2, $f0
/* D7F1B0 80240450 E6020084 */  swc1      $f2, 0x84($s0)
/* D7F1B4 80240454 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7F1B8 80240458 8FB00010 */  lw        $s0, 0x10($sp)
/* D7F1BC 8024045C 24020002 */  addiu     $v0, $zero, 2
/* D7F1C0 80240460 03E00008 */  jr        $ra
/* D7F1C4 80240464 27BD0018 */   addiu    $sp, $sp, 0x18
