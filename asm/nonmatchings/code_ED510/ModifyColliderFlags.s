.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ModifyColliderFlags
/* EE77C 802C9DCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE780 802C9DD0 AFB10014 */  sw        $s1, 0x14($sp)
/* EE784 802C9DD4 0080882D */  daddu     $s1, $a0, $zero
/* EE788 802C9DD8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EE78C 802C9DDC AFB20018 */  sw        $s2, 0x18($sp)
/* EE790 802C9DE0 AFB00010 */  sw        $s0, 0x10($sp)
/* EE794 802C9DE4 8E30000C */  lw        $s0, 0xc($s1)
/* EE798 802C9DE8 8E050000 */  lw        $a1, ($s0)
/* EE79C 802C9DEC 0C0B1EAF */  jal       get_variable
/* EE7A0 802C9DF0 26100004 */   addiu    $s0, $s0, 4
/* EE7A4 802C9DF4 8E050000 */  lw        $a1, ($s0)
/* EE7A8 802C9DF8 26100004 */  addiu     $s0, $s0, 4
/* EE7AC 802C9DFC 0220202D */  daddu     $a0, $s1, $zero
/* EE7B0 802C9E00 0C0B1EAF */  jal       get_variable
/* EE7B4 802C9E04 0040902D */   daddu    $s2, $v0, $zero
/* EE7B8 802C9E08 0220202D */  daddu     $a0, $s1, $zero
/* EE7BC 802C9E0C 8E050000 */  lw        $a1, ($s0)
/* EE7C0 802C9E10 0C0B1EAF */  jal       get_variable
/* EE7C4 802C9E14 0040802D */   daddu    $s0, $v0, $zero
/* EE7C8 802C9E18 001018C0 */  sll       $v1, $s0, 3
/* EE7CC 802C9E1C 00701823 */  subu      $v1, $v1, $s0
/* EE7D0 802C9E20 3C04800B */  lui       $a0, %hi(D_800B42E4)
/* EE7D4 802C9E24 8C8442E4 */  lw        $a0, %lo(D_800B42E4)($a0)
/* EE7D8 802C9E28 00031880 */  sll       $v1, $v1, 2
/* EE7DC 802C9E2C 00838021 */  addu      $s0, $a0, $v1
/* EE7E0 802C9E30 86040006 */  lh        $a0, 6($s0)
/* EE7E4 802C9E34 04800004 */  bltz      $a0, .L802C9E48
/* EE7E8 802C9E38 0040882D */   daddu    $s1, $v0, $zero
/* EE7EC 802C9E3C 0220282D */  daddu     $a1, $s1, $zero
/* EE7F0 802C9E40 0C0B273A */  jal       modify_collider_family_flags
/* EE7F4 802C9E44 0240302D */   daddu    $a2, $s2, $zero
.L802C9E48:
/* EE7F8 802C9E48 24020001 */  addiu     $v0, $zero, 1
/* EE7FC 802C9E4C 12420011 */  beq       $s2, $v0, .L802C9E94
/* EE800 802C9E50 00111827 */   nor      $v1, $zero, $s1
/* EE804 802C9E54 2A420002 */  slti      $v0, $s2, 2
/* EE808 802C9E58 50400005 */  beql      $v0, $zero, .L802C9E70
/* EE80C 802C9E5C 24020002 */   addiu    $v0, $zero, 2
/* EE810 802C9E60 12400009 */  beqz      $s2, .L802C9E88
/* EE814 802C9E64 00000000 */   nop
/* EE818 802C9E68 080B27AF */  j         .L802C9EBC
/* EE81C 802C9E6C 00000000 */   nop
.L802C9E70:
/* EE820 802C9E70 1242000B */  beq       $s2, $v0, .L802C9EA0
/* EE824 802C9E74 24020003 */   addiu    $v0, $zero, 3
/* EE828 802C9E78 1242000B */  beq       $s2, $v0, .L802C9EA8
/* EE82C 802C9E7C 2403FF00 */   addiu    $v1, $zero, -0x100
/* EE830 802C9E80 080B27AF */  j         .L802C9EBC
/* EE834 802C9E84 00000000 */   nop
.L802C9E88:
/* EE838 802C9E88 8E020000 */  lw        $v0, ($s0)
/* EE83C 802C9E8C 080B27AE */  j         .L802C9EB8
/* EE840 802C9E90 00511025 */   or       $v0, $v0, $s1
.L802C9E94:
/* EE844 802C9E94 8E020000 */  lw        $v0, ($s0)
/* EE848 802C9E98 080B27AE */  j         .L802C9EB8
/* EE84C 802C9E9C 00431024 */   and      $v0, $v0, $v1
.L802C9EA0:
/* EE850 802C9EA0 080B27AF */  j         .L802C9EBC
/* EE854 802C9EA4 AE110000 */   sw       $s1, ($s0)
.L802C9EA8:
/* EE858 802C9EA8 8E020000 */  lw        $v0, ($s0)
/* EE85C 802C9EAC 00431024 */  and       $v0, $v0, $v1
/* EE860 802C9EB0 322300FF */  andi      $v1, $s1, 0xff
/* EE864 802C9EB4 00431025 */  or        $v0, $v0, $v1
.L802C9EB8:
/* EE868 802C9EB8 AE020000 */  sw        $v0, ($s0)
.L802C9EBC:
/* EE86C 802C9EBC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE870 802C9EC0 8FB20018 */  lw        $s2, 0x18($sp)
/* EE874 802C9EC4 8FB10014 */  lw        $s1, 0x14($sp)
/* EE878 802C9EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* EE87C 802C9ECC 24020002 */  addiu     $v0, $zero, 2
/* EE880 802C9ED0 03E00008 */  jr        $ra
/* EE884 802C9ED4 27BD0020 */   addiu    $sp, $sp, 0x20
