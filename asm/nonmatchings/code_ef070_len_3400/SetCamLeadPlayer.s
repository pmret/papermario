.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetCamLeadPlayer
/* 0F0030 802CB680 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0034 802CB684 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0038 802CB688 0080882D */  daddu $s1, $a0, $zero
/* 0F003C 802CB68C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F0040 802CB690 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0044 802CB694 8E30000C */  lw    $s0, 0xc($s1)
/* 0F0048 802CB698 8E050000 */  lw    $a1, ($s0)
/* 0F004C 802CB69C 0C0B1EAF */  jal   get_variable
/* 0F0050 802CB6A0 26100004 */   addiu $s0, $s0, 4
/* 0F0054 802CB6A4 0220202D */  daddu $a0, $s1, $zero
/* 0F0058 802CB6A8 8E050000 */  lw    $a1, ($s0)
/* 0F005C 802CB6AC 0C0B1EAF */  jal   get_variable
/* 0F0060 802CB6B0 0040802D */   daddu $s0, $v0, $zero
/* 0F0064 802CB6B4 3C05800B */  lui   $a1, 0x800b
/* 0F0068 802CB6B8 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0F006C 802CB6BC 00101880 */  sll   $v1, $s0, 2
/* 0F0070 802CB6C0 00701821 */  addu  $v1, $v1, $s0
/* 0F0074 802CB6C4 00031880 */  sll   $v1, $v1, 2
/* 0F0078 802CB6C8 00701823 */  subu  $v1, $v1, $s0
/* 0F007C 802CB6CC 000320C0 */  sll   $a0, $v1, 3
/* 0F0080 802CB6D0 00641821 */  addu  $v1, $v1, $a0
/* 0F0084 802CB6D4 000318C0 */  sll   $v1, $v1, 3
/* 0F0088 802CB6D8 10400004 */  beqz  $v0, .L802CB6EC
/* 0F008C 802CB6DC 00651821 */   addu  $v1, $v1, $a1
/* 0F0090 802CB6E0 94620000 */  lhu   $v0, ($v1)
/* 0F0094 802CB6E4 080B2DBD */  j     .L802CB6F4
/* 0F0098 802CB6E8 34420004 */   ori   $v0, $v0, 4

.L802CB6EC:
/* 0F009C 802CB6EC 94620000 */  lhu   $v0, ($v1)
/* 0F00A0 802CB6F0 3042FFFB */  andi  $v0, $v0, 0xfffb
.L802CB6F4:
/* 0F00A4 802CB6F4 A4620000 */  sh    $v0, ($v1)
/* 0F00A8 802CB6F8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F00AC 802CB6FC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F00B0 802CB700 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F00B4 802CB704 24020002 */  addiu $v0, $zero, 2
/* 0F00B8 802CB708 03E00008 */  jr    $ra
/* 0F00BC 802CB70C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F00C0 802CB710 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F00C4 802CB714 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F00C8 802CB718 0080882D */  daddu $s1, $a0, $zero
/* 0F00CC 802CB71C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F00D0 802CB720 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F00D4 802CB724 8E30000C */  lw    $s0, 0xc($s1)
/* 0F00D8 802CB728 8E050000 */  lw    $a1, ($s0)
/* 0F00DC 802CB72C 0C0B1EAF */  jal   get_variable
/* 0F00E0 802CB730 26100004 */   addiu $s0, $s0, 4
/* 0F00E4 802CB734 0220202D */  daddu $a0, $s1, $zero
/* 0F00E8 802CB738 8E050000 */  lw    $a1, ($s0)
/* 0F00EC 802CB73C 0C0B1EAF */  jal   get_variable
/* 0F00F0 802CB740 0040802D */   daddu $s0, $v0, $zero
/* 0F00F4 802CB744 44821000 */  mtc1  $v0, $f2
/* 0F00F8 802CB748 00000000 */  nop   
/* 0F00FC 802CB74C 468010A0 */  cvt.s.w $f2, $f2
/* 0F0100 802CB750 24020002 */  addiu $v0, $zero, 2
/* 0F0104 802CB754 00501804 */  sllv  $v1, $s0, $v0
/* 0F0108 802CB758 00701821 */  addu  $v1, $v1, $s0
/* 0F010C 802CB75C 00431804 */  sllv  $v1, $v1, $v0
/* 0F0110 802CB760 00701823 */  subu  $v1, $v1, $s0
/* 0F0114 802CB764 000320C0 */  sll   $a0, $v1, 3
/* 0F0118 802CB768 00641821 */  addu  $v1, $v1, $a0
/* 0F011C 802CB76C 3C0142C8 */  lui   $at, 0x42c8
/* 0F0120 802CB770 44810000 */  mtc1  $at, $f0
/* 0F0124 802CB774 000318C0 */  sll   $v1, $v1, 3
/* 0F0128 802CB778 46001083 */  div.s $f2, $f2, $f0
/* 0F012C 802CB77C 3C01800B */  lui   $at, 0x800b
/* 0F0130 802CB780 00230821 */  addu  $at, $at, $v1
/* 0F0134 802CB784 E42222A0 */  swc1  $f2, 0x22a0($at)
/* 0F0138 802CB788 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F013C 802CB78C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0140 802CB790 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0144 802CB794 03E00008 */  jr    $ra
/* 0F0148 802CB798 27BD0020 */   addiu $sp, $sp, 0x20

