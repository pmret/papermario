.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024126C_CF8DDC
/* CF8DDC 8024126C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF8DE0 80241270 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8DE4 80241274 0080882D */  daddu     $s1, $a0, $zero
/* CF8DE8 80241278 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF8DEC 8024127C AFB00010 */  sw        $s0, 0x10($sp)
/* CF8DF0 80241280 8E30000C */  lw        $s0, 0xc($s1)
/* CF8DF4 80241284 8E050000 */  lw        $a1, ($s0)
/* CF8DF8 80241288 0C0B1EAF */  jal       get_variable
/* CF8DFC 8024128C 26100004 */   addiu    $s0, $s0, 4
/* CF8E00 80241290 0220202D */  daddu     $a0, $s1, $zero
/* CF8E04 80241294 8E050000 */  lw        $a1, ($s0)
/* CF8E08 80241298 0C0B210B */  jal       get_float_variable
/* CF8E0C 8024129C 0040802D */   daddu    $s0, $v0, $zero
/* CF8E10 802412A0 24020002 */  addiu     $v0, $zero, 2
/* CF8E14 802412A4 00501804 */  sllv      $v1, $s0, $v0
/* CF8E18 802412A8 00701821 */  addu      $v1, $v1, $s0
/* CF8E1C 802412AC 00431804 */  sllv      $v1, $v1, $v0
/* CF8E20 802412B0 00701823 */  subu      $v1, $v1, $s0
/* CF8E24 802412B4 000320C0 */  sll       $a0, $v1, 3
/* CF8E28 802412B8 00641821 */  addu      $v1, $v1, $a0
/* CF8E2C 802412BC 000318C0 */  sll       $v1, $v1, 3
/* CF8E30 802412C0 3C01800B */  lui       $at, 0x800b
/* CF8E34 802412C4 00230821 */  addu      $at, $at, $v1
/* CF8E38 802412C8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* CF8E3C 802412CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF8E40 802412D0 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8E44 802412D4 8FB00010 */  lw        $s0, 0x10($sp)
/* CF8E48 802412D8 03E00008 */  jr        $ra
/* CF8E4C 802412DC 27BD0020 */   addiu    $sp, $sp, 0x20
