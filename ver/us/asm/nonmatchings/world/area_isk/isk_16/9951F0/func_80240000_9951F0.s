.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel isk_16_StarSpiritEffectFunc1
/* 9951F0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9951F4 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9951F8 80240008 AFB00018 */  sw        $s0, 0x18($sp)
/* 9951FC 8024000C 8C900084 */  lw        $s0, 0x84($a0)
/* 995200 80240010 C6000008 */  lwc1      $f0, 8($s0)
/* 995204 80240014 240400A2 */  addiu     $a0, $zero, 0xa2
/* 995208 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 99520C 8024001C 8E060000 */  lw        $a2, ($s0)
/* 995210 80240020 8E070004 */  lw        $a3, 4($s0)
/* 995214 80240024 0C05267B */  jal       sfx_adjust_env_sound_pos
/* 995218 80240028 0000282D */   daddu    $a1, $zero, $zero
/* 99521C 8024002C 86020044 */  lh        $v0, 0x44($s0)
/* 995220 80240030 8FBF001C */  lw        $ra, 0x1c($sp)
/* 995224 80240034 8FB00018 */  lw        $s0, 0x18($sp)
/* 995228 80240038 28420002 */  slti      $v0, $v0, 2
/* 99522C 8024003C 38420001 */  xori      $v0, $v0, 1
/* 995230 80240040 00021040 */  sll       $v0, $v0, 1
/* 995234 80240044 03E00008 */  jr        $ra
/* 995238 80240048 27BD0020 */   addiu    $sp, $sp, 0x20
