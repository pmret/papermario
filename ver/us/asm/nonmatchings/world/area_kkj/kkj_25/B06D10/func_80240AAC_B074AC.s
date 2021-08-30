.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_B074AC
/* B074AC 80240AAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B074B0 80240AB0 AFB10014 */  sw        $s1, 0x14($sp)
/* B074B4 80240AB4 0080882D */  daddu     $s1, $a0, $zero
/* B074B8 80240AB8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B074BC 80240ABC AFB00010 */  sw        $s0, 0x10($sp)
/* B074C0 80240AC0 8E30000C */  lw        $s0, 0xc($s1)
/* B074C4 80240AC4 8E050000 */  lw        $a1, ($s0)
/* B074C8 80240AC8 0C0B1EAF */  jal       evt_get_variable
/* B074CC 80240ACC 26100004 */   addiu    $s0, $s0, 4
/* B074D0 80240AD0 0220202D */  daddu     $a0, $s1, $zero
/* B074D4 80240AD4 8E050000 */  lw        $a1, ($s0)
/* B074D8 80240AD8 0C0B1EAF */  jal       evt_get_variable
/* B074DC 80240ADC 0040882D */   daddu    $s1, $v0, $zero
/* B074E0 80240AE0 0000202D */  daddu     $a0, $zero, $zero
/* B074E4 80240AE4 3C05FD05 */  lui       $a1, 0xfd05
/* B074E8 80240AE8 34A50F8A */  ori       $a1, $a1, 0xf8a
/* B074EC 80240AEC 0C0B1EAF */  jal       evt_get_variable
/* B074F0 80240AF0 0040802D */   daddu    $s0, $v0, $zero
/* B074F4 80240AF4 0040182D */  daddu     $v1, $v0, $zero
/* B074F8 80240AF8 AC710008 */  sw        $s1, 8($v1)
/* B074FC 80240AFC AC70000C */  sw        $s0, 0xc($v1)
/* B07500 80240B00 8FBF0018 */  lw        $ra, 0x18($sp)
/* B07504 80240B04 8FB10014 */  lw        $s1, 0x14($sp)
/* B07508 80240B08 8FB00010 */  lw        $s0, 0x10($sp)
/* B0750C 80240B0C 24020002 */  addiu     $v0, $zero, 2
/* B07510 80240B10 03E00008 */  jr        $ra
/* B07514 80240B14 27BD0020 */   addiu    $sp, $sp, 0x20
