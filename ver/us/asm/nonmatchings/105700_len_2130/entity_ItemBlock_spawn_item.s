.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_ItemBlock_spawn_item
/* 10578C 802E3F0C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 105790 802E3F10 AFB00020 */  sw        $s0, 0x20($sp)
/* 105794 802E3F14 0080802D */  daddu     $s0, $a0, $zero
/* 105798 802E3F18 AFBF002C */  sw        $ra, 0x2c($sp)
/* 10579C 802E3F1C AFB20028 */  sw        $s2, 0x28($sp)
/* 1057A0 802E3F20 AFB10024 */  sw        $s1, 0x24($sp)
/* 1057A4 802E3F24 8E110040 */  lw        $s1, 0x40($s0)
/* 1057A8 802E3F28 86220010 */  lh        $v0, 0x10($s1)
/* 1057AC 802E3F2C 1040003E */  beqz      $v0, .L802E4028
/* 1057B0 802E3F30 3C120010 */   lui      $s2, 0x10
/* 1057B4 802E3F34 8E020000 */  lw        $v0, ($s0)
/* 1057B8 802E3F38 00521024 */  and       $v0, $v0, $s2
/* 1057BC 802E3F3C 1440003A */  bnez      $v0, .L802E4028
/* 1057C0 802E3F40 00000000 */   nop
/* 1057C4 802E3F44 0C03951B */  jal       player_get_camera_facing_angle
/* 1057C8 802E3F48 00000000 */   nop
/* 1057CC 802E3F4C 8E020000 */  lw        $v0, ($s0)
/* 1057D0 802E3F50 4600010D */  trunc.w.s $f4, $f0
/* 1057D4 802E3F54 44032000 */  mfc1      $v1, $f4
/* 1057D8 802E3F58 00521025 */  or        $v0, $v0, $s2
/* 1057DC 802E3F5C AE020000 */  sw        $v0, ($s0)
/* 1057E0 802E3F60 86240010 */  lh        $a0, 0x10($s1)
/* 1057E4 802E3F64 24020157 */  addiu     $v0, $zero, 0x157
/* 1057E8 802E3F68 54820013 */  bnel      $a0, $v0, .L802E3FB8
/* 1057EC 802E3F6C 24630168 */   addiu    $v1, $v1, 0x168
/* 1057F0 802E3F70 C602004C */  lwc1      $f2, 0x4c($s0)
/* 1057F4 802E3F74 24020015 */  addiu     $v0, $zero, 0x15
/* 1057F8 802E3F78 AFA20010 */  sw        $v0, 0x10($sp)
/* 1057FC 802E3F7C AFA00014 */  sw        $zero, 0x14($sp)
/* 105800 802E3F80 AFA30018 */  sw        $v1, 0x18($sp)
/* 105804 802E3F84 9622000A */  lhu       $v0, 0xa($s1)
/* 105808 802E3F88 3C01403C */  lui       $at, 0x403c
/* 10580C 802E3F8C 44810800 */  mtc1      $at, $f1
/* 105810 802E3F90 44800000 */  mtc1      $zero, $f0
/* 105814 802E3F94 460010A1 */  cvt.d.s   $f2, $f2
/* 105818 802E3F98 46201080 */  add.d     $f2, $f2, $f0
/* 10581C 802E3F9C AFA2001C */  sw        $v0, 0x1c($sp)
/* 105820 802E3FA0 8E050048 */  lw        $a1, 0x48($s0)
/* 105824 802E3FA4 8E070050 */  lw        $a3, 0x50($s0)
/* 105828 802E3FA8 462010A0 */  cvt.s.d   $f2, $f2
/* 10582C 802E3FAC 44061000 */  mfc1      $a2, $f2
/* 105830 802E3FB0 080B9008 */  j         .L802E4020
/* 105834 802E3FB4 24040157 */   addiu    $a0, $zero, 0x157
.L802E3FB8:
/* 105838 802E3FB8 26050048 */  addiu     $a1, $s0, 0x48
/* 10583C 802E3FBC 00041140 */  sll       $v0, $a0, 5
/* 105840 802E3FC0 C600004C */  lwc1      $f0, 0x4c($s0)
/* 105844 802E3FC4 3C014034 */  lui       $at, 0x4034
/* 105848 802E3FC8 44811800 */  mtc1      $at, $f3
/* 10584C 802E3FCC 44801000 */  mtc1      $zero, $f2
/* 105850 802E3FD0 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* 105854 802E3FD4 00220821 */  addu      $at, $at, $v0
/* 105858 802E3FD8 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* 10585C 802E3FDC 46000021 */  cvt.d.s   $f0, $f0
/* 105860 802E3FE0 46220000 */  add.d     $f0, $f0, $f2
/* 105864 802E3FE4 26070050 */  addiu     $a3, $s0, 0x50
/* 105868 802E3FE8 30420040 */  andi      $v0, $v0, 0x40
/* 10586C 802E3FEC 10400003 */  beqz      $v0, .L802E3FFC
/* 105870 802E3FF0 46200020 */   cvt.s.d  $f0, $f0
/* 105874 802E3FF4 080B9000 */  j         .L802E4000
/* 105878 802E3FF8 2402000B */   addiu    $v0, $zero, 0xb
.L802E3FFC:
/* 10587C 802E3FFC 2402000A */  addiu     $v0, $zero, 0xa
.L802E4000:
/* 105880 802E4000 AFA20010 */  sw        $v0, 0x10($sp)
/* 105884 802E4004 AFA00014 */  sw        $zero, 0x14($sp)
/* 105888 802E4008 AFA30018 */  sw        $v1, 0x18($sp)
/* 10588C 802E400C 9622000A */  lhu       $v0, 0xa($s1)
/* 105890 802E4010 44060000 */  mfc1      $a2, $f0
/* 105894 802E4014 AFA2001C */  sw        $v0, 0x1c($sp)
/* 105898 802E4018 8CA50000 */  lw        $a1, ($a1)
/* 10589C 802E401C 8CE70000 */  lw        $a3, ($a3)
.L802E4020:
/* 1058A0 802E4020 0C04C4FD */  jal       make_item_entity
/* 1058A4 802E4024 00000000 */   nop
.L802E4028:
/* 1058A8 802E4028 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1058AC 802E402C 8FB20028 */  lw        $s2, 0x28($sp)
/* 1058B0 802E4030 8FB10024 */  lw        $s1, 0x24($sp)
/* 1058B4 802E4034 8FB00020 */  lw        $s0, 0x20($sp)
/* 1058B8 802E4038 03E00008 */  jr        $ra
/* 1058BC 802E403C 27BD0030 */   addiu    $sp, $sp, 0x30
