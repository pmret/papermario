.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_draw_title
/* 14188C 8024E54C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 141890 8024E550 AFB30024 */  sw        $s3, 0x24($sp)
/* 141894 8024E554 00A0982D */  daddu     $s3, $a1, $zero
/* 141898 8024E558 AFB40028 */  sw        $s4, 0x28($sp)
/* 14189C 8024E55C 00C0A02D */  daddu     $s4, $a2, $zero
/* 1418A0 8024E560 AFB20020 */  sw        $s2, 0x20($sp)
/* 1418A4 8024E564 00E0902D */  daddu     $s2, $a3, $zero
/* 1418A8 8024E568 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 1418AC 8024E56C 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 1418B0 8024E570 24020006 */  addiu     $v0, $zero, 6
/* 1418B4 8024E574 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1418B8 8024E578 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1418BC 8024E57C 14620019 */  bne       $v1, $v0, .L8024E5E4
/* 1418C0 8024E580 AFB00018 */   sw       $s0, 0x18($sp)
/* 1418C4 8024E584 3C118027 */  lui       $s1, %hi(D_8027071C)
/* 1418C8 8024E588 2631071C */  addiu     $s1, $s1, %lo(D_8027071C)
/* 1418CC 8024E58C 8E230000 */  lw        $v1, ($s1)
/* 1418D0 8024E590 2402FFFF */  addiu     $v0, $zero, -1
/* 1418D4 8024E594 10620013 */  beq       $v1, $v0, .L8024E5E4
/* 1418D8 8024E598 3C10001D */   lui      $s0, 0x1d
/* 1418DC 8024E59C 361000F2 */  ori       $s0, $s0, 0xf2
/* 1418E0 8024E5A0 00032040 */  sll       $a0, $v1, 1
/* 1418E4 8024E5A4 00832021 */  addu      $a0, $a0, $v1
/* 1418E8 8024E5A8 00902021 */  addu      $a0, $a0, $s0
/* 1418EC 8024E5AC 0C04991D */  jal       get_string_width
/* 1418F0 8024E5B0 0000282D */   daddu    $a1, $zero, $zero
/* 1418F4 8024E5B4 02421023 */  subu      $v0, $s2, $v0
/* 1418F8 8024E5B8 00021043 */  sra       $v0, $v0, 1
/* 1418FC 8024E5BC 02622821 */  addu      $a1, $s3, $v0
/* 141900 8024E5C0 26860001 */  addiu     $a2, $s4, 1
/* 141904 8024E5C4 8E230000 */  lw        $v1, ($s1)
/* 141908 8024E5C8 240700FF */  addiu     $a3, $zero, 0xff
/* 14190C 8024E5CC AFA00010 */  sw        $zero, 0x10($sp)
/* 141910 8024E5D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 141914 8024E5D4 00032040 */  sll       $a0, $v1, 1
/* 141918 8024E5D8 00832021 */  addu      $a0, $a0, $v1
/* 14191C 8024E5DC 0C04993B */  jal       draw_string
/* 141920 8024E5E0 00902021 */   addu     $a0, $a0, $s0
.L8024E5E4:
/* 141924 8024E5E4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 141928 8024E5E8 8FB40028 */  lw        $s4, 0x28($sp)
/* 14192C 8024E5EC 8FB30024 */  lw        $s3, 0x24($sp)
/* 141930 8024E5F0 8FB20020 */  lw        $s2, 0x20($sp)
/* 141934 8024E5F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 141938 8024E5F8 8FB00018 */  lw        $s0, 0x18($sp)
/* 14193C 8024E5FC 03E00008 */  jr        $ra
/* 141940 8024E600 27BD0030 */   addiu    $sp, $sp, 0x30
