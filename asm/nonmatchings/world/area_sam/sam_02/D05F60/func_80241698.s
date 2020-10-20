.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241698
/* D06DC8 80241698 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D06DCC 8024169C AFB10014 */  sw        $s1, 0x14($sp)
/* D06DD0 802416A0 0080882D */  daddu     $s1, $a0, $zero
/* D06DD4 802416A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* D06DD8 802416A8 AFB00010 */  sw        $s0, 0x10($sp)
/* D06DDC 802416AC 8E30000C */  lw        $s0, 0xc($s1)
/* D06DE0 802416B0 8E050000 */  lw        $a1, ($s0)
/* D06DE4 802416B4 0C0B1EAF */  jal       get_variable
/* D06DE8 802416B8 26100004 */   addiu    $s0, $s0, 4
/* D06DEC 802416BC 0220202D */  daddu     $a0, $s1, $zero
/* D06DF0 802416C0 8E050000 */  lw        $a1, ($s0)
/* D06DF4 802416C4 0C0B210B */  jal       get_float_variable
/* D06DF8 802416C8 0040802D */   daddu    $s0, $v0, $zero
/* D06DFC 802416CC 24020002 */  addiu     $v0, $zero, 2
/* D06E00 802416D0 00501804 */  sllv      $v1, $s0, $v0
/* D06E04 802416D4 00701821 */  addu      $v1, $v1, $s0
/* D06E08 802416D8 00431804 */  sllv      $v1, $v1, $v0
/* D06E0C 802416DC 00701823 */  subu      $v1, $v1, $s0
/* D06E10 802416E0 000320C0 */  sll       $a0, $v1, 3
/* D06E14 802416E4 00641821 */  addu      $v1, $v1, $a0
/* D06E18 802416E8 000318C0 */  sll       $v1, $v1, 3
/* D06E1C 802416EC 3C01800B */  lui       $at, 0x800b
/* D06E20 802416F0 00230821 */  addu      $at, $at, $v1
/* D06E24 802416F4 E4201D98 */  swc1      $f0, 0x1d98($at)
/* D06E28 802416F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D06E2C 802416FC 8FB10014 */  lw        $s1, 0x14($sp)
/* D06E30 80241700 8FB00010 */  lw        $s0, 0x10($sp)
/* D06E34 80241704 03E00008 */  jr        $ra
/* D06E38 80241708 27BD0020 */   addiu    $sp, $sp, 0x20
