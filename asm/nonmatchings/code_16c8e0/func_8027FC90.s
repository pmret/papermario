.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027FC90
/* 1AE570 8027FC90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1AE574 8027FC94 AFB40028 */  sw        $s4, 0x28($sp)
/* 1AE578 8027FC98 0080A02D */  daddu     $s4, $a0, $zero
/* 1AE57C 8027FC9C AFBF002C */  sw        $ra, 0x2c($sp)
/* 1AE580 8027FCA0 AFB30024 */  sw        $s3, 0x24($sp)
/* 1AE584 8027FCA4 AFB20020 */  sw        $s2, 0x20($sp)
/* 1AE588 8027FCA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1AE58C 8027FCAC AFB00018 */  sw        $s0, 0x18($sp)
/* 1AE590 8027FCB0 8E92000C */  lw        $s2, 0xc($s4)
/* 1AE594 8027FCB4 8E450000 */  lw        $a1, ($s2)
/* 1AE598 8027FCB8 0C0B1EAF */  jal       get_variable
/* 1AE59C 8027FCBC 26520004 */   addiu    $s2, $s2, 4
/* 1AE5A0 8027FCC0 0040202D */  daddu     $a0, $v0, $zero
/* 1AE5A4 8027FCC4 3C13800E */  lui       $s3, 0x800e
/* 1AE5A8 8027FCC8 2673C070 */  addiu     $s3, $s3, -0x3f90
/* 1AE5AC 8027FCCC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AE5B0 8027FCD0 14820002 */  bne       $a0, $v0, .L8027FCDC
/* 1AE5B4 8027FCD4 00000000 */   nop      
/* 1AE5B8 8027FCD8 8E840148 */  lw        $a0, 0x148($s4)
.L8027FCDC:
/* 1AE5BC 8027FCDC 0C09A75B */  jal       get_actor
/* 1AE5C0 8027FCE0 8E520000 */   lw       $s2, ($s2)
/* 1AE5C4 8027FCE4 8E630000 */  lw        $v1, ($s3)
/* 1AE5C8 8027FCE8 0040802D */  daddu     $s0, $v0, $zero
/* 1AE5CC 8027FCEC 34630020 */  ori       $v1, $v1, 0x20
/* 1AE5D0 8027FCF0 0C09F8CA */  jal       calc_partner_damage_enemy
/* 1AE5D4 8027FCF4 AE630000 */   sw       $v1, ($s3)
/* 1AE5D8 8027FCF8 AFA00010 */  sw        $zero, 0x10($sp)
/* 1AE5DC 8027FCFC 8E060020 */  lw        $a2, 0x20($s0)
/* 1AE5E0 8027FD00 86670180 */  lh        $a3, 0x180($s3)
/* 1AE5E4 8027FD04 C60C0018 */  lwc1      $f12, 0x18($s0)
/* 1AE5E8 8027FD08 C60E001C */  lwc1      $f14, 0x1c($s0)
/* 1AE5EC 8027FD0C 0C09996B */  jal       show_damage_popup
/* 1AE5F0 8027FD10 0040882D */   daddu    $s1, $v0, $zero
/* 1AE5F4 8027FD14 0280202D */  daddu     $a0, $s4, $zero
/* 1AE5F8 8027FD18 0240282D */  daddu     $a1, $s2, $zero
/* 1AE5FC 8027FD1C 0C0B2026 */  jal       set_variable
/* 1AE600 8027FD20 0220302D */   daddu    $a2, $s1, $zero
/* 1AE604 8027FD24 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1AE608 8027FD28 8FB40028 */  lw        $s4, 0x28($sp)
/* 1AE60C 8027FD2C 8FB30024 */  lw        $s3, 0x24($sp)
/* 1AE610 8027FD30 8FB20020 */  lw        $s2, 0x20($sp)
/* 1AE614 8027FD34 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1AE618 8027FD38 8FB00018 */  lw        $s0, 0x18($sp)
/* 1AE61C 8027FD3C 24020002 */  addiu     $v0, $zero, 2
/* 1AE620 8027FD40 03E00008 */  jr        $ra
/* 1AE624 8027FD44 27BD0030 */   addiu    $sp, $sp, 0x30
