.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF8
/* C61908 80240BF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C6190C 80240BFC AFB10014 */  sw        $s1, 0x14($sp)
/* C61910 80240C00 0080882D */  daddu     $s1, $a0, $zero
/* C61914 80240C04 AFBF0018 */  sw        $ra, 0x18($sp)
/* C61918 80240C08 AFB00010 */  sw        $s0, 0x10($sp)
/* C6191C 80240C0C 8E300148 */  lw        $s0, 0x148($s1)
/* C61920 80240C10 0C00EABB */  jal       get_npc_unsafe
/* C61924 80240C14 86040008 */   lh       $a0, 8($s0)
/* C61928 80240C18 24030001 */  addiu     $v1, $zero, 1
/* C6192C 80240C1C 0040202D */  daddu     $a0, $v0, $zero
/* C61930 80240C20 AE03006C */  sw        $v1, 0x6c($s0)
/* C61934 80240C24 8482008C */  lh        $v0, 0x8c($a0)
/* C61938 80240C28 14400009 */  bnez      $v0, .L80240C50
/* C6193C 80240C2C 24020002 */   addiu    $v0, $zero, 2
/* C61940 80240C30 96030072 */  lhu       $v1, 0x72($s0)
/* C61944 80240C34 AE02006C */  sw        $v0, 0x6c($s0)
/* C61948 80240C38 A483008E */  sh        $v1, 0x8e($a0)
/* C6194C 80240C3C 8E0200CC */  lw        $v0, 0xcc($s0)
/* C61950 80240C40 8C420020 */  lw        $v0, 0x20($v0)
/* C61954 80240C44 AC820028 */  sw        $v0, 0x28($a0)
/* C61958 80240C48 2402001F */  addiu     $v0, $zero, 0x1f
/* C6195C 80240C4C AE220070 */  sw        $v0, 0x70($s1)
.L80240C50:
/* C61960 80240C50 8FBF0018 */  lw        $ra, 0x18($sp)
/* C61964 80240C54 8FB10014 */  lw        $s1, 0x14($sp)
/* C61968 80240C58 8FB00010 */  lw        $s0, 0x10($sp)
/* C6196C 80240C5C 03E00008 */  jr        $ra
/* C61970 80240C60 27BD0020 */   addiu    $sp, $sp, 0x20
