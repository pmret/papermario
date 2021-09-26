.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_10_StarSpiritEffectFunc1
/* 9C2910 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C2914 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9C2918 80240008 AFB00018 */  sw        $s0, 0x18($sp)
/* 9C291C 8024000C 8C900084 */  lw        $s0, 0x84($a0)
/* 9C2920 80240010 C6000008 */  lwc1      $f0, 8($s0)
/* 9C2924 80240014 240400A2 */  addiu     $a0, $zero, 0xa2
/* 9C2928 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9C292C 8024001C 8E060000 */  lw        $a2, ($s0)
/* 9C2930 80240020 8E070004 */  lw        $a3, 4($s0)
/* 9C2934 80240024 0C05267B */  jal       sfx_adjust_env_sound_pos
/* 9C2938 80240028 0000282D */   daddu    $a1, $zero, $zero
/* 9C293C 8024002C 86020044 */  lh        $v0, 0x44($s0)
/* 9C2940 80240030 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9C2944 80240034 8FB00018 */  lw        $s0, 0x18($sp)
/* 9C2948 80240038 28420002 */  slti      $v0, $v0, 2
/* 9C294C 8024003C 38420001 */  xori      $v0, $v0, 1
/* 9C2950 80240040 00021040 */  sll       $v0, $v0, 1
/* 9C2954 80240044 03E00008 */  jr        $ra
/* 9C2958 80240048 27BD0020 */   addiu    $sp, $sp, 0x20
