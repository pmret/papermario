.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel modify_collider_family_flags
/* EE698 802C9CE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE69C 802C9CEC AFB20018 */  sw        $s2, 0x18($sp)
/* EE6A0 802C9CF0 00A0902D */  daddu     $s2, $a1, $zero
/* EE6A4 802C9CF4 000410C0 */  sll       $v0, $a0, 3
/* EE6A8 802C9CF8 00441023 */  subu      $v0, $v0, $a0
/* EE6AC 802C9CFC 3C03800B */  lui       $v1, 0x800b
/* EE6B0 802C9D00 8C6342E4 */  lw        $v1, 0x42e4($v1)
/* EE6B4 802C9D04 00021080 */  sll       $v0, $v0, 2
/* EE6B8 802C9D08 AFBF001C */  sw        $ra, 0x1c($sp)
/* EE6BC 802C9D0C AFB10014 */  sw        $s1, 0x14($sp)
/* EE6C0 802C9D10 AFB00010 */  sw        $s0, 0x10($sp)
/* EE6C4 802C9D14 00628021 */  addu      $s0, $v1, $v0
/* EE6C8 802C9D18 86040004 */  lh        $a0, 4($s0)
/* EE6CC 802C9D1C 04800003 */  bltz      $a0, .L802C9D2C
/* EE6D0 802C9D20 00C0882D */   daddu    $s1, $a2, $zero
/* EE6D4 802C9D24 0C0B273A */  jal       modify_collider_family_flags
/* EE6D8 802C9D28 00000000 */   nop      
.L802C9D2C:
/* EE6DC 802C9D2C 86040006 */  lh        $a0, 6($s0)
/* EE6E0 802C9D30 04800003 */  bltz      $a0, .L802C9D40
/* EE6E4 802C9D34 0240282D */   daddu    $a1, $s2, $zero
/* EE6E8 802C9D38 0C0B273A */  jal       modify_collider_family_flags
/* EE6EC 802C9D3C 0220302D */   daddu    $a2, $s1, $zero
.L802C9D40:
/* EE6F0 802C9D40 24020001 */  addiu     $v0, $zero, 1
/* EE6F4 802C9D44 12220011 */  beq       $s1, $v0, .L802C9D8C
/* EE6F8 802C9D48 00121827 */   nor      $v1, $zero, $s2
/* EE6FC 802C9D4C 2A220002 */  slti      $v0, $s1, 2
/* EE700 802C9D50 50400005 */  beql      $v0, $zero, .L802C9D68
/* EE704 802C9D54 24020002 */   addiu    $v0, $zero, 2
/* EE708 802C9D58 12200009 */  beqz      $s1, .L802C9D80
/* EE70C 802C9D5C 00000000 */   nop      
/* EE710 802C9D60 080B276D */  j         .L802C9DB4
/* EE714 802C9D64 00000000 */   nop      
.L802C9D68:
/* EE718 802C9D68 1222000B */  beq       $s1, $v0, .L802C9D98
/* EE71C 802C9D6C 24020003 */   addiu    $v0, $zero, 3
/* EE720 802C9D70 1222000B */  beq       $s1, $v0, .L802C9DA0
/* EE724 802C9D74 2403FF00 */   addiu    $v1, $zero, -0x100
/* EE728 802C9D78 080B276D */  j         .L802C9DB4
/* EE72C 802C9D7C 00000000 */   nop      
.L802C9D80:
/* EE730 802C9D80 8E020000 */  lw        $v0, ($s0)
/* EE734 802C9D84 080B276C */  j         .L802C9DB0
/* EE738 802C9D88 00521025 */   or       $v0, $v0, $s2
.L802C9D8C:
/* EE73C 802C9D8C 8E020000 */  lw        $v0, ($s0)
/* EE740 802C9D90 080B276C */  j         .L802C9DB0
/* EE744 802C9D94 00431024 */   and      $v0, $v0, $v1
.L802C9D98:
/* EE748 802C9D98 080B276D */  j         .L802C9DB4
/* EE74C 802C9D9C AE120000 */   sw       $s2, ($s0)
.L802C9DA0:
/* EE750 802C9DA0 8E020000 */  lw        $v0, ($s0)
/* EE754 802C9DA4 00431024 */  and       $v0, $v0, $v1
/* EE758 802C9DA8 324300FF */  andi      $v1, $s2, 0xff
/* EE75C 802C9DAC 00431025 */  or        $v0, $v0, $v1
.L802C9DB0:
/* EE760 802C9DB0 AE020000 */  sw        $v0, ($s0)
.L802C9DB4:
/* EE764 802C9DB4 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE768 802C9DB8 8FB20018 */  lw        $s2, 0x18($sp)
/* EE76C 802C9DBC 8FB10014 */  lw        $s1, 0x14($sp)
/* EE770 802C9DC0 8FB00010 */  lw        $s0, 0x10($sp)
/* EE774 802C9DC4 03E00008 */  jr        $ra
/* EE778 802C9DC8 27BD0020 */   addiu    $sp, $sp, 0x20
