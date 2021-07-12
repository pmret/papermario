.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE6A0_3221F0
/* 3221F0 802BE6A0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3221F4 802BE6A4 0080302D */  daddu     $a2, $a0, $zero
/* 3221F8 802BE6A8 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 3221FC 802BE6AC 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 322200 802BE6B0 27A50028 */  addiu     $a1, $sp, 0x28
/* 322204 802BE6B4 AFBF0048 */  sw        $ra, 0x48($sp)
/* 322208 802BE6B8 848200B0 */  lh        $v0, 0xb0($a0)
/* 32220C 802BE6BC C480002C */  lwc1      $f0, 0x2c($a0)
/* 322210 802BE6C0 44821000 */  mtc1      $v0, $f2
/* 322214 802BE6C4 00000000 */  nop
/* 322218 802BE6C8 468010A0 */  cvt.s.w   $f2, $f2
/* 32221C 802BE6CC 46020000 */  add.s     $f0, $f0, $f2
/* 322220 802BE6D0 27A7002C */  addiu     $a3, $sp, 0x2c
/* 322224 802BE6D4 E7A20030 */  swc1      $f2, 0x30($sp)
/* 322228 802BE6D8 E4C00000 */  swc1      $f0, ($a2)
/* 32222C 802BE6DC C4800028 */  lwc1      $f0, 0x28($a0)
/* 322230 802BE6E0 C4820030 */  lwc1      $f2, 0x30($a0)
/* 322234 802BE6E4 27A20030 */  addiu     $v0, $sp, 0x30
/* 322238 802BE6E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 32223C 802BE6EC E7A2002C */  swc1      $f2, 0x2c($sp)
/* 322240 802BE6F0 AFA20010 */  sw        $v0, 0x10($sp)
/* 322244 802BE6F4 27A20034 */  addiu     $v0, $sp, 0x34
/* 322248 802BE6F8 AFA20014 */  sw        $v0, 0x14($sp)
/* 32224C 802BE6FC 27A20038 */  addiu     $v0, $sp, 0x38
/* 322250 802BE700 AFA20018 */  sw        $v0, 0x18($sp)
/* 322254 802BE704 27A2003C */  addiu     $v0, $sp, 0x3c
/* 322258 802BE708 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32225C 802BE70C 27A20040 */  addiu     $v0, $sp, 0x40
/* 322260 802BE710 0C03791B */  jal       player_raycast_below_cam_relative
/* 322264 802BE714 AFA20020 */   sw       $v0, 0x20($sp)
/* 322268 802BE718 8FBF0048 */  lw        $ra, 0x48($sp)
/* 32226C 802BE71C 03E00008 */  jr        $ra
/* 322270 802BE720 27BD0050 */   addiu    $sp, $sp, 0x50
