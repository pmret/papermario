.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel NpcSetHomePosToCurrent
/* F3D6C 802CF3BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F3D70 802CF3C0 AFB00010 */  sw        $s0, 0x10($sp)
/* F3D74 802CF3C4 0080802D */  daddu     $s0, $a0, $zero
/* F3D78 802CF3C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* F3D7C 802CF3CC 8E02000C */  lw        $v0, 0xc($s0)
/* F3D80 802CF3D0 0C0B1EAF */  jal       get_variable
/* F3D84 802CF3D4 8C450000 */   lw       $a1, ($v0)
/* F3D88 802CF3D8 0200202D */  daddu     $a0, $s0, $zero
/* F3D8C 802CF3DC 0C0B36B0 */  jal       resolve_npc
/* F3D90 802CF3E0 0040282D */   daddu    $a1, $v0, $zero
/* F3D94 802CF3E4 0040202D */  daddu     $a0, $v0, $zero
/* F3D98 802CF3E8 1080000F */  beqz      $a0, .L802CF428
/* F3D9C 802CF3EC 24020002 */   addiu    $v0, $zero, 2
/* F3DA0 802CF3F0 C4800038 */  lwc1      $f0, 0x38($a0)
/* F3DA4 802CF3F4 C4820040 */  lwc1      $f2, 0x40($a0)
/* F3DA8 802CF3F8 4600010D */  trunc.w.s $f4, $f0
/* F3DAC 802CF3FC 44032000 */  mfc1      $v1, $f4
/* F3DB0 802CF400 C480003C */  lwc1      $f0, 0x3c($a0)
/* F3DB4 802CF404 A4830090 */  sh        $v1, 0x90($a0)
/* F3DB8 802CF408 4600010D */  trunc.w.s $f4, $f0
/* F3DBC 802CF40C 44032000 */  mfc1      $v1, $f4
/* F3DC0 802CF410 00000000 */  nop       
/* F3DC4 802CF414 A4830092 */  sh        $v1, 0x92($a0)
/* F3DC8 802CF418 4600110D */  trunc.w.s $f4, $f2
/* F3DCC 802CF41C 44032000 */  mfc1      $v1, $f4
/* F3DD0 802CF420 00000000 */  nop       
/* F3DD4 802CF424 A4830094 */  sh        $v1, 0x94($a0)
.L802CF428:
/* F3DD8 802CF428 8FBF0014 */  lw        $ra, 0x14($sp)
/* F3DDC 802CF42C 8FB00010 */  lw        $s0, 0x10($sp)
/* F3DE0 802CF430 03E00008 */  jr        $ra
/* F3DE4 802CF434 27BD0018 */   addiu    $sp, $sp, 0x18
