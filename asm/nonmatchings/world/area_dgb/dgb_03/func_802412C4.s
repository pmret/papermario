.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C4
/* C327A4 802412C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C327A8 802412C8 AFB00010 */  sw        $s0, 0x10($sp)
/* C327AC 802412CC 0080802D */  daddu     $s0, $a0, $zero
/* C327B0 802412D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C327B4 802412D4 8E020148 */  lw        $v0, 0x148($s0)
/* C327B8 802412D8 0C00EABB */  jal       get_npc_unsafe
/* C327BC 802412DC 84440008 */   lh       $a0, 8($v0)
/* C327C0 802412E0 0040202D */  daddu     $a0, $v0, $zero
/* C327C4 802412E4 C482003C */  lwc1      $f2, 0x3c($a0)
/* C327C8 802412E8 C480001C */  lwc1      $f0, 0x1c($a0)
/* C327CC 802412EC 46001080 */  add.s     $f2, $f2, $f0
/* C327D0 802412F0 C4840014 */  lwc1      $f4, 0x14($a0)
/* C327D4 802412F4 46040001 */  sub.s     $f0, $f0, $f4
/* C327D8 802412F8 C4840064 */  lwc1      $f4, 0x64($a0)
/* C327DC 802412FC 4602203C */  c.lt.s    $f4, $f2
/* C327E0 80241300 E482003C */  swc1      $f2, 0x3c($a0)
/* C327E4 80241304 45010009 */  bc1t      .L8024132C
/* C327E8 80241308 E480001C */   swc1     $f0, 0x1c($a0)
/* C327EC 8024130C 8C820000 */  lw        $v0, ($a0)
/* C327F0 80241310 2403F7FF */  addiu     $v1, $zero, -0x801
/* C327F4 80241314 E484003C */  swc1      $f4, 0x3c($a0)
/* C327F8 80241318 AC80001C */  sw        $zero, 0x1c($a0)
/* C327FC 8024131C 00431024 */  and       $v0, $v0, $v1
/* C32800 80241320 AC820000 */  sw        $v0, ($a0)
/* C32804 80241324 2402000C */  addiu     $v0, $zero, 0xc
/* C32808 80241328 AE020070 */  sw        $v0, 0x70($s0)
.L8024132C:
/* C3280C 8024132C 8FBF0014 */  lw        $ra, 0x14($sp)
/* C32810 80241330 8FB00010 */  lw        $s0, 0x10($sp)
/* C32814 80241334 03E00008 */  jr        $ra
/* C32818 80241338 27BD0018 */   addiu    $sp, $sp, 0x18
