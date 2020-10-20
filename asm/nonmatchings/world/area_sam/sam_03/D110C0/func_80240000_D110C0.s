.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D110C0
/* D110C0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D110C4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* D110C8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* D110CC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* D110D0 80240010 0C00EABB */  jal       get_npc_unsafe
/* D110D4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* D110D8 80240018 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* D110DC 8024001C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* D110E0 80240020 C44C0038 */  lwc1      $f12, 0x38($v0)
/* D110E4 80240024 C44E0040 */  lwc1      $f14, 0x40($v0)
/* D110E8 80240028 8C660028 */  lw        $a2, 0x28($v1)
/* D110EC 8024002C 0C00A720 */  jal       atan2
/* D110F0 80240030 8C670030 */   lw       $a3, 0x30($v1)
/* D110F4 80240034 4600008D */  trunc.w.s $f2, $f0
/* D110F8 80240038 E6020084 */  swc1      $f2, 0x84($s0)
/* D110FC 8024003C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D11100 80240040 8FB00010 */  lw        $s0, 0x10($sp)
/* D11104 80240044 24020002 */  addiu     $v0, $zero, 2
/* D11108 80240048 03E00008 */  jr        $ra
/* D1110C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18
