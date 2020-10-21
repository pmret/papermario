.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024002C_8CA92C
/* 8CA92C 8024002C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CA930 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CA934 80240034 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CA938 80240038 0C039D59 */  jal       get_player_data
/* 8CA93C 8024003C 0080802D */   daddu    $s0, $a0, $zero
/* 8CA940 80240040 80430002 */  lb        $v1, 2($v0)
/* 8CA944 80240044 AE030084 */  sw        $v1, 0x84($s0)
/* 8CA948 80240048 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CA94C 8024004C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CA950 80240050 24020002 */  addiu     $v0, $zero, 2
/* 8CA954 80240054 03E00008 */  jr        $ra
/* 8CA958 80240058 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8CA95C 8024005C 00000000 */  nop       
