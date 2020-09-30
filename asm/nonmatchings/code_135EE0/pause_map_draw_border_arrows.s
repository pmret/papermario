.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_draw_border_arrows
/* 140D68 8024DA28 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 140D6C 8024DA2C AFBF0028 */  sw        $ra, 0x28($sp)
/* 140D70 8024DA30 00A0182D */  daddu     $v1, $a1, $zero
/* 140D74 8024DA34 00C0382D */  daddu     $a3, $a2, $zero
/* 140D78 8024DA38 24020001 */  addiu     $v0, $zero, 1
/* 140D7C 8024DA3C 10820016 */  beq       $a0, $v0, .L8024DA98
/* 140D80 8024DA40 24080010 */   addiu    $t0, $zero, 0x10
/* 140D84 8024DA44 28820002 */  slti      $v0, $a0, 2
/* 140D88 8024DA48 10400005 */  beqz      $v0, .L8024DA60
/* 140D8C 8024DA4C 24020002 */   addiu    $v0, $zero, 2
/* 140D90 8024DA50 10800007 */  beqz      $a0, .L8024DA70
/* 140D94 8024DA54 00032080 */   sll      $a0, $v1, 2
/* 140D98 8024DA58 080936B8 */  j         .L8024DAE0
/* 140D9C 8024DA5C 00072880 */   sll      $a1, $a3, 2
.L8024DA60:
/* 140DA0 8024DA60 10820015 */  beq       $a0, $v0, .L8024DAB8
/* 140DA4 8024DA64 00032080 */   sll      $a0, $v1, 2
/* 140DA8 8024DA68 080936B8 */  j         .L8024DAE0
/* 140DAC 8024DA6C 00072880 */   sll      $a1, $a3, 2
.L8024DA70:
/* 140DB0 8024DA70 00072880 */  sll       $a1, $a3, 2
/* 140DB4 8024DA74 24660010 */  addiu     $a2, $v1, 0x10
/* 140DB8 8024DA78 00063080 */  sll       $a2, $a2, 2
/* 140DBC 8024DA7C 24E70010 */  addiu     $a3, $a3, 0x10
/* 140DC0 8024DA80 00073880 */  sll       $a3, $a3, 2
/* 140DC4 8024DA84 24020400 */  addiu     $v0, $zero, 0x400
/* 140DC8 8024DA88 AFA00010 */  sw        $zero, 0x10($sp)
/* 140DCC 8024DA8C AFA00014 */  sw        $zero, 0x14($sp)
/* 140DD0 8024DA90 080936C1 */  j         .L8024DB04
/* 140DD4 8024DA94 AFA00018 */   sw       $zero, 0x18($sp)
.L8024DA98:
/* 140DD8 8024DA98 00032080 */  sll       $a0, $v1, 2
/* 140DDC 8024DA9C 00072880 */  sll       $a1, $a3, 2
/* 140DE0 8024DAA0 24660010 */  addiu     $a2, $v1, 0x10
/* 140DE4 8024DAA4 00063080 */  sll       $a2, $a2, 2
/* 140DE8 8024DAA8 24E70010 */  addiu     $a3, $a3, 0x10
/* 140DEC 8024DAAC 00073880 */  sll       $a3, $a3, 2
/* 140DF0 8024DAB0 080936BD */  j         .L8024DAF4
/* 140DF4 8024DAB4 24020200 */   addiu    $v0, $zero, 0x200
.L8024DAB8:
/* 140DF8 8024DAB8 00072880 */  sll       $a1, $a3, 2
/* 140DFC 8024DABC 24660010 */  addiu     $a2, $v1, 0x10
/* 140E00 8024DAC0 00063080 */  sll       $a2, $a2, 2
/* 140E04 8024DAC4 24E70010 */  addiu     $a3, $a3, 0x10
/* 140E08 8024DAC8 00073880 */  sll       $a3, $a3, 2
/* 140E0C 8024DACC 24020400 */  addiu     $v0, $zero, 0x400
/* 140E10 8024DAD0 AFA00010 */  sw        $zero, 0x10($sp)
/* 140E14 8024DAD4 AFA00014 */  sw        $zero, 0x14($sp)
/* 140E18 8024DAD8 080936C1 */  j         .L8024DB04
/* 140E1C 8024DADC AFA20018 */   sw       $v0, 0x18($sp)
.L8024DAE0:
/* 140E20 8024DAE0 00683021 */  addu      $a2, $v1, $t0
/* 140E24 8024DAE4 00063080 */  sll       $a2, $a2, 2
/* 140E28 8024DAE8 00E83821 */  addu      $a3, $a3, $t0
/* 140E2C 8024DAEC 00073880 */  sll       $a3, $a3, 2
/* 140E30 8024DAF0 24020600 */  addiu     $v0, $zero, 0x600
.L8024DAF4:
/* 140E34 8024DAF4 AFA20018 */  sw        $v0, 0x18($sp)
/* 140E38 8024DAF8 24020400 */  addiu     $v0, $zero, 0x400
/* 140E3C 8024DAFC AFA00010 */  sw        $zero, 0x10($sp)
/* 140E40 8024DB00 AFA00014 */  sw        $zero, 0x14($sp)
.L8024DB04:
/* 140E44 8024DB04 AFA2001C */  sw        $v0, 0x1c($sp)
/* 140E48 8024DB08 0C091216 */  jal       pause_draw_rect
/* 140E4C 8024DB0C AFA20020 */   sw       $v0, 0x20($sp)
/* 140E50 8024DB10 8FBF0028 */  lw        $ra, 0x28($sp)
/* 140E54 8024DB14 03E00008 */  jr        $ra
/* 140E58 8024DB18 27BD0030 */   addiu    $sp, $sp, 0x30
