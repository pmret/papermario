.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405E0_A274B0
/* A274B0 802405E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A274B4 802405E4 AFB10014 */  sw        $s1, 0x14($sp)
/* A274B8 802405E8 0080882D */  daddu     $s1, $a0, $zero
/* A274BC 802405EC AFBF0018 */  sw        $ra, 0x18($sp)
/* A274C0 802405F0 AFB00010 */  sw        $s0, 0x10($sp)
/* A274C4 802405F4 8E30000C */  lw        $s0, 0xc($s1)
/* A274C8 802405F8 8E050000 */  lw        $a1, ($s0)
/* A274CC 802405FC 0C0B1EAF */  jal       get_variable
/* A274D0 80240600 26100004 */   addiu    $s0, $s0, 4
/* A274D4 80240604 0220202D */  daddu     $a0, $s1, $zero
/* A274D8 80240608 8E050000 */  lw        $a1, ($s0)
/* A274DC 8024060C 0C0B210B */  jal       get_float_variable
/* A274E0 80240610 0040802D */   daddu    $s0, $v0, $zero
/* A274E4 80240614 24020002 */  addiu     $v0, $zero, 2
/* A274E8 80240618 00501804 */  sllv      $v1, $s0, $v0
/* A274EC 8024061C 00701821 */  addu      $v1, $v1, $s0
/* A274F0 80240620 00431804 */  sllv      $v1, $v1, $v0
/* A274F4 80240624 00701823 */  subu      $v1, $v1, $s0
/* A274F8 80240628 000320C0 */  sll       $a0, $v1, 3
/* A274FC 8024062C 00641821 */  addu      $v1, $v1, $a0
/* A27500 80240630 000318C0 */  sll       $v1, $v1, 3
/* A27504 80240634 3C01800B */  lui       $at, 0x800b
/* A27508 80240638 00230821 */  addu      $at, $at, $v1
/* A2750C 8024063C E4201D98 */  swc1      $f0, 0x1d98($at)
/* A27510 80240640 8FBF0018 */  lw        $ra, 0x18($sp)
/* A27514 80240644 8FB10014 */  lw        $s1, 0x14($sp)
/* A27518 80240648 8FB00010 */  lw        $s0, 0x10($sp)
/* A2751C 8024064C 03E00008 */  jr        $ra
/* A27520 80240650 27BD0020 */   addiu    $sp, $sp, 0x20
