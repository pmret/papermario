.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410C4_B85244
/* B85244 802410C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B85248 802410C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* B8524C 802410CC 0080882D */  daddu     $s1, $a0, $zero
/* B85250 802410D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* B85254 802410D4 AFB00018 */  sw        $s0, 0x18($sp)
/* B85258 802410D8 8E30000C */  lw        $s0, 0xc($s1)
/* B8525C 802410DC 8E020000 */  lw        $v0, ($s0)
/* B85260 802410E0 1040001B */  beqz      $v0, .L80241150
/* B85264 802410E4 26100004 */   addiu    $s0, $s0, 4
/* B85268 802410E8 8E050000 */  lw        $a1, ($s0)
/* B8526C 802410EC 0C0B1EAF */  jal       evt_get_variable
/* B85270 802410F0 26100004 */   addiu    $s0, $s0, 4
/* B85274 802410F4 AE220070 */  sw        $v0, 0x70($s1)
/* B85278 802410F8 8E050000 */  lw        $a1, ($s0)
/* B8527C 802410FC 26100004 */  addiu     $s0, $s0, 4
/* B85280 80241100 0C0B1EAF */  jal       evt_get_variable
/* B85284 80241104 0220202D */   daddu    $a0, $s1, $zero
/* B85288 80241108 AE220074 */  sw        $v0, 0x74($s1)
/* B8528C 8024110C 8E050000 */  lw        $a1, ($s0)
/* B85290 80241110 0C0B1EAF */  jal       evt_get_variable
/* B85294 80241114 0220202D */   daddu    $a0, $s1, $zero
/* B85298 80241118 24040185 */  addiu     $a0, $zero, 0x185
/* B8529C 8024111C 0000282D */  daddu     $a1, $zero, $zero
/* B852A0 80241120 C6200070 */  lwc1      $f0, 0x70($s1)
/* B852A4 80241124 46800020 */  cvt.s.w   $f0, $f0
/* B852A8 80241128 C6220074 */  lwc1      $f2, 0x74($s1)
/* B852AC 8024112C 468010A0 */  cvt.s.w   $f2, $f2
/* B852B0 80241130 44060000 */  mfc1      $a2, $f0
/* B852B4 80241134 44071000 */  mfc1      $a3, $f2
/* B852B8 80241138 44820000 */  mtc1      $v0, $f0
/* B852BC 8024113C 00000000 */  nop
/* B852C0 80241140 46800020 */  cvt.s.w   $f0, $f0
/* B852C4 80241144 AE220078 */  sw        $v0, 0x78($s1)
/* B852C8 80241148 0C05267B */  jal       sfx_adjust_env_sound_pos
/* B852CC 8024114C E7A00010 */   swc1     $f0, 0x10($sp)
.L80241150:
/* B852D0 80241150 8FBF0020 */  lw        $ra, 0x20($sp)
/* B852D4 80241154 8FB1001C */  lw        $s1, 0x1c($sp)
/* B852D8 80241158 8FB00018 */  lw        $s0, 0x18($sp)
/* B852DC 8024115C 24020002 */  addiu     $v0, $zero, 2
/* B852E0 80241160 03E00008 */  jr        $ra
/* B852E4 80241164 27BD0028 */   addiu    $sp, $sp, 0x28
