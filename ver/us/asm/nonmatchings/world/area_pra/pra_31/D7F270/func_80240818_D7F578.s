.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240818_D7F578
/* D7F578 80240818 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D7F57C 8024081C AFB10014 */  sw        $s1, 0x14($sp)
/* D7F580 80240820 0080882D */  daddu     $s1, $a0, $zero
/* D7F584 80240824 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7F588 80240828 AFB00010 */  sw        $s0, 0x10($sp)
/* D7F58C 8024082C F7B40020 */  sdc1      $f20, 0x20($sp)
/* D7F590 80240830 8E30000C */  lw        $s0, 0xc($s1)
/* D7F594 80240834 8E050000 */  lw        $a1, ($s0)
/* D7F598 80240838 0C0B1EAF */  jal       get_variable
/* D7F59C 8024083C 26100004 */   addiu    $s0, $s0, 4
/* D7F5A0 80240840 0220202D */  daddu     $a0, $s1, $zero
/* D7F5A4 80240844 8E050000 */  lw        $a1, ($s0)
/* D7F5A8 80240848 0C0B210B */  jal       evt_get_float_variable
/* D7F5AC 8024084C 0040802D */   daddu    $s0, $v0, $zero
/* D7F5B0 80240850 0220202D */  daddu     $a0, $s1, $zero
/* D7F5B4 80240854 3C05FD05 */  lui       $a1, 0xfd05
/* D7F5B8 80240858 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7F5BC 8024085C 0C0B1EAF */  jal       get_variable
/* D7F5C0 80240860 46000506 */   mov.s    $f20, $f0
/* D7F5C4 80240864 00101840 */  sll       $v1, $s0, 1
/* D7F5C8 80240868 00701821 */  addu      $v1, $v1, $s0
/* D7F5CC 8024086C 000318C0 */  sll       $v1, $v1, 3
/* D7F5D0 80240870 00431821 */  addu      $v1, $v0, $v1
/* D7F5D4 80240874 E4740014 */  swc1      $f20, 0x14($v1)
/* D7F5D8 80240878 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7F5DC 8024087C 8FB10014 */  lw        $s1, 0x14($sp)
/* D7F5E0 80240880 8FB00010 */  lw        $s0, 0x10($sp)
/* D7F5E4 80240884 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D7F5E8 80240888 24020002 */  addiu     $v0, $zero, 2
/* D7F5EC 8024088C 03E00008 */  jr        $ra
/* D7F5F0 80240890 27BD0028 */   addiu    $sp, $sp, 0x28
