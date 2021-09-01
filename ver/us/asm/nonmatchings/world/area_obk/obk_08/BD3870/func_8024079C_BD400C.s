.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024079C_BD400C
/* BD400C 8024079C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4010 802407A0 AFB10014 */  sw        $s1, 0x14($sp)
/* BD4014 802407A4 0080882D */  daddu     $s1, $a0, $zero
/* BD4018 802407A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD401C 802407AC AFB00010 */  sw        $s0, 0x10($sp)
/* BD4020 802407B0 8E30000C */  lw        $s0, 0xc($s1)
/* BD4024 802407B4 8E050000 */  lw        $a1, ($s0)
/* BD4028 802407B8 0C0B1EAF */  jal       evt_get_variable
/* BD402C 802407BC 26100004 */   addiu    $s0, $s0, 4
/* BD4030 802407C0 0220202D */  daddu     $a0, $s1, $zero
/* BD4034 802407C4 8E050000 */  lw        $a1, ($s0)
/* BD4038 802407C8 0C0B1EAF */  jal       evt_get_variable
/* BD403C 802407CC 0040882D */   daddu    $s1, $v0, $zero
/* BD4040 802407D0 0000202D */  daddu     $a0, $zero, $zero
/* BD4044 802407D4 3C05FD05 */  lui       $a1, 0xfd05
/* BD4048 802407D8 34A50F8A */  ori       $a1, $a1, 0xf8a
/* BD404C 802407DC 0C0B1EAF */  jal       evt_get_variable
/* BD4050 802407E0 0040802D */   daddu    $s0, $v0, $zero
/* BD4054 802407E4 0040182D */  daddu     $v1, $v0, $zero
/* BD4058 802407E8 AC710008 */  sw        $s1, 8($v1)
/* BD405C 802407EC AC70000C */  sw        $s0, 0xc($v1)
/* BD4060 802407F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD4064 802407F4 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4068 802407F8 8FB00010 */  lw        $s0, 0x10($sp)
/* BD406C 802407FC 24020002 */  addiu     $v0, $zero, 2
/* BD4070 80240800 03E00008 */  jr        $ra
/* BD4074 80240804 27BD0020 */   addiu    $sp, $sp, 0x20
